#include "src/Adafruit_GFX/Adafruit_GFX.h"
#include "src/Adafruit_GFX/ext_canvas.h"
#include "src/Adafruit_GFX/config.h"
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

#include "src/RTCLib/RTClib.h"

#include "res.h"

PCF8563 rtc;

#define ST77XX_BLACK      0x000000
#define ST77XX_WHITE      0xFFFFFF
#define ST77XX_RED        0xFF0000
#define ST77XX_GREEN      0x00FF00
#define ST77XX_BLUE       0x0000FF
#define ST77XX_CYAN       0x00FFFF
#define ST77XX_MAGENTA    0xFF00FF
#define ST77XX_YELLOW     0xFFFF00
#define ST77XX_ORANGE     0xFFA500

const uint32_t COLORS_LIGHT[10] = {
  0xff4aad, 0x0e88fe, 0xcc03fc, 0xfe49ad, 0xff0505,
  0xfa660d, 0xfff800, 0x14fa00, 0x0496ff, 0xc900ff
};
const uint32_t COLORS_DARK[10] = {
  0x471f32, 0x002548, 0x3b004b, 0x3e1a2c, 0x4a000c,
  0x4a1e00, 0x4b4500, 0x004700, 0x022242, 0x380249
};

#include <Wire.h>

#include <SPI.h>
#include "src/Lcd_Driver.h"

#define TFT_MOSI      15
#define TFT_CLK       13
#define TFT_CS        5   // Chip select line for TFT display on Shield
#define TFT_DC        23  // Data/command line for TFT on Shield
#define TFT_RST       18  // Reset line for TFT is handled by seesaw!

GFXcanvas24 canvas = GFXcanvas24(LCD_WIDTH, LCD_HEIGHT);

// End of constructor list

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

void show_time() {
  DateTime now = rtc.now();
  char buf[100];
  strncpy(buf, "YYYY.MM.DD hh:mm:ss\0", 100);
  now.format(buf);
  // Serial.printf("time now: %s\n", buf);

  canvas.setCursor(28, 70);
  canvas.setTextColor(0xAAFFFFFF);
  canvas.print(buf);
}


void setup(void) {
  Wire.begin();
  rtc.begin();
  DateTime now = rtc.now();
  if (now.year() < 2018) {
    Serial.println("RTC need factory reset!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }

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

void loop(void) {
  canvas.fillScreen(0x00000000); // fill screen bg

  loopTime = millis();
  // 4 digit 100ms counter
  int count = (loopTime / 100) % 10000;
  startTime = loopTime;

  //  canvas.drawPixel(159, 79, ST77XX_CYAN);
  //  canvas.fillCircle(1, 11, 5, ST77XX_RED);
  //  canvas.fillCircle(11, 1, 5, ST77XX_GREEN);
  //  canvas.setCursor(0, 30);
  //  canvas.setTextColor(0xAAFFFFFF);
  //  canvas.setTextSize(1);
  //  canvas.print("Bad");
  //  canvas.setCursor(0, 40);
  //  canvas.setTextSize(1);
  //  canvas.print("Apple");

  // canvas.drawRGBBitmap(0, 15, clock_data, VIDEO_WIDTH, VIDEO_HEIGHT);

  int x_start = 6;
  int x_delta = 7;
  int r = 2;
  canvas.fillCircle(x_start + x_delta * 0, 4, r, COLORS_LIGHT[0]);
  canvas.fillCircle(x_start + x_delta * 1, 4, r, COLORS_LIGHT[1]);
  canvas.fillCircle(x_start + x_delta * 2, 4, r, COLORS_LIGHT[2]);
  canvas.fillCircle(x_start + x_delta * 3, 4, r, COLORS_LIGHT[3]);
  canvas.fillCircle(x_start + x_delta * 4, 4, r, COLORS_LIGHT[4]);
  canvas.fillCircle(x_start + x_delta * 5, 4, r, COLORS_LIGHT[5]);
  canvas.fillCircle(x_start + x_delta * 6, 4, r, COLORS_LIGHT[6]);
  canvas.fillCircle(x_start + x_delta * 7, 4, r, COLORS_LIGHT[7]);
  canvas.fillCircle(x_start + x_delta * 8, 4, r, COLORS_LIGHT[8]);
  canvas.fillCircle(x_start + x_delta * 9, 4, r, COLORS_LIGHT[9]);

  int y2 = 11;
  canvas.fillCircle(x_start + x_delta * 0, y2, r, COLORS_DARK[0]);
  canvas.fillCircle(x_start + x_delta * 1, y2, r, COLORS_DARK[1]);
  canvas.fillCircle(x_start + x_delta * 2, y2, r, COLORS_DARK[2]);
  canvas.fillCircle(x_start + x_delta * 3, y2, r, COLORS_DARK[3]);
  canvas.fillCircle(x_start + x_delta * 4, y2, r, COLORS_DARK[4]);
  canvas.fillCircle(x_start + x_delta * 5, y2, r, COLORS_DARK[5]);
  canvas.fillCircle(x_start + x_delta * 6, y2, r, COLORS_DARK[6]);
  canvas.fillCircle(x_start + x_delta * 7, y2, r, COLORS_DARK[7]);
  canvas.fillCircle(x_start + x_delta * 8, y2, r, COLORS_DARK[8]);
  canvas.fillCircle(x_start + x_delta * 9, y2, r, COLORS_DARK[9]);


  int y_start = 19;
  for (int pos = 0; pos < 4; pos++) {
    uint8_t curr_digit = 0;
    if (pos == 0) {
      curr_digit = count / 1000;
    } else if (pos == 1) {
      curr_digit = count / 100 % 10;
    } else if (pos == 2) {
      curr_digit = count / 10 % 10;
    } else if (pos == 3) {
      curr_digit = count % 10;
    }
    for (int row = 0; row < 7; row++) {
      for (int col = 0; col < 5; col++) {
        uint32_t color = DIGITS[curr_digit][row][col] ?
                         COLORS_LIGHT[curr_digit] : COLORS_DARK[curr_digit];
        canvas.fillCircle(x_start + col * 7, y_start + row * 7, r, color);
      }
    }
    x_start += 39;
  }

  show_time();
  sendGRAM();

  loopTime = millis();
  endTime = loopTime;
  unsigned long delta = endTime - startTime;
  fps = 1000 / delta;
  // Serial.printf("fill+draw+send GRAM cost: %ldms, calc fps:%ld, real fps:%ld\r\n", delta, fps, fps > 60 ? 60 : fps);
  delay(25); // fps wrong fix

  if (digitalRead(BUTTON_HOME) == 0) {
    Serial.println("\r\nGoing to sleep now\r\n");
    esp_deep_sleep_start();
    Serial.println("This will never be printed");
  }
}

void blink() //中断函数
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


void sendGRAM() {
  Lcd_pic(canvas.getBuffer(), GRAM_BUFFER_SIZE);
}
