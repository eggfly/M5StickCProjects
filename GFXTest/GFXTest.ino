#include <Adafruit_GFX.h>
#include <Adafruit_ST77xx.h>

//#include <M5Stack.h>
#include <Arduino.h>
#include <U8g2lib.h>

#include <stdio.h>
#include "esp_sleep.h"
#include "soc/rtc_cntl_reg.h"
#include "soc/rtc_io_reg.h"
#include "soc/sens_reg.h"
#include "soc/soc.h"
#include "driver/gpio.h"
#include "driver/rtc_io.h"
#include "esp32/ulp.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

// osmar
#include <SPI.h>
#include "Lcd_Driver.h"
#include "LCD_Config.h"

#define TFT_MOSI      15
#define TFT_CLK       13
#define TFT_CS        5   // Chip select line for TFT display on Shield
#define TFT_DC        23  // Data/command line for TFT on Shield
#define TFT_RST       18  // Reset line for TFT is handled by seesaw!

// osmar

GFXcanvas16 tft = GFXcanvas16(80, 160);

// End of constructor list

uint32_t vbat = 0;
float vbat_mv = 0.0;

int stateA = 0;

int LED_RI = 9;
int LED_BUILTIN = 10;
int BUTTON_HOME = 37;
int BUTTON_PIN = 39;

//int BUTTON_HOME = 34;
//int BUTTON_PIN = 39;
RTC_DATA_ATTR int bootCount = 0;

void print_wakeup_reason() {
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch (wakeup_reason)
  {
    case 1  : Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    case 2  : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
    case 3  : Serial.println("Wakeup caused by timer"); break;
    case 4  : Serial.println("Wakeup caused by touchpad"); break;
    case 5  : Serial.println("Wakeup caused by ULP program"); break;
    default : Serial.println("Wakeup was not caused by deep sleep"); break;
  }
}

void setup(void) {
  Wire.begin();
  pinMode(LED_RI, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(BUTTON_HOME, INPUT | PULLUP);
  pinMode(BUTTON_PIN, INPUT | PULLUP);

  pinMode(TFT_MOSI, OUTPUT);
  pinMode(TFT_CLK, OUTPUT);
  pinMode(TFT_CS, OUTPUT);
  pinMode(TFT_DC, OUTPUT);
  pinMode(TFT_RST, OUTPUT);

  digitalWrite(TFT_CS, LOW);


  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(10);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

  SPI.begin (TFT_CLK, -1, TFT_MOSI, -1);
  SPI.beginTransaction(SPISettings(70000000, MSBFIRST, SPI_MODE0));

  Serial.begin(115200);
  while (!Serial);             // Leonardo: wait for serial monitor

  ++bootCount;
  Serial.println("Boot number: " + String(bootCount));

  //Print the wakeup reason for ESP32
  print_wakeup_reason();
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_39, 0);

  Wire.beginTransmission(0x34);
  Wire.write(0x10);
  Wire.write(0xff);  //OLED_VPP Enable
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x28);
  Wire.write(0x9f); //Enable LDO2&LDO3, LED&TFT 3.3V
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x82);  //Enable all the ADCs
  Wire.write(0xff);
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x33);  //Enable Charging, 100mA, 4.2V, End at 0.9
  Wire.write(0xC0);
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x33);
  Wire.write(0xC3);
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0xB8);  //Enable Colume Counter
  Wire.write(0x80);
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x12);
  Wire.write(0x4d); //Enable DC-DC1, OLED_VDD, 5B V_EXT
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x36);
  Wire.write(0x5c); //PEK
  Wire.endTransmission();

  Lcd_Init();
  Lcd_Clear(WHITE);
  // Lcd_pic(gImage_001);
  //attachInterrupt(digitalPinToInterrupt(BUTTON_HOME), blink, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), blink, FALLING);
  tft.setRotation(3);

  // u8g2.begin();
  // runGraphicTest();
}

long loopTime, startTime, endTime, fps;

//  Lcd_Clear(WHITE);
//  Lcd_Clear(RED);
//  Lcd_Clear(GREEN);
//  Lcd_Clear(BLUE);
//  Lcd_Clear(BLACK);
//  Lcd_Clear(YELLOW);
//  Lcd_Clear(GRAY0);
//  Lcd_Clear(GRAY2);
//  Lcd_Clear(BLUE);

void sendGRAM() {
  Lcd_pic((unsigned char *)tft.getBuffer());
}

