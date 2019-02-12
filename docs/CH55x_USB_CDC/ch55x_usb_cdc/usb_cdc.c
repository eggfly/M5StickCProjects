#include "usb_cdc.h"
#include "usb_endp.h"
#include <string.h>
#include "bootloader.h"

#include "ch554_platform.h"

SBIT(bootPin,	0x90, 7);
SBIT(rstPin,	0x90, 0);

extern uint8_t state;
extern uint32_t count;

//��ʼ��������Ϊ57600��1ֹͣλ����У�飬8����λ��
xdatabuf(LINECODING_ADDR, LineCoding, LINECODING_SIZE);

#define SI5351_ReferenceClock	"26000000"
#define Device_Version			"1.0.1"

void CDC_Puts(char *str);

idata volatile uint8_t CDC_PutChar_Current_Buf = 0;
// CDC Tx
idata uint8_t  CDC_PutCharBuf[CDC_PUTCHARBUF_LEN];	// The buffer for CDC_PutChar
idata volatile uint8_t CDC_PutCharBuf_Last = 0;		// Point to the last char in the buffer
idata volatile uint8_t CDC_PutCharBuf_First = 0;	// Point to the first char in the buffer
idata volatile uint8_t CDC_Tx_Busy  = 0;
idata volatile uint8_t CDC_Tx_Full = 0;

idata uint8_t  CDC_PutCharBuf_2[CDC_PUTCHARBUF_LEN];
idata volatile uint8_t CDC_PutCharBuf_2_Last = 0;		// Point to the last char in the buffer
idata volatile uint8_t CDC_PutCharBuf_2_First = 0;

// CDC Rx
idata volatile uint8_t CDC_Rx_Pending = 0;	// Number of bytes need to be processed before accepting more USB packets
idata volatile uint8_t CDC_Rx_CurPos = 0;

// CDC configuration
extern uint8_t UsbConfig;
uint32_t CDC_Baud;		// The baud rate

void CDC_InitBaud(void) {
	LineCoding[0] = 0x00;
	LineCoding[1] = 0xE1;
	LineCoding[2] = 0x00;
	LineCoding[3] = 0x00;
	LineCoding[4] = 0x00;
	LineCoding[5] = 0x00;
	LineCoding[6] = 0x08;
}

void CDC_SetBaud(void) {

	U32_XLittle(&CDC_Baud, LineCoding);

	volatile uint32_t x;
    volatile uint8_t x2;
	
	x = 10 * FREQ_SYS / CDC_Baud / 16;                                       //���������Ƶ��ע��x��ֵ��Ҫ���
    x2 = x % 10;
    x /= 10;
    if ( x2 >= 5 ) x ++;    
	TH1 = 0-x;  
}

void USB_EP1_IN(void) {
	UEP1_T_LEN = 0;
	UEP1_CTRL = UEP1_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_NAK;
}

void USB_EP2_IN(void) {
	UEP2_T_LEN = 0;
	if (CDC_Tx_Full) {
		// Send a zero-length-packet(ZLP) to end this transfer
		UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_ACK;	// ACK next IN transfer
		CDC_Tx_Full = 0;
		// CDC_Tx_Busy remains set until the next ZLP sent to the host
	} else {
		UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_NAK;
		CDC_Tx_Busy = 0;
	}
}

void USB_EP2_OUT(void) {
	if (!U_TOG_OK )
		return;

	CDC_Rx_Pending = USB_RX_LEN;
	CDC_Rx_CurPos = 0;				// Reset Rx pointer
	// Reject packets by replying NAK, until uart_poll() finishes its job, then it informs the USB peripheral to accept incoming packets
	UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_R_RES | UEP_R_RES_NAK;
}

void CDC_PutChar(uint8_t tdata) {
	// Add new data to CDC_PutCharBuf
	if(CDC_PutChar_Current_Buf){
		CDC_PutCharBuf[CDC_PutCharBuf_Last++] = tdata;
		if(CDC_PutCharBuf_Last >= CDC_PUTCHARBUF_LEN) {
			// Rotate the tail to the beginning of the buffer
			CDC_PutCharBuf_Last = 0;
		}
		if (CDC_PutCharBuf_Last == CDC_PutCharBuf_First) {
			// Buffer is full
			CDC_PutChar_Current_Buf = ~CDC_PutChar_Current_Buf;	
		}
	}else{
		CDC_PutCharBuf_2[CDC_PutCharBuf_2_Last++] = tdata;
		if(CDC_PutCharBuf_2_Last >= CDC_PUTCHARBUF_LEN) {
			// Rotate the tail to the beginning of the buffer
			CDC_PutCharBuf_2_Last = 0;
		}
		if (CDC_PutCharBuf_2_Last == CDC_PutCharBuf_2_First) {
			// Buffer is full
			CDC_PutChar_Current_Buf = ~CDC_PutChar_Current_Buf;	
		}
	}
}

while(CDC_Tx_Full)	// Wait until the buffer has vacancy
			CDC_USB_Poll();

void CDC_Puts(char *str) {
	while(*str)
		CDC_PutChar(*(str++));
}

