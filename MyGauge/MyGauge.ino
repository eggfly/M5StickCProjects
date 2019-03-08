
//#include <M5Stack.h>
#include <Arduino.h>
#include <U8g2lib.h>

#include <stdio.h>
#include "esp_sleep.h"
#include "nvs.h"
#include "nvs_flash.h"
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
#include "IMU.h"

#define TFT_MOSI      15
#define TFT_CLK       13
#define TFT_CS        5   // Chip select line for TFT display on Shield
#define TFT_DC        23  // Data/command line for TFT on Shield
#define TFT_RST       18  // Reset line for TFT is handled by seesaw!

// osmar


// End of constructor list

uint32_t vbat = 0;
float vbat_mv = 0.0;

int state = 0;
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
  Wire.write(0xff); //Enable LDO2&LDO3, LED&TFT 3.3V
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
  Lcd_pic(gImage_001);
  //attachInterrupt(digitalPinToInterrupt(BUTTON_HOME), blink, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), blink, FALLING);

  //    u8g2.begin();
  sh200i_init();
}

long loopTime, startTime, endTime, fps;
int16_t accX = 0;
int16_t accY = 0;
int16_t accZ = 0;

int16_t gyroX = 0;
int16_t gyroY = 0;
int16_t gyroZ = 0;

void loop(void) {
  loopTime = millis();
  startTime = loopTime;

  if (state)
    Lcd_pic(gImage_002);
  else
    Lcd_pic(gImage_001);
  //  Lcd_Clear(WHITE);
  //  Lcd_Clear(RED);
  //  Lcd_Clear(GREEN);
  //  Lcd_Clear(BLUE);
  //  Lcd_Clear(BLACK);
  //  Lcd_Clear(YELLOW);
  //  Lcd_Clear(GRAY0);
  //  Lcd_Clear(GRAY2);
  //  Lcd_Clear(BLUE);

  loopTime = millis();
  endTime = loopTime;
  fps = 1000 / (endTime - startTime);
  // printf("fps:%d\r\n", fps);
  ///*
  unsigned char tempdata[1];
  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_OUTPUT_ACC_X, 1, tempdata);
  accX = tempdata[0];
  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_OUTPUT_ACC_X + 1, 1, tempdata);
  accX |= tempdata[0] << 8;


  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_OUTPUT_ACC_X + 2, 1, tempdata);
  accY = tempdata[0];
  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_OUTPUT_ACC_X + 3, 1, tempdata);
  accY |= tempdata[0] << 8;

  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_OUTPUT_ACC_X + 4, 1, tempdata);
  accZ = tempdata[0];
  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_OUTPUT_ACC_X + 5, 1, tempdata);
  accZ |= tempdata[0] << 8;

  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_OUTPUT_ACC_X + 6, 1, tempdata);
  gyroX = tempdata[0];
  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_OUTPUT_ACC_X + 7, 1, tempdata);
  gyroX |= tempdata[0] << 8;

  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_OUTPUT_ACC_X + 8, 1, tempdata);
  gyroY = tempdata[0];
  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_OUTPUT_ACC_X + 9, 1, tempdata);
  gyroY |= tempdata[0] << 8;

  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_OUTPUT_ACC_X + 10, 1, tempdata);
  gyroZ = tempdata[0];
  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_OUTPUT_ACC_X + 11, 1, tempdata);
  gyroZ |= tempdata[0] << 8;


  // Serial.printf("%ld,%ld,%ld,%ld,%ld,%ld\r\n", accX, accY, accZ, gyroX, gyroY, gyroZ);
  Serial.printf("%ld,%ld,%ld\r\n", accX, accY, accZ);

  delay(10);
  if (abs(accX) > abs(accY))
    state = 1;
  else
    state = 0;


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
