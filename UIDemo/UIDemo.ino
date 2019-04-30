
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

}

void loop() {
  canvas.fillScreen(ST77XX_RED);
  canvas.fillCircle(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 4, ST77XX_GREEN);
  sendGRAM();
  delay(100);
}
