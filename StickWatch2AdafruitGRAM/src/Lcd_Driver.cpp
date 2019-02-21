
#include "Lcd_Driver.h"
#include "Adafruit_GFX/config.h"
#include <SPI.h>


void LCD_GPIO_Init(void)
{


}
void delay_ms(unsigned int x)
{
  delay(x);
}



void SPI_WriteData(u8 Data)
{
  SPI.transfer(Data);
}

void Lcd_WriteIndex(u8 Index)
{
  LCD_RS_CLR;
  SPI_WriteData(Index);
}

void Lcd_WriteData(u8 Data)
{
  LCD_RS_SET;
  SPI_WriteData(Data);
}

void LCD_WriteData_16Bit(u16 Data)
{
  LCD_RS_SET;
  SPI_WriteData(Data >> 8);
  SPI_WriteData(Data);
}

void Lcd_WriteReg(u8 Index, u8 Data)
{
  Lcd_WriteIndex(Index);
  Lcd_WriteData(Data);
}

void Lcd_Reset(void)
{
  LCD_RST_CLR;
  delay_ms(100);
  LCD_RST_SET;
  delay_ms(50);
}

//LCD Init For 1.44Inch LCD Panel with ST7735R.
void Lcd_Init(void)
{
  LCD_GPIO_Init();
  Lcd_Reset(); //Reset before LCD Init.

  //LCD Init For 1.44Inch LCD Panel with ST7735R.
  Lcd_WriteIndex(0x11);//Sleep exit
  delay_ms (120);

  Lcd_WriteIndex(0x13); // >??
  //Lcd_WriteIndex(0x21);
  //Lcd_WriteIndex(0x21);
  // Lcd_WriteIndex(0x21);
  Lcd_WriteIndex(0x21);

  Lcd_WriteIndex(0xB1);
  Lcd_WriteData(0x05);
  Lcd_WriteData(0x3A);
  Lcd_WriteData(0x3A);

  Lcd_WriteIndex(0xB2);
  Lcd_WriteData(0x05);
  Lcd_WriteData(0x3A);
  Lcd_WriteData(0x3A);

  Lcd_WriteIndex(0xB3);
  Lcd_WriteData(0x05);
  Lcd_WriteData(0x3A);
  Lcd_WriteData(0x3A);
  Lcd_WriteData(0x05);
  Lcd_WriteData(0x3A);
  Lcd_WriteData(0x3A);

  Lcd_WriteIndex(0xB4);
  Lcd_WriteData(0x03);

  Lcd_WriteIndex(0xC0);
  Lcd_WriteData(0x62);
  Lcd_WriteData(0x02);
  Lcd_WriteData(0x04);

  Lcd_WriteIndex(0xC1);
  Lcd_WriteData(0xC0);

  Lcd_WriteIndex(0xC2);
  Lcd_WriteData(0x0D);
  Lcd_WriteData(0x00);

  Lcd_WriteIndex(0xC3);
  Lcd_WriteData(0x8D);
  Lcd_WriteData(0x6A);

  Lcd_WriteIndex(0xC4);
  Lcd_WriteData(0x8D);
  Lcd_WriteData(0xEE);

  Lcd_WriteIndex(0xC5);  /*VCOM*/
  Lcd_WriteData(0x0E);

  Lcd_WriteIndex(0xE0);
  Lcd_WriteData(0x10);
  Lcd_WriteData(0x0E);
  Lcd_WriteData(0x02);
  Lcd_WriteData(0x03);
  Lcd_WriteData(0x0E);
  Lcd_WriteData(0x07);
  Lcd_WriteData(0x02);
  Lcd_WriteData(0x07);
  Lcd_WriteData(0x0A);
  Lcd_WriteData(0x12);
  Lcd_WriteData(0x27);
  Lcd_WriteData(0x37);
  Lcd_WriteData(0x00);
  Lcd_WriteData(0x0D);
  Lcd_WriteData(0x0E);
  Lcd_WriteData(0x10);

  Lcd_WriteIndex(0xE1);
  Lcd_WriteData(0x10);
  Lcd_WriteData(0x0E);
  Lcd_WriteData(0x03);
  Lcd_WriteData(0x03);
  Lcd_WriteData(0x0F);
  Lcd_WriteData(0x06);
  Lcd_WriteData(0x02);
  Lcd_WriteData(0x08);
  Lcd_WriteData(0x0A);
  Lcd_WriteData(0x13);
  Lcd_WriteData(0x26);
  Lcd_WriteData(0x36);
  Lcd_WriteData(0x00);
  Lcd_WriteData(0x0D);
  Lcd_WriteData(0x0E);
  Lcd_WriteData(0x10);

  Lcd_WriteIndex(0x3A);
  // Lcd_WriteData(0x05); // RGB 5-6-5
  Lcd_WriteData(0x06); // RGB 6-6-6

  Lcd_WriteIndex(0x36);
  Lcd_WriteData(0x00);
  // Lcd_WriteData(0xC8); // ???

  Lcd_WriteIndex(0x29);


}


void Lcd_SetRegion(u16 x_start, u16 y_start, u16 x_end, u16 y_end)
{
  Lcd_WriteIndex(0x2a);
  Lcd_WriteData(0x00); // 0x00
  Lcd_WriteData(x_start + 0x1A); // 0x1a (it means x_offset = 26)
  Lcd_WriteData(0x00); // 0x00
  Lcd_WriteData(x_end + 0x1A); // 80 - 1 + 0x1a

  Lcd_WriteIndex(0x2b);
  Lcd_WriteData(0x00); // 0x00
  Lcd_WriteData(y_start + 1); // 0x01 (it means y_offset = 1)
  Lcd_WriteData(0x00); // 0x00
  Lcd_WriteData(y_end + 1); // 160 - 1 + 0x1a
  Lcd_WriteIndex(0x2c);

}


void Lcd_SetXY(u16 x, u16 y)
{
  Lcd_SetRegion(x, y, x, y);
}


void Gui_DrawPoint(u16 x, u16 y, u16 Data)
{
  Lcd_SetRegion(x, y, x + 1, y + 1);
  LCD_WriteData_16Bit(Data);

}



void Lcd_pic(const unsigned char *array, int len)
{
  Lcd_SetRegion(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
  Lcd_WriteIndex(0x2C);

  LCD_RS_SET;
  SPI.writeBytes((uint8_t*)array, len);
  // SPI.writePixels(array, len);

}
