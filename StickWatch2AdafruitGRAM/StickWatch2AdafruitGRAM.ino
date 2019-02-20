#include "src/Adafruit_GFX/Adafruit_GFX.h"
#include "src/Adafruit_GFX/ext_canvas.h"
#include "src/image_data.h"

#include <stdio.h>
#include "esp_sleep.h"
#include "soc/rtc_cntl_reg.h"
#include "soc/rtc_io_reg.h"
#include "soc/sens_reg.h"
#include "soc/soc.h"
#include "driver/gpio.h"
#include "driver/rtc_io.h"
#include "esp32/ulp.h"


#define ST77XX_BLACK      0xAA000000
#define ST77XX_WHITE      0xAAFFFFFF
#define ST77XX_RED        0xAAFF0000
#define ST77XX_GREEN      0xAA00FF00
#define ST77XX_BLUE       0xAA0000FF
#define ST77XX_CYAN       0x07FF
#define ST77XX_MAGENTA    0xF81F
#define ST77XX_YELLOW     0xFFE0
#define ST77XX_ORANGE     0xFC00

#include <Wire.h>

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

GFXcanvas24 canvas = GFXcanvas24(80, 160);

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
  Serial.printf("winxp_888_bg3.size=%d\n", sizeof(winxp_888_bg3));

  //Print the wakeup reason for ESP32
  print_wakeup_reason();
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_39, 0);

  Wire.beginTransmission(0x34);
  Wire.write(0x10);
  Wire.write(0x9f);  //OLED_VPP Enable
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x28);
  Wire.write(0x9f); //Enable LDO2&LDO3, LED&TFT 3.3V
  // Wire.write(0xff); //Enable LDO2&LDO3, LED&TFT 3.3V
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
  // Lcd_Clear(WHITE); // TODO?
  // Lcd_pic(gImage_001);
  //attachInterrupt(digitalPinToInterrupt(BUTTON_HOME), blink, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), blink, FALLING);
  canvas.setRotation(1);

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

void loop(void) {
  loopTime = millis();
  startTime = loopTime;

  canvas.fillScreen(ST77XX_WHITE); // fill with white
  canvas.drawPixel(40, 40, 0x8000);
  canvas.fillCircle(1, 5, 20, ST77XX_RED);
  canvas.fillCircle(5, 1, 20, ST77XX_BLUE);
  canvas.setCursor(10, 10);
  canvas.setTextColor(ST77XX_GREEN);
  canvas.setTextSize(2);
  canvas.print("112233");
  canvas.setTextSize(1);
  canvas.print("test");

  canvas.drawRGBBitmap(20, 10, (uint8_t *)imagen_888, 160, 80);
  sendGRAM();

  loopTime = millis();
  endTime = loopTime;
  unsigned long delta = endTime - startTime;
  fps = 1000 / delta;
  printf("fill+draw+send GRAM cost: %dms, calc fps:%d, real fps:%d\r\n", delta, fps, fps > 60 ? 60 : fps);
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
  canvas.fillScreen(ST77XX_BLACK);

  delay(500);

  // large block of text
  canvas.fillScreen(ST77XX_BLACK);
  testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", ST77XX_WHITE);
  sendGRAM();
  delay(1000);

  // tft print function!
  tftPrintTest();
  sendGRAM();
  delay(4000);

  // a single pixel
  canvas.drawPixel(canvas.width() / 2, canvas.height() / 2, ST77XX_GREEN);
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

  canvas.fillScreen(ST77XX_BLACK);
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


void sendGRAM() {
  Lcd_pic((unsigned char *)canvas.getBuffer(), 38400);
  // Lcd_pic(imagen_666, sizeof(imagen_666));
}


// from Adafruit graphictest below

void testlines(uint16_t color) {
  canvas.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < canvas.width(); x += 6) {
    canvas.drawLine(0, 0, x, canvas.height() - 1, color);
    sendGRAM();
    delay(0);
  }
  for (int16_t y = 0; y < canvas.height(); y += 6) {
    canvas.drawLine(0, 0, canvas.width() - 1, y, color);
    sendGRAM();
    delay(0);
  }

  canvas.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < canvas.width(); x += 6) {
    canvas.drawLine(canvas.width() - 1, 0, x, canvas.height() - 1, color);
    sendGRAM();
    delay(0);
  }
  for (int16_t y = 0; y < canvas.height(); y += 6) {
    canvas.drawLine(canvas.width() - 1, 0, 0, y, color);
    sendGRAM();
    delay(0);
  }

  canvas.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < canvas.width(); x += 6) {
    canvas.drawLine(0, canvas.height() - 1, x, 0, color);
    sendGRAM();
    delay(0);
  }
  for (int16_t y = 0; y < canvas.height(); y += 6) {
    canvas.drawLine(0, canvas.height() - 1, canvas.width() - 1, y, color);
    sendGRAM();
    delay(0);
  }

  canvas.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < canvas.width(); x += 6) {
    canvas.drawLine(canvas.width() - 1, canvas.height() - 1, x, 0, color);
    sendGRAM();
    delay(0);
  }
  for (int16_t y = 0; y < canvas.height(); y += 6) {
    canvas.drawLine(canvas.width() - 1, canvas.height() - 1, 0, y, color);
    sendGRAM();
    delay(0);
  }
}

void testdrawtext(char *text, uint16_t color) {
  canvas.setCursor(0, 0);
  canvas.setTextColor(color);
  canvas.setTextWrap(true);
  canvas.print(text);
  sendGRAM();
}

