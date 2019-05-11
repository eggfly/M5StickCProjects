// Date and time functions using a DS1307 RTC connected via I2C and Wire lib

#include <Wire.h>
#include "RTClib.h"

DS1307 rtc;
//RTC_Millis rtc;
//DS3231 rtc;
//PCF8563 rtc;
//PCF8583 rtc;
//DS1302 rtc(CE_PIN,SCK_PIN,IO_PIN);
//DS1302 rtc;// CE_PIN 4, SCK_PIN 5, IO_PIN 6 as default

void setup () {
  Serial.begin(57600);
  Wire.begin();
  rtc.begin();
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }
}

void loop () {
    DateTime now = rtc.now();
    char buf[100];
    strncpy(buf,"DD.MM.YYYY  hh:mm:ss\0",100);
    Serial.println(now.format(buf));
    delay(1000);
}