void loop(void) {
  loopTime = millis();
  startTime = loopTime;

  tft.fillScreen(0xFFFF); // fill with white
  tft.setRotation(3);
  tft.drawPixel(40, 40, 0x8000);
  tft.fillCircle(40, 40, 20, RED);
  tft.fillCircle(80, 80, 20, BLUE);
  tft.setCursor(10, 10);
  tft.setTextColor(GREEN);
  tft.setTextSize(2);
  tft.print("112233");
  tft.setTextSize(1);
  tft.print("test");

  // Send GRAM using SPI.writePixels() is very very fast
  sendGRAM();

  loopTime = millis();
  endTime = loopTime;
  unsigned long delta =  (endTime - startTime);
  fps = 1000 / delta;
  printf("清屏+绘制+发送GRAM 共耗时: %dms, 理论fps:%d, 实际fps:%d\r\n", delta, fps, fps > 60 ? 60 : fps);
  delay(10);

  if (digitalRead(BUTTON_HOME) == 0) {
    Serial.println("\r\nGoing to sleep now\r\n");
    esp_deep_sleep_start();
    Serial.println("This will never be printed");
  }
}


void blink()//中断函数
{
  stateA = !stateA;
  delay(10);
  if (stateA) {
    digitalWrite(LED_RI, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_RI, LOW);
    digitalWrite(LED_BUILTIN, LOW);
  }

}





void runGraphicTest() {
  tft.fillScreen(ST77XX_BLACK);

  delay(500);

  // large block of text
  tft.fillScreen(ST77XX_BLACK);
  testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", ST77XX_WHITE);
  sendGRAM();
  delay(1000);

  // tft print function!
  tftPrintTest();
  sendGRAM();
  delay(4000);

  // a single pixel
  tft.drawPixel(tft.width() / 2, tft.height() / 2, ST77XX_GREEN);
  sendGRAM();
  delay(500);

  // line draw test
  testlines(ST77XX_YELLOW);
  sendGRAM();
  delay(500);

  // optimized lines
  testfastlines(ST77XX_RED, ST77XX_BLUE);
  sendGRAM();
  delay(500);

  testdrawrects(ST77XX_GREEN);
  sendGRAM();
  delay(500);

  testfillrects(ST77XX_YELLOW, ST77XX_MAGENTA);
  sendGRAM();
  delay(500);

  tft.fillScreen(ST77XX_BLACK);
  testfillcircles(10, ST77XX_BLUE);
  testdrawcircles(10, ST77XX_WHITE);
  sendGRAM();
  delay(500);

  testroundrects();
  sendGRAM();
  delay(500);

  testtriangles();
  sendGRAM();
  delay(500);

  mediabuttons();
  sendGRAM();
  delay(500);

  Serial.println("done");
  sendGRAM();
  delay(1000);
}



// from Adafruit graphictest below

void testlines(uint16_t color) {
  tft.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < tft.width(); x += 6) {
    tft.drawLine(0, 0, x, tft.height() - 1, color);
    sendGRAM();
    delay(0);
  }
  for (int16_t y = 0; y < tft.height(); y += 6) {
    tft.drawLine(0, 0, tft.width() - 1, y, color);
    sendGRAM();
    delay(0);
  }

  tft.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < tft.width(); x += 6) {
    tft.drawLine(tft.width() - 1, 0, x, tft.height() - 1, color);
    sendGRAM();
    delay(0);
  }
  for (int16_t y = 0; y < tft.height(); y += 6) {
    tft.drawLine(tft.width() - 1, 0, 0, y, color);
    sendGRAM();
    delay(0);
  }

  tft.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < tft.width(); x += 6) {
    tft.drawLine(0, tft.height() - 1, x, 0, color);
    sendGRAM();
    delay(0);
  }
  for (int16_t y = 0; y < tft.height(); y += 6) {
    tft.drawLine(0, tft.height() - 1, tft.width() - 1, y, color);
    sendGRAM();
    delay(0);
  }

  tft.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < tft.width(); x += 6) {
    tft.drawLine(tft.width() - 1, tft.height() - 1, x, 0, color);
    sendGRAM();
    delay(0);
  }
  for (int16_t y = 0; y < tft.height(); y += 6) {
    tft.drawLine(tft.width() - 1, tft.height() - 1, 0, y, color);
    sendGRAM();
    delay(0);
  }
}

void testdrawtext(char *text, uint16_t color) {
  tft.setCursor(0, 0);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
  sendGRAM();
}

void testfastlines(uint16_t color1, uint16_t color2) {
  tft.fillScreen(ST77XX_BLACK);
  for (int16_t y = 0; y < tft.height(); y += 5) {
    tft.drawFastHLine(0, y, tft.width(), color1);
    sendGRAM();
  }
  for (int16_t x = 0; x < tft.width(); x += 5) {
    tft.drawFastVLine(x, 0, tft.height(), color2);
    sendGRAM();
  }
}

