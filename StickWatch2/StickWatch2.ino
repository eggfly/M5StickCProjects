
#include "config.h"
#include "app_nvs.h"
#include "res.h"
#include "imu.h"
#include "power.h"
#include "battery.h"
#include "axp.h"
#include "lcd.h"
#include "rtc.h"
#include "math.h"
#include "3d.h"
#include "flappy_bird.h"

#include <string.h>
#include <assert.h>
#include "esp_partition.h"
#include "esp_log.h"

// static const char *TAG = "app";

#define calibration_x 19
#define calibration_y 0

#define sensitivity_x 1.9
#define sensitivity_y 1.2

#define level_calibration_y 14


const uint32_t COLORS_LIGHT[10] = {
  0xff4aad, 0x0e88fe, 0xcc03fc, 0xfe49ad, 0xff0505,
  0xfa660d, 0xfff800, 0x14fa00, 0x0496ff, 0xc900ff
};

const uint32_t COLORS_DARK[10] = {
  0x471f32, 0x002548, 0x3b004b, 0x3e1a2c, 0x4a000c,
  0x4a1e00, 0x4b4500, 0x004700, 0x022242, 0x380249
};

// End of constructor list

int stateA = 0;

//int BUTTON_HOME = 34;
RTC_DATA_ATTR int bootCount = 0;

void print_wakeup_reason() {
  esp_sleep_wakeup_cause_t wakeup_reason;
  wakeup_reason = esp_sleep_get_wakeup_cause();
  switch (wakeup_reason) {
    case 1  : Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    case 2  : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
    case 3  : Serial.println("Wakeup caused by timer"); break;
    case 4  : Serial.println("Wakeup caused by touchpad"); break;
    case 5  : Serial.println("Wakeup caused by ULP program"); break;
    default : Serial.println("Wakeup was not caused by deep sleep"); break;
  }
}


void show_time() {
  now = rtc.now();
  now.hour();
  char buf[100];
  strncpy(buf, "YYYY.MM.DD hh:mm:ss\0", 100);
  now.format(buf);
  // Serial.printf("time now: %s\n", buf);

  canvas.setCursor(28, 70);
  canvas.setTextColor(0xAAFFFFFF);
  canvas.print(buf);
}
// Get the string name of type enum values used in this example
static const char* get_type_str(esp_partition_type_t type)
{
  switch (type) {
    case ESP_PARTITION_TYPE_APP:
      return "ESP_PARTITION_TYPE_APP";
    case ESP_PARTITION_TYPE_DATA:
      return "ESP_PARTITION_TYPE_DATA";
    default:
      return "UNKNOWN_PARTITION_TYPE"; // type not used in this example
  }
}

// Get the string name of subtype enum values used in this example
static const char* get_subtype_str(esp_partition_subtype_t subtype) {
  switch (subtype) {
    case ESP_PARTITION_SUBTYPE_DATA_NVS:
      return "ESP_PARTITION_SUBTYPE_DATA_NVS";
    case ESP_PARTITION_SUBTYPE_DATA_PHY:
      return "ESP_PARTITION_SUBTYPE_DATA_PHY";
    case ESP_PARTITION_SUBTYPE_APP_FACTORY:
      return "ESP_PARTITION_SUBTYPE_APP_FACTORY";
    case ESP_PARTITION_SUBTYPE_DATA_FAT:
      return "ESP_PARTITION_SUBTYPE_DATA_FAT";
    default:
      return "UNKNOWN_PARTITION_SUBTYPE"; // subtype not used in this example
  }
}

// Find the partition using given parameters
static void find_partition(esp_partition_type_t type, esp_partition_subtype_t subtype, const char* name) {
  ESP_LOGI(TAG, "Find partition with type %s, subtype %s, label %s...", get_type_str(type), get_subtype_str(subtype),
           name == NULL ? "NULL (unspecified)" : name);
  const esp_partition_t * part  = esp_partition_find_first(type, subtype, name);
  ESP_LOGI(TAG, "\tfound partition '%s' at offset 0x%x with size 0x%x", part->label, part->address, part->size);
}

