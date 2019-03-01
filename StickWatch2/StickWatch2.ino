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

void color_test() {
  uint16_t c, x;
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

#define COLOR_COUNT 6

int color_index = 0;
uint8_t color_r[COLOR_COUNT] = {255,   0,   0, 255, 0,   255};
uint8_t color_g[COLOR_COUNT] = {  0, 255,   0, 255, 255,   0};
uint8_t color_b[COLOR_COUNT] = {  0,   0, 255,   0, 255, 255};

void draw_background(void) {
  // Serial.printf("w=%d, h=%d\n", ucg.getWidth(), ucg.getHeight());
  color_index++;
  int i = color_index % COLOR_COUNT;
  // Serial.printf("color index: %d", i);
  ucg.setColor(0, color_r[i], color_g[i], color_b[i]);
  ucg.setColor(1, color_r[(i + 1) % COLOR_COUNT], color_g[(i + 1) % COLOR_COUNT], color_b[(i + 1) % COLOR_COUNT]);
  ucg.setColor(2, color_r[(i + 2) % COLOR_COUNT], color_g[(i + 2) % COLOR_COUNT], color_b[(i + 2) % COLOR_COUNT]);
  ucg.setColor(3, color_r[(i + 3) % COLOR_COUNT], color_g[(i + 3) % COLOR_COUNT], color_b[(i + 3) % COLOR_COUNT]);
  // ucg.drawBox(0, 0, ucg.getWidth(), ucg.getHeight());
  ucg.drawGradientBox(2, 23, 157, 78);
}

double acin_mv = 0;
double acin_current = 0;
double vbus_v = 0;
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
  vbus_v = vbus * 1.7 / 1000.0;

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

  //  ucg.setPrintPos(2, 90);
  //  ucg.print("watt:");
  //  ucg.print(bat_mw, 3);
  //  ucg.print("mW");

  ucg.setPrintPos(85, 40);
  ucg.print("Vin:");
  ucg.print(vbus_v, 4);
  ucg.print("V");

  ucg.setPrintPos(85, 50);
  ucg.print("Iin:");
  ucg.print(ibus_ma, 2);
  ucg.print("mA");

  //  ucg.setPrintPos(85, 60);
  //  ucg.print("CoIn:");
  //  ucg.print(coin);
  //
  //  ucg.setPrintPos(85, 70);
  //  ucg.print("CoOut:");
  //  ucg.print(coout);
  //
  //  ucg.setPrintPos(85, 80);
  //  ucg.print("ccc:");
  //  ucg.print(ccc, 2);
  //  ucg.print("mAh");

  char charge_status[128] = "";
  boolean battery_charging = is_charging();
  boolean has_usb = usb_plugged_in();
  if (has_usb) {
    if (battery_charging) {
      sprintf(charge_status, "Charging..");
    } else {
      sprintf(charge_status, "Charge full");
    }
  } else {
    sprintf(charge_status, "Using battery.");
  }
  ucg.setPrintPos(70, 30);
  ucg.print(charge_status);

  Serial.printf("time0: %ld\n", millis() - loop_start);
}



void drawAXP2() {
  unsigned long loop_start = millis();

  ucg.setColor(255, 255, 255);

  ucg.drawString(2, 40, 0, data0_bin);
  ucg.drawString(42, 40, 0, data1_bin);

  char buf[64] = "";

  sprintf(buf, "vbat:%.4fV", vbat_v);
  ucg.drawString(2, 50, 0, buf);

  sprintf(buf, "charge:%dmA", charge);
  ucg.drawString(2, 60, 0, buf);

  sprintf(buf, "disCHG:%dmA", discharge);
  ucg.drawString(2, 70, 0, buf);

  sprintf(buf, "temp:%f C", temperature);
  ucg.drawString(2, 80, 0, buf);

  sprintf(buf, "temp:%.1f C", temperature);
  ucg.setPrintPos(2, 90);
  ucg.print("watt:");
  ucg.print(bat_mw, 3);
  ucg.print("mW");

  ucg.setPrintPos(85, 40);
  ucg.print("Vin:");
  ucg.print(vbus_v, 2);
  ucg.print("V");

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
  Serial.printf("AXP2 time0: %ld\n", millis() - loop_start);
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

void set_axp_pek() {
  Wire.beginTransmission(0x34);
  Wire.write(0x31); // enable sleep button short press
  Wire.write(0x0C); // 0b00001100
  Wire.endTransmission();
}

void shutdown_axp() {
  Wire.beginTransmission(0x34);
  Wire.write(0x31); // enable sleep button short press
  Wire.write(0x0B);
  Wire.endTransmission();
  delay(100);
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

boolean usb_plugged_in() {
  uint8_t data00 = read_register(AXP192_ADDR, 0x00);
  return data00 & 0b10100000; // 7 bit or 5 bit
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
  Serial.begin(115200);
  rtc.begin();
  rtc.isrunning();
  DateTime now = rtc.now();
  if (now.year() < 2018) {
    Serial.println("RTC need factory reset!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }
  pinMode(BUTTON_HOME, INPUT | PULLUP);
  pinMode(BUTTON_PIN, INPUT | PULLUP);

  attachInterrupt(digitalPinToInterrupt(BUTTON_HOME), homePressed, FALLING);
  // esp_sleep_enable_ext0_wakeup((gpio_num_t)BUTTON_PIN, 0);
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
  now.format(buf);
  // Serial.printf("time now: %s\n", buf);
  ucg.setColor(255, 255, 255);
  ucg.drawString(40, 100, 0, buf);
}

unsigned long active_time = millis();

void loop(void) {
  unsigned long loop_start = millis();
  ucg.setRotate90();
  Serial.printf("time-1: %ld\n", millis() - loop_start);
  draw_background();
  Serial.printf("time0: %ld\n", millis() - loop_start);
  readAXP();
  Serial.printf("time1: %ld\n", millis() - loop_start);
  drawAXP2();
  Serial.printf("time2: %ld\n", millis() - loop_start);
  show_time();
  Serial.printf("time3: %ld\n", millis() - loop_start);
  ucg.setMaxClipRange();
  if (usb_plugged_in()) {
    // won't go so sleep when usb
    active_time = loop_start;
  }
  if (need_shutdown || loop_start - active_time > 30 * 1000) {
    // shutdown_all_except_self();
    set_axp_pek();
    shutdown_axp();
    Serial.println("\r\nGoing to sleep now\r\n");
    // esp_deep_sleep_start();
    Serial.println("This will never be printed");
  }
  DLY();
}
