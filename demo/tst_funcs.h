// --------------------------------------------------------------------------
// ST7735-library (declaration of test-functions)
//
// Author: Bernhard Bablok
//
// The code is based on work from Gavin Lyons, see
// https://github.com/gavinlyonsrepo/pic_16F18346_projects
//
// https://github.com/bablokb/pic-st7735
// --------------------------------------------------------------------------

#ifndef TEST_FUNCS_H
#define TEST_FUNCS_H

#include <stdint.h>

#ifdef ENABLE_ALL
  #if ! defined(ENABLE_TEST1)
    #define ENABLE_TEST1
  #endif
  #if ! defined(ENABLE_TEST2)
    #define ENABLE_TEST2
  #endif
  #if ! defined(ENABLE_TEST3)
    #define ENABLE_TEST3
  #endif
  #if ! defined(ENABLE_TEST4)
    #define ENABLE_TEST4
  #endif
  #if ! defined(ENABLE_TEST5)
    #define ENABLE_TEST5
  #endif
  #if ! defined(ENABLE_TEST6)
    #define ENABLE_TEST6
  #endif
  #if ! defined(ENABLE_TEST7)
    #define ENABLE_TEST7
  #endif
  #if ! defined(ENABLE_TEST8)
    #define ENABLE_TEST8
  #endif
  #if ! defined(ENABLE_TEST9)
    #define ENABLE_TEST9
  #endif
  #if ! defined(ENABLE_TEST9A)
    #define ENABLE_TEST9A
  #endif
#endif

#define TEST_DELAY1() sleep_ms(1000)
#define TEST_DELAY2() sleep_ms(2000)
#define TEST_DELAY5() sleep_ms(5000)

#if defined(ENABLE_TEST1)
void Test1(void); // Hello world fonts + Colors text
#endif
#if defined(ENABLE_TEST1A)
void Test1A(void); // print entire font
#endif
#if defined(ENABLE_TEST2)
void Test2(void); // font sizes + character draw
#endif
#if defined(ENABLE_TEST3)
void Test3(void); // pixels and lines
#endif
#if defined(ENABLE_TEST4)
void Test4(void); // rectangles 
#endif
#if defined(ENABLE_TEST5)
void Test5(void); // Circle
#endif
#if defined(ENABLE_TEST6)
void Test6(void); // Triangles 
#endif
#if defined(ENABLE_TEST7)
void Test7(void); // scroll TODO not working in version 1.0
#endif
#if defined(ENABLE_TEST8)
void Test8(void); // shapes media buttons graphic + invert display
#endif
#if defined(ENABLE_TEST9)
void Test9(void); // glyph-fonts
#endif
#if defined(ENABLE_TEST9A)
void Test9A(void); // glyph-fonts (subset)
#endif
#endif
