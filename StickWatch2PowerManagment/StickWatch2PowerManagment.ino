
#include <SPI.h>
#include "src/Ucglib/src/Ucglib.h"

#include <Wire.h>

#define AXP192_ADDR  0x34

Ucglib_ST7735_18x128x160_HWSPI ucg(/*cd=*/ 23, /*cs=*/ 5, /*reset=*/ 18);

#define T 4000
#define DLY() delay(1000)

int BUTTON_HOME = GPIO_NUM_37;
int BUTTON_PIN = GPIO_NUM_39;


void color_test(void)
{
  ucg_int_t mx;
  uint16_t c, x;
  mx = ucg.getWidth() / 2;
  //my = ucg.getHeight() / 2;

  Serial.printf("w=%d, h=%d\n", ucg.getWidth(), ucg.getHeight());
  ucg.setColor(0, 0, 0, 0);
  ucg.drawBox(0, 0, ucg.getWidth(), ucg.getHeight());

  //  ucg.setColor(255, 255, 255);
  //  ucg.setPrintPos(40, 40);
  //  // ucg.setPrintPos(2, 18);
  //  ucg.setPrintDir(0);
  //  ucg.print("Color Test");

  //  ucg.setColor(0, 80, 80, 80);
  //  ucg.drawBox(0, 20, 16 * 4 + 4, 5 * 8 + 4);

  //  ucg.setColor(0, 200, 200, 0);
  //  ucg.drawBox(0, 0, 79, 79);

  for ( c = 0, x = 2; c <= 255; c += 17, x += 4 ) {
    ucg.setColor(0, c, c, c);
    ucg.drawBox(x, 22, 4, 8);
    ucg.setColor(0, c, 0, 0);
    ucg.drawBox(x, 22 + 8, 4, 8);
    ucg.setColor(0, 0, c, 0);
    ucg.drawBox(x, 22 + 2 * 8, 4, 8);
    ucg.setColor(0, 0, 0, c);
    ucg.drawBox(x, 22 + 3 * 8, 4, 8);
    ucg.setColor(0, c, 255 - c, 0);
    ucg.drawBox(x, 22 + 4 * 8, 4, 8);
  }

  //  ucg.setColor(0, 0, 255, 255);
  //  ucg.drawFrame(1, 1, 78, 78);
}

void printAXP(uint8_t value, char * desc) {
  Serial.print(value, BIN);
  Serial.printf(", %s = %d\n", desc, value);
}

void testAXP() {
  uint8_t data0 = read_register(AXP192_ADDR, 0x00);
  printAXP(data0, "data0");

  uint8_t data56 = read_register(AXP192_ADDR, 0x56); //
  printAXP(data56, "data56");
  uint8_t data57 = read_register(AXP192_ADDR, 0x57); //
  printAXP(data57, "data57");

  uint8_t data5e = read_register(AXP192_ADDR, 0x5e); //
  uint8_t data5f = read_register(AXP192_ADDR, 0x5f); //
  double temp = -144.7 + ((data5e << 4) + data5f) * 0.1; // 'C
  Serial.printf("temperature: %.1f\n", temp);

  uint8_t data70 = read_register(AXP192_ADDR, 0x70); //
  printAXP(data70, "data70");
  uint8_t data71 = read_register(AXP192_ADDR, 0x71); //
  printAXP(data71, "data71");
  uint8_t data72 = read_register(AXP192_ADDR, 0x72); //
  printAXP(data72, "data72");
  // vbat
  uint8_t data78 = read_register(AXP192_ADDR, 0x78); //
  printAXP(data78, "data78");
  uint8_t data79 = read_register(AXP192_ADDR, 0x79); //
  printAXP(data79, "data79");
  double vbat = ((data78 << 4) + data79) * 1.1 / 1000; // V
  Serial.printf("78&79->VBat: %.4f\n", vbat);
  // charge current
  uint8_t data7a = read_register(AXP192_ADDR, 0x7a); //
  printAXP(data7a, "data7a");
  uint8_t data7b = read_register(AXP192_ADDR, 0x7b); //
  printAXP(data7b, "data7b");
  int charge = ((data7a << 5) + data7b) / 2; // mA
  Serial.printf("7a&7b->CHARGE: %d\n", charge);
  // discharge current
  uint8_t data7c = read_register(AXP192_ADDR, 0x7c); //
  printAXP(data7c, "data7c");
  uint8_t data7d = read_register(AXP192_ADDR, 0x7d); //
  printAXP(data7d, "data7d");
  int discharge = ((data7c << 5) + data7d) / 2;
  Serial.printf("7c&7d->DISCHARGE: %d\n", discharge);

  char buffer0[33];
  itoa(data0, buffer0, 2);

  ucg.setColor(255, 255, 255);
  ucg.setPrintDir(0);
  ucg.setPrintPos(5, 40);
  ucg.print(buffer0);

  ucg.setPrintPos(5, 55);
  ucg.print("vbat:");
  ucg.print(vbat);
  ucg.print("V");

  ucg.setPrintPos(5, 70);
  ucg.print("charge:");
  ucg.print(charge);
  ucg.print("mA");

  ucg.setPrintPos(5, 85);
  ucg.print("discharge:");
  ucg.print(discharge);
  ucg.print("mA");

  ucg.setPrintPos(5, 100);
  ucg.print("temp:");
  ucg.print(temp);
  ucg.print(" C");
}

uint8_t read_register(uint8_t deviceAddr, uint8_t regAddr) {
  Wire.beginTransmission(deviceAddr);
  Wire.write(regAddr);
  Wire.endTransmission(false);
  Wire.requestFrom(deviceAddr, 1);
  uint8_t data = Wire.read();
  return data;
}


void beginPower() {
  Wire.begin();

  Wire.beginTransmission(0x34);
  Wire.write(0x10);
  Wire.write(0xff);  //OLED_VPP Enable
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x28);
  Wire.write(0xff); //Enable LDO2&LDO3, LED&TFT 3.3V
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x82);  //Enable all the ADCs
  Wire.write(0xff);
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x33);  //Enable Charging, 100mA, 4.2V, End at 0.9
  Wire.write(0xC0);
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x33);
  Wire.write(0xC3);
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0xB8);  //Enable Colume Counter
  Wire.write(0x80);
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x12);
  Wire.write(0x4d); //Enable DC-DC1, OLED_VDD, 5B V_EXT
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x36);
  Wire.write(0x5c); //PEK
  Wire.endTransmission();
}

void shutdown_all_except_self() {
  Wire.beginTransmission(0x34);
  Wire.write(0x12);
  Wire.write(0x01);
  Wire.endTransmission();
}

//中断函数
void homePressed() {
  shutdown_all_except_self();
}

void setup(void) {
  pinMode(BUTTON_HOME, INPUT | PULLUP);
  pinMode(BUTTON_PIN, INPUT | PULLUP);

  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(BUTTON_HOME), homePressed, FALLING);
  esp_sleep_enable_ext0_wakeup((gpio_num_t)BUTTON_PIN, 0);
  beginPower();
  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  ucg.setFont(ucg_font_ncenR14_hr);
  ucg.clearScreen();
}

uint8_t r = 0;
void loop(void) {
  ucg.setRotate90();
  color_test();
  testAXP();
  DLY();
  ucg.setMaxClipRange();
}
