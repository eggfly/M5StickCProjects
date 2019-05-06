#ifndef _FLAPPY_BIRD_H
#define _FLAPPY_BIRD_H

#include "config.h"
#include "lcd.h"

#include <Preferences.h>

Preferences preferences;

#define TFTW            80     // screen width
#define TFTH            160     // screen height
#define TFTW2           40     // half screen width
#define TFTH2           80     // half screen height
// game constant
#define SPEED             1
#define GRAVITY         9.8
#define JUMP_FORCE      1.8
#define SKIP_TICKS     20.0     // 1000 / 50fps
#define MAX_FRAMESKIP     5
// bird size
#define BIRDW             8     // bird width
#define BIRDH             8     // bird height
#define BIRDW2            4     // half width
#define BIRDH2            4     // half height
// pipe size
#define PIPEW            10     // pipe width
#define GAPHEIGHT        38     // pipe gap height
// floor size
#define FLOORH           40     // floor height (from bottom of the screen)
// grass size
#define GRASSH            6     // grass height (inside floor, starts at floor y)

unsigned int maxScore = 0;
const int buttonPin = 2;
// background
const unsigned int BCKGRDCOL =  (138 << 16) + ( 235 << 8) + 244;
// bird
const unsigned int BIRDCOL = (255 << 16) + ( 254 << 8) + 174;
// pipe
const unsigned int PIPECOL  =  (99 << 16) + ( 255 << 8) + 78;
// pipe highlight
const unsigned int PIPEHIGHCOL  =  (250 << 16) + ( 255 << 8) + 250;
// pipe seam
const unsigned int PIPESEAMCOL  = 0;
// floor
const unsigned int FLOORCOL =  (246 << 16) + ( 240 << 8) + 163;
// grass (col2 is the stripe color)
const unsigned int GRASSCOL  =  (141 << 16) + ( 225 << 8) + 87;
const unsigned int GRASSCOL2 =  (156 << 16) + ( 239 << 8) + 88;

// bird sprite
// bird sprite colors (Cx name for values to keep the array readable)
#define C0 BCKGRDCOL
#define C1 ((195<<16)+(165<<8)+75)
#define C2 BIRDCOL
#define C3 ST77XX_WHITE
#define C4 ST77XX_RED
#define C5 ((251<<16)+(216<<8)+114)

static unsigned int birdcol[] =
{ C0, C0, C1, C1, C1, C1, C1, C0, C0, C0, C1, C1, C1, C1, C1, C0,
  C0, C1, C2, C2, C2, C1, C3, C1, C0, C1, C2, C2, C2, C1, C3, C1,
  C0, C2, C2, C2, C2, C1, C3, C1, C0, C2, C2, C2, C2, C1, C3, C1,
  C1, C1, C1, C2, C2, C3, C1, C1, C1, C1, C1, C2, C2, C3, C1, C1,
  C1, C2, C2, C2, C2, C2, C4, C4, C1, C2, C2, C2, C2, C2, C4, C4,
  C1, C2, C2, C2, C1, C5, C4, C0, C1, C2, C2, C2, C1, C5, C4, C0,
  C0, C1, C2, C1, C5, C5, C5, C0, C0, C1, C2, C1, C5, C5, C5, C0,
  C0, C0, C1, C5, C5, C5, C0, C0, C0, C0, C1, C5, C5, C5, C0, C0
};

// bird structure
static struct BIRD {
  long x, y, old_y;
  long col;
  float vel_y;
} bird;

// pipe structure
static struct PIPES {
  long x, gap_y;
  long col;
} pipes;

// score
unsigned int score;
// temporary x and y var
static short tmpx, tmpy;

