#ifndef _MAZE_H
#define _MAZE_H

#include "config.h"
#include "lcd.h"

// actually y
#define maze_calibration_x     0
// actually x
#define maze_calibration_y  (-600)

#define delta_t_ms             10
#define acc_sensitivity        1
#define ball_r                 2

#define friction_coefficient   0.99
#define collision_coefficient  0.7

#define calculated_sensitivity (delta_t_ms / 100.0 * acc_sensitivity)

#define wall_color           ST77XX_GRAY
#define ball_color           ST77XX_RED
#define debug_color          ST77XX_GREEN

typedef struct {
  double x;
  double y;
  double vx;
  double vy;
} maze_ball;

maze_ball m_ball = {
  .x = ball_r + 3, // TODO
  .y = ball_r + 3, // TODO
  .vx = 0,
  .vy = 0
};

boolean limit_left(maze_ball *b, double x) {
  boolean r = b->x <= x + ball_r;
  if (r) {
    b->x = x + ball_r;
  }
  return r;
}

boolean limit_right(maze_ball *b, double x) {
  boolean r = b->x >= x - ball_r;
  if (r) {
    b->x = x - ball_r;
  }
  return r;
}

boolean limit_top(maze_ball *b, double y) {
  boolean r = b->y <= y + ball_r;
  if (r) {
    b->y = y + ball_r;
  }
  return r;
}

boolean limit_bottom(maze_ball *b, double y) {
  boolean r = b->y >= y - ball_r;
  if (r) {
    b->y = y - ball_r;
  }
  return r;
}

long last_acc_sample_time = 0;

typedef struct {
  double start_x;
  double end_x;
  double y;
} h_wall;

typedef struct {
  double x;
  double start_y;
  double end_y;
} v_wall;

// horizontal: x1, x2, y
h_wall maze_h_walls[] = {
  {.start_x = 32, .end_x = 111, .y = 14},
  {.start_x = 17, .end_x = 111, .y = 27},
  {.start_x = 0, .end_x = 32, .y = 40},
  {.start_x = 64, .end_x = 95, .y = 40},
  {.start_x = 110, .end_x = 127, .y = 40},
  {.start_x = 142, .end_x = 159, .y = 40},
  {.start_x = 16, .end_x = 47, .y = 53},
  {.start_x = 64, .end_x = 80, .y = 53},
  {.start_x = 95, .end_x = 110, .y = 53},
  {.start_x = 126, .end_x = 143, .y = 53},
  {.start_x = 0, .end_x = 17, .y = 65},
  {.start_x = 32, .end_x = 64, .y = 65},
  {.start_x = 95, .end_x = 143, .y = 65},
};

// vertical: x, y1, y2
v_wall maze_v_walls[] = {
  {.x = SCREEN_WIDTH / 2, .start_y = SCREEN_HEIGHT / 4, .end_y = SCREEN_HEIGHT * 3 / 4}
};

void draw_maze() {
  int h_count = sizeof(maze_h_walls) / sizeof(h_wall);
  // Serial.printf("h_count=%d\r\n", h_count);
  for (int i = 0; i < h_count; i++) {
    h_wall w = maze_h_walls[i];
    canvas.drawFastHLine(w.start_x, w.y, w.end_x - w.start_x, wall_color);
  }
  int v_count = sizeof(maze_v_walls) / sizeof(v_wall);
  // Serial.printf("v_count=%d\r\n", v_count);
  for (int i = 0; i < v_count; i++) {
    v_wall w = maze_v_walls[i];
    canvas.drawFastVLine(w.x, w.start_y, w.end_y - w.start_y, wall_color);
  }
}

void find_nearest_walls(double x, double y, double *left, double *right, double *top, double *bottom) {
  int h_count = sizeof(maze_h_walls) / sizeof(h_wall);
  int v_count = sizeof(maze_v_walls) / sizeof(v_wall);
  double l = 0, r = SCREEN_WIDTH, t = 0, b = SCREEN_HEIGHT;
  for (int i = 0; i < h_count; i++) {
    h_wall w = maze_h_walls[i];
    if (w.y < y && w.start_x <= x && w.end_x >= x && w.y > t) {
      // found nearer top wall
      t = w.y;
    }
    if (w.y > y && w.start_x <= x && w.end_x >= x && w.y < b) {
      // found nearer bottom wall
      b = w.y;
    }
  }
  for (int i = 0; i < v_count; i++) {
    v_wall w = maze_v_walls[i];
    if (w.x < x && w.start_y <= y && w.end_y >= y && w.x > l) {
      // found nearer left wall
      l = w.x;
    }
    if (w.x > x && w.start_y <= y && w.end_y >= y && w.x < r) {
      // found nearer right wall
      r = w.x;
    }
  }
  Serial.printf("(%.2f, %.2f)'s nearest walls: l=%.2f, r=%.2f, t=%.2f, b=%.2f\r\n", x, y, l, r, t, b);
  // assign result values
  *left = l;
  *right = r;
  *top = t;
  *bottom = b;
}

void page_maze() {
  // canvas.setRotation(1);
  canvas.fillScreen(ST77XX_BLACK);
  canvas.fillCircle(m_ball.x, m_ball.y, ball_r, ball_color);
  draw_maze();
  if (millis() - last_acc_sample_time > delta_t_ms) {
    int16_t acc_x = 0, acc_y = 0;
    read_imu(&acc_x, &acc_y);
    acc_x += maze_calibration_x;
    acc_y += maze_calibration_y;
    // need swap x and y
    double d_acc_x = -acc_y / 1000.0;
    double d_acc_y = -acc_x / 1000.0;
    m_ball.vx += d_acc_x;
    m_ball.vy += d_acc_y;
    m_ball.x += m_ball.vx * calculated_sensitivity;
    m_ball.y += m_ball.vy * calculated_sensitivity;

    double l_wall, r_wall, t_wall, b_wall;
    find_nearest_walls(m_ball.x, m_ball.y, &l_wall, &r_wall, &t_wall, &b_wall);
    canvas.drawPixel(l_wall, m_ball.y, debug_color);
    canvas.drawPixel(m_ball.x, t_wall, debug_color);
    canvas.drawPixel(r_wall, m_ball.y, debug_color);
    canvas.drawPixel(m_ball.x, b_wall, debug_color);

    // collision detection
    if ((limit_left(&m_ball, l_wall) && m_ball.vx < 0)
        || (limit_right(&m_ball, r_wall) && m_ball.vx > 0)) {
      // Serial.printf("collision x! %f", m_ball.vx);
      m_ball.vx = -m_ball.vx * collision_coefficient;
      // Serial.printf(", %f\r\n", m_ball.vx);
    }
    if ((limit_top(&m_ball, t_wall) && m_ball.vy < 0)
        || (limit_bottom(&m_ball, b_wall) && m_ball.vy > 0)) {
      // Serial.printf("collision y! %f", m_ball.vy);
      m_ball.vy = -m_ball.vy * collision_coefficient;
      // Serial.printf(", %f\r\n", m_ball.vy);
    }
    //Serial.printf("-acc=(%d, %d), d_acc=(%f, %f), v=(%f, %f), pos=(%f, %f)\r\n",
    //              -acc_y, -acc_x, d_acc_x, d_acc_y,  m_ball.vx, m_ball.vy, m_ball.x, m_ball.y);
    // force of friction
    m_ball.vx *= friction_coefficient;
    m_ball.vy *= friction_coefficient;
    last_acc_sample_time = millis();
  }
  sendGRAM();
  delay(2);
}

#endif // _MAZE_H
