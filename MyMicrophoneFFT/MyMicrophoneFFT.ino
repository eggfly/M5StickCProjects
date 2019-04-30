#include "config.h"
#include "power.h"
#include "lcd.h"

#include <driver/i2s.h>
#include <math.h>

#include "src/arduinoFFT/arduinoFFT.h"

arduinoFFT FFT = arduinoFFT(); /* Create FFT object */

#define SAMPLES 256 // must be 2^n

double vReal[SAMPLES];
double vImag[SAMPLES];

#define SCL_INDEX 0x00
#define SCL_TIME 0x01
#define SCL_FREQUENCY 0x02
#define SCL_PLOT 0x03

#define PIN_CLK 0
#define PIN_DATA 34
#define READ_LEN (2 * SAMPLES)
#define SAMPLE_RATE 44100

uint8_t BUFFER[READ_LEN] = {0};
int16_t *adcBuffer = (int16_t *)BUFFER;

void i2sInit() {
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX | I2S_MODE_PDM),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample =
    I2S_BITS_PER_SAMPLE_16BIT,  // is fixed at 12bit, stereo, MSB
    .channel_format = I2S_CHANNEL_FMT_ALL_RIGHT,
    .communication_format = I2S_COMM_FORMAT_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 2,
    .dma_buf_len = 128,
  };

  i2s_pin_config_t pin_config;
  pin_config.bck_io_num = I2S_PIN_NO_CHANGE;
  pin_config.ws_io_num = PIN_CLK;
  pin_config.data_out_num = I2S_PIN_NO_CHANGE;
  pin_config.data_in_num = PIN_DATA;

  i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM_0, &pin_config);
  i2s_set_clk(I2S_NUM_0, SAMPLE_RATE, I2S_BITS_PER_SAMPLE_16BIT, I2S_CHANNEL_MONO);
}

void setup() {
  Serial.begin(115200);
  while (!Serial);
  init_power();
  lcd_init();
  i2sInit();
}

void loop() {
  int bytes = i2s_read_bytes(I2S_NUM_0, (char *)BUFFER, READ_LEN, (100 / portTICK_RATE_MS));
  for (uint16_t i = 0; i < SAMPLES; i++) {
    vReal[i] = adcBuffer[i];
    /* Build data with positive and negative values */
    vImag[i] = 0.0; //Imaginary part must be zeroed in case of looping to avoid wrong calculations and overflows
  }

  FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);  /* Weigh data */
  FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD); /* Compute FFT */
  FFT.ComplexToMagnitude(vReal, vImag, SAMPLES); /* Compute magnitudes */
  // PrintVector(vReal, samples >> 1, SCL_PLOT);
  // double x = FFT.MajorPeak(vReal, SAMPLES, SAMPLE_RATE);

  // clear screen
  canvas.fillScreen(ST77XX_BLACK);
  if (bytes) {
    for (int i = 1; i < min(160, SAMPLES >> 1); i++) {
      double value = vReal[i] / 80;
      canvas.drawPixel(i, 78 - int(value), ST77XX_GREEN);
      // Serial.println(value, 4);
      // display.drawLine(i * 2 + x, ylim, i * 2 + x, ylim - dat, WHITE); // draw bar graphics for freqs above 500Hz to buffer
    };
    sendGRAM();
    //Serial.print("---- show in screen, bytes=");
    //Serial.println(bytes);
    delay(20);
  } else {
    //Serial.println("---- error reading data ----");
  }
  // Serial.println("--------");
}