void dump_partitions() {

  /*
    This example uses the partition table from ../partitions_example.csv. For reference, its contents are as follows:

     nvs,        data, nvs,      0x9000,  0x6000,
     phy_init,   data, phy,      0xf000,  0x1000,
     factory,    app,  factory,  0x10000, 1M,
     storage1,   data, fat,             , 0x40000,
     storage2,   data, fat,             , 0x40000,

    Display the partition table to the user for reference.
  */
  //  extern const char csv_start[] asm("_binary_partitions_example_csv_start");
  //  extern const char csv_end[]   asm("_binary_partitions_example_csv_end");
  //
  //  ESP_LOGI(TAG, "Printing partition table csv file contents for reference...\n\n%.*s", csv_end - csv_start + 1, csv_start);

  /* First Part - Finding partitions using esp_partition_find_first. */

  ESP_LOGI(TAG, "----------------Find partitions---------------");

  // Find partitions using esp_partition_find_first(). This returns the first partition matching the passed constraints.
  find_partition(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_DATA_NVS, NULL);
  find_partition(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_DATA_PHY, NULL);
  find_partition(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_FACTORY, NULL);

  find_partition(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_DATA_FAT, NULL);

  ESP_LOGI(TAG, "Find second FAT partition by specifying the label");
  // In case of multiple matches, `esp_partition_find_first` returns the first match.
  find_partition(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_DATA_FAT, "storage2");

  /* Second Part - Iterating over partitions */

  ESP_LOGI(TAG, "----------------Iterate through partitions---------------");

  esp_partition_iterator_t it;

  ESP_LOGI(TAG, "Iterating through app partitions...");
  it = esp_partition_find(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_ANY, NULL);

  // Loop through all matching partitions, in this case, all with the type 'data' until partition with desired
  // label is found. Verify if its the same instance as the one found before.
  for (; it != NULL; it = esp_partition_next(it)) {
    const esp_partition_t *part = esp_partition_get(it);
    ESP_LOGI(TAG, "\tfound partition '%s' at offset 0x%x with size 0x%x", part->label, part->address, part->size);
  }
  // Release the partition iterator to release memory allocated for it
  esp_partition_iterator_release(it);

  ESP_LOGI(TAG, "Iterating through data partitions...");
  it = esp_partition_find(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_ANY, NULL);

  // Loop through all matching partitions, in this case, all with the type 'data' until partition with desired
  // label is found. Verify if its the same instance as the one found before.
  for (; it != NULL; it = esp_partition_next(it)) {
    const esp_partition_t *part = esp_partition_get(it);
    ESP_LOGI(TAG, "\tfound partition '%s' at offset 0x%x with size 0x%x", part->label, part->address, part->size);
  }

  // Release the partition iterator to release memory allocated for it
  esp_partition_iterator_release(it);

  ESP_LOGI(TAG, "Example end");
}

void setup(void) {
  Serial.begin(115200);
  while (!Serial);             // Leonardo: wait for serial monitor

  init_power();
  init_rtc();
  lcd_init();

  axp_print_power();
  // nvs_test();
  // dump_partitions();
  // pinMode(LED_RI, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(BUTTON_HOME, INPUT | PULLUP);
  pinMode(BUTTON_PIN, INPUT | PULLUP);

  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(10);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

  ++bootCount;
  Serial.println("Boot number: " + String(bootCount));

  //Print the wakeup reason for ESP32
  print_wakeup_reason();
  // esp_sleep_enable_ext0_wakeup(GPIO_NUM_39, 0);

  attachInterrupt(digitalPinToInterrupt(BUTTON_HOME), home_isr, FALLING);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), button_isr, FALLING);

  sh200i_init();
}

long loopTime, startTime, endTime, fps;

#define PAGE_CLOCK 0
#define PAGE_TIMER 1
#define PAGE_KEYBOARD 2
#define PAGE_ELECTRONIC_LEVEL 3
#define PAGE_AXP_INFO 4
#define PAGE_3D 5
#define PAGE_FLAPPY_BIRD 6

#define PAGE_COUNT 7

int current_page = PAGE_CLOCK;

int cursorX, cursorY;
int clicked_cursor_x = -1, clicked_cursor_y = -1;

void draw_cursor() {
  int times = 1;
  int average_accX = 0, average_accY = 0;
  for (int i = 0; i < times; i++) {
    read_imu();
    average_accX += accX;
    average_accY += accY;
  }
  average_accX /= times;
  average_accY /= times;
  cursorX = 80 + calibration_x - sensitivity_x * average_accY / 50;
  cursorY = 40 + calibration_y - sensitivity_y * average_accX / 50;
  if (cursorX < 0) {
    cursorX = 0;
  } else if (cursorX > 159) {
    cursorX = 159;
  }
  if (cursorY < 0) {
    cursorY = 0;
  } else if (cursorY > 79) {
    cursorY = 79;
  }
  // draw cursor
  canvas.fillCircle(cursorX, cursorY, 1, ST77XX_WHITE);
}


