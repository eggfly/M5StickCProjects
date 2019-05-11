#ifndef _LCD_H
#define _LCD_H

#include <SPI.h>
#include "src/Lcd_Driver.h"

#include "src/Adafruit_GFX/Adafruit_GFX.h"
#include "src/Adafruit_GFX/ext_canvas.h"
#include "src/Adafruit_GFX/config.h"

#define TFT_MOSI      15
#define TFT_CLK       13
#define TFT_CS        5   // Chip select line for TFT display on Shield
#define TFT_DC        23  // Data/command line for TFT on Shield
#define TFT_RST       18  // Reset line for TFT is handled by seesaw!

#define ST77XX_BLACK      0x000000
#define ST77XX_WHITE      0xFFFFFF
#define ST77XX_RED        0xFF0000
#define ST77XX_GREEN      0x00FF00
#define ST77XX_BLUE       0x0000FF
#define ST77XX_CYAN       0x00FFFF
#define ST77XX_MAGENTA    0xFF00FF
#define ST77XX_YELLOW     0xFFFF00
#define ST77XX_ORANGE     0xFFA500

GFXcanvas24 canvas = GFXcanvas24(LCD_WIDTH, LCD_HEIGHT);

void lcd_init() {
  pinMode(TFT_MOSI, OUTPUT);
  pinMode(TFT_CLK, OUTPUT);
  pinMode(TFT_CS, OUTPUT);
  pinMode(TFT_DC, OUTPUT);
  pinMode(TFT_RST, OUTPUT);

  digitalWrite(TFT_CS, LOW);
  SPI.begin (TFT_CLK, -1, TFT_MOSI, -1);
  SPI.beginTransaction(SPISettings(70000000, MSBFIRST, SPI_MODE0));
  Lcd_Init();
  canvas.setRotation(1);
}

void sendGRAM() {
  Lcd_pic(canvas.getBuffer(), GRAM_BUFFER_SIZE);
}

#endif // _LCD_H
