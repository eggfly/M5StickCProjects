
#include <SPI.h>
#include "src/Ucglib/src/Ucglib.h"
#include "src/RTCLib/RTClib.h"

#include <Wire.h>

PCF8563 rtc;

#define AXP192_ADDR  0x34

Ucglib_ST7735_18x128x160_HWSPI ucg(/*cd=*/ 23, /*cs=*/ 5, /*reset=*/ 18);

#define T 4000
#define DLY() delay(500)

int BUTTON_HOME = GPIO_NUM_37;
int BUTTON_PIN = GPIO_NUM_39;


void color_test(void) {
  ucg_int_t mx;
  uint16_t c, x;
  mx = ucg.getWidth() / 2;
  //my = ucg.getHeight() / 2;

  // Serial.printf("w=%d, h=%d\n", ucg.getWidth(), ucg.getHeight());
  ucg.setColor(0, 255, 0, 0);
  ucg.setColor(1, 0, 255, 0);
  ucg.setColor(2, 255, 0, 255);
  ucg.setColor(3, 0, 255, 255);
  // ucg.drawBox(0, 0, ucg.getWidth(), ucg.getHeight());
  ucg.drawGradientBox(0, 0 + 30, 161, 80 + 30);
  // ucg.clearScreen();
  //  ucg.setColor(255, 255, 255);

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
}


double acin_mv = 0;
double acin_current = 0;
double vbus_mv = 0;
double ibus_ma = 0;

double temperature = 0;
double bat_mw = 0;
int charge = 0;
int discharge = 0;

char data0_bin[33] = "?";
char data1_bin[33] = "?";

uint32_t coin = 0;
uint32_t coout = 0;
double ccc = 0.0;
double vbat_v = 0.0;


void readAXP() {
  uint8_t data0 = read_register(AXP192_ADDR, 0x00);
  uint8_t data1 = read_register(AXP192_ADDR, 0x01);

  uint8_t data56 = read_register(AXP192_ADDR, 0x56);
  uint8_t data57 = read_register(AXP192_ADDR, 0x57);
  int vin = (data56 << 4) | data57;
  acin_mv = vin * 1.7;

  uint8_t data58 = read_register(AXP192_ADDR, 0x58);
  uint8_t data59 = read_register(AXP192_ADDR, 0x59);
  int iin = (data58 << 4) | data59;
  acin_current = iin * 0.625;

  uint8_t data5a = read_register(AXP192_ADDR, 0x5A);
  uint8_t data5b = read_register(AXP192_ADDR, 0x5B);
  int vbus = (data5a << 4) | data5b;
  vbus_mv = vbus * 1.7;

  uint8_t data5c = read_register(AXP192_ADDR, 0x5C);
  uint8_t data5d = read_register(AXP192_ADDR, 0x5D);
  int ibus = (data5c << 4) | data5d;
  ibus_ma = ibus * 0.375;

  // axp temp
  uint8_t data5e = read_register(AXP192_ADDR, 0x5e); //
  uint8_t data5f = read_register(AXP192_ADDR, 0x5f); //
  temperature = -144.7 + ((data5e << 4) + data5f) * 0.1; // 'C

  uint8_t data70 = read_register(AXP192_ADDR, 0x70); //
  uint8_t data71 = read_register(AXP192_ADDR, 0x71); //
  uint8_t data72 = read_register(AXP192_ADDR, 0x72); //
  uint32_t watt = (data70 << 16) + (data71 << 8) + data72;
  bat_mw = watt * 1.1 * 0.5 / 1000;

  // vbat
  uint8_t data78 = read_register(AXP192_ADDR, 0x78); //
  uint8_t data79 = read_register(AXP192_ADDR, 0x79); //
  vbat_v = ((data78 << 4) | data79) * 1.1 / 1000; // V
  // charge current
  uint8_t data7a = read_register(AXP192_ADDR, 0x7a); //
  uint8_t data7b = read_register(AXP192_ADDR, 0x7b); //
  charge = ((data7a << 5) + data7b) / 2; // mA
  // discharge current
  uint8_t data7c = read_register(AXP192_ADDR, 0x7c); //
  uint8_t data7d = read_register(AXP192_ADDR, 0x7d); //
  discharge = ((data7c << 5) + data7d) / 2;

  itoa(data0, data0_bin, 2);
  itoa(data1, data1_bin, 2);

  uint8_t datab0 = read_register(AXP192_ADDR, 0xb0);
  uint8_t datab1 = read_register(AXP192_ADDR, 0xb1);
  uint8_t datab2 = read_register(AXP192_ADDR, 0xb2);
  uint8_t datab3 = read_register(AXP192_ADDR, 0xb3);
  coin = (datab0 << 24) | (datab1 << 16) || (datab2 << 8) |  datab3;

  uint8_t datab4 = read_register(AXP192_ADDR, 0xb4);
  uint8_t datab5 = read_register(AXP192_ADDR, 0xb5);
  uint8_t datab6 = read_register(AXP192_ADDR, 0xb6);
  uint8_t datab7 = read_register(AXP192_ADDR, 0xb7);
  coout = (datab4 << 24) | (datab5 << 16) || (datab6 << 8) |  datab7;

  ccc = 65536 * 0.5 * (coin - coout) / 3600.0 / 25.0;
}

