;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (MINGW64)
;--------------------------------------------------------
	.module usb_cdc
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _CDC_PutChar
	.globl _JumpToBootloader
	.globl _memcpy
	.globl _CH554UART0SendByte
	.globl _rstPin
	.globl _bootPin
	.globl _UIF_BUS_RST
	.globl _UIF_DETECT
	.globl _UIF_TRANSFER
	.globl _UIF_SUSPEND
	.globl _UIF_HST_SOF
	.globl _UIF_FIFO_OV
	.globl _U_SIE_FREE
	.globl _U_TOG_OK
	.globl _U_IS_NAK
	.globl _ADC_CHAN0
	.globl _ADC_CHAN1
	.globl _CMP_CHAN
	.globl _ADC_START
	.globl _ADC_IF
	.globl _CMP_IF
	.globl _CMPO
	.globl _U1RI
	.globl _U1TI
	.globl _U1RB8
	.globl _U1TB8
	.globl _U1REN
	.globl _U1SMOD
	.globl _U1SM0
	.globl _S0_R_FIFO
	.globl _S0_T_FIFO
	.globl _S0_FREE
	.globl _S0_IF_BYTE
	.globl _S0_IF_FIRST
	.globl _S0_IF_OV
	.globl _S0_FST_ACT
	.globl _CP_RL2
	.globl _C_T2
	.globl _TR2
	.globl _EXEN2
	.globl _TCLK
	.globl _RCLK
	.globl _EXF2
	.globl _CAP1F
	.globl _TF2
	.globl _RI
	.globl _TI
	.globl _RB8
	.globl _TB8
	.globl _REN
	.globl _SM2
	.globl _SM1
	.globl _SM0
	.globl _IT0
	.globl _IE0
	.globl _IT1
	.globl _IE1
	.globl _TR0
	.globl _TF0
	.globl _TR1
	.globl _TF1
	.globl _RXD
	.globl _PWM1_
	.globl _TXD
	.globl _PWM2_
	.globl _AIN3
	.globl _VBUS1
	.globl _INT0
	.globl _TXD1_
	.globl _INT1
	.globl _T0
	.globl _RXD1_
	.globl _PWM2
	.globl _T1
	.globl _UDP
	.globl _UDM
	.globl _TIN0
	.globl _CAP1
	.globl _T2
	.globl _AIN0
	.globl _VBUS2
	.globl _TIN1
	.globl _CAP2
	.globl _T2EX
	.globl _RXD_
	.globl _TXD_
	.globl _AIN1
	.globl _UCC1
	.globl _TIN2
	.globl _SCS
	.globl _CAP1_
	.globl _T2_
	.globl _AIN2
	.globl _UCC2
	.globl _TIN3
	.globl _PWM1
	.globl _MOSI
	.globl _TIN4
	.globl _RXD1
	.globl _MISO
	.globl _TIN5
	.globl _TXD1
	.globl _SCK
	.globl _IE_SPI0
	.globl _IE_TKEY
	.globl _IE_USB
	.globl _IE_ADC
	.globl _IE_UART1
	.globl _IE_PWMX
	.globl _IE_GPIO
	.globl _IE_WDOG
	.globl _PX0
	.globl _PT0
	.globl _PX1
	.globl _PT1
	.globl _PS
	.globl _PT2
	.globl _PL_FLAG
	.globl _PH_FLAG
	.globl _EX0
	.globl _ET0
	.globl _EX1
	.globl _ET1
	.globl _ES
	.globl _ET2
	.globl _E_DIS
	.globl _EA
	.globl _P
	.globl _F1
	.globl _OV
	.globl _RS0
	.globl _RS1
	.globl _F0
	.globl _AC
	.globl _CY
	.globl _UEP1_DMA_H
	.globl _UEP1_DMA_L
	.globl _UEP1_DMA
	.globl _UEP0_DMA_H
	.globl _UEP0_DMA_L
	.globl _UEP0_DMA
	.globl _UEP2_3_MOD
	.globl _UEP4_1_MOD
	.globl _UEP3_DMA_H
	.globl _UEP3_DMA_L
	.globl _UEP3_DMA
	.globl _UEP2_DMA_H
	.globl _UEP2_DMA_L
	.globl _UEP2_DMA
	.globl _USB_DEV_AD
	.globl _USB_CTRL
	.globl _USB_INT_EN
	.globl _UEP4_T_LEN
	.globl _UEP4_CTRL
	.globl _UEP0_T_LEN
	.globl _UEP0_CTRL
	.globl _USB_RX_LEN
	.globl _USB_MIS_ST
	.globl _USB_INT_ST
	.globl _USB_INT_FG
	.globl _UEP3_T_LEN
	.globl _UEP3_CTRL
	.globl _UEP2_T_LEN
	.globl _UEP2_CTRL
	.globl _UEP1_T_LEN
	.globl _UEP1_CTRL
	.globl _UDEV_CTRL
	.globl _USB_C_CTRL
	.globl _TKEY_DATH
	.globl _TKEY_DATL
	.globl _TKEY_DAT
	.globl _TKEY_CTRL
	.globl _ADC_DATA
	.globl _ADC_CFG
	.globl _ADC_CTRL
	.globl _SBAUD1
	.globl _SBUF1
	.globl _SCON1
	.globl _SPI0_SETUP
	.globl _SPI0_CK_SE
	.globl _SPI0_CTRL
	.globl _SPI0_DATA
	.globl _SPI0_STAT
	.globl _PWM_CK_SE
	.globl _PWM_CTRL
	.globl _PWM_DATA1
	.globl _PWM_DATA2
	.globl _T2CAP1H
	.globl _T2CAP1L
	.globl _T2CAP1
	.globl _TH2
	.globl _TL2
	.globl _T2COUNT
	.globl _RCAP2H
	.globl _RCAP2L
	.globl _RCAP2
	.globl _T2MOD
	.globl _T2CON
	.globl _SBUF
	.globl _SCON
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _XBUS_AUX
	.globl _PIN_FUNC
	.globl _P3_DIR_PU
	.globl _P3_MOD_OC
	.globl _P3
	.globl _P2
	.globl _P1_DIR_PU
	.globl _P1_MOD_OC
	.globl _P1
	.globl _ROM_CTRL
	.globl _ROM_DATA_H
	.globl _ROM_DATA_L
	.globl _ROM_DATA
	.globl _ROM_ADDR_H
	.globl _ROM_ADDR_L
	.globl _ROM_ADDR
	.globl _GPIO_IE
	.globl _IP_EX
	.globl _IE_EX
	.globl _IP
	.globl _IE
	.globl _WDOG_COUNT
	.globl _RESET_KEEP
	.globl _WAKE_CTRL
	.globl _CLOCK_CFG
	.globl _PCON
	.globl _GLOBAL_CFG
	.globl _SAFE_MOD
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _LineCoding
	.globl _CDC_Rx_CurPos
	.globl _CDC_Rx_Pending
	.globl _CDC_Tx_Full
	.globl _CDC_Tx_Busy
	.globl _CDC_PutCharBuf_First
	.globl _CDC_PutCharBuf_Last
	.globl _CDC_PutCharBuf
	.globl _countESP32Endl
	.globl _rebootESP32
	.globl _resetToBoot
	.globl _espBootCount
	.globl _CDC_Baud
	.globl _CDC_InitBaud
	.globl _CDC_SetBaud
	.globl _USB_EP1_IN
	.globl _USB_EP2_IN
	.globl _USB_EP2_OUT
	.globl _CDC_Puts
	.globl _CDC_USB_Poll
	.globl _CDC_UART_Poll
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_SAFE_MOD	=	0x00a1
_GLOBAL_CFG	=	0x00b1
_PCON	=	0x0087
_CLOCK_CFG	=	0x00b9
_WAKE_CTRL	=	0x00a9
_RESET_KEEP	=	0x00fe
_WDOG_COUNT	=	0x00ff
_IE	=	0x00a8
_IP	=	0x00b8
_IE_EX	=	0x00e8
_IP_EX	=	0x00e9
_GPIO_IE	=	0x00c7
_ROM_ADDR	=	0x8584
_ROM_ADDR_L	=	0x0084
_ROM_ADDR_H	=	0x0085
_ROM_DATA	=	0x8f8e
_ROM_DATA_L	=	0x008e
_ROM_DATA_H	=	0x008f
_ROM_CTRL	=	0x0086
_P1	=	0x0090
_P1_MOD_OC	=	0x0092
_P1_DIR_PU	=	0x0093
_P2	=	0x00a0
_P3	=	0x00b0
_P3_MOD_OC	=	0x0096
_P3_DIR_PU	=	0x0097
_PIN_FUNC	=	0x00c6
_XBUS_AUX	=	0x00a2
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_SCON	=	0x0098
_SBUF	=	0x0099
_T2CON	=	0x00c8
_T2MOD	=	0x00c9
_RCAP2	=	0xcbca
_RCAP2L	=	0x00ca
_RCAP2H	=	0x00cb
_T2COUNT	=	0xcdcc
_TL2	=	0x00cc
_TH2	=	0x00cd
_T2CAP1	=	0xcfce
_T2CAP1L	=	0x00ce
_T2CAP1H	=	0x00cf
_PWM_DATA2	=	0x009b
_PWM_DATA1	=	0x009c
_PWM_CTRL	=	0x009d
_PWM_CK_SE	=	0x009e
_SPI0_STAT	=	0x00f8
_SPI0_DATA	=	0x00f9
_SPI0_CTRL	=	0x00fa
_SPI0_CK_SE	=	0x00fb
_SPI0_SETUP	=	0x00fc
_SCON1	=	0x00c0
_SBUF1	=	0x00c1
_SBAUD1	=	0x00c2
_ADC_CTRL	=	0x0080
_ADC_CFG	=	0x009a
_ADC_DATA	=	0x009f
_TKEY_CTRL	=	0x00c3
_TKEY_DAT	=	0xc5c4
_TKEY_DATL	=	0x00c4
_TKEY_DATH	=	0x00c5
_USB_C_CTRL	=	0x0091
_UDEV_CTRL	=	0x00d1
_UEP1_CTRL	=	0x00d2
_UEP1_T_LEN	=	0x00d3
_UEP2_CTRL	=	0x00d4
_UEP2_T_LEN	=	0x00d5
_UEP3_CTRL	=	0x00d6
_UEP3_T_LEN	=	0x00d7
_USB_INT_FG	=	0x00d8
_USB_INT_ST	=	0x00d9
_USB_MIS_ST	=	0x00da
_USB_RX_LEN	=	0x00db
_UEP0_CTRL	=	0x00dc
_UEP0_T_LEN	=	0x00dd
_UEP4_CTRL	=	0x00de
_UEP4_T_LEN	=	0x00df
_USB_INT_EN	=	0x00e1
_USB_CTRL	=	0x00e2
_USB_DEV_AD	=	0x00e3
_UEP2_DMA	=	0xe5e4
_UEP2_DMA_L	=	0x00e4
_UEP2_DMA_H	=	0x00e5
_UEP3_DMA	=	0xe7e6
_UEP3_DMA_L	=	0x00e6
_UEP3_DMA_H	=	0x00e7
_UEP4_1_MOD	=	0x00ea
_UEP2_3_MOD	=	0x00eb
_UEP0_DMA	=	0xedec
_UEP0_DMA_L	=	0x00ec
_UEP0_DMA_H	=	0x00ed
_UEP1_DMA	=	0xefee
_UEP1_DMA_L	=	0x00ee
_UEP1_DMA_H	=	0x00ef
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_CY	=	0x00d7
_AC	=	0x00d6
_F0	=	0x00d5
_RS1	=	0x00d4
_RS0	=	0x00d3
_OV	=	0x00d2
_F1	=	0x00d1
_P	=	0x00d0
_EA	=	0x00af
_E_DIS	=	0x00ae
_ET2	=	0x00ad
_ES	=	0x00ac
_ET1	=	0x00ab
_EX1	=	0x00aa
_ET0	=	0x00a9
_EX0	=	0x00a8
_PH_FLAG	=	0x00bf
_PL_FLAG	=	0x00be
_PT2	=	0x00bd
_PS	=	0x00bc
_PT1	=	0x00bb
_PX1	=	0x00ba
_PT0	=	0x00b9
_PX0	=	0x00b8
_IE_WDOG	=	0x00ef
_IE_GPIO	=	0x00ee
_IE_PWMX	=	0x00ed
_IE_UART1	=	0x00ec
_IE_ADC	=	0x00eb
_IE_USB	=	0x00ea
_IE_TKEY	=	0x00e9
_IE_SPI0	=	0x00e8
_SCK	=	0x0097
_TXD1	=	0x0097
_TIN5	=	0x0097
_MISO	=	0x0096
_RXD1	=	0x0096
_TIN4	=	0x0096
_MOSI	=	0x0095
_PWM1	=	0x0095
_TIN3	=	0x0095
_UCC2	=	0x0095
_AIN2	=	0x0095
_T2_	=	0x0094
_CAP1_	=	0x0094
_SCS	=	0x0094
_TIN2	=	0x0094
_UCC1	=	0x0094
_AIN1	=	0x0094
_TXD_	=	0x0093
_RXD_	=	0x0092
_T2EX	=	0x0091
_CAP2	=	0x0091
_TIN1	=	0x0091
_VBUS2	=	0x0091
_AIN0	=	0x0091
_T2	=	0x0090
_CAP1	=	0x0090
_TIN0	=	0x0090
_UDM	=	0x00b7
_UDP	=	0x00b6
_T1	=	0x00b5
_PWM2	=	0x00b4
_RXD1_	=	0x00b4
_T0	=	0x00b4
_INT1	=	0x00b3
_TXD1_	=	0x00b2
_INT0	=	0x00b2
_VBUS1	=	0x00b2
_AIN3	=	0x00b2
_PWM2_	=	0x00b1
_TXD	=	0x00b1
_PWM1_	=	0x00b0
_RXD	=	0x00b0
_TF1	=	0x008f
_TR1	=	0x008e
_TF0	=	0x008d
_TR0	=	0x008c
_IE1	=	0x008b
_IT1	=	0x008a
_IE0	=	0x0089
_IT0	=	0x0088
_SM0	=	0x009f
_SM1	=	0x009e
_SM2	=	0x009d
_REN	=	0x009c
_TB8	=	0x009b
_RB8	=	0x009a
_TI	=	0x0099
_RI	=	0x0098
_TF2	=	0x00cf
_CAP1F	=	0x00cf
_EXF2	=	0x00ce
_RCLK	=	0x00cd
_TCLK	=	0x00cc
_EXEN2	=	0x00cb
_TR2	=	0x00ca
_C_T2	=	0x00c9
_CP_RL2	=	0x00c8
_S0_FST_ACT	=	0x00ff
_S0_IF_OV	=	0x00fe
_S0_IF_FIRST	=	0x00fd
_S0_IF_BYTE	=	0x00fc
_S0_FREE	=	0x00fb
_S0_T_FIFO	=	0x00fa
_S0_R_FIFO	=	0x00f8
_U1SM0	=	0x00c7
_U1SMOD	=	0x00c5
_U1REN	=	0x00c4
_U1TB8	=	0x00c3
_U1RB8	=	0x00c2
_U1TI	=	0x00c1
_U1RI	=	0x00c0
_CMPO	=	0x0087
_CMP_IF	=	0x0086
_ADC_IF	=	0x0085
_ADC_START	=	0x0084
_CMP_CHAN	=	0x0083
_ADC_CHAN1	=	0x0081
_ADC_CHAN0	=	0x0080
_U_IS_NAK	=	0x00df
_U_TOG_OK	=	0x00de
_U_SIE_FREE	=	0x00dd
_UIF_FIFO_OV	=	0x00dc
_UIF_HST_SOF	=	0x00db
_UIF_SUSPEND	=	0x00da
_UIF_TRANSFER	=	0x00d9
_UIF_DETECT	=	0x00d8
_UIF_BUS_RST	=	0x00d8
_bootPin	=	0x0097
_rstPin	=	0x0090
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_CDC_Baud::
	.ds 4