// ---------------
// draw pixel
// ---------------
// faster drawPixel method by inlining calls and using setAddrWindow and pushColor
// using macro to force inlining
// #define drawPixel(a, b, c) M5.Lcd.setAddrWindow(a, b, a, b); M5.Lcd.pushColor(c)
// ---------------
// game loop
// ---------------
void game_loop() {
  // ===============
  // prepare game variables
  // draw floor
  // ===============
  // instead of calculating the distance of the floor from the screen height each time store it in a variable
  unsigned char GAMEH = TFTH - FLOORH;
  // draw the floor once, we will not overwrite on this area in-game
  // black line
  canvas.drawFastHLine(0, GAMEH, TFTW, ST77XX_BLACK);
  // grass and stripe
  canvas.fillRect(0, GAMEH + 1, TFTW2, GRASSH, GRASSCOL);
  canvas.fillRect(TFTW2, GAMEH + 1, TFTW2, GRASSH, GRASSCOL2);
  // black line
  canvas.drawFastHLine(0, GAMEH + GRASSH, TFTW, ST77XX_BLACK);
  // mud
  canvas.fillRect(0, GAMEH + GRASSH + 1, TFTW, FLOORH - GRASSH, FLOORCOL);
  // grass x position (for stripe animation)
  long grassx = TFTW;
  // game loop time variables
  double delta, old_time, next_game_tick, current_time;
  next_game_tick = current_time = millis();
  int loops;
  // passed pipe flag to count score
  bool passed_pipe = false;
  // temp var for setAddrWindow
  unsigned char px;
  unsigned char bpx;
  sendGRAM();

  while (1) {
    loops = 0;
    while ( millis() > next_game_tick && loops < MAX_FRAMESKIP) {
      if (digitalRead(BUTTON_HOME) == LOW) {
        if (bird.y > BIRDH2 * 0.5) bird.vel_y = -JUMP_FORCE;
        // else zero velocity
        else bird.vel_y = 0;
      }

      // ===============
      // update
      // ===============
      // calculate delta time
      // ---------------
      old_time = current_time;
      current_time = millis();
      delta = (current_time - old_time) / 1000;

      // bird
      // ---------------
      bird.vel_y += GRAVITY * delta;
      bird.y += bird.vel_y;

      // pipe
      // ---------------

      pipes.x -= SPEED;
      // if pipe reached edge of the screen reset its position and gap
      if (pipes.x < -PIPEW) {
        pipes.x = TFTW;
        pipes.gap_y = random(10, GAMEH - (10 + GAPHEIGHT));
      }

      // ---------------
      next_game_tick += SKIP_TICKS;
      loops++;
    }

    // ===============
    // draw
    // ===============
    // pipe
    // ---------------
    // we save cycles if we avoid drawing the pipe when outside the screen

    if (pipes.x >= 0 && pipes.x < TFTW) {
      // pipe color
      canvas.drawFastVLine(pipes.x + 3, 0, pipes.gap_y, PIPECOL);
      canvas.drawFastVLine(pipes.x + 3, pipes.gap_y + GAPHEIGHT + 1, GAMEH - (pipes.gap_y + GAPHEIGHT + 1), PIPECOL);
      // highlight
      canvas.drawFastVLine(pipes.x, 0, pipes.gap_y, PIPEHIGHCOL);
      canvas.drawFastVLine(pipes.x, pipes.gap_y + GAPHEIGHT + 1, GAMEH - (pipes.gap_y + GAPHEIGHT + 1), PIPEHIGHCOL);
      // bottom and top border of pipe
      canvas.drawPixel(pipes.x, pipes.gap_y, PIPESEAMCOL);
      canvas.drawPixel(pipes.x, pipes.gap_y + GAPHEIGHT, PIPESEAMCOL);
      // pipe seam
      canvas.drawPixel(pipes.x, pipes.gap_y - 6, PIPESEAMCOL);
      canvas.drawPixel(pipes.x, pipes.gap_y + GAPHEIGHT + 6, PIPESEAMCOL);
      canvas.drawPixel(pipes.x + 3, pipes.gap_y - 6, PIPESEAMCOL);
      canvas.drawPixel(pipes.x + 3, pipes.gap_y + GAPHEIGHT + 6, PIPESEAMCOL);
    }
#if 1
    // erase behind pipe
    if (pipes.x <= TFTW)
      canvas.drawFastVLine(pipes.x + PIPEW, 0, GAMEH, BCKGRDCOL);
    // PIPECOL
#endif
    // bird
    // ---------------
    tmpx = BIRDW - 1;
    do {
      px = bird.x + tmpx + BIRDW;
      // clear bird at previous position stored in old_y
      // we can't just erase the pixels before and after current position
      // because of the non-linear bird movement (it would leave 'dirty' pixels)
      tmpy = BIRDH - 1;
      do {
        canvas.drawPixel(px, bird.old_y + tmpy, BCKGRDCOL);
      } while (tmpy--);
      // draw bird sprite at new position
      tmpy = BIRDH - 1;
      do {
        canvas.drawPixel(px, bird.y + tmpy, birdcol[tmpx + (tmpy * BIRDW)]);
      } while (tmpy--);
    } while (tmpx--);
    // save position to erase bird on next draw
    bird.old_y = bird.y;

    // grass stripes
    // ---------------
    grassx -= SPEED;
    if (grassx < 0) grassx = TFTW;
    canvas.drawFastVLine( grassx    % TFTW, GAMEH + 1, GRASSH - 1, GRASSCOL);
    canvas.drawFastVLine((grassx + 64) % TFTW, GAMEH + 1, GRASSH - 1, GRASSCOL2);

    // ===============
    // collision
    // ===============
    // if the bird hit the ground game over
    if (bird.y > GAMEH - BIRDH) {
      sendGRAM();
      break;
    }
    // checking for bird collision with pipe
    if (bird.x + BIRDW >= pipes.x - BIRDW2 && bird.x <= pipes.x + PIPEW - BIRDW) {
      // bird entered a pipe, check for collision
      if (bird.y < pipes.gap_y || bird.y + BIRDH > pipes.gap_y + GAPHEIGHT) {
        sendGRAM();
        break;
      }
      else passed_pipe = true;
    }
    // if bird has passed the pipe increase score
    else if (bird.x > pipes.x + PIPEW - BIRDW && passed_pipe) {
      passed_pipe = false;
      // erase score with background color
      canvas.setTextColor(BCKGRDCOL);
      canvas.setCursor( TFTW2, 4);
      canvas.print(score);
      // set text color back to white for new score
      canvas.setTextColor(ST77XX_WHITE);
      // increase score since we successfully passed a pipe
      score++;
    }

    // update score
    // ---------------
    canvas.setCursor( 2, 4);
    canvas.print(score);
    sendGRAM();
  }

  // add a small delay to show how the player lost
  delay(1200);
}

