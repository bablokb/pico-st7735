// --------------------------------------------------------------------------
// ST7735-library (hw-specific defines and interfaces)
//
// If you want to port the library to a different platform, change this
// include (pins and ports, includes, function-map at the end of the file).
//
// Author: Bernhard Bablok
//
// https://github.com/bablokb/pico-st7735
// --------------------------------------------------------------------------

#ifndef _HW_H
#define _HW_H

#include "pico/stdlib.h"
#include "hardware/spi.h"

// ----------------------------------------------------------------
// pin and ports (usually defined in the makefile)

#ifndef SPI_TFT_PORT
  #define SPI_TFT_PORT spi1
#endif

// chip-select output pin
#ifndef PIN_TFT_CS
  #define PIN_TFT_CS 9
#endif

// TFT_DC output pin
#ifndef PIN_TFT_DC
  #define PIN_TFT_DC 10
#endif

// TFT_RST output pin
#ifndef PIN_TFT_RST
  #define PIN_TFT_RST 11
#endif
// ----------------------------------------------------------------

// ----------------------------------------------------------------
// helper macros

// ----------------------------------------------------------------
// declerations
void tft_spi_init();

// ----------------------------------------------------------------
// necessary includes

#include "hardware/spi.h"

// ----------------------------------------------------------------
// function-map
#ifdef __delay_ms
#undef __delay_ms
#endif
#define __delay_ms(x)              sleep_ms(x)

#define spiwrite(data)             spi_write_blocking(SPI_TFT_PORT,&data,1)

#define tft_cs_low()               asm volatile("nop \n nop \n nop"); \
                                   gpio_put(PIN_TFT_CS,0); \
                                   asm volatile("nop \n nop \n nop")
#define tft_cs_high()              asm volatile("nop \n nop \n nop"); \
                                   gpio_put(PIN_TFT_CS,1); \
                                   asm volatile("nop \n nop \n nop")

#define tft_dc_low()               asm volatile("nop \n nop \n nop"); \
                                   gpio_put(PIN_TFT_DC,0); \
                                   asm volatile("nop \n nop \n nop")
#define tft_dc_high()              asm volatile("nop \n nop \n nop"); \
                                   gpio_put(PIN_TFT_DC,1); \
                                   asm volatile("nop \n nop \n nop")

#define tft_rst_low()              asm volatile("nop \n nop \n nop"); \
                                   gpio_put(PIN_TFT_RST,0); \
                                   asm volatile("nop \n nop \n nop")
#define tft_rst_high()             asm volatile("nop \n nop \n nop"); \
                                   gpio_put(PIN_TFT_RST,1); \
                                   asm volatile("nop \n nop \n nop")
// ----------------------------------------------------------------

#endif
