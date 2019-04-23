#ifndef _RTC_H
#define _RTC_H

#include "src/RTCLib/RTClib.h"

PCF8563 rtc;

DateTime now;

void init_rtc() {
  rtc.begin();
  DateTime now = rtc.now();
  // following line sets the RTC to the date & time this sketch was compiled
  DateTime compileTime = DateTime(__DATE__, __TIME__);
  if (now < compileTime) {
    Serial.println("RTC need factory reset!");
    rtc.adjust(compileTime);
  }
}

#endif // _RTC_H
