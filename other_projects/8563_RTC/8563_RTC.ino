#include <Wire.h>
#include "src/RTCLib/RTClib.h"

PCF8563 rtc;

void setup () {
  Serial.begin(115200);
  Wire.begin();
  rtc.begin();
  rtc.isrunning();
  //  if (!rtc.isrunning()) {
  //    Serial.println("RTC is NOT running!");
  //    // following line sets the RTC to the date & time this sketch was compiled
  //    rtc.adjust(DateTime(__DATE__, __TIME__));
  //  }
}

void loop () {
  DateTime now = rtc.now();
  char buf[100];
  strncpy(buf, "DD.MM.YYYY  hh:mm:ss\0", 100);
  Serial.println(now.format(buf));
  delay(1000);
}
