#ifndef _RTC_H
#define _RTC_H

#include "src/RTCLib/RTClib.h"

PCF8563 rtc;

DateTime now;

void init_rtc() {
  rtc.begin();
  DateTime now = rtc.now();
  if (now.year() < 2019) {
    Serial.println("RTC need factory reset!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }
}

#endif // _RTC_H
