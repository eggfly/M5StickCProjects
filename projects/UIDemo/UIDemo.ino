
#include "res.h"
#include "config.h"
#include "power.h"
#include "lcd.h"

// -------
void setup() {
  Serial.begin(115200);
  while (!Serial);             // Leonardo: wait for serial monitor

  init_power();
  lcd_init();

  test_esp32_api();
}

void loop() {
  canvas.fillScreen(ST77XX_RED);
  canvas.fillCircle(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 4, ST77XX_GREEN);
  sendGRAM();
  delay(100);
}
void test_esp32_api() {
  // uint32_t realSize = ESP.getFlashChipRealSize();
  uint32_t ideSize = ESP.getFlashChipSize();
  FlashMode_t ideMode = ESP.getFlashChipMode();

  // Serial.printf("Flash real id:   %08X\n", ESP.getFlashChipId());
  // Serial.printf("Flash real size: %u bytes\n\n", realSize);

  Serial.printf("SDK Version: %s\n", ESP.getSdkVersion());
  Serial.printf("getChipRevision() = %u\n", ESP.getChipRevision());
  Serial.printf("getCpuFreqMHz() = %u\n", ESP.getCpuFreqMHz());
  Serial.printf("getEfuseMac() = %u\n", ESP.getEfuseMac());
  Serial.printf("getSketchSize() = %u\n", ESP.getSketchSize());
  Serial.printf("Flash ide size: %u bytes\n", ideSize);
  Serial.printf("Flash ide speed: %u Hz\n", ESP.getFlashChipSpeed());
  Serial.printf("Flash ide mode:  %s\n", (ideMode == FM_QIO ? "QIO" : ideMode == FM_QOUT ? "QOUT" : ideMode == FM_DIO ? "DIO" : ideMode == FM_DOUT ? "DOUT" : "UNKNOWN"));
}
