#ifndef _RTC_H
#define _RTC_H

#include "src/RTCLib/RTClib.h"
#include "config.h"
#include <time.h>

PCF8563 rtc;

// adjust 1970 -> 2078
// adjust 1980 -> 2088
// adjust 1990 -> 2098
// adjust 1991 -> 2099
// adjust 1992 -> 2000
// adjust 1993 -> 2001
// adjust 1999 -> 2007
// adjust 2078 -> 2078
// adjust 2100 -> 2000

DateTime now;

time_t unix_time(DateTime& t) {
  char buf[100];
  strncpy(buf, "YYYY-MM-DD hh:mm:ss\0", sizeof(buf));
  t.format(buf);
  struct tm tm;
  time_t epoch;
  if (strptime(buf, "%Y-%m-%d %H:%M:%S", &tm) != NULL ) {
    epoch = mktime(&tm);
#ifdef APP_DEBUG
    Serial.print("unix timestamp value: ");
    Serial.println(epoch);
#endif
    return epoch;
  } else {
    Serial.println("time convert error");
    return 0;
  }
}

void init_rtc() {
  rtc.begin();
  now = rtc.now();
  // following line sets the RTC to the date & time this sketch was compiled
  DateTime compileTime = DateTime(__DATE__, __TIME__);
  Serial.print("compile time in this firmware: ");
  Serial.print(__DATE__);
  Serial.print(" ");
  Serial.println(__TIME__);
  if (unix_time(now) < unix_time(compileTime)) {
    Serial.println("now < compileTime, RTC need factory reset!");
    rtc.adjust(compileTime);
  } else {
    Serial.println("now >= compileTime, RTC already ok, ignore time adjustment.");
  }
}

#endif // _RTC_H