void draw_level() {
  int times = 1;
  int average_accX = 0, average_accY = 0;
  for (int i = 0; i < times; i++) {
    read_imu();
    average_accX += accX;
    average_accY += accY;
  }
  average_accX /= times;
  average_accY /= times;
  cursorX = 80 + calibration_x - sensitivity_x * average_accY / 50;
  cursorY = 40 + calibration_y + level_calibration_y - sensitivity_y * average_accX / 50;
  if (cursorX < 0) {
    cursorX = 0;
  } else if (cursorX > 159) {
    cursorX = 159;
  }
  if (cursorY < 0) {
    cursorY = 0;
  } else if (cursorY > 79) {
    cursorY = 79;
  }

  // draw cursor
  float r_percent = 0.9;
  float r = min(SCREEN_HEIGHT, SCREEN_WIDTH) / 2 * r_percent;
  int dx = cursorX - SCREEN_WIDTH / 2;
  int dy = cursorY - SCREEN_HEIGHT / 2;
  if (dx * dx + dy * dy > r * r) {
    float scale = r / sqrt(dx * dx + dy * dy);
    cursorX = SCREEN_WIDTH / 2 + dx * scale;
    cursorY = SCREEN_HEIGHT / 2 + dy * scale;
  }
  canvas.drawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, r, ST77XX_RED);
  canvas.fillCircle(cursorX, cursorY, 4, ST77XX_GREEN);
}

void draw_menu() {
  canvas.drawRect(0, 0, 33, 11, ST77XX_WHITE);

  canvas.setCursor(2, 2);
  canvas.setTextColor(0xAAFFFFFF);
  canvas.print("Timer");

  canvas.drawRect(35, 0, 35, 11, ST77XX_WHITE);
  canvas.setCursor(38, 2);
  canvas.setTextColor(0xAAFFFFFF);
  canvas.print("Clock");

  canvas.drawRect(36 + 35, 0, 50, 11, ST77XX_WHITE);
  canvas.setCursor(38 + 35, 2);
  canvas.setTextColor(0xAAFFFFFF);
  canvas.print("Keyboard");
}

void page_1_2() {
  show_time();
  loopTime = millis();
  int count = 0;
  if (current_page == PAGE_CLOCK) {
    count = now.hour() * 100 + now.minute();
  } else {
    // 4 digit 100ms counter
    count = (loopTime / 100) % 10000;
  }
  startTime = loopTime;

  int x_start = 6;
  int x_delta = 7;
  int r = 2;
  for (int n = 0; n < 10; n++) {
    // canvas.fillCircle(x_start + x_delta * n, 4, r, COLORS_LIGHT[n]);
  }

  int y2 = 11;
  for (int n = 0; n < 10; n++) {
    // canvas.fillCircle(x_start + x_delta * n, y2, r, COLORS_DARK[n]);
  }

  int y_start = 19;
  for (int pos = 0; pos < 4; pos++) {
    uint8_t curr_digit = 0;
    if (pos == 0) {
      curr_digit = count / 1000;
    } else if (pos == 1) {
      curr_digit = count / 100 % 10;
    } else if (pos == 2) {
      curr_digit = count / 10 % 10;
    } else if (pos == 3) {
      curr_digit = count % 10;
    }
    for (int row = 0; row < 7; row++) {
      for (int col = 0; col < 5; col++) {
        uint32_t color = DIGITS[curr_digit][row][col] ?
                         COLORS_LIGHT[curr_digit] : COLORS_DARK[curr_digit];
        canvas.fillCircle(x_start + col * 7, y_start + row * 7, r, color);
      }
    }
    x_start += 39;
  }
}

char input_text[128] = {};

int keyboard_start_x = 3;
int keyboard_start_y = 33;
int keyboard_offset_x = 5;

int _1_center_x = keyboard_start_x + 2;
int _1_center_y = keyboard_start_y + 3;

double keyboard_x_space = 12.0;
double keyboard_y_space = 12.0;

