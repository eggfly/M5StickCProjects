
void setup() {
  Serial.begin(115200);
}

uint8_t buf[1070];

void loop() {
  while (Serial.available() > 0) {
    size_t count = Serial.readBytes(buf, sizeof(buf));
    Serial.printf("count: %d, sizeof: %d\r\n", count, sizeof(buf));
  }
}
