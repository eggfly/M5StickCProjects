#ifndef _EXT_CANVAS_H
#define _EXT_CANVAS_H

#include "Adafruit_GFX.h"

///  A GFX 24-bit canvas context for graphics
class GFXcanvas24 : public Adafruit_GFX {
 public:
  GFXcanvas24(uint16_t w, uint16_t h);
  ~GFXcanvas24(void);
  void      drawPixel(int16_t x, int16_t y, uint32_t color),
            fillScreen(uint32_t color);
  uint8_t *getBuffer(void);
 private:
  uint8_t *buffer;
};

#endif // _EXT_CANVAS_H
