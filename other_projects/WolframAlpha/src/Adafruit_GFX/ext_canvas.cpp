
#include "ext_canvas.h"
#include "config.h"
#include "Adafruit_GFX.h"


/**************************************************************************/
/*!
   @brief    Instatiate a GFX 16-bit canvas context for graphics
   @param    w   Display width, in pixels
   @param    h   Display height, in pixels
*/
/**************************************************************************/
GFXcanvas24::GFXcanvas24(uint16_t w, uint16_t h) : Adafruit_GFX(w, h) {
    uint32_t bytes = w * h * BYTES_PER_PIXEL;
    if((buffer = (uint8_t *)malloc(bytes))) {
        memset(buffer, 0, bytes);
    }
}

/**************************************************************************/
/*!
   @brief    Delete the canvas, free memory
*/
/**************************************************************************/
GFXcanvas24::~GFXcanvas24(void) {
    if(buffer) free(buffer);
}

/**************************************************************************/
/*!
   @brief    Get a pointer to the internal memory
   @returns  A pointer to the allocated 
*/
/**************************************************************************/
uint8_t* GFXcanvas24::getBuffer(void) {
    return buffer;
}

/**************************************************************************/
/*!
   @brief    Draw a pixel to the canvas 
    @param   x   x coordinate
    @param   y   y coordinate
   @param    color 32-bit ARGB Color to fill with
*/
/**************************************************************************/
void GFXcanvas24::drawPixel(int16_t x, int16_t y, uint32_t color) {
    if(buffer) {
        if((x < 0) || (y < 0) || (x >= _width) || (y >= _height)) return;
        int16_t t;
        switch(rotation) {
            case 1:
                t = x;
                x = WIDTH  - 1 - y;
                y = t;
                break;
            case 2:
                x = WIDTH  - 1 - x;
                y = HEIGHT - 1 - y;
                break;
            case 3:
                t = x;
                x = y;
                y = HEIGHT - 1 - t;
                break;
        }
        uint32_t offset = BYTES_PER_PIXEL * (x + y * WIDTH);
        buffer[offset] = (color >> 16) & 0xFF;
        buffer[offset + 1] = (color>>8) & 0xFF;
        buffer[offset + 2] = color & 0xFF;
    }
}

/**************************************************************************/
/*!
   @brief    Fill the gram completely with one color
    @param    color 32-bit ARGB Color to fill with
*/
/**************************************************************************/
void GFXcanvas24::fillScreen(uint32_t color) {
    if (buffer) {
        uint8_t r = (color >> 16) & 0xFF;
        uint8_t g = (color >> 8) & 0xFF;
        uint8_t b = color & 0xFF;
        if (r == g && g == b) {
            memset(buffer, r, WIDTH * HEIGHT * 3);
        } else {
            uint32_t i, pixels = WIDTH * HEIGHT;
            for (i = 0; i < pixels; i++) {
                buffer[i*BYTES_PER_PIXEL] = r;
                buffer[i*BYTES_PER_PIXEL+1] = g;
                buffer[i*BYTES_PER_PIXEL+2] = b;
            }
        }
    }
}

