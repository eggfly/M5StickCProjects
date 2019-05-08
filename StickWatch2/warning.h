#ifndef _WARNING_H
#define _WARNING_H

#include "lcd.h"

long last_button_active_time = -1;

long last_axp_update_time = 0;

boolean is_usb_plugged_in;

void draw_warning() {
  canvas.setTextSize(1);
  canvas.setCursor(1, 1);
  canvas.print("This watch has been inactive for 1 minute without any USB power.");

  canvas.setTextSize(2);
  canvas.setCursor(15, 28);
  canvas.print("SHUTDOWN TO");
  canvas.setCursor(15, 49);
  canvas.print("SAVE POWER!");

  canvas.setTextSize(1);
  canvas.setCursor(35, 70);
  canvas.print("Or press any button.");
}

void check_battery_warning_and_escape() {
  if (millis() - last_axp_update_time > 1000) {
    axp_power_data axp_data = axp_read();
    is_usb_plugged_in = axp_data.vbus_present;
    // Serial.printf("is_usb_plugged_in ? %d\n", is_usb_plugged_in);
    last_axp_update_time = millis();
  }
  if (last_button_active_time == -1) {
    // init time
    last_button_active_time = millis();
  }
  while (!is_usb_plugged_in && millis() - last_button_active_time > 60 * 1000) {
    canvas.fillScreen(ST77XX_RED);
    canvas.setTextColor(ST77XX_BLACK);
    draw_warning();
    sendGRAM();
    delay(500);

    canvas.fillScreen(ST77XX_BLACK);
    canvas.setTextColor(ST77XX_RED);
    draw_warning();
    sendGRAM();
    delay(500);
  }
}

void feed_battery_warning() {
  last_button_active_time = millis();
}

#endif // _WARNING_H
