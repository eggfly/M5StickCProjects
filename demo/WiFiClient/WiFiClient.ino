/*
    This sketch sends data via HTTP GET requests to data.sparkfun.com service.

    You need to get streamId and privateKey at data.sparkfun.com and paste them
    below. Or just customize this script to talk to other HTTP servers.

*/

#include <WiFi.h>

const char* ssid     = "MIWIFI8";
const char* password = "12345678";

const char* host = "192.168.31.233";

void setup()
{
  Serial.begin(115200);
  delay(10);

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

byte _data[32 * 1024];

void loop() {
  ++value;

  delay(1000);
  Serial.print("connecting to ");
  Serial.println(host);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 8000;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  // We now create a URI for the request
  String url = "/genymotion-3.0.0.dmg";

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
    total_bytes += bytes;
    unsigned long current = millis();
    Serial.printf("%d Bytes data read! total bytes: %ld, speed: %lf KB/s\n", bytes, total_bytes, total_bytes * 1000.0 / (current - start_time) / 1024.0);
  }

  Serial.println();
  Serial.println("closing connection");
}
