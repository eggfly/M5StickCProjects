#include <Wire.h>

#define AXP192_ADDR  0x34

void setup() {
  Wire.begin();
  // put your setup code here, to run once:
  Serial.begin(115200);
}


void testAXP() {
  uint8_t data = read_register(AXP192_ADDR, 0x00);
  Serial.print(data, BIN);
  Serial.printf(", data = %d\n", data);
  // if (data & (1 << CHARGE_FULL_BIT)) return true;
  // else return false;
}

uint8_t read_register(uint8_t deviceAddr, uint8_t regAddr) {
  Wire.beginTransmission(deviceAddr);
  Wire.write(regAddr);
  Wire.endTransmission(false);
  Wire.requestFrom(deviceAddr, 1);
  uint8_t data = Wire.read();
  return data;
}


void loop() {
  testAXP();
  // put your main code here, to run repeatedly:
  delay(1000);
}
