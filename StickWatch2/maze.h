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
#define ball_r                 3

#define calculated_sensitivity (delta_t_ms / 100.0 * acc_sensitivity)

typedef struct {
  double x;
  double y;
  double vx;
  double vy;
} maze_ball;

maze_ball m_ball = {
  .x = SCREEN_WIDTH / 2,
  .y = SCREEN_HEIGHT / 2,
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

void page_maze() {
  // canvas.setRotation(1);
  canvas.fillScreen(ST77XX_BLACK);
  canvas.fillCircle(m_ball.x, m_ball.y, ball_r, ST77XX_RED);
  double friction_coefficient = 0.99;
  double collision_coefficient = 0.7;
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
    // collision detection
    if ((limit_left(&m_ball, 0) && m_ball.vx < 0)
        || (limit_right(&m_ball, SCREEN_WIDTH) && m_ball.vx > 0)) {
      Serial.printf("collision x! %f", m_ball.vx);
      m_ball.vx = -m_ball.vx * collision_coefficient;
      Serial.printf(", %f\r\n", m_ball.vx);
    }
    if ((limit_top(&m_ball, 0) && m_ball.vy < 0)
        || (limit_bottom(&m_ball, SCREEN_HEIGHT) && m_ball.vy > 0)) {
      Serial.printf("collision y! %f", m_ball.vy);
      m_ball.vy = -m_ball.vy * collision_coefficient;
      Serial.printf(", %f\r\n", m_ball.vy);
    }
    Serial.printf("-acc=(%d, %d), d_acc=(%f, %f), v=(%f, %f), pos=(%f, %f)\r\n",
                  -acc_y, -acc_x, d_acc_x, d_acc_y,  m_ball.vx, m_ball.vy, m_ball.x, m_ball.y);
    // force of friction
    m_ball.vx *= friction_coefficient;
    m_ball.vy *= friction_coefficient;
    last_acc_sample_time = millis();
  }
  sendGRAM();
}

#endif // _MAZE_H