void testfastlines(uint16_t color1, uint16_t color2) {
  canvas.fillScreen(ST77XX_BLACK);
  for (int16_t y = 0; y < canvas.height(); y += 5) {
    canvas.drawFastHLine(0, y, canvas.width(), color1);
    sendGRAM();
  }
  for (int16_t x = 0; x < canvas.width(); x += 5) {
    canvas.drawFastVLine(x, 0, canvas.height(), color2);
    sendGRAM();
  }
}

void testdrawrects(uint16_t color) {
  canvas.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < canvas.width(); x += 6) {
    canvas.drawRect(canvas.width() / 2 - x / 2, canvas.height() / 2 - x / 2 , x, x, color);
    sendGRAM();
  }
}

void testfillrects(uint16_t color1, uint16_t color2) {
  canvas.fillScreen(ST77XX_BLACK);
  for (int16_t x = canvas.width() - 1; x > 6; x -= 6) {
    canvas.fillRect(canvas.width() / 2 - x / 2, canvas.height() / 2 - x / 2 , x, x, color1);
    sendGRAM();
    canvas.drawRect(canvas.width() / 2 - x / 2, canvas.height() / 2 - x / 2 , x, x, color2);
    sendGRAM();
  }
}

void testfillcircles(uint8_t radius, uint16_t color) {
  for (int16_t x = radius; x < canvas.width(); x += radius * 2) {
    for (int16_t y = radius; y < canvas.height(); y += radius * 2) {
      canvas.fillCircle(x, y, radius, color);
      sendGRAM();
    }
  }
}

void testdrawcircles(uint8_t radius, uint16_t color) {
  for (int16_t x = 0; x < canvas.width() + radius; x += radius * 2) {
    for (int16_t y = 0; y < canvas.height() + radius; y += radius * 2) {
      canvas.drawCircle(x, y, radius, color);
      sendGRAM();
    }
  }
}

void testtriangles() {
  canvas.fillScreen(ST77XX_BLACK);
  int color = 0xF800;
  int t;
  int w = canvas.width() / 2;
  int x = canvas.height() - 1;
  int y = 0;
  int z = canvas.width();
  for (t = 0 ; t <= 15; t++) {
    canvas.drawTriangle(w, y, y, x, z, x, color);
    sendGRAM();
    x -= 4;
    y += 4;
    z -= 4;
    color += 100;
  }
}

void testroundrects() {
  canvas.fillScreen(ST77XX_BLACK);
  int color = 100;
  int i;
  int t;
  for (t = 0 ; t <= 4; t += 1) {
    int x = 0;
    int y = 0;
    int w = canvas.width() - 2;
    int h = canvas.height() - 2;
    for (i = 0 ; i <= 16; i += 1) {
      canvas.drawRoundRect(x, y, w, h, 5, color);
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
  canvas.setTextWrap(false);
  canvas.fillScreen(ST77XX_BLACK);
  canvas.setCursor(0, 30);
  canvas.setTextColor(ST77XX_RED);
  canvas.setTextSize(1);
  canvas.println("Hello World!");
  canvas.setTextColor(ST77XX_YELLOW);
  canvas.setTextSize(2);
  canvas.println("Hello World!");
  canvas.setTextColor(ST77XX_GREEN);
  canvas.setTextSize(3);
  canvas.println("Hello World!");
  canvas.setTextColor(ST77XX_BLUE);
  canvas.setTextSize(4);
  canvas.print(1234.567);
  delay(1500);
  canvas.setCursor(0, 0);
  canvas.fillScreen(ST77XX_BLACK);
  canvas.setTextColor(ST77XX_WHITE);
  canvas.setTextSize(0);
  canvas.println("Hello World!");
  canvas.setTextSize(1);
  canvas.setTextColor(ST77XX_GREEN);
  canvas.print(p, 6);
  canvas.println(" Want pi?");
  sendGRAM();
  canvas.println(" ");
  canvas.print(8675309, HEX); // print 8,675,309 out in HEX!
  canvas.println(" Print HEX!");
  canvas.println(" ");
  canvas.setTextColor(ST77XX_WHITE);
  canvas.println("Sketch has been");
  canvas.println("running for: ");
  canvas.setTextColor(ST77XX_MAGENTA);
  canvas.print(millis() / 1000);
  canvas.setTextColor(ST77XX_WHITE);
  canvas.print(" seconds.");
}

void mediabuttons() {
  // play
  canvas.fillScreen(ST77XX_BLACK);
  sendGRAM();
  canvas.fillRoundRect(25, 10, 78, 60, 8, ST77XX_WHITE);
  sendGRAM();
  canvas.fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_RED);
  sendGRAM();
  delay(500);
  // pause
  canvas.fillRoundRect(25, 90, 78, 60, 8, ST77XX_WHITE);
  sendGRAM();
  canvas.fillRoundRect(39, 98, 20, 45, 5, ST77XX_GREEN);
  sendGRAM();
  canvas.fillRoundRect(69, 98, 20, 45, 5, ST77XX_GREEN);
  sendGRAM();
  delay(500);
  // play color
  canvas.fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_BLUE);
  sendGRAM();
  delay(50);
  // pause color
  canvas.fillRoundRect(39, 98, 20, 45, 5, ST77XX_RED);
  sendGRAM();
  canvas.fillRoundRect(69, 98, 20, 45, 5, ST77XX_RED);
  sendGRAM();
  // play color
  canvas.fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_GREEN);
  sendGRAM();
}