_CDC_SetBaud_x_65537_44:
	.ds 4
_CDC_SetBaud_x2_65537_44:
	.ds 1
_CDC_USB_Poll_usb_frame_count_65536_59:
	.ds 1
_jumptoBoot:
	.ds 1
_resetESP32:
	.ds 1
_printIO:
	.ds 1
_espBootCount::
	.ds 1
_resetToBoot::
	.ds 1
_rebootESP32::
	.ds 1
_countESP32Endl::
	.ds 1
_esp32EndlFlash:
	.ds 12
_CDC_UART_Poll_former_data_65536_69:
	.ds 1
_CDC_UART_Poll_cdc_rx_state_65536_69:
	.ds 1
_CDC_UART_Poll_dontstop_65536_69:
	.ds 1
_CDC_UART_Poll_frame_len_65536_69:
	.ds 1
_CDC_UART_Poll_frame_sent_65536_69:
	.ds 1
_CDC_UART_Poll_i2c_error_no_65536_69:
	.ds 1
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
_CDC_PutCharBuf::
	.ds 64
_CDC_PutCharBuf_Last::
	.ds 1
_CDC_PutCharBuf_First::
	.ds 1
_CDC_Tx_Busy::
	.ds 1
_CDC_Tx_Full::
	.ds 1
