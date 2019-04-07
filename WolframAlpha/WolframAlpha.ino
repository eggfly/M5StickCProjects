#include <WiFi.h>

#include <SPI.h>
#include <Wire.h>

#include "src/Lcd_Driver.h"

#include "src/Adafruit_GFX/Adafruit_GFX.h"
#include "src/Adafruit_GFX/ext_canvas.h"
#include "src/Adafruit_GFX/config.h"

#define TFT_MOSI      15
#define TFT_CLK       13
#define TFT_CS        5   // Chip select line for TFT display on Shield
#define TFT_DC        23  // Data/command line for TFT on Shield
#define TFT_RST       18  // Reset line for TFT is handled by seesaw!

GFXcanvas24 canvas = GFXcanvas24(LCD_WIDTH, LCD_HEIGHT);

const char* ssid     = "MIWIFI8";
const char* password = "12345678";

const char* host = "www.baidu.com";


#define VIDEO_WIDTH 104
#define VIDEO_HEIGHT 78

uint8_t _data[VIDEO_WIDTH * VIDEO_HEIGHT * 3];

#define ST77XX_BLACK      0x000000
#define ST77XX_WHITE      0xFFFFFF
#define ST77XX_RED        0xFF0000
#define ST77XX_GREEN      0x00FF00
#define ST77XX_BLUE       0x0000FF
#define ST77XX_CYAN       0x00FFFF
#define ST77XX_MAGENTA    0xFF00FF
#define ST77XX_YELLOW     0xFFFF00
#define ST77XX_ORANGE     0xFFA500

void setup() {
  Wire.begin();
  Serial.begin(115200);
  delay(10);

  pinMode(TFT_MOSI, OUTPUT);
  pinMode(TFT_CLK, OUTPUT);
  pinMode(TFT_CS, OUTPUT);
  pinMode(TFT_DC, OUTPUT);
  pinMode(TFT_RST, OUTPUT);

  digitalWrite(TFT_CS, LOW);

  SPI.begin (TFT_CLK, -1, TFT_MOSI, -1);
  SPI.beginTransaction(SPISettings(70000000, MSBFIRST, SPI_MODE0));

  Wire.beginTransmission(0x34);
  Wire.write(0x10);
  Wire.write(0x9f);  //OLED_VPP Enable
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x28);
  Wire.write(0x9f); //Enable LDO2&LDO3, LED&TFT 3.3V
  // Wire.write(0xff); //Enable LDO2&LDO3, LED&TFT 3.3V
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

  Lcd_Init();
  canvas.setRotation(1);

  canvas.fillScreen(0xAAFF0000); // fill screen bg
  sendGRAM();

  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.disconnect(true);  //disconnect form wifi to set new wifi connection
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;


void loop() {
  ++value;

  delay(1000);
  Serial.print("connecting to ");
  Serial.println(host);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  // We now create a URI for the request
  String url = "/";

  Serial.print("Requesting URL: ");
  Serial.println(url);

  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  unsigned long total_bytes = 0;
  unsigned long start_time = millis();
  while (client.available()) {
    int bytes = client.readBytes(_data, sizeof(_data));
    canvas.drawRGBBitmap(30, 1, (uint8_t *)_data, VIDEO_WIDTH, VIDEO_HEIGHT);

    canvas.fillCircle(1, 11, 5, ST77XX_RED);
    canvas.fillCircle(11, 1, 5, ST77XX_GREEN);
    canvas.setCursor(0, 30);
    canvas.setTextColor(0xAAFFFFFF);
    canvas.setTextSize(1);
    canvas.print("Bad");
    canvas.setCursor(0, 40);
    canvas.setTextSize(1);
    canvas.print("Apple");

    sendGRAM();
    total_bytes += bytes;
    unsigned long current = millis();
    Serial.printf("%d Bytes data read! total bytes: %ld, speed: %lf KB/s\n", bytes, total_bytes, total_bytes * 1000.0 / (current - start_time) / 1024.0);
  }

  Serial.println();
  Serial.println("closing connection");
}


void sendGRAM() {
  Lcd_pic(canvas.getBuffer(), GRAM_BUFFER_SIZE);
}