void drawAXP() {
  unsigned long loop_start = millis();

  ucg.setColor(255, 255, 255);
  ucg.setPrintDir(0);
  ucg.setPrintPos(2, 40);
  ucg.print(data0_bin);
  ucg.setPrintPos(42, 40);
  ucg.print(data1_bin);

  ucg.setPrintPos(2, 50);
  ucg.print("vbat:");
  ucg.print(vbat_v, 4);
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
  ucg.print(temperature);
  ucg.print(" C");

  ucg.setPrintPos(2, 90);
  ucg.print("watt:");
  ucg.print(bat_mw, 3);
  ucg.print("mW");

  ucg.setPrintPos(85, 40);
  ucg.print("Vin:");
  ucg.print(vbus_mv, 2);
  ucg.print("mV");

  ucg.setPrintPos(85, 50);
  ucg.print("Iin:");
  ucg.print(ibus_ma, 2);
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
  Serial.printf("time0: %ld\n", millis() - loop_start);
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
  Wire.write(0x9f); //Enable LDO2&LDO3, LED&TFT 3.3V
  // 背光亮度通过LDO2调节
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

void shutdown_axp() {
  Wire.beginTransmission(0x34);
  Wire.write(0x31); // enable sleep button short press
  Wire.write(0x0B);
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x32); // power down!
  Wire.write(0xC6);
  Wire.endTransmission();
}

/**
   false: 未充电或充电已完成
   true: 正在充电
*/
boolean is_charging() {
  uint8_t data01 = read_register(AXP192_ADDR, 0x01);
  return data01 & 0b01000000;
}

boolean has_usb_plugin() {
  uint8_t data00 = read_register(AXP192_ADDR, 0x00);
  return data00 | 0b10100000; // 7 bit or 5 bit
}

/**
   true: charge current
   false: discharge current
*/
boolean battery_current_direction() {
  uint8_t data00 = read_register(AXP192_ADDR, 0x00);
  return data00 & 0b00000100;
}

void shutdown_all_except_self() {
  /**
     0:关闭； 1:打开:

     7 保留，不可更改 RW X
     6 EXTEN 开关控制 RW X
     5 保留，不可更改 RW X
     4 DC-DC2 开关控制 RW X
     3 LDO3 开关控制 RW X
     2 LDO2 开关控制 RW X
     1 DC-DC3 开关控制 RW X
     0 DC-DC1 开关控制 RW X
     注：REG12Hbit6/4 分别对应 REG10Hbit2/0
  */
  Wire.beginTransmission(0x34);
  Wire.write(0x12); // REG 12H:电源输出控制
  Wire.write(0x01); // 除了DCDC1，其他设置0
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x10);
  Wire.write(0x00);  // OLED_VPP DISABLE
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x82);  // disable all the ADCs
  Wire.write(0x00);
  Wire.endTransmission();
}

boolean need_shutdown = false;

//中断函数
void homePressed() {
  need_shutdown = true;
}

void setup(void) {
  rtc.begin();
  rtc.isrunning();
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

void show_time() {
  DateTime now = rtc.now();
  char buf[100];
  strncpy(buf, "YYYY.MM.DD hh:mm:ss\0", 100);
  Serial.println(now.format(buf));

  ucg.setPrintPos(40, 100);
  ucg.print(buf);
}

void loop(void) {
  unsigned long loop_start = millis();
  ucg.setRotate90();
  color_test();
  Serial.printf("time0: %ld\n", millis() - loop_start);
  readAXP();
  Serial.printf("time1: %ld\n", millis() - loop_start);
  drawAXP();
  Serial.printf("time2: %ld\n", millis() - loop_start);
  show_time();
  Serial.printf("time3: %ld\n", millis() - loop_start);
  ucg.setMaxClipRange();
  if (need_shutdown) {
    // shutdown_all_except_self();
    shutdown_axp();
    Serial.println("\r\nGoing to sleep now\r\n");
    esp_deep_sleep_start();
    Serial.println("This will never be printed");
  }
  DLY();
  //  if (digitalRead(BUTTON_HOME) == 0) {
  //    while (digitalRead(BUTTON_HOME) == 0);
  //    delay(100);
  //    shutdown_all_except_self();
  //    Serial.println("\r\nGoing to sleep now\r\n");
  //    esp_deep_sleep_start();
  //    Serial.println("This will never be printed");
  //  }
}
