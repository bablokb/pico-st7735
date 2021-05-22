// --------------------------------------------------------------------------
// ST7735-library (declaration)
//
// Author: Bernhard Bablok
//
// The code is based on work from Gavin Lyons, see
// https://github.com/gavinlyonsrepo/pic_16F18346_projects
//
// https://github.com/bablokb/pic-st7735
// --------------------------------------------------------------------------

#ifndef ST7735_TFT_H
#define ST7735_TFT_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#if defined _PTC
  #include "picconfig.h"
#endif

#if defined TFT_ENABLE_FONTS
  #if !defined TFT_ENABLE_TEXT
    #define TFT_ENABLE_TEXT
  #endif
  #if !defined PROGMEM
    #define PROGMEM
  #endif
#endif

#if defined TFT_ENABLE_ALL
  #if !defined TFT_ENABLE_SHAPES
    #define TFT_ENABLE_SHAPES
  #endif
  #if !defined TFT_ENABLE_SCROLL
    #define TFT_ENABLE_SCROLL
  #endif
  #if !defined TFT_ENABLE_TEXT
    #define TFT_ENABLE_TEXT
  #endif
  #if !defined TFT_ENABLE_ROTATE
    #define TFT_ENABLE_ROTATE
  #endif
#endif

extern uint8_t tft_width, tft_height;

#define _swap(a, b) { int16_t t; t = a; a = b; b = t;}
#define ST7735_NOP     0x00
#define ST7735_SWRESET 0x01
#define ST7735_RDDID   0x04
#define ST7735_RDDST   0x09
#define ST7735_SLPIN   0x10
#define ST7735_SLPOUT  0x11
#define ST7735_PTLON   0x12
#define ST7735_NORON   0x13
#define ST7735_INVOFF  0x20
#define ST7735_INVON   0x21
#define ST7735_DISPOFF 0x28
#define ST7735_DISPON  0x29
#define ST7735_CASET   0x2A
#define ST7735_RASET   0x2B
#define ST7735_RAMWR   0x2C
#define ST7735_RAMRD   0x2E
#define ST7735_PTLAR   0x30
#define ST7735_VSCRDEF 0x33
#define ST7735_COLMOD  0x3A
#define ST7735_MADCTL  0x36
#define ST7735_MADCTL_MY 0x80
#define ST7735_MADCTL_MX 0x40
#define ST7735_MADCTL_MV 0x20
#define ST7735_MADCTL_ML 0x10
#define ST7735_MADCTL_RGB 0x00
#define ST7735_VSCRSADD 0x37
#define ST7735_FRMCTR1 0xB1
#define ST7735_FRMCTR2 0xB2
#define ST7735_FRMCTR3 0xB3
#define ST7735_INVCTR  0xB4
#define ST7735_DISSET5 0xB6
#define ST7735_PWCTR1  0xC0
#define ST7735_PWCTR2  0xC1
#define ST7735_PWCTR3  0xC2
#define ST7735_PWCTR4  0xC3
#define ST7735_PWCTR5  0xC4
#define ST7735_VMCTR1  0xC5
#define ST7735_RDID1   0xDA
#define ST7735_RDID2   0xDB
#define ST7735_RDID3   0xDC
#define ST7735_RDID4   0xDD
#define ST7735_PWCTR6  0xFC
#define ST7735_GMCTRP1 0xE0
#define ST7735_GMCTRN1 0xE1

// Color definitions
#define   ST7735_BLACK   0x0000
#define   ST7735_BLUE    0x001F
#define   ST7735_RED     0xF800
#define   ST7735_GREEN   0x07E0
#define   ST7735_CYAN    0x07FF
#define   ST7735_MAGENTA 0xF81F
#define   ST7735_YELLOW  0xFFE0
#define   ST7735_WHITE   0xFFFF

#define LCD_ASCII_OFFSET 0x20 //0x20, ASCII character for Space, The font table starts with this character


// ******** FUNCTION  PROTOTYPES ************

// SPI
void write_command(uint8_t );
void write_data(uint8_t );

// Init
#if defined TFT_ENABLE_GREEN
void TFT_GreenTab_Initialize(void);
void Rcmd2green();
#endif

#if defined TFT_ENABLE_RED
void TFT_RedTab_Initialize(void);
#endif

#if defined TFT_ENABLE_BLACK
void TFT_BlackTab_Initialize(void);
#endif

#if defined(TFT_ENABLE_RED) || defined(TFT_ENABLE_BLACK)
void Rcmd2red();
#endif

#if defined TFT_ENABLE_GENERIC
void TFT_ST7735B_Initialize(void);
void Bcmd();
#endif

#if defined TFT_ENABLE_RESET
void TFT_ResetPIN(void);
#endif

void Rcmd1();
void Rcmd3();

// Misc + Screen related
void setAddrWindow(uint8_t , uint8_t , uint8_t , uint8_t );
void fillScreen(uint16_t color);
void drawFastVLine(uint8_t x, uint8_t y, uint8_t h, uint16_t color);
void drawFastHLine(uint8_t x, uint8_t y, uint8_t w, uint16_t color);
void drawPixel(uint8_t , uint8_t , uint16_t );
void fillRectangle(uint8_t , uint8_t , uint8_t , uint8_t , uint16_t );
void fillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color);

void invertDisplay(bool i);
void NormalDisplay(void);
void pushColor(uint16_t color);

//Scroll
#if defined TFT_ENABLE_SCROLL
void setScrollDefinition(uint8_t top_fix_height, uint8_t bottom_fix_height, bool _scroll_direction);
void VerticalScroll(uint8_t _vsp);
#endif

// Shapes
#if defined TFT_ENABLE_SHAPES
void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
void drawRectWH(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color);
void drawRoundRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t r, uint16_t color);
void fillRoundRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t r, uint16_t color);
void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);
void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color);
void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
#endif

// Text
#if defined(TFT_ENABLE_TEXT)
void drawChar(uint8_t x, uint8_t y, uint8_t c, uint16_t color, uint16_t bg,  uint8_t size);
void setTextWrap(bool w);
void drawText(uint8_t x, uint8_t y, const char *_text, uint16_t color, uint16_t bg, uint8_t size);
#endif

#if defined TFT_ENABLE_ROTATE
void setRotation(uint8_t m);
#endif

#if defined TFT_ENABLE_FONTS
/// Font data stored PER GLYPH
typedef struct {
  uint16_t bitmapOffset; ///< Pointer into GFXfont->bitmap
  uint8_t width;         ///< Bitmap dimensions in pixels
  uint8_t height;        ///< Bitmap dimensions in pixels
  uint8_t xAdvance;      ///< Distance to advance cursor (x axis)
  int8_t xOffset;        ///< X dist from cursor pos to UL corner
  int8_t yOffset;        ///< Y dist from cursor pos to UL corner
} GFXglyph;

/// Data stored for FONT AS A WHOLE
typedef struct {
  uint8_t *bitmap;     ///< Glyph bitmaps, concatenated
  GFXglyph *glyph;     ///< Glyph array
  uint16_t first;      ///< ASCII extents (first char)
  uint16_t last;       ///< ASCII extents (last char)
  uint8_t yAdvance;    ///< Newline distance (y axis)
  const char *subset;  ///< subset of chars in the font
} GFXfont;

extern GFXfont *_gfxFont;
void setFont(const GFXfont *f);
#endif

// ------ not functional yet ----------------------------------------------
// needs fat-library

// BMP processing from SD-card
#if defined TFT_ENABLE_BMP
bool bmpDraw(int8_t x, int8_t y, int8_t *bmpname);
#endif

#endif
