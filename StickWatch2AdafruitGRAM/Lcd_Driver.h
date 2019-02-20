//2014/3/16
#include <Arduino.h>
//
//#define RED  	0xf800
//#define GREEN	0x07e0
//#define BLUE 	0x001f
//#define WHITE	0xffff
//#define BLACK	0x0000
//#define YELLOW  0xFFE0
//#define GRAY0   0xEF7D   	//��ɫ0 3165 00110 001011 00101
//#define GRAY1   0x8410      	//��ɫ1      00000 000000 00000
//#define GRAY2   0x4208      	//��ɫ2  1111111111011111


#define TFT_CLK       13
#define TFT_CS        5   // Chip select line for TFT display on Shield
#define TFT_DC        23  // Data/command line for TFT on Shield
#define TFT_RST       18  // Reset line for TFT is handled by seesaw!

//#define LCD_CS_SET(x) LCD_CTRL->ODR=(LCD_CTRL->ODR&~LCD_CS)|(x ? LCD_CS:0)

#define LCD_SDA_SET   digitalWrite(TFT_MOSI, HIGH)
#define	LCD_SCL_SET  	digitalWrite(TFT_CLK, HIGH)
#define	LCD_RS_SET  	digitalWrite(TFT_DC, HIGH)
#define LCD_RST_SET   digitalWrite(TFT_RST, HIGH)
#define LCD_CS_SET    digitalWrite(TFT_CS, HIGH)
#define	LCD_BL_SET  	digitalWrite(0, HIGH)


#define  LCD_SDA_CLR   digitalWrite(TFT_MOSI, LOW)
#define	LCD_SCL_CLR  	digitalWrite(TFT_CLK, LOW)
#define	LCD_RS_CLR  	digitalWrite(TFT_DC, LOW)
#define LCD_RST_CLR   digitalWrite(TFT_RST, LOW)
#define LCD_CS_CLR    digitalWrite(TFT_CS, LOW)
#define	LCD_BL_CLR  	digitalWrite(0, LOW)


typedef unsigned char u8;
typedef signed int u16;
typedef unsigned int u32;

void LCD_GPIO_Init(void);
void Lcd_WriteIndex(u8 Index);
void Lcd_WriteData(u8 Data);
void Lcd_WriteReg(u8 Index,u8 Data);
u16 Lcd_ReadReg(u8 LCD_Reg);
void Lcd_Reset(void);
void Lcd_Init(void);
void Lcd_Clear(u16 Color);
void Lcd_SetXY(u16 x,u16 y);
void Gui_DrawPoint(u16 x,u16 y,u16 Data);
unsigned int Lcd_ReadPoint(u16 x,u16 y);
void Lcd_SetRegion(u16 x_start,u16 y_start,u16 x_end,u16 y_end);
void LCD_WriteData_16Bit(u16 Data);
void Lcd_pic(const unsigned char *array, int len);