_CDC_Rx_Pending::
	.ds 1
_CDC_Rx_CurPos::
	.ds 1
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
_LineCoding	=	0x00ca
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'CDC_USB_Poll'
;------------------------------------------------------------
;usb_frame_count           Allocated with name '_CDC_USB_Poll_usb_frame_count_65536_59'
;usb_tx_len                Allocated to registers r7 
;------------------------------------------------------------
;	usb_cdc.c:113: static uint8_t usb_frame_count = 0;
	mov	_CDC_USB_Poll_usb_frame_count_65536_59,#0x00
;------------------------------------------------------------
;Allocation info for local variables in function 'CDC_UART_Poll'
;------------------------------------------------------------
;former_data               Allocated with name '_CDC_UART_Poll_former_data_65536_69'
;cdc_rx_state              Allocated with name '_CDC_UART_Poll_cdc_rx_state_65536_69'
;dontstop                  Allocated with name '_CDC_UART_Poll_dontstop_65536_69'
;frame_len                 Allocated with name '_CDC_UART_Poll_frame_len_65536_69'
;frame_sent                Allocated with name '_CDC_UART_Poll_frame_sent_65536_69'
;i2c_error_no              Allocated with name '_CDC_UART_Poll_i2c_error_no_65536_69'
;cur_byte                  Allocated to registers r7 
;------------------------------------------------------------
;	usb_cdc.c:194: static uint8_t former_data = 0;		// Previous byte
	mov	_CDC_UART_Poll_former_data_65536_69,#0x00
;	usb_cdc.c:195: static uint8_t cdc_rx_state = 0;	// Rx processing state machine
	mov	_CDC_UART_Poll_cdc_rx_state_65536_69,#0x00
;	usb_cdc.c:207: static uint8_t dontstop = 0;
	mov	_CDC_UART_Poll_dontstop_65536_69,#0x00
;	usb_cdc.c:208: static uint8_t frame_len = 0;
	mov	_CDC_UART_Poll_frame_len_65536_69,#0x00
;	usb_cdc.c:211: static uint8_t frame_sent = 0;
	mov	_CDC_UART_Poll_frame_sent_65536_69,#0x00
