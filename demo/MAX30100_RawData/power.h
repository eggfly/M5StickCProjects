#ifndef _POWER_H
#define _POWER_H

#include "soc/rtc.h"
#include <Wire.h>

// #define LOW_CPU_FREQ

void init_power() {
#ifdef LOW_CPU_FREQ
  rtc_cpu_freq_config_t conf = {
  };
  uint32_t source_freq_mhz = rtc_clk_xtal_freq_get();
  conf.source = RTC_CPU_FREQ_SRC_XTAL;
  conf.source_freq_mhz = source_freq_mhz;
  conf.div = source_freq_mhz / 10;
  conf.freq_mhz = 10;
  Serial.print("div=");
  Serial.println(conf.div);
  rtc_clk_cpu_freq_set_config(&conf);
#else
  // rtc_clk_cpu_freq_set(RTC_CPU_FREQ_80M);
#endif
  Wire1.begin(21, 22);

  Wire1.beginTransmission(0x34);
  Wire1.write(0x10);
  Wire1.write(0x9f);  //OLED_VPP Enable
  Wire1.endTransmission();

  Wire1.beginTransmission(0x34);
  Wire1.write(0x28);
  Wire1.write(0x9f); //Enable LDO2&LDO3, LED&TFT 3.3V
  // Wire.write(0xff); //Enable LDO2&LDO3, LED&TFT 3.3V
  Wire1.endTransmission();

  Wire1.beginTransmission(0x34);
  Wire1.write(0x82);  //Enable all the ADCs
  Wire1.write(0xff);
  Wire1.endTransmission();

  Wire1.beginTransmission(0x34);
  Wire1.write(0x33);  //Enable Charging, 100mA, 4.2V, End at 0.9
  Wire1.write(0xC0);
  Wire1.endTransmission();

  Wire1.beginTransmission(0x34);
  Wire1.write(0x33);
  Wire1.write(0xC3);
  Wire1.endTransmission();

  Wire1.beginTransmission(0x34);
  Wire1.write(0xB8);  //Enable Colume Counter
  Wire1.write(0x80);
  Wire1.endTransmission();

  Wire1.beginTransmission(0x34);
  Wire1.write(0x12);
  Wire1.write(0x4d); //Enable DC-DC1, OLED_VDD, 5B V_EXT
  Wire1.endTransmission();

  Wire1.beginTransmission(0x34);
  Wire1.write(0x36);
  Wire1.write(0x5c); //PEK
  Wire1.endTransmission();
}

#endif // _POWER_H
