
#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>
#include "power.h"
#include "lcd.h"

#define USE_SERIAL Serial

#define WIFI_SSID "your_wifi"
#define WIFI_PASSWORD "your_password"

int BUTTON_HOME = 37;

WiFiMulti wifiMulti;

#define SCREEN_WIDTH   160
#define SCREEN_HEIGHT   80
#define IMAGE_MAX_SIZE  (SCREEN_WIDTH * SCREEN_HEIGHT * 3)
uint8_t image_data[IMAGE_MAX_SIZE] = { 0 };

void setup() {
  init_power();
  lcd_init();
  USE_SERIAL.begin(115200);
  USE_SERIAL.println();
  for (uint8_t t = 4; t > 0; t--) {
    USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
    USE_SERIAL.flush();
    delay(1000);
  }
  int r = WiFi.disconnect(true);  //disconnect form wifi to set new wifi connection
  wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);
  pinMode(BUTTON_HOME, INPUT | PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_HOME), home_isr, FALLING);
}

String query = "lim ((x+h)^5 - x^5)/h as h->0";
// sin(x)dx
// Poisson distribution
// Xiaomi
// plot 1+x-(x^2(1-sqrt(7)x^2)^2)^(1/3)
// d^2(x*ln(x)+cos(x))/dx^2
// C60
// CO2
// H2O
// solve a x^2 + b x + c = 0 for x
// solve x^2 + 4x + 6 = 0
// integrate sin x dx from x=0 to pi
// derivative of x^4 sin x
// d/dx x^2 y^4, d/dy x^2 y^4
// annulus, inner radius=2, outer radius=5  ----- 90
// plot e^x from x=0 to 10 ---- 50
// cone ---- 50
// tetrahedron -- 90
// platinum image -- 90
// simplify x^5-20x^4+163x^3-676x^2+1424x-1209 --- 化简 100
// int sinx/x dx, x=0..infinity -- 定积分 100
// sphere, surface area=1 ----球 100
// truncated icosahedron -- 截角二十面体 100
// great rhombicosidodecahedron --- 大斜方截半二十面体 120
// structure of aspirin -- 阿斯匹林结构 120
// Structure diagram of H2SO4 -- 硫酸分子结构 120
// 3d structure of H2SO4 -- 硫酸3D结构 120
// 3d structure of benzene -- 苯3D结构 110
// 3d structure of C60 -- 碳60的3D结构 100
// 3d of insulin -- 胰岛素3D结构 100
// H Periodic table location -- H元素 位置
// Photo of Linkin Park -- Linkin Park照片
void loop() {
  if (query.length() <= 0) {
    USE_SERIAL.println("[Debug] waiting for query from serial..");
    query = Serial.readStringUntil('\n');
    query.trim();
  } else {
    USE_SERIAL.println("[Debug] Query: " + query);
    USE_SERIAL.println("[HTTP] ENCODED " + urlencode(query));
    // wait for WiFi connection
    if ((wifiMulti.run() == WL_CONNECTED)) {
      HTTPClient http;
      USE_SERIAL.print("[HTTP] begin...\n");

      canvas.fillScreen(0xAAFFFFFF); // fill screen bg
      sendGRAM();
      String url = "http://music.kagura.space/watch/query/?t=" + String(millis()) + "&i=" + urlencode(query);
      http.begin(url);

      USE_SERIAL.println("[HTTP] GET " + url);
      // start connection and send HTTP header
      unsigned long request_start_time = millis();
      http.setTimeout(12 * 1000);
      const char * headerKeys[] = {
        "X-Image-Width", "X-Image-Height", "X-Image-X", "X-Image-Y", "X-Image-Title"
      };
      size_t headerKeySize = sizeof(headerKeys) / sizeof(char*);
      http.collectHeaders(headerKeys, headerKeySize);
      int httpCode = http.GET();
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);
        // file found at server
        if (httpCode == HTTP_CODE_OK) {
          for (int i = 0; i < http.headers(); i++) {
            Serial.println(http.header(i));
          }
          const char * image_width_str = http.header("X-Image-Width").c_str();
          int image_width = atoi(image_width_str);
          const char * image_height_str = http.header("X-Image-Height").c_str();
          int image_height = atoi(image_height_str);
          const char * image_x_str = http.header("X-Image-X").c_str();
          int image_x = atoi(image_x_str);
          const char * image_y_str = http.header("X-Image-Y").c_str();
          int image_y = atoi(image_y_str);
          USE_SERIAL.printf("[Debug] width=%d, height=%d, x=%d, y=%d\n", image_width, image_height, image_x, image_y);

          // get lenght of document (is -1 when Server sends no Content-Length header)
          size_t len = http.getSize();
          USE_SERIAL.printf("[HTTP] Content-Length: %d\n", len);
          // create buffer for read
          // get tcp stream
          WiFiClient * stream = http.getStreamPtr();
          // read all data from server
          int total = 0;
          while (http.connected() && (len > 0 || len == -1)) {
            // get available data size
            size_t available_size = stream->available();
            if (available_size) {
              USE_SERIAL.printf("[HTTP] total: %d, available_size: %d\n", total, available_size);
              int c = stream->readBytes(image_data + total, min(len, available_size));
              total += c;
              if (len > 0) {
                len -= c;
              }
            }
            delay(1);
          }
          USE_SERIAL.println();
          USE_SERIAL.print("[HTTP] connection closed or file end.\n");
          unsigned long cost = millis() - request_start_time;
          USE_SERIAL.printf("[HTTP] GET cost: %ld\n", cost);
          // write buffer and send gram
          canvas.fillScreen(0xAAFFFFFF); // fill screen bg
          canvas.drawRGBBitmap(image_x, image_y, image_data, image_width, image_height);
          sendGRAM();
          query = "";
        } else {
          USE_SERIAL.println("[HTTP] Not 200, clear query");
          query = "";
        }
      } else {
        USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();
    } else {
      USE_SERIAL.println("[LOOP] delay...");
      delay(10 * 1000);
    }
  }
}

char specials[] = "$&+,/:;=?@ <>#%{}|\\^~[]`"; /* String containing chars you want encoded */

static char hex_digit(unsigned char c) {
  return "01234567890ABCDEF"[c & 0x0F];
}

char *urlencode(char *dst, const char *src) {
  char c, *d = dst;
  while (c = *src++) {
    if (strchr(specials, c)) {
      *d++ = '%';
      *d++ = hex_digit(c >> 4);
      *d++ = hex_digit(c);
    }
    else *d++ = c;
  }
  return dst;
}

String urlencode(String str) {
  String encodedString = "";
  char c;
  char code0;
  char code1;
  char code2;
  for (int i = 0; i < str.length(); i++) {
    c = str.charAt(i);
    if (c == ' ') {
      encodedString += '+';
    } else if (!strchr(specials, c)) {
      encodedString += c;
    } else {
      code1 = (c & 0xf) + '0';
      if ((c & 0xf) > 9) {
        code1 = (c & 0xf) - 10 + 'A';
      }
      c = (c >> 4) & 0xf;
      code0 = c + '0';
      if (c > 9) {
        code0 = c - 10 + 'A';
      }
      code2 = '\0';
      encodedString += '%';
      encodedString += code0;
      encodedString += code1;
      //encodedString+=code2;
    }
    yield();
  }
  return encodedString;
}

unsigned long last_isr_time;
#define ISR_DITHERING_TIME_MS 10

// 中断函数
void home_isr() {
  if (millis() - last_isr_time < ISR_DITHERING_TIME_MS) {
    return;
  }
  last_isr_time = millis();
}
