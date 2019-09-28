
#include "res.h"
#include "config.h"
#include "power.h"
#include "lcd.h"

// MAX30100lib
#include "src/MAX30100/MAX30100.h"

// Sampling is tightly related to the dynamic range of the ADC.
// refer to the datasheet for further info
#define SAMPLING_RATE                       MAX30100_SAMPRATE_100HZ

// The LEDs currents must be set to a level that avoids clipping and maximises the
// dynamic range
#define IR_LED_CURRENT                      MAX30100_LED_CURR_50MA
#define RED_LED_CURRENT                     MAX30100_LED_CURR_27_1MA

// The pulse width of the LEDs driving determines the resolution of
// the ADC (which is a Sigma-Delta).
// set HIGHRES_MODE to true only when setting PULSE_WIDTH to MAX30100_SPC_PW_1600US_16BITS
#define PULSE_WIDTH                         MAX30100_SPC_PW_1600US_16BITS
#define HIGHRES_MODE                        true


// Instantiate a MAX30100 sensor class
MAX30100 sensor;


void setup() {
  Serial.begin(115200);
  while (!Serial);             // Leonardo: wait for serial monitor

  init_power();
  lcd_init();
  init_max30100();
}

void init_max30100() {
  Serial.println("Initializing MAX30100..");

  // Initialize the sensor
  // Failures are generally due to an improper I2C wiring, missing power supply
  // or wrong target chip
  int result = Wire.begin(32, 33);
  Serial.println(result);

  if (!sensor.begin()) {
    Serial.println("FAILED");
    for (;;);
  } else {
    Serial.println("SUCCESS");
  }

  // Set up the wanted parameters
  sensor.setMode(MAX30100_MODE_SPO2_HR);
  sensor.setLedsCurrent(IR_LED_CURRENT, RED_LED_CURRENT);
  sensor.setLedsPulseWidth(PULSE_WIDTH);
  sensor.setSamplingRate(SAMPLING_RATE);
  sensor.setHighresModeEnabled(HIGHRES_MODE);
}

void loop() {
  test();

  canvas.fillScreen(ST77XX_RED);
  canvas.fillCircle(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 4, ST77XX_GREEN);
  sendGRAM();
  delay(100);
}

void test() {
  uint16_t ir, red;
  sensor.update();
  while (sensor.getRawValues(&ir, &red)) {
    Serial.print(ir);
    Serial.print('\t');
    Serial.println(red);
  }
}
