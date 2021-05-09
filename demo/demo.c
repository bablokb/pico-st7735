// --------------------------------------------------------------------------
// Demo program for the ST7735-library
//
// Author: Bernhard Bablok
//
// The code is based on work from Gavin Lyons, see
// https://github.com/gavinlyonsrepo/pic_16F18346_projects
//
// https://github.com/bablokb/pico-st7735
// --------------------------------------------------------------------------
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hw.h"
#include "tst_funcs.h"
#include "ST7735_TFT.h"

// ---------------------------------------------------------------------------
// hardware-specific intialization
// SPI_* constants from CMakeLists.txt or user.h

void init_hw() {
  stdio_init_all();
  spi_init(SPI_TFT_PORT, 1000000);                // SPI with 1Mhz
  gpio_set_function(SPI_RX, GPIO_FUNC_SPI);
  gpio_set_function(SPI_SCK,GPIO_FUNC_SPI);
  gpio_set_function(SPI_TX, GPIO_FUNC_SPI);

  gpio_init(SPI_TFT_CS);
  gpio_set_dir(SPI_TFT_CS, GPIO_OUT);
  gpio_put(SPI_TFT_CS, 1);                        // Chip select is active-low

  gpio_init(SPI_TFT_DC);
  gpio_set_dir(SPI_TFT_DC, GPIO_OUT);
  gpio_put(SPI_TFT_DC, 0);                        // Chip select is active-low

  gpio_init(SPI_TFT_RST);
  gpio_set_dir(SPI_TFT_RST, GPIO_OUT);
  gpio_put(SPI_TFT_RST, 0);
}


// ---------------------------------------------------------------------------
// main loop

int main() {
  init_hw();
#ifdef TFT_ENABLE_BLACK
  TFT_BlackTab_Initialize();
#elif defined(TFT_ENABLE_GREEN)
  TFT_GreenTab_Initialize();
#elif defined(TFT_ENABLE_RED)
  TFT_RedTab_Initialize();
#elif defined(TFT_ENABLE_GENERIC)
  TFT_ST7735B_Initialize();
#endif
  setTextWrap(true);
  TEST_DELAY1();
  fillScreen(ST7735_BLACK);

#if defined(ENABLE_TEST1)
  Test1();
#endif
#if defined(ENABLE_TEST1A)
  Test1A();
#endif
#if defined(ENABLE_TEST2)
  Test2();
#endif
#if defined(ENABLE_TEST3)
  Test3();
#endif
#if defined(ENABLE_TEST4)
  Test4(); 
#endif
#if defined(ENABLE_TEST5)
  Test5();
#endif
#if defined(ENABLE_TEST6)
  Test6();
#endif
#if defined(ENABLE_TEST7)
  Test7();
#endif
#if defined(ENABLE_TEST8)
  Test8();
#endif

#if defined(TFT_ENABLE_TEXT)
  #if defined(ENABLE_TESTR) && defined(TFT_ENABLE_ROTATE)
  for (size_t i = 0; i < 4; i++) {
    setRotation(i);
  #endif
    fillScreen(ST7735_BLACK);
    drawText(10, 10, "Test over!", ST7735_WHITE, ST7735_BLACK, 1);
    drawFastHLine(0,0,80,ST7735_CYAN);
    drawFastHLine(0,25,80,ST7735_CYAN);
    drawFastVLine(0,0,25,ST7735_CYAN);
    drawFastVLine(80,0,25,ST7735_CYAN);
  #if defined(ENABLE_TESTR) && defined(TFT_ENABLE_ROTATE)
    TEST_DELAY1();
  }
  #endif
#endif
  while(1);
  return 0;
}