void game_init() {
  // clear screen
  canvas.fillScreen(BCKGRDCOL);
  sendGRAM();
  // reset score
  score = 0;
  // init bird
  bird.x = 30;
  bird.y = bird.old_y = TFTH2 - BIRDH;
  bird.vel_y = -JUMP_FORCE;
  tmpx = tmpy = 0;
  // generate new random seed for the pipe gape
  randomSeed(analogRead(0));
  // init pipe
  pipes.x = 0;
  pipes.gap_y = random(20, TFTH - 60);
}

// ---------------
// game start
// ---------------
void game_start() {
  canvas.fillScreen(ST77XX_BLACK);
  canvas.fillRect(0, TFTH2 - 10, TFTW, 1, ST77XX_WHITE);
  canvas.fillRect(0, TFTH2 + 15, TFTW, 1, ST77XX_WHITE);
  canvas.setTextColor(ST77XX_WHITE);
  canvas.setTextSize(1);
  // half width - num char * char width in pixels
  canvas.setCursor( TFTW2 - 15, TFTH2 - 6);
  canvas.println("FLAPPY");
  canvas.setTextSize(1);
  canvas.setCursor( TFTW2 - 15, TFTH2 + 6);
  canvas.println("-BIRD-");
  canvas.setTextSize(1);
  canvas.setCursor( 15, TFTH2 - 21);
  canvas.println("M5StickC");
  canvas.setCursor( TFTW2 - 40, TFTH2 + 21);
  canvas.println("please press home");
  sendGRAM();
  while (1) {
    // wait for push button
    if (digitalRead(BUTTON_HOME) == LOW) {
      while (digitalRead(BUTTON_HOME) == LOW);
      break;
    }

  }
  // init game settings
  game_init();
}

void EEPROM_Read(unsigned int *num) {
  *num = preferences.getUInt("max_score", 0);
  Serial.printf("read eeprom, value: %d\n", *num);
}

void EEPROM_Write(unsigned int *num) {
  preferences.putUInt("max_score", *num);
  Serial.printf("write eeprom, value: %d\n",  *num);
}

// ---------------
// game over
// ---------------
void game_over() {
  canvas.fillScreen(ST77XX_BLACK);
  EEPROM_Read(&maxScore);
  canvas.setTextColor(ST77XX_RED);
  if (score > maxScore) {
    EEPROM_Write(&score);
    maxScore = score;
    canvas.setTextSize(1);
    canvas.setCursor( 0, TFTH2 - 16);
    canvas.print("NEW HIGHSCORE");
  }
  canvas.setTextSize(1);
  // half width - num char * char width in pixels
  canvas.setCursor( TFTW2 - 25, TFTH2 - 6);
  canvas.print("GAME OVER");
  canvas.setTextSize(1);
  canvas.setCursor( 1, 10);
  canvas.print("score: ");
  canvas.print(score);
  canvas.setCursor( 5, TFTH2 + 6);
  canvas.print("press button");
  canvas.setCursor( 1, 21);
  canvas.print("Max Score:");
  canvas.print(maxScore);

  sendGRAM();
  while (1) {
    // wait for push button
    if (digitalRead(BUTTON_HOME) == LOW) {
      while (digitalRead(BUTTON_HOME) == LOW);
      break;
    }
  }
  Serial.printf("game_over 8\n");
}

void readMaxScore() {
  EEPROM_Read(&maxScore);
  Serial.printf("max score before: %d\n", maxScore);
}

void flappy_bird_dead_loop() {
  while (1) {
    game_start();
    game_loop();
    game_over();
  }
}

void page_flappy_bird() {
  canvas.setRotation(2);
  preferences.begin("flappy-bird", false);
  readMaxScore();
  flappy_bird_dead_loop();
}

#endif // _FLAPPY_BIRD_H
