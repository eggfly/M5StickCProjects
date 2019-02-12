#include "Delay.H"
#include "usb_cdc.h"

#include "ch554_platform.h"

#define UPF_DisableRd(SS)  (USB_C_CTRL = SS ? (USB_C_CTRL|bUCC1_PD_EN|bUCC2_PD_EN) : 0)

SBIT(bootPin,	0x90, 7);
SBIT(resetPin,	0x90, 0);

SBIT(SDA,	0xB0, 3);
SBIT(SCL,	0xB0, 4);

extern void CDC_PutChar(uint8_t tdata);
extern uint8_t resetToBoot;

extern void CDC_Puts(char *str);

void Port1Cfg(uint8_t Mode,uint8_t Pin)
{
  switch(Mode){
    case 0:
      P1_MOD_OC = P1_MOD_OC & ~(1<<Pin);
      P1_DIR_PU = P1_DIR_PU &	~(1<<Pin);	
      break;
    case 1:
      P1_MOD_OC = P1_MOD_OC & ~(1<<Pin);
      P1_DIR_PU = P1_DIR_PU |	(1<<Pin);				
      break;		
    case 2:
      P1_MOD_OC = P1_MOD_OC | (1<<Pin);
      P1_DIR_PU = P1_DIR_PU &	~(1<<Pin);				
      break;		
    case 3:
      P1_MOD_OC = P1_MOD_OC | (1<<Pin);
      P1_DIR_PU = P1_DIR_PU |	(1<<Pin);			
      break;
    default:
      break;			
  }
}

void TypeC_UPF_PDInit( void )
{
   P1_MOD_OC &= ~(bUCC2|bUCC1);                                                   
   P1_DIR_PU &= ~(bUCC2|bUCC1);                                                   //UCC1 UCC2 设置浮空输入
	 UPF_DisableRd(1);                                                              //开启UCC下拉电阻
   //ADC_CFG = ADC_CFG & ~bADC_CLK | bADC_EN;											                  //ADC时钟配置,0(96clk) 1(384clk),ADC模块开启	
	 //P1_DIR_PU &= ~(bAIN0 | bAIN1);																									//配置UCC1和UCC2作为ADC引脚
   //mDelayuS(2);                                                                   //等待上拉完全关闭和ADC电源稳定	
}

uint32_t count = 0;
uint8_t state = 0;

uint8_t wasInDownloadMode = 0;

void main(void) {
  TypeC_UPF_PDInit();
	CDC_InitBaud();
  CH554_Init();
	//P1_DIR_PU = 0xFF;
	Port1Cfg(3, 0);
	Port1Cfg(3, 1);

  SDA = 1;
  SCL = 1;

      P3_MOD_OC = P3_MOD_OC | (1<<3);
      P3_DIR_PU = P3_DIR_PU | (1<<3);

      P3_MOD_OC = P3_MOD_OC | (1<<4);
      P3_DIR_PU = P3_DIR_PU | (1<<4);	

	bootPin = 1;
	resetPin = 1;

  
	
    while(1) {
    if(RI != 0){
			RI = 0;
			CDC_PutChar(SBUF);
		} 
    	CDC_USB_Poll();

    	CDC_UART_Poll();
      ++count;
    if(RI != 0){
			RI = 0;
			CDC_PutChar(SBUF);
		} 

		
		if(resetToBoot == 1 && state == 0){
			resetPin = 0;
			bootPin = 0;
      state = 1;
      count = 0;
		}     
    
    if(state == 1 && count == 100000){
      resetPin = 1;
      state = 2;
      count = 0;
    }        
    
    if(state == 3 && count == 40000){
      resetPin = 1;
      state = 0;
      count = 0;
    }  

    if(state == 4 && count == 40000){
      resetPin = 0;
      state = 3;
      count = 0;
    }  

    if(state == 2 && count == 800000){
      bootPin = 1;
      state = 0;
      wasInDownloadMode = 1;
      resetToBoot = 0;
    }        
                                 //查询接收，中断方式可不用
    }
}

       
/*
 * According to SDCC specification, interrupt handlers MUST be placed within the file which contains
 * the void main(void) function, otherwise SDCC won't be able to recognize it. It's not a bug but a feature.
 * If you know how to fix this, please let me know.
 */
void USBInterruptEntry(void) interrupt INT_NO_USB {
	USBInterrupt();
}

void UART0_RX(void) interrupt INT_NO_UART0 {
	USBInterrupt();
}

