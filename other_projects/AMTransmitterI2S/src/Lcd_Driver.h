#ifndef _LCD_DRIVER_H
#define _LCD_DRIVER_H

//2014/3/16
#include <Arduino.h>

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
void Lcd_SetXY(u16 x,u16 y);
void Gui_DrawPoint(u16 x,u16 y,u16 Data);
void Lcd_SetRegion(u16 x_start,u16 y_start,u16 x_end,u16 y_end);
void LCD_WriteData_16Bit(u16 Data);
void Lcd_pic(const unsigned char *array, int len);

#endif // _LCD_DRIVER_H