;	usb_cdc.c:214: static uint8_t i2c_error_no = 0;
	mov	_CDC_UART_Poll_i2c_error_no_65536_69,#0x00
;	usb_cdc.c:182: static uint8_t jumptoBoot = 0;
	mov	_jumptoBoot,#0x00
;	usb_cdc.c:183: static uint8_t resetESP32 = 0;
	mov	_resetESP32,#0x00
;	usb_cdc.c:184: static uint8_t printIO = 0;
	mov	_printIO,#0x00
;	usb_cdc.c:185: uint8_t espBootCount = 0;
	mov	_espBootCount,#0x00
;	usb_cdc.c:186: uint8_t resetToBoot = 0;
	mov	_resetToBoot,#0x00
;	usb_cdc.c:188: uint8_t rebootESP32 = 0;
	mov	_rebootESP32,#0x00
;	usb_cdc.c:189: uint8_t countESP32Endl = 0;
	mov	_countESP32Endl,#0x00
;	usb_cdc.c:190: static uint8_t esp32EndlFlash[12] = {0x00, 0x12, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00};
	mov	_esp32EndlFlash,#0x00
	mov	(_esp32EndlFlash + 0x0001),#0x12
	mov	(_esp32EndlFlash + 0x0002),#0x04
	mov	(_esp32EndlFlash + 0x0003),#0x00
	mov	(_esp32EndlFlash + 0x0004),#0x00
	mov	(_esp32EndlFlash + 0x0005),#0x00
	mov	(_esp32EndlFlash + 0x0006),#0x00
	mov	(_esp32EndlFlash + 0x0007),#0x00
	mov	(_esp32EndlFlash + 0x0008),#0x01
	mov	(_esp32EndlFlash + 0x0009),#0x00
	mov	(_esp32EndlFlash + 0x000a),#0x00
	mov	(_esp32EndlFlash + 0x000b),#0x00
;	usb_cdc.c:24: idata volatile uint8_t CDC_PutCharBuf_Last = 0;		// Point to the last char in the buffer
	mov	r0,#_CDC_PutCharBuf_Last
	mov	@r0,#0x00
;	usb_cdc.c:25: idata volatile uint8_t CDC_PutCharBuf_First = 0;	// Point to the first char in the buffer
	mov	r0,#_CDC_PutCharBuf_First
	mov	@r0,#0x00
;	usb_cdc.c:26: idata volatile uint8_t CDC_Tx_Busy  = 0;
	mov	r0,#_CDC_Tx_Busy
	mov	@r0,#0x00
;	usb_cdc.c:27: idata volatile uint8_t CDC_Tx_Full = 0;
	mov	r0,#_CDC_Tx_Full
	mov	@r0,#0x00
;	usb_cdc.c:30: idata volatile uint8_t CDC_Rx_Pending = 0;	// Number of bytes need to be processed before accepting more USB packets
	mov	r0,#_CDC_Rx_Pending
	mov	@r0,#0x00
