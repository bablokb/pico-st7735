ST7735 TFT-Library for the Raspberry Pi Pico
============================================

Status
------

The code compiles and runs. It was tested with a no-name 1.8" TFT with
128x160 pixel.


Overview
--------

This is a port of the Adafruit's ST7735-library for the Pi Pico.
The code is a copy of <https://github.com/gavinlyonsrepo/pic_16F18346_projects>
with some added features (`TFT_ENABLE_*`-defines, rotation) and some modifications.

The code was developed for PIC MCUs, but porting it to the Pico was
straightforward.

The library-code is in directory `lib-st7735`, a demo and test-program
in directory `demo`. You can build, run and debug as you do with other
projects from within VS-Code, the editor automagically detects that the
executable is within a subdirectory instead of within the top-level dir.


Library-configuration
---------------------

The library has many functions and to keep the footprint small, you must selectively
include only the features you need. Currently, the library supports the following
`#define`s, which you should set in the `CMakeLists.txt`:

  - `TFT_ENABLE_ALL`:     enable all features
  - `TFT_ENABLE_BLACK`:   "black"-type TFT
  - `TFT_ENABLE_GREEN`:   "green"-type TFT
  - `TFT_ENABLE_RED`:     "red"-type TFT
  - `TFT_ENABLE_GENERIC`: "generic"-type TFT
  - `TFT_ENABLE_RESET`:   use reset-pin during initialization
  - `TFT_ENABLE_TEXT`:    enable text-functions
  - `TFT_ENABLE_SHAPES`:  enable shape-functions
  - `TFT_ENABLE_SCROLL`:  enable scroll-functions
  - `TFT_ENABLE_ROTATE`:  enable rotation
  - `TFT_ENABLE_FONTS`:   enable glyph-fonts (see below)
  - `TFT_ENABLE_BMP`:     enable bitmap-functions (not usable yet)


Fonts
-----

The ST7735-library uses a small standard-font, which is impossible to read
unless you are really near the screen. You can scale the font, but the
result is ugly.

The solution to the problem are glyph-fonts. They take up a lot of space,
too much for most MCUs, but since the Pico has a lot of flash, this is
no problem here.

This repository only distributes a single glyph-font
`lib-st7735/include/FreeMonoOblique12pt7b.h`, others are available from
the original Adafruit project <https://github.com/adafruit/Adafruit-GFX-Library/>.

To use these fonts, you need to `#define TFT_ENABLE_FONTS` and set the
font before drawing text. See `Test9()` in the demo-program for an
example.


Font-Subsets
------------

Very often, a complete font is not necessary. The project
<https://github.com/bablokb/pic-st7735> provides a
utility to create a subset of the font only with the necessary characters
in the subdirectory `fc_subset`. You should read complete instructions in
the above mentioned Adafruit-repo (subdirectory `fontconvert`).

Handling of subsets needs some care, see `Test9A()` for an example. Since
the Pico has a lot of memory, it is usually better to use the complete fonts.