char keyboard[4][14] = {
  {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', ' '},
  {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'},
  {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', ' ', ' '},
  {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/', ' ', ' ', ' '}
};

void handle_keyboard_click(int x, int y) {
  // calculate y first so that offset is right
  double y_delta_count = (y - _1_center_y) / keyboard_y_space;
  double x_delta_count = (x - _1_center_x - y_delta_count * keyboard_offset_x /* x has some offset */) / keyboard_x_space;
  int xx = int(x_delta_count + 0.5);
  int yy = int(y_delta_count + 0.5);
  char clicked_char = keyboard[yy][xx];
  Serial.printf("debug: y=%lf, x=%lf, char: %c\r\n", y_delta_count, x_delta_count, clicked_char);
  int len = strlen(input_text);
  input_text[len] = clicked_char;
  input_text[len + 1] = '\0';
}

void handle_other_area_click(int x, int y) {
  if (x >= 111 && x <= 124 && y >= 16 && y <= 27) {
    Serial.println("cl clicked");
    input_text[0] = '\0';
  }
  if (x >= 126 && x <= 157 && y >= 16 && y <= 27) {
    Serial.println("<- clicked");
    int len = strlen(input_text);
    if (len > 0) {
      input_text[len - 1] = '\0';
    }
  }
}

void page_keyboard() {
  int input_start_x = 0;
  canvas.drawRect(input_start_x, 15, 110, 13, 0xAAFFFFFF);
  canvas.setTextColor(0xAAFFFFFF);
  // print cl button
  canvas.drawRect(input_start_x + 111, 15, 14, 13, 0xAAFFFFFF);
  canvas.setCursor(input_start_x + 111 + 2, 15 + 2);
  canvas.print("cl");
  // print backspace button
  canvas.drawRect(input_start_x + 112 + 14, 15, 32, 13, 0xAAFFFFFF);
  canvas.setCursor(input_start_x + 112 + 14 + 2, 15 + 2);
  canvas.print("<-");
  // print input text
  canvas.setCursor(input_start_x + 3, 18);
  canvas.print(input_text);

  canvas.setCursor(keyboard_start_x, keyboard_start_y);
  canvas.print("` 1 2 3 4 5 6 7 8 9 0 - =");
  canvas.setCursor(keyboard_start_x + keyboard_offset_x, keyboard_start_y + 12);
  canvas.print("Q W E R T Y U I O P [ ] \\");
  canvas.setCursor(keyboard_start_x + keyboard_offset_x * 2, keyboard_start_y + 24);
  canvas.print("A S D F G H J K L ; '    ");
  canvas.setCursor(keyboard_start_x + keyboard_offset_x * 3, keyboard_start_y + 36);
  canvas.print("Z X C V B N M , . /      ");
  canvas.setTextSize(1);
  if (clicked_cursor_x >= 0 && clicked_cursor_y >= 0) {
    if (clicked_cursor_y > 33) {
      handle_keyboard_click(clicked_cursor_x, clicked_cursor_y);
    } else {
      handle_other_area_click(clicked_cursor_x, clicked_cursor_y);
    }
    clicked_cursor_x = clicked_cursor_y = -1;
  }
}

void page_electronic_level() {
  draw_level();
}

#define GAME_STATE_INIT     0
#define GAME_STATE_PLAYING  1
int game_state = GAME_STATE_INIT;

#define STICK_STILL 0
#define STICK_LEFT  1
#define STICK_RIGHT 2

int game_stick_state = STICK_STILL;

#define STICK_LENGTH_SHORT   25
#define STICK_LENGTH_NORMAL  40
#define STICK_LENGTH_LONG    80

#define STICK_START_Y  72
#define STICK_HEIGHT    3
int stick_length = STICK_LENGTH_NORMAL;

#define BALL_R 2

double stick_pos = 80.0;
double ball_x = 80.0;
double ball_y = STICK_START_Y - BALL_R * 2;
double ball_speed_x = 2.0;
double ball_speed_y = -2.0;

void page_game_old() {
  if (game_state == GAME_STATE_INIT) {
    canvas.setTextSize(2);
    canvas.setTextColor(0xAAFF8888);
    canvas.setCursor(14, 18);
    canvas.print("DxBall Game");
    canvas.setCursor(18, 50);
    canvas.setTextSize(1);
    canvas.setTextColor(0xAAFFFFFF);
    canvas.print("press button to start");
    int arrow_center_x = 77;
    canvas.drawFastVLine(arrow_center_x, 65, 5, 0xAAFFFFFF);
    canvas.fillTriangle(arrow_center_x - 3, 70,
                        arrow_center_x + 3, 70,
                        arrow_center_x, 75, 0xAAFFFFFF);
  } else if (game_state == GAME_STATE_PLAYING) {
    // update stick position
    if (game_stick_state == STICK_LEFT) {
      stick_pos -= 4;
    } else if (game_stick_state == STICK_RIGHT) {
      stick_pos += 4;
    }
    ball_x += ball_speed_x;
    ball_y += ball_speed_y;
    if (ball_x <= BALL_R || ball_x >= SCREEN_WIDTH - BALL_R) {
      ball_speed_x = -ball_speed_x;
      Serial.printf("case 1: %lf\r\n", ball_speed_x);
    } else if (ball_y <= BALL_R || ball_y >= STICK_START_Y - BALL_R) {
      ball_speed_y = -ball_speed_y;
      Serial.printf("case 2: %lf\r\n", ball_speed_y);
    }
    // update ball position
    canvas.fillRect(stick_pos - stick_length / 2 , STICK_START_Y,
                    stick_length, STICK_HEIGHT, 0xAAFF0000);
    canvas.fillCircle(ball_x, ball_y, BALL_R, 0xAA00FF00);
  }
  if (digitalRead(BUTTON_HOME) == 0) {
    // Serial.println("button 1 is down");
    game_button1_pressed();
  } else if (digitalRead(BUTTON_PIN) == 0) {
    // Serial.println("button 2 is down");
    game_button2_pressed();
  } else {
    game_no_button_pressed();
  }
}

void game_button1_pressed() {
  if (game_state == GAME_STATE_PLAYING) {
    game_stick_state = STICK_LEFT;
  }
}

void game_button2_pressed() {
  if (game_state == GAME_STATE_INIT) {
    game_state = GAME_STATE_PLAYING;
  } else if (game_state == GAME_STATE_PLAYING) {
    game_stick_state = STICK_RIGHT;
  }
}

void game_no_button_pressed() {
  if (game_state == GAME_STATE_PLAYING) {
    game_stick_state = STICK_STILL;
  }
}

boolean _3d_inited = false;

void loop(void) {
  canvas.fillScreen(0x00000000); // fill screen bg
  check_update_battery();
  if (current_page == PAGE_CLOCK || current_page == PAGE_TIMER) {
    draw_menu();
    page_1_2();
    draw_cursor();
    draw_battery_percent();
    // send frame then delay
    sendGRAM();
    delay(25); // fps wrong fix
  } else if (current_page == PAGE_KEYBOARD) {
    draw_menu();
    page_keyboard();
    draw_cursor();
    draw_battery_percent();
    // send frame then delay
    sendGRAM();
    delay(25); // fps wrong fix
  } else if (current_page == PAGE_ELECTRONIC_LEVEL) {
    page_electronic_level();
    draw_battery_percent();
    // send frame then delay
    sendGRAM();
    delay(25); // fps wrong fix
  } else if (current_page == PAGE_AXP_INFO) {
    page_axp_info();
    // send frame then delay
    sendGRAM();
    delay(25); // fps wrong fix
  } else if (current_page == PAGE_3D) {
    if (!_3d_inited) {
      init_3d();
      _3d_inited = true;
    }
    page_3d();
  } else if (current_page == PAGE_FLAPPY_BIRD) {
    page_flappy_bird();
  }

  loopTime = millis();
  endTime = loopTime;
  unsigned long delta = endTime - startTime;
  fps = 1000 / delta;
  // Serial.printf("fill+draw+send GRAM cost: %ldms, calc fps:%ld, real fps:%ld\r\n", delta, fps, fps > 60 ? 60 : fps);
}

unsigned long last_isr_time;
#define ISR_DITHERING_TIME_MS 10

// 中断函数
void home_isr() {
  if (millis() - last_isr_time < ISR_DITHERING_TIME_MS) {
    return;
  }
  last_isr_time = millis();
  if (current_page != PAGE_FLAPPY_BIRD) {
    current_page++;
    if (current_page > PAGE_COUNT - 1) {
      current_page = 0;
    }
  }
}

// 中断函数
void button_isr() {
  if (millis() - last_isr_time < ISR_DITHERING_TIME_MS) {
    return;
  }
  last_isr_time = millis();
  if (current_page != PAGE_FLAPPY_BIRD) {
    Serial.printf("cursorX=%d, cursorY=%d\r\n", cursorX, cursorY);
    if (current_page == PAGE_KEYBOARD) {
      clicked_cursor_x = cursorX;
      clicked_cursor_y = cursorY;
    }
  }
}