;	usb_cdc.c:31: idata volatile uint8_t CDC_Rx_CurPos = 0;
	mov	r0,#_CDC_Rx_CurPos
	mov	@r0,#0x00
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'CDC_InitBaud'
;------------------------------------------------------------
;	usb_cdc.c:37: void CDC_InitBaud(void) {
;	-----------------------------------------
;	 function CDC_InitBaud
;	-----------------------------------------
_CDC_InitBaud:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	usb_cdc.c:38: LineCoding[0] = 0x00;
	mov	dptr,#_LineCoding
	clr	a
	movx	@dptr,a
;	usb_cdc.c:39: LineCoding[1] = 0xE1;
	mov	dptr,#(_LineCoding + 0x0001)
	mov	a,#0xe1
	movx	@dptr,a
;	usb_cdc.c:40: LineCoding[2] = 0x00;
	mov	dptr,#(_LineCoding + 0x0002)
	clr	a
	movx	@dptr,a
;	usb_cdc.c:41: LineCoding[3] = 0x00;
	mov	dptr,#(_LineCoding + 0x0003)
	movx	@dptr,a
;	usb_cdc.c:42: LineCoding[4] = 0x00;
	mov	dptr,#(_LineCoding + 0x0004)
	movx	@dptr,a
;	usb_cdc.c:43: LineCoding[5] = 0x00;
	mov	dptr,#(_LineCoding + 0x0005)
	movx	@dptr,a
;	usb_cdc.c:44: LineCoding[6] = 0x08;
	mov	dptr,#(_LineCoding + 0x0006)
	mov	a,#0x08
	movx	@dptr,a
;	usb_cdc.c:45: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'CDC_SetBaud'
;------------------------------------------------------------
;x                         Allocated with name '_CDC_SetBaud_x_65537_44'
;x2                        Allocated with name '_CDC_SetBaud_x2_65537_44'
;------------------------------------------------------------
;	usb_cdc.c:47: void CDC_SetBaud(void) {
;	-----------------------------------------
;	 function CDC_SetBaud
;	-----------------------------------------
_CDC_SetBaud:
;	usb_cdc.c:49: U32_XLittle(&CDC_Baud, LineCoding);
	mov	dptr,#_LineCoding
	movx	a,@dptr
	mov	r7,a
	mov	_CDC_Baud,r7
	mov	dptr,#(_LineCoding + 0x0001)
	movx	a,@dptr
	mov	r7,a
	mov	(_CDC_Baud + 0x0001),r7
	mov	dptr,#(_LineCoding + 0x0002)
	movx	a,@dptr
	mov	r7,a
	mov	(_CDC_Baud + 0x0002),r7
	mov	dptr,#(_LineCoding + 0x0003)
	movx	a,@dptr
	mov	r7,a
	mov	(_CDC_Baud + 0x0003),r7
;	usb_cdc.c:54: x = 10 * FREQ_SYS / CDC_Baud / 16;                                       //���������Ƶ��ע��x��ֵ��Ҫ���
	mov	__divulong_PARM_2,_CDC_Baud
	mov	(__divulong_PARM_2 + 1),(_CDC_Baud + 1)
	mov	(__divulong_PARM_2 + 2),(_CDC_Baud + 2)
	mov	(__divulong_PARM_2 + 3),(_CDC_Baud + 3)
	mov	dptr,#0x1c00
	mov	b,#0x4e
	mov	a,#0x0e
	lcall	__divulong
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	_CDC_SetBaud_x_65537_44,r4
	mov	a,r5
	swap	a
	xch	a,_CDC_SetBaud_x_65537_44
	swap	a
	anl	a,#0x0f
	xrl	a,_CDC_SetBaud_x_65537_44
	xch	a,_CDC_SetBaud_x_65537_44
	anl	a,#0x0f
	xch	a,_CDC_SetBaud_x_65537_44
	xrl	a,_CDC_SetBaud_x_65537_44
	xch	a,_CDC_SetBaud_x_65537_44
	mov	(_CDC_SetBaud_x_65537_44 + 1),a
	mov	a,r6
	swap	a
	anl	a,#0xf0
	orl	a,(_CDC_SetBaud_x_65537_44 + 1)
	mov	(_CDC_SetBaud_x_65537_44 + 1),a
	mov	(_CDC_SetBaud_x_65537_44 + 2),r6
	mov	a,r7
	swap	a
	xch	a,(_CDC_SetBaud_x_65537_44 + 2)
	swap	a
	anl	a,#0x0f
	xrl	a,(_CDC_SetBaud_x_65537_44 + 2)
	xch	a,(_CDC_SetBaud_x_65537_44 + 2)
	anl	a,#0x0f
	xch	a,(_CDC_SetBaud_x_65537_44 + 2)
	xrl	a,(_CDC_SetBaud_x_65537_44 + 2)
	xch	a,(_CDC_SetBaud_x_65537_44 + 2)
	mov	(_CDC_SetBaud_x_65537_44 + 3),a
;	usb_cdc.c:55: x2 = x % 10;
	mov	__modulong_PARM_2,#0x0a
	clr	a
	mov	(__modulong_PARM_2 + 1),a
	mov	(__modulong_PARM_2 + 2),a
	mov	(__modulong_PARM_2 + 3),a
	mov	dpl,_CDC_SetBaud_x_65537_44
	mov	dph,(_CDC_SetBaud_x_65537_44 + 1)
	mov	b,(_CDC_SetBaud_x_65537_44 + 2)
	mov	a,(_CDC_SetBaud_x_65537_44 + 3)
	lcall	__modulong
	mov	r4,dpl
	mov	_CDC_SetBaud_x2_65537_44,r4
;	usb_cdc.c:56: x /= 10;
	mov	__divulong_PARM_2,#0x0a
	clr	a
	mov	(__divulong_PARM_2 + 1),a
	mov	(__divulong_PARM_2 + 2),a
	mov	(__divulong_PARM_2 + 3),a
	mov	dpl,_CDC_SetBaud_x_65537_44
	mov	dph,(_CDC_SetBaud_x_65537_44 + 1)
	mov	b,(_CDC_SetBaud_x_65537_44 + 2)
	mov	a,(_CDC_SetBaud_x_65537_44 + 3)
	lcall	__divulong
	mov	_CDC_SetBaud_x_65537_44,dpl
	mov	(_CDC_SetBaud_x_65537_44 + 1),dph
	mov	(_CDC_SetBaud_x_65537_44 + 2),b
	mov	(_CDC_SetBaud_x_65537_44 + 3),a
;	usb_cdc.c:57: if ( x2 >= 5 ) x ++;    
	mov	a,#0x100 - 0x05
	add	a,_CDC_SetBaud_x2_65537_44
	jnc	00102$
	mov	a,#0x01
	add	a,_CDC_SetBaud_x_65537_44
	mov	_CDC_SetBaud_x_65537_44,a
	clr	a
	addc	a,(_CDC_SetBaud_x_65537_44 + 1)
	mov	(_CDC_SetBaud_x_65537_44 + 1),a
	clr	a
	addc	a,(_CDC_SetBaud_x_65537_44 + 2)
	mov	(_CDC_SetBaud_x_65537_44 + 2),a
	clr	a
	addc	a,(_CDC_SetBaud_x_65537_44 + 3)
	mov	(_CDC_SetBaud_x_65537_44 + 3),a
00102$:
;	usb_cdc.c:58: TH1 = 0-x;  
	mov	r7,_CDC_SetBaud_x_65537_44
	clr	c
	clr	a
	subb	a,r7
	mov	_TH1,a
;	usb_cdc.c:59: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'USB_EP1_IN'
;------------------------------------------------------------
;	usb_cdc.c:61: void USB_EP1_IN(void) {
;	-----------------------------------------
;	 function USB_EP1_IN
;	-----------------------------------------
_USB_EP1_IN:
;	usb_cdc.c:62: UEP1_T_LEN = 0;
	mov	_UEP1_T_LEN,#0x00
;	usb_cdc.c:63: UEP1_CTRL = UEP1_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_NAK;
	mov	a,#0xfc
	anl	a,_UEP1_CTRL
	mov	r7,a
	orl	ar7,#0x02
	mov	_UEP1_CTRL,r7
;	usb_cdc.c:64: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'USB_EP2_IN'
;------------------------------------------------------------
;	usb_cdc.c:66: void USB_EP2_IN(void) {
;	-----------------------------------------
;	 function USB_EP2_IN
;	-----------------------------------------
_USB_EP2_IN:
;	usb_cdc.c:67: UEP2_T_LEN = 0;
	mov	_UEP2_T_LEN,#0x00
;	usb_cdc.c:68: if (CDC_Tx_Full) {
	mov	r0,#_CDC_Tx_Full
	mov	a,@r0
	jz	00102$
;	usb_cdc.c:70: UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_ACK;	// ACK next IN transfer
	mov	a,#0xfc
	anl	a,_UEP2_CTRL
	mov	r7,a
	mov	_UEP2_CTRL,r7
;	usb_cdc.c:71: CDC_Tx_Full = 0;
	mov	r0,#_CDC_Tx_Full
	mov	@r0,#0x00
	ret
00102$:
;	usb_cdc.c:74: UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_NAK;
	mov	a,#0xfc
	anl	a,_UEP2_CTRL
	mov	r7,a
	orl	ar7,#0x02
	mov	_UEP2_CTRL,r7
;	usb_cdc.c:75: CDC_Tx_Busy = 0;
	mov	r0,#_CDC_Tx_Busy
	mov	@r0,#0x00
;	usb_cdc.c:77: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'USB_EP2_OUT'
;------------------------------------------------------------
;	usb_cdc.c:79: void USB_EP2_OUT(void) {
;	-----------------------------------------
;	 function USB_EP2_OUT
;	-----------------------------------------
_USB_EP2_OUT:
;	usb_cdc.c:80: if (!U_TOG_OK )
	jb	_U_TOG_OK,00102$
;	usb_cdc.c:81: return;
	ret
00102$:
;	usb_cdc.c:83: CDC_Rx_Pending = USB_RX_LEN;
	mov	r0,#_CDC_Rx_Pending
	mov	@r0,_USB_RX_LEN
;	usb_cdc.c:84: CDC_Rx_CurPos = 0;				// Reset Rx pointer
	mov	r0,#_CDC_Rx_CurPos
	mov	@r0,#0x00
;	usb_cdc.c:86: UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_R_RES | UEP_R_RES_NAK;
	mov	a,#0xf3
	anl	a,_UEP2_CTRL
	mov	r7,a
	orl	ar7,#0x08
	mov	_UEP2_CTRL,r7
;	usb_cdc.c:87: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'CDC_PutChar'
;------------------------------------------------------------
;tdata                     Allocated to registers r7 
;------------------------------------------------------------
;	usb_cdc.c:89: void CDC_PutChar(uint8_t tdata) {
;	-----------------------------------------
;	 function CDC_PutChar
;	-----------------------------------------
_CDC_PutChar:
	mov	r7,dpl
;	usb_cdc.c:91: CDC_PutCharBuf[CDC_PutCharBuf_Last++] = tdata;
	mov	r0,#_CDC_PutCharBuf_Last
	mov	ar6,@r0
	mov	r0,#_CDC_PutCharBuf_Last
	inc	@r0
	mov	a,r6
	add	a,#_CDC_PutCharBuf
	mov	r0,a
	mov	@r0,ar7
;	usb_cdc.c:92: if(CDC_PutCharBuf_Last >= CDC_PUTCHARBUF_LEN) {
	mov	r0,#_CDC_PutCharBuf_Last
	cjne	@r0,#0x40,00126$
00126$:
	jc	00102$
;	usb_cdc.c:94: CDC_PutCharBuf_Last = 0;
	mov	r0,#_CDC_PutCharBuf_Last
	mov	@r0,#0x00
00102$:
;	usb_cdc.c:97: if (CDC_PutCharBuf_Last == CDC_PutCharBuf_First) {
	mov	r0,#_CDC_PutCharBuf_Last
	mov	r1,#_CDC_PutCharBuf_First
	mov	b,@r0
	mov	a,@r1
	cjne	a,b,00108$
;	usb_cdc.c:99: CDC_Tx_Full = 1;
	mov	r0,#_CDC_Tx_Full
	mov	@r0,#0x01
;	usb_cdc.c:101: while(CDC_Tx_Full)	// Wait until the buffer has vacancy
00103$:
	mov	r0,#_CDC_Tx_Full
	mov	a,@r0
	jz	00108$
;	usb_cdc.c:102: CDC_USB_Poll();
	lcall	_CDC_USB_Poll
	sjmp	00103$
00108$:
;	usb_cdc.c:104: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'CDC_Puts'
;------------------------------------------------------------
;str                       Allocated to registers 
;------------------------------------------------------------
;	usb_cdc.c:106: void CDC_Puts(char *str) {
;	-----------------------------------------
;	 function CDC_Puts
;	-----------------------------------------
_CDC_Puts:
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
;	usb_cdc.c:107: while(*str)
00101$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	jz	00104$
;	usb_cdc.c:108: CDC_PutChar(*(str++));
	mov	dpl,r4
	inc	r5
	cjne	r5,#0x00,00116$
	inc	r6
00116$:
	push	ar7
	push	ar6
	push	ar5
	lcall	_CDC_PutChar
	pop	ar5
	pop	ar6
	pop	ar7
	sjmp	00101$
00104$:
;	usb_cdc.c:109: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'CDC_USB_Poll'
;------------------------------------------------------------
;usb_frame_count           Allocated with name '_CDC_USB_Poll_usb_frame_count_65536_59'
;usb_tx_len                Allocated to registers r7 
;------------------------------------------------------------
;	usb_cdc.c:112: void CDC_USB_Poll() {
;	-----------------------------------------
;	 function CDC_USB_Poll
;	-----------------------------------------
_CDC_USB_Poll:
;	usb_cdc.c:116: if(UsbConfig) {
	mov	a,_UsbConfig
	jnz	00168$
	ret
00168$:
;	usb_cdc.c:117: if(usb_frame_count++ > 100) {
	mov	r7,_CDC_USB_Poll_usb_frame_count_65536_59
	inc	_CDC_USB_Poll_usb_frame_count_65536_59
	mov	a,r7
	add	a,#0xff - 0x64
	jc	00169$
	ret
00169$:
;	usb_cdc.c:118: usb_frame_count = 0;
	mov	_CDC_USB_Poll_usb_frame_count_65536_59,#0x00
;	usb_cdc.c:120: if(!CDC_Tx_Busy) {
	mov	r0,#_CDC_Tx_Busy
	mov	a,@r0
	jz	00170$
	ret
00170$:
;	usb_cdc.c:121: if(CDC_PutCharBuf_First == CDC_PutCharBuf_Last) {
	mov	r0,#_CDC_PutCharBuf_First
	mov	r1,#_CDC_PutCharBuf_Last
	mov	b,@r0
	mov	a,@r1
	cjne	a,b,00113$
;	usb_cdc.c:122: if (CDC_Tx_Full) { // Buffer is full
	mov	r0,#_CDC_Tx_Full
	mov	a,@r0
	jz	00104$
;	usb_cdc.c:123: CDC_Tx_Busy = 1;
	mov	r0,#_CDC_Tx_Busy
	mov	@r0,#0x01
;	usb_cdc.c:126: usb_tx_len = CDC_PUTCHARBUF_LEN - CDC_PutCharBuf_First;
	mov	r0,#_CDC_PutCharBuf_First
	mov	ar7,@r0
	mov	a,#0x40
	clr	c
	subb	a,r7
	mov	r7,a
;	usb_cdc.c:127: memcpy(EP2_TX_BUF, &CDC_PutCharBuf[CDC_PutCharBuf_First], usb_tx_len);
	mov	r0,#_CDC_PutCharBuf_First
	mov	a,@r0
	add	a,#_CDC_PutCharBuf
	mov	r6,a
	mov	_memcpy_PARM_2,r6
	mov	(_memcpy_PARM_2 + 1),#0x00
	mov	(_memcpy_PARM_2 + 2),#0x40
	mov	_memcpy_PARM_3,r7
	mov	(_memcpy_PARM_3 + 1),#0x00
	mov	dptr,#(_Ep2Buffer + 0x0040)
	mov	b,#0x00
	push	ar7
	lcall	_memcpy
	pop	ar7
;	usb_cdc.c:130: if (CDC_PutCharBuf_Last > 0)
	mov	r0,#_CDC_PutCharBuf_Last
	mov	a,@r0
	jz	00102$
;	usb_cdc.c:131: memcpy(&EP2_TX_BUF[usb_tx_len], CDC_PutCharBuf, CDC_PutCharBuf_Last);
	mov	a,r7
	add	a,#(_Ep2Buffer + 0x0040)
	mov	r7,a
	clr	a
	addc	a,#((_Ep2Buffer + 0x0040) >> 8)
	mov	r6,a
	mov	r5,#0x00
	mov	_memcpy_PARM_2,#_CDC_PutCharBuf
;	1-genFromRTrack replaced	mov	(_memcpy_PARM_2 + 1),#0x00
	mov	(_memcpy_PARM_2 + 1),r5
	mov	(_memcpy_PARM_2 + 2),#0x40
	mov	r0,#_CDC_PutCharBuf_Last
	mov	_memcpy_PARM_3,@r0
;	1-genFromRTrack replaced	mov	(_memcpy_PARM_3 + 1),#0x00
	mov	(_memcpy_PARM_3 + 1),r5
	mov	dpl,r7
	mov	dph,r6
	mov	b,r5
	lcall	_memcpy
00102$:
;	usb_cdc.c:134: UEP2_T_LEN = CDC_PUTCHARBUF_LEN;
	mov	_UEP2_T_LEN,#0x40
;	usb_cdc.c:135: UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_ACK;	// ACK next IN transfer
	mov	a,#0xfc
	anl	a,_UEP2_CTRL
	mov	r7,a
	mov	_UEP2_CTRL,r7
;	usb_cdc.c:139: return;
	ret
00104$:
;	usb_cdc.c:143: return;
	ret
00113$:
;	usb_cdc.c:145: CDC_Tx_Busy = 1;
	mov	r0,#_CDC_Tx_Busy
	mov	@r0,#0x01
;	usb_cdc.c:150: if(CDC_PutCharBuf_First > CDC_PutCharBuf_Last) { // Rollback
	mov	r0,#_CDC_PutCharBuf_First
	mov	r1,#_CDC_PutCharBuf_Last
	clr	c
	mov	a,@r1
	subb	a,@r0
	jnc	00108$
;	usb_cdc.c:152: usb_tx_len = CDC_PUTCHARBUF_LEN - CDC_PutCharBuf_First;
	mov	r0,#_CDC_PutCharBuf_First
	mov	ar7,@r0
	mov	a,#0x40
	clr	c
	subb	a,r7
	mov	r7,a
;	usb_cdc.c:153: memcpy(EP2_TX_BUF, &CDC_PutCharBuf[CDC_PutCharBuf_First], usb_tx_len);
	mov	r0,#_CDC_PutCharBuf_First
	mov	a,@r0
	add	a,#_CDC_PutCharBuf
	mov	r6,a
	mov	_memcpy_PARM_2,r6
	mov	(_memcpy_PARM_2 + 1),#0x00
	mov	(_memcpy_PARM_2 + 2),#0x40
	mov	_memcpy_PARM_3,r7
	mov	(_memcpy_PARM_3 + 1),#0x00
	mov	dptr,#(_Ep2Buffer + 0x0040)
	mov	b,#0x00
	push	ar7
	lcall	_memcpy
	pop	ar7
;	usb_cdc.c:156: if (CDC_PutCharBuf_Last > 0) {
	mov	r0,#_CDC_PutCharBuf_Last
	mov	a,@r0
	jz	00106$
;	usb_cdc.c:157: memcpy(&EP2_TX_BUF[usb_tx_len], CDC_PutCharBuf, CDC_PutCharBuf_Last);
	mov	a,r7
	add	a,#(_Ep2Buffer + 0x0040)
	mov	r5,a
	clr	a
	addc	a,#((_Ep2Buffer + 0x0040) >> 8)
	mov	r6,a
	mov	r4,#0x00
	mov	_memcpy_PARM_2,#_CDC_PutCharBuf
;	1-genFromRTrack replaced	mov	(_memcpy_PARM_2 + 1),#0x00
	mov	(_memcpy_PARM_2 + 1),r4
	mov	(_memcpy_PARM_2 + 2),#0x40
	mov	r0,#_CDC_PutCharBuf_Last
	mov	_memcpy_PARM_3,@r0
;	1-genFromRTrack replaced	mov	(_memcpy_PARM_3 + 1),#0x00
	mov	(_memcpy_PARM_3 + 1),r4
	mov	dpl,r5
	mov	dph,r6
	mov	b,r4
	push	ar7
	lcall	_memcpy
	pop	ar7
;	usb_cdc.c:158: usb_tx_len += CDC_PutCharBuf_Last;
	mov	r0,#_CDC_PutCharBuf_Last
	mov	a,@r0
	add	a,r7
	mov	r7,a
00106$:
;	usb_cdc.c:161: UEP2_T_LEN = usb_tx_len;
	mov	_UEP2_T_LEN,r7
	sjmp	00109$
00108$:
;	usb_cdc.c:163: usb_tx_len = CDC_PutCharBuf_Last - CDC_PutCharBuf_First;
	mov	r0,#_CDC_PutCharBuf_Last
	mov	r1,#_CDC_PutCharBuf_First
	mov	a,@r0
	clr	c
	subb	a,@r1
	mov	r7,a
;	usb_cdc.c:164: memcpy(EP2_TX_BUF, &CDC_PutCharBuf[CDC_PutCharBuf_First], usb_tx_len);
	mov	r0,#_CDC_PutCharBuf_First
	mov	a,@r0
	add	a,#_CDC_PutCharBuf
	mov	r6,a
	mov	_memcpy_PARM_2,r6
	mov	(_memcpy_PARM_2 + 1),#0x00
	mov	(_memcpy_PARM_2 + 2),#0x40
	mov	_memcpy_PARM_3,r7
	mov	(_memcpy_PARM_3 + 1),#0x00
	mov	dptr,#(_Ep2Buffer + 0x0040)
	mov	b,#0x00
	push	ar7
	lcall	_memcpy
	pop	ar7
;	usb_cdc.c:166: UEP2_T_LEN = usb_tx_len;
	mov	_UEP2_T_LEN,r7
00109$:
;	usb_cdc.c:169: CDC_PutCharBuf_First += usb_tx_len;
	mov	r0,#_CDC_PutCharBuf_First
	mov	a,r7
	add	a,@r0
	mov	@r0,a
;	usb_cdc.c:170: if(CDC_PutCharBuf_First>=CDC_PUTCHARBUF_LEN)
	mov	r0,#_CDC_PutCharBuf_First
	cjne	@r0,#0x40,00177$
00177$:
	jc	00111$
;	usb_cdc.c:171: CDC_PutCharBuf_First -= CDC_PUTCHARBUF_LEN;
	mov	r0,#_CDC_PutCharBuf_First
	mov	ar7,@r0
	mov	r0,#_CDC_PutCharBuf_First
	mov	a,r7
	add	a,#0xc0
	mov	@r0,a
00111$:
;	usb_cdc.c:174: UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_ACK;
	mov	a,#0xfc
	anl	a,_UEP2_CTRL
	mov	r7,a
	mov	_UEP2_CTRL,r7
;	usb_cdc.c:180: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'CDC_UART_Poll'
;------------------------------------------------------------
;former_data               Allocated with name '_CDC_UART_Poll_former_data_65536_69'
;cdc_rx_state              Allocated with name '_CDC_UART_Poll_cdc_rx_state_65536_69'
;dontstop                  Allocated with name '_CDC_UART_Poll_dontstop_65536_69'
;frame_len                 Allocated with name '_CDC_UART_Poll_frame_len_65536_69'
;frame_sent                Allocated with name '_CDC_UART_Poll_frame_sent_65536_69'
;i2c_error_no              Allocated with name '_CDC_UART_Poll_i2c_error_no_65536_69'
;cur_byte                  Allocated to registers r7 
;------------------------------------------------------------
;	usb_cdc.c:192: void CDC_UART_Poll() {
;	-----------------------------------------
;	 function CDC_UART_Poll
;	-----------------------------------------
_CDC_UART_Poll:
;	usb_cdc.c:217: if(CDC_Rx_Pending) {
	mov	r0,#_CDC_Rx_Pending
	mov	a,@r0
	jnz	00179$
	ret
00179$:
;	usb_cdc.c:218: cur_byte = EP2_RX_BUF[CDC_Rx_CurPos++];
	mov	r0,#_CDC_Rx_CurPos
	mov	ar7,@r0
	mov	r0,#_CDC_Rx_CurPos
	inc	@r0
	mov	a,r7
	add	a,#_Ep2Buffer
	mov	dpl,a
	clr	a
	addc	a,#(_Ep2Buffer >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r7,a
;	usb_cdc.c:220: if(cdc_rx_state == CDC_STATE_IDLE) {
	mov	a,_CDC_UART_Poll_cdc_rx_state_65536_69
	jz	00180$
	ljmp	00124$
00180$:
;	usb_cdc.c:221: CH554UART0SendByte(cur_byte);
	mov	dpl,r7
	push	ar7
	lcall	_CH554UART0SendByte
	pop	ar7
;	usb_cdc.c:222: if(cur_byte == '^') {
	cjne	r7,#0x5e,00104$
;	usb_cdc.c:223: ++jumptoBoot;
	inc	_jumptoBoot
;	usb_cdc.c:224: if(jumptoBoot > 10){
	mov	a,_jumptoBoot
	add	a,#0xff - 0x0a
	jnc	00105$
;	usb_cdc.c:225: JumpToBootloader();
	push	ar7
	lcall	_JumpToBootloader
	pop	ar7
	sjmp	00105$
00104$:
;	usb_cdc.c:228: jumptoBoot = 0;
	mov	_jumptoBoot,#0x00
00105$:
;	usb_cdc.c:231: if(cur_byte == '%') {
	cjne	r7,#0x25,00109$
;	usb_cdc.c:232: ++resetESP32;
	inc	_resetESP32
;	usb_cdc.c:233: if(resetESP32 > 5){
	mov	a,_resetESP32
	add	a,#0xff - 0x05
	jnc	00110$
;	usb_cdc.c:234: rstPin  = 0;
;	assignBit
	clr	_rstPin
;	usb_cdc.c:235: state = 3;
	mov	_state,#0x03
;	usb_cdc.c:236: count = 0;
	clr	a
	mov	_count,a
	mov	(_count + 1),a
	mov	(_count + 2),a
	mov	(_count + 3),a
	sjmp	00110$
00109$:
;	usb_cdc.c:239: resetESP32 = 0;
	mov	_resetESP32,#0x00
00110$:
;	usb_cdc.c:242: if(cur_byte == esp32EndlFlash[countESP32Endl]) {
	mov	a,_countESP32Endl
	add	a,#_esp32EndlFlash
	mov	r1,a
	mov	ar6,@r1
	mov	a,r7
	cjne	a,ar6,00116$
;	usb_cdc.c:243: ++countESP32Endl;
	inc	_countESP32Endl
;	usb_cdc.c:244: if(countESP32Endl == 12){
	mov	a,#0x0c
	cjne	a,_countESP32Endl,00112$
;	usb_cdc.c:245: state = 4;
	mov	_state,#0x04
;	usb_cdc.c:246: count = 0;
	clr	a
	mov	_count,a
	mov	(_count + 1),a
	mov	(_count + 2),a
	mov	(_count + 3),a
00112$:
;	usb_cdc.c:248: if(countESP32Endl > 12){
	mov	a,_countESP32Endl
	add	a,#0xff - 0x0c
	jnc	00117$
;	usb_cdc.c:249: countESP32Endl = 0;
	mov	_countESP32Endl,#0x00
	sjmp	00117$
00116$:
;	usb_cdc.c:252: countESP32Endl = 0;
	mov	_countESP32Endl,#0x00
00117$:
;	usb_cdc.c:255: if(cur_byte == 0x55) {
	cjne	r7,#0x55,00121$
;	usb_cdc.c:256: ++espBootCount;
	inc	_espBootCount
;	usb_cdc.c:257: if(espBootCount > 16){
	mov	a,_espBootCount
	add	a,#0xff - 0x10
	jnc	00124$
;	usb_cdc.c:258: resetToBoot = 1;
	mov	_resetToBoot,#0x01
;	usb_cdc.c:259: espBootCount = 0;
	mov	_espBootCount,#0x00
	sjmp	00124$
00121$:
;	usb_cdc.c:262: espBootCount = 0;
	mov	_espBootCount,#0x00
00124$:
;	usb_cdc.c:268: former_data = cur_byte;
	mov	_CDC_UART_Poll_former_data_65536_69,r7
;	usb_cdc.c:270: CDC_Rx_Pending--;
	mov	r0,#_CDC_Rx_Pending
	dec	@r0
;	usb_cdc.c:272: if(CDC_Rx_Pending == 0)
	mov	r0,#_CDC_Rx_Pending
	mov	a,@r0
	jnz	00129$
;	usb_cdc.c:273: UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_R_RES | UEP_R_RES_ACK;
	mov	a,#0xf3
	anl	a,_UEP2_CTRL
	mov	r7,a
	mov	r6,#0x00
	mov	_UEP2_CTRL,r7
00129$:
;	usb_cdc.c:275: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