// Handles CDC_PutCharBuf and IN transfer
void CDC_USB_Poll() {
	static uint8_t usb_frame_count = 0;
	uint8_t usb_tx_len;

	if(UsbConfig) {
		if(usb_frame_count++ > 100) {
			usb_frame_count = 0;

			if(!CDC_Tx_Busy) {
				if(CDC_PutCharBuf_First == CDC_PutCharBuf_Last) {
					if (CDC_Tx_Full) { // Buffer is full
						CDC_Tx_Busy = 1;

						// length (the first byte to send, the end of the buffer)
						usb_tx_len = CDC_PUTCHARBUF_LEN - CDC_PutCharBuf_First;
						memcpy(EP2_TX_BUF, &CDC_PutCharBuf[CDC_PutCharBuf_First], usb_tx_len);

						// length (the first byte in the buffer, the last byte to send), if any
						if (CDC_PutCharBuf_Last > 0)
							memcpy(&EP2_TX_BUF[usb_tx_len], CDC_PutCharBuf, CDC_PutCharBuf_Last);

						// Send the entire buffer
						UEP2_T_LEN = CDC_PUTCHARBUF_LEN;
						UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_ACK;	// ACK next IN transfer

						// A 64-byte packet is going to be sent, according to USB specification, USB uses a less-than-max-length packet to demarcate an end-of-transfer
						// As a result, we need to send a zero-length-packet.
						return;
					}

					// Otherwise buffer is empty, nothing to send
					return;
				} else {
					CDC_Tx_Busy = 1;

					// CDC_PutChar() is the only way to insert into CDC_PutCharBuf, it detects buffer overflow and notify the CDC_USB_Poll().
					// So in this condition the buffer can not be full, so we don't have to send a zero-length-packet after this.

					if(CDC_PutCharBuf_First > CDC_PutCharBuf_Last) { // Rollback
						// length (the first byte to send, the end of the buffer)
						usb_tx_len = CDC_PUTCHARBUF_LEN - CDC_PutCharBuf_First;
						memcpy(EP2_TX_BUF, &CDC_PutCharBuf[CDC_PutCharBuf_First], usb_tx_len);

						// length (the first byte in the buffer, the last byte to send), if any
						if (CDC_PutCharBuf_Last > 0) {
							memcpy(&EP2_TX_BUF[usb_tx_len], CDC_PutCharBuf, CDC_PutCharBuf_Last);
							usb_tx_len += CDC_PutCharBuf_Last;
						}

						UEP2_T_LEN = usb_tx_len;
					} else {
						usb_tx_len = CDC_PutCharBuf_Last - CDC_PutCharBuf_First;
						memcpy(EP2_TX_BUF, &CDC_PutCharBuf[CDC_PutCharBuf_First], usb_tx_len);

						UEP2_T_LEN = usb_tx_len;
					}

					CDC_PutCharBuf_First += usb_tx_len;
					if(CDC_PutCharBuf_First>=CDC_PUTCHARBUF_LEN)
						CDC_PutCharBuf_First -= CDC_PUTCHARBUF_LEN;

					// ACK next IN transfer
					UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_ACK;
				}
			}
		}

	}
}

static uint8_t jumptoBoot = 0;
static uint8_t resetESP32 = 0;
static uint8_t printIO = 0;
uint8_t espBootCount = 0;
uint8_t resetToBoot = 0;

uint8_t rebootESP32 = 0;
uint8_t countESP32Endl = 0;
static uint8_t esp32EndlFlash[12] = {0x00, 0x12, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00};

void CDC_UART_Poll() {
	uint8_t cur_byte;
	static uint8_t former_data = 0;		// Previous byte
	static uint8_t cdc_rx_state = 0;	// Rx processing state machine

	/*
	 *	I2C Tx:
	 *		bit7: If set, no stop condition will be generated at the end of current transfer
	 *		rest bits: Unused
	 *	I2C Rx:
	 *		Inapplicable
	 *	SPI Tx, Rx:
	 *		bit7: If set, CS remains low after this transfer, otherwise CS becomes high after transfer
	 *		rest bits: Unused
	 */
	static uint8_t dontstop = 0;
	static uint8_t frame_len = 0;

	// Tx only
	static uint8_t frame_sent = 0;

	// I2C only
	static uint8_t i2c_error_no = 0;

	// If there are data pending
	if(CDC_Rx_Pending) {
		cur_byte = EP2_RX_BUF[CDC_Rx_CurPos++];

		if(cdc_rx_state == CDC_STATE_IDLE) {
			CH554UART0SendByte(cur_byte);
			if(cur_byte == '^') {
				++jumptoBoot;
				if(jumptoBoot > 10){
					JumpToBootloader();
				}
			} else{
				jumptoBoot = 0;
			}

			if(cur_byte == '%') {
				++resetESP32;
				if(resetESP32 > 5){
					rstPin  = 0;
					state = 3;
					count = 0;
				}
			} else{
				resetESP32 = 0;
			}

			if(cur_byte == esp32EndlFlash[countESP32Endl]) {
				++countESP32Endl;
				if(countESP32Endl == 12){
					state = 4;
					count = 0;
				}
				if(countESP32Endl > 12){
					countESP32Endl = 0;
				}
			} else{
				countESP32Endl = 0;
			}

			if(cur_byte == 0x55) {
				++espBootCount;
				if(espBootCount > 16){
					resetToBoot = 1;
					espBootCount = 0;
				}
			} else{
				espBootCount = 0;
			}
			//0x00, 0x0a, 0x00, 0x04, [ 0x00, 0x00, 0x00, 0x00 ], [ 0x60, 0x00 0x00, 0x78 ]

		}

		former_data = cur_byte;

		CDC_Rx_Pending--;

		if(CDC_Rx_Pending == 0)
			UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_R_RES | UEP_R_RES_ACK;
	} // if(CDC_PendingRxByte)
}

