
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
    ucg.drawBox(x, -12, 4, 8);
    ucg.setColor(0, c, 0, 0);
    ucg.drawBox(x, -12 + 8, 4, 8);
    ucg.setColor(0, 0, c, 0);
    ucg.drawBox(x, -12 + 2 * 8, 4, 8);
    ucg.setColor(0, 0, 0, c);
    ucg.drawBox(x, -12 + 3 * 8, 4, 8);
    ucg.setColor(0, c, 255 - c, 0);
    ucg.drawBox(x, -12 + 4 * 8, 4, 8);
  }

  //  ucg.setColor(0, 0, 255, 255);
  //  ucg.drawFrame(1, 1, 78, 78);
}

void printAXP(uint8_t value, char * desc) {
  Serial.print(value, BIN);
  Serial.printf(", %s = %d\n", desc, value);
}

void hanxiao() {
  uint32_t vbat = 0;
  float vbat_mv = 0.0;
  uint32_t ibat = 0;
  uint32_t dibat = 0;
  uint32_t vin = 0;
  uint32_t iin = 0;
  uint32_t coin = 0;
  uint32_t coout = 0;
  Wire.beginTransmission(0x34);
  Wire.write(0x78);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  byte buf = Wire.read();
  vbat = ((uint32_t)(buf)) << 4;


  Wire.beginTransmission(0x34);
  Wire.write(0x79);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  byte buf2 = Wire.read();
  vbat |= buf2;


  Wire.beginTransmission(0x34);
  Wire.write(0x7A);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  ibat = ((uint32_t)(Wire.read())) << 5;


  Wire.beginTransmission(0x34);
  Wire.write(0x7B);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  ibat |= Wire.read();

  Wire.beginTransmission(0x34);
  Wire.write(0x7C);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  dibat = ((uint32_t)(Wire.read())) << 5;


  Wire.beginTransmission(0x34);
  Wire.write(0x7D);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  dibat |= Wire.read();


  Wire.beginTransmission(0x34);
  Wire.write(0x7C);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  dibat = ((uint32_t)(Wire.read())) << 5;


  Wire.beginTransmission(0x34);
  Wire.write(0x7D);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  dibat |= Wire.read();


  Wire.beginTransmission(0x34);
  Wire.write(0x56);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  vin = ((uint32_t)(Wire.read())) << 4;


  Wire.beginTransmission(0x34);
  Wire.write(0x57);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  vin |= Wire.read();

  Wire.beginTransmission(0x34);
  Wire.write(0x58);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  iin = ((uint32_t)(Wire.read())) << 4;


  Wire.beginTransmission(0x34);
  Wire.write(0x59);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  iin |= Wire.read();

  Wire.beginTransmission(0x34);
  Wire.write(0xB0);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  coin = ((uint32_t)(Wire.read())) << 24;

  Wire.beginTransmission(0x34);
  Wire.write(0xB1);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  coin |= ((uint32_t)(Wire.read())) << 16;
  Wire.beginTransmission(0x34);
  Wire.write(0xB2);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  coin |= ((uint32_t)(Wire.read())) << 8;
  Wire.beginTransmission(0x34);
  Wire.write(0xB3);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  coin |= ((uint32_t)(Wire.read()));

  Wire.beginTransmission(0x34);
  Wire.write(0xB4);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  coout = ((uint32_t)(Wire.read())) << 24;

  Wire.beginTransmission(0x34);
  Wire.write(0xB5);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  coout |= ((uint32_t)(Wire.read())) << 16;
  Wire.beginTransmission(0x34);
  Wire.write(0xB6);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  coout |= ((uint32_t)(Wire.read())) << 8;
  Wire.beginTransmission(0x34);
  Wire.write(0xB7);
  Wire.endTransmission();
  Wire.requestFrom(0x34, 1);
  coout |= ((uint32_t)(Wire.read()));

  float ccc = 65536 * 0.5 * (coin - coout) / 3600.0 / 25.0;

  vbat_mv = vbat * 1.1;
  Serial.printf("COIN: %lu, COOUT: %lu\n\r", coin, coout);
  char printbuf[30] = "";

  double acin_mv = vin * 1.7;
  double acin_current = iin * 0.625;
  Serial.printf("VBat: %.03fmV\n", vbat_mv);
  Serial.printf("CHG: %.03fmA\n",  ibat * 0.5);
  Serial.printf("DisCHG: %.03fmA\n",  dibat * 0.5);
  Serial.printf("Vin: %.03fmV\n", acin_mv);
  Serial.printf("Iin: %.03fmA\n", acin_current);
  Serial.printf("Remain: %.03fmAh\n",  ccc);

  ucg.setPrintPos(85, 40);
  ucg.print("Vin:");
  ucg.print(acin_mv, 2);
  ucg.print("mV");

  ucg.setPrintPos(85, 50);
  ucg.print("Iin:");
  ucg.print(acin_current, 2);
  ucg.print("mA");

  ucg.setPrintPos(85, 60);
  ucg.print("CoIn:");
  ucg.print(coin);
  // ucg.print("?");

  ucg.setPrintPos(85, 70);
  ucg.print("CoOut:");
  ucg.print(coout);
  // ucg.print("?");

  ucg.setPrintPos(85, 80);
  ucg.print("ccc:");
  ucg.print(ccc, 2);
  ucg.print("mAh");
}
void testAXP() {
  uint8_t data0 = read_register(AXP192_ADDR, 0x00);
  printAXP(data0, "data0");
  uint8_t data1 = read_register(AXP192_ADDR, 0x01);
  printAXP(data1, "data1");

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
  uint32_t watt = (data70 << 16) + (data71 << 8) + data72;
  double bat_mw = watt * 1.1 * 0.5 / 1000;
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
  char buffer1[33];
  itoa(data1, buffer1, 2);

  ucg.setColor(255, 255, 255);
  ucg.setPrintDir(0);
  ucg.setPrintPos(2, 40);
  ucg.print(buffer0);
  ucg.setPrintPos(45, 40);
  ucg.print(buffer1);

  ucg.setPrintPos(2, 50);
  ucg.print("vbat:");
  ucg.print(vbat, 4);
  ucg.print("V");

  ucg.setPrintPos(2, 60);
  ucg.print("charge:");
  ucg.print(charge);
  ucg.print("mA");

  ucg.setPrintPos(2, 70);
  ucg.print("disCHG:");
  ucg.print(discharge);
  ucg.print("mA");

  ucg.setPrintPos(2, 80);
  ucg.print("temp:");
  ucg.print(temp);
  ucg.print(" C");
  
  ucg.setPrintPos(2, 90);
  ucg.print("watt:");
  ucg.print(bat_mw, 3);
  ucg.print("mW");
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

boolean need_shutdown = false;

//中断函数
void homePressed() {
  need_shutdown = true;
}

void setup(void) {
  pinMode(BUTTON_HOME, INPUT | PULLUP);
  pinMode(BUTTON_PIN, INPUT | PULLUP);

  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(BUTTON_HOME), homePressed, FALLING);
  esp_sleep_enable_ext0_wakeup((gpio_num_t)BUTTON_PIN, 0);
  beginPower();
  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  // ucg.setFont(ucg_font_ncenR14_hr);
  // ucg.setFont(ucg_font_7x13_tf);
  ucg.setFont(ucg_font_6x12_tf);
  ucg.clearScreen();
}

void loop(void) {
  ucg.setRotate90();
  color_test();
  testAXP();
  hanxiao();
  DLY();
  ucg.setMaxClipRange();
  if (need_shutdown) {
    shutdown_all_except_self();
    Serial.println("\r\nGoing to sleep now\r\n");
    esp_deep_sleep_start();
    Serial.println("This will never be printed");
  }
  //  if (digitalRead(BUTTON_HOME) == 0) {
  //    while (digitalRead(BUTTON_HOME) == 0);
  //    delay(100);
  //    shutdown_all_except_self();
  //    Serial.println("\r\nGoing to sleep now\r\n");
  //    esp_deep_sleep_start();
  //    Serial.println("This will never be printed");
  //  }
}
