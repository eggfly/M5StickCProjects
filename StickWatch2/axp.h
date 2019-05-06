#ifndef _AXP_H
#define _AXP_H

#define AXP192_ADDR  0x34

typedef struct {
  boolean vbus_present;
  boolean acin_present;
  boolean batt_current_direction;    // true: charging, false: discharing
  boolean is_charging;
  boolean is_plug_power_on;     // vbus or acin triggered power on
  double vbus_v;
  double ibus_ma;
  double vbat_v;
  uint32_t icharge_ma;
  uint32_t idischarge_ma;
  double temperature;
  double bat_mw; // battery instantaneous power, mW
  uint32_t coin;                     // total coulomb in
  uint32_t coout;                    // total coulomb out
  double ccc;                        // coulomb counter
} axp_power_data;

uint8_t read_register(uint8_t deviceAddr, uint8_t regAddr) {
  Wire.beginTransmission(deviceAddr);
  Wire.write(regAddr);
  Wire.endTransmission(false);
  Wire.requestFrom(deviceAddr, 1);
  uint8_t data = Wire.read();
  return data;
}

axp_power_data axp_read() {
  axp_power_data result;
  uint8_t data0 = read_register(AXP192_ADDR, 0x00);
  result.vbus_present = data0 & 0b100000;
  result.acin_present = data0 & 0b10000000;
  result.is_plug_power_on = data0 & 0x01;
  result.batt_current_direction = data0 & 0b100;
  uint8_t data1 = read_register(AXP192_ADDR, 0x01);
  result.is_charging = data1 & 0b1000000;

  uint8_t data5e = read_register(AXP192_ADDR, 0x5e); //
  uint8_t data5f = read_register(AXP192_ADDR, 0x5f); //
  result.temperature = -144.7 + ((data5e << 4) + data5f) * 0.1; // 'C

  uint8_t data70 = read_register(AXP192_ADDR, 0x70); //
  uint8_t data71 = read_register(AXP192_ADDR, 0x71); //
  uint8_t data72 = read_register(AXP192_ADDR, 0x72); //
  uint32_t watt = (data70 << 16) + (data71 << 8) + data72;
  result.bat_mw = watt * 1.1 * 0.5 / 1000;

  // vbat
  uint8_t data78 = read_register(AXP192_ADDR, 0x78); //
  uint8_t data79 = read_register(AXP192_ADDR, 0x79); //
  result.vbat_v = ((data78 << 4) + data79) * 1.1 / 1000; // V

  // charge current
  uint8_t data7a = read_register(AXP192_ADDR, 0x7a); //
  uint8_t data7b = read_register(AXP192_ADDR, 0x7b); //
  result.icharge_ma = ((data7a << 5) + data7b) / 2; // mA

  // discharge current
  uint8_t data7c = read_register(AXP192_ADDR, 0x7c); //
  uint8_t data7d = read_register(AXP192_ADDR, 0x7d); //
  result.idischarge_ma = ((data7c << 5) + data7d) / 2;


  uint8_t datab0 = read_register(AXP192_ADDR, 0xb0);
  uint8_t datab1 = read_register(AXP192_ADDR, 0xb1);
  uint8_t datab2 = read_register(AXP192_ADDR, 0xb2);
  uint8_t datab3 = read_register(AXP192_ADDR, 0xb3);

  result.coin = (datab0 << 24) | (datab1 << 16) | (datab2 << 8) | datab3;

  uint8_t datab4 = read_register(AXP192_ADDR, 0xb4);
  uint8_t datab5 = read_register(AXP192_ADDR, 0xb5);
  uint8_t datab6 = read_register(AXP192_ADDR, 0xb6);
  uint8_t datab7 = read_register(AXP192_ADDR, 0xb7);

  result.coout = (datab4 << 24) | (datab5 << 16) | (datab6 << 8) | datab7;

  result.ccc = 65536 * 0.5 * (result.coin - result.coout) / 3600.0 / 25.0;

  uint8_t data5a = read_register(AXP192_ADDR, 0x5a);
  uint8_t data5b = read_register(AXP192_ADDR, 0x5b);
  uint32_t vbus = (data5a << 4) | data5b;

  double vbus_v = vbus * 1.7 / 1000.0;
  result.vbus_v = vbus_v;

  uint8_t data5c = read_register(AXP192_ADDR, 0x5c);
  uint8_t data5d = read_register(AXP192_ADDR, 0x5d);
  uint32_t ibus = (data5c << 4) | data5d;
  double ibus_ma = ibus * 0.375;
  result.ibus_ma = ibus_ma;

  return result;
}

void axp_print_power() {
  axp_power_data d = axp_read();
  Serial.printf("vbus_present=%d, acin_present=%d, batt_current_direction=%d, is_charging=%d, is_plug_power_on=%d\n",
                d.vbus_present,
                d.acin_present,
                d.batt_current_direction,
                d.is_charging,
                d.is_plug_power_on);
  Serial.printf("vbus_v=%lf, ibus_ma=%lf, vbat_v=%lf, icharge_ma=%d, idischarge_ma=%d\n",
                d.vbus_v,
                d.ibus_ma,
                d.vbat_v,
                d.icharge_ma,
                d.idischarge_ma);
  Serial.printf("temperature=%lf, bat_mw=%lf, coin=%d, coout=%d, coout=%lf\n",
                d.temperature,
                d.bat_mw,
                d.coin,
                d.coout,
                d.ccc);
}

void axp_backlight(uint8_t brightness){ // input value between 7 - 16
    Wire.beginTransmission(AXP192_ADDR);
    Wire.write(0x28);  
    Wire.write(((brightness & 0x0f) << 4)); //Enable LDO2&LDO3, LED&TFT 3.3V
    Wire.endTransmission();
}

#endif // _AXP_H
