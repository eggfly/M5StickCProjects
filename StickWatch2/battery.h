#ifndef _BATTERY_H
#define _BATTERY_H

#include "axp.h"
#include "lcd.h"

static const float levels[] = {4.13, 4.06, 3.98, 3.92, 3.87, 3.82, 3.79, 3.77, 3.74, 3.68, 3.45, 3.00};

unsigned long axp_last_update;
axp_power_data axp_data;

float getBatteryLevel(float voltage) {
  float level = 1;
  if (voltage >= levels[0]) {
    level = 1;
  } else if (voltage >= levels[1]) {
    level = 0.9;
    level += 0.1 * (voltage - levels[1]) / (levels[0] - levels[1]);
  } else if (voltage >= levels[2]) {
    level = 0.8;
    level += 0.1 * (voltage - levels[2]) / (levels[1] - levels[2]);
  } else if (voltage >= levels[3]) {
    level = 0.7;
    level += 0.1 * (voltage - levels[3]) / (levels[2] - levels[3]);
  } else if (voltage >= levels[4]) {
    level = 0.6;
    level += 0.1 * (voltage - levels[4]) / (levels[3] - levels[4]);
  } else if (voltage >= levels[5]) {
    level = 0.5;
    level += 0.1 * (voltage - levels[5]) / (levels[4] - levels[5]);
  } else if (voltage >= levels[6]) {
    level = 0.4;
    level += 0.1 * (voltage - levels[6]) / (levels[5] - levels[6]);
  } else if (voltage >= levels[7]) {
    level = 0.3;
    level += 0.1 * (voltage - levels[7]) / (levels[6] - levels[7]);
  } else if (voltage >= levels[8]) {
    level = 0.2;
    level += 0.1 * (voltage - levels[8]) / (levels[7] - levels[8]);
  } else if (voltage >= levels[9]) {
    level = 0.1;
    level += 0.1 * (voltage - levels[9]) / (levels[8] - levels[9]);
  } else if (voltage >= levels[10]) {
    level = 0.05;
    level += 0.05 * (voltage - levels[10]) / (levels[9] - levels[10]);
  } else if (voltage >= levels[11]) {
    level = 0.00;
    level += 0.05 * (voltage - levels[11]) / (levels[10] - levels[11]);
  } else {
    level = 0.00;
  }
  return level;
}

void draw_battery_percent() {
  float battery_percent = getBatteryLevel(axp_data.vbat_v);
  canvas.setTextColor(0xAA00FF00);
  canvas.setCursor(122, 2);
  canvas.print(battery_percent * 100, 1);
  canvas.print("%");
}

void check_update_battery() {
  unsigned long now = millis();
  if (now - axp_last_update > 400) {
    axp_data = axp_read();
    axp_last_update = now;
  }
}

void page_axp_info() {
  check_update_battery();
  axp_power_data d = axp_data;

  canvas.setTextSize(1);
  canvas.setTextColor(0xAAFF0000);
  canvas.setCursor(30, 1);
  canvas.print("Battery Info");

  draw_battery_percent();

  canvas.setTextSize(1);
  canvas.setTextColor(0xAAFFFFFF);

  int start_y = 13;
  int delta_y = 9;
  int start_x = 4;
  canvas.setCursor(start_x, start_y);
  canvas.print("vbat=");
  canvas.print(d.vbat_v, 3);
  canvas.print("V");

  canvas.setCursor(start_x, start_y + delta_y);
  canvas.print("chg=");
  canvas.print(d.icharge_ma);
  canvas.print("mA");

  canvas.setCursor(start_x, start_y + delta_y * 2);
  canvas.print("dis=");
  canvas.print(d.idischarge_ma);
  canvas.print("mA");

  canvas.setCursor(start_x, start_y + delta_y * 3);
  canvas.print("watt=");
  canvas.print(d.bat_mw, 1);
  canvas.print("mW");

  canvas.setCursor(start_x, start_y + delta_y * 4);
  canvas.print("coin=");
  canvas.print(d.coin);

  canvas.setCursor(start_x, start_y + delta_y * 5);
  canvas.print("coout=");
  canvas.print(d.coout);

  canvas.setCursor(start_x, start_y + delta_y * 6);
  canvas.print("ccc=");
  canvas.print(d.ccc, 2);

  canvas.setCursor(80, start_y);
  canvas.print("vbus? ");
  canvas.print(d.vbus_present);

  canvas.setCursor(80, start_y + delta_y);
  canvas.print("vbus=");
  canvas.print(d.vbus_v, 3);
  canvas.print("V");

  canvas.setCursor(80, start_y + delta_y * 2);
  canvas.print("ibus=");
  canvas.print(d.ibus_ma, 2);
  canvas.print("mA");

  canvas.setCursor(80, start_y + delta_y * 3);
  canvas.print("PWR On USB? ");
  canvas.print(d.is_plug_power_on);

  canvas.setCursor(80, start_y + delta_y * 4);
  canvas.print("temp=");
  canvas.print(d.temperature, 1);
  canvas.print("C");

  canvas.setCursor(80, start_y + delta_y * 5);
  canvas.print("charging? ");
  canvas.print(d.is_charging);

  canvas.setCursor(80, start_y + delta_y * 6);
  canvas.print("bat_chg? ");
  canvas.print(d.batt_current_direction);
}

#endif // _BATTERY_H