void testdrawrects(uint16_t color) {
  tft.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < tft.width(); x += 6) {
    tft.drawRect(tft.width() / 2 - x / 2, tft.height() / 2 - x / 2 , x, x, color);
    sendGRAM();
  }
}

void testfillrects(uint16_t color1, uint16_t color2) {
  tft.fillScreen(ST77XX_BLACK);
  for (int16_t x = tft.width() - 1; x > 6; x -= 6) {
    tft.fillRect(tft.width() / 2 - x / 2, tft.height() / 2 - x / 2 , x, x, color1);
    sendGRAM();
    tft.drawRect(tft.width() / 2 - x / 2, tft.height() / 2 - x / 2 , x, x, color2);
    sendGRAM();
  }
}

void testfillcircles(uint8_t radius, uint16_t color) {
  for (int16_t x = radius; x < tft.width(); x += radius * 2) {
    for (int16_t y = radius; y < tft.height(); y += radius * 2) {
      tft.fillCircle(x, y, radius, color);
      sendGRAM();
    }
  }
}

void testdrawcircles(uint8_t radius, uint16_t color) {
  for (int16_t x = 0; x < tft.width() + radius; x += radius * 2) {
    for (int16_t y = 0; y < tft.height() + radius; y += radius * 2) {
      tft.drawCircle(x, y, radius, color);
      sendGRAM();
    }
  }
}

void testtriangles() {
  tft.fillScreen(ST77XX_BLACK);
  int color = 0xF800;
  int t;
  int w = tft.width() / 2;
  int x = tft.height() - 1;
  int y = 0;
  int z = tft.width();
  for (t = 0 ; t <= 15; t++) {
    tft.drawTriangle(w, y, y, x, z, x, color);
    sendGRAM();
    x -= 4;
    y += 4;
    z -= 4;
    color += 100;
  }
}

void testroundrects() {
  tft.fillScreen(ST77XX_BLACK);
  int color = 100;
  int i;
  int t;
  for (t = 0 ; t <= 4; t += 1) {
    int x = 0;
    int y = 0;
    int w = tft.width() - 2;
    int h = tft.height() - 2;
    for (i = 0 ; i <= 16; i += 1) {
      tft.drawRoundRect(x, y, w, h, 5, color);
      sendGRAM();
      x += 2;
      y += 3;
      w -= 4;
      h -= 6;
      color += 1100;
    }
    color += 100;
  }
}

float p = 3.1415926;

void tftPrintTest() {
  tft.setTextWrap(false);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 30);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(1);
  tft.println("Hello World!");
  tft.setTextColor(ST77XX_YELLOW);
  tft.setTextSize(2);
  tft.println("Hello World!");
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(3);
  tft.println("Hello World!");
  tft.setTextColor(ST77XX_BLUE);
  tft.setTextSize(4);
  tft.print(1234.567);
  delay(1500);
  tft.setCursor(0, 0);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(0);
  tft.println("Hello World!");
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_GREEN);
  tft.print(p, 6);
  tft.println(" Want pi?");
  sendGRAM();
  tft.println(" ");
  tft.print(8675309, HEX); // print 8,675,309 out in HEX!
  tft.println(" Print HEX!");
  tft.println(" ");
  tft.setTextColor(ST77XX_WHITE);
  tft.println("Sketch has been");
  tft.println("running for: ");
  tft.setTextColor(ST77XX_MAGENTA);
  tft.print(millis() / 1000);
  tft.setTextColor(ST77XX_WHITE);
  tft.print(" seconds.");
}

void mediabuttons() {
  // play
  tft.fillScreen(ST77XX_BLACK);
  sendGRAM();
  tft.fillRoundRect(25, 10, 78, 60, 8, ST77XX_WHITE);
  sendGRAM();
  tft.fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_RED);
  sendGRAM();
  delay(500);
  // pause
  tft.fillRoundRect(25, 90, 78, 60, 8, ST77XX_WHITE);
  sendGRAM();
  tft.fillRoundRect(39, 98, 20, 45, 5, ST77XX_GREEN);
  sendGRAM();
  tft.fillRoundRect(69, 98, 20, 45, 5, ST77XX_GREEN);
  sendGRAM();
  delay(500);
  // play color
  tft.fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_BLUE);
  sendGRAM();
  delay(50);
  // pause color
  tft.fillRoundRect(39, 98, 20, 45, 5, ST77XX_RED);
  sendGRAM();
  tft.fillRoundRect(69, 98, 20, 45, 5, ST77XX_RED);
  sendGRAM();
  // play color
  tft.fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_GREEN);
  sendGRAM();
}
