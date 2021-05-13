# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
#set(PICO_SDK_PATH "/data/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico-st7735 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

add_compile_definitions(SPI_TFT_PORT=spi1)
add_compile_definitions(SPI_TFT_CS=9)
add_compile_definitions(SPI_TFT_DC=10)
add_compile_definitions(SPI_TFT_RST=11)
add_compile_definitions(SPI_RX=12)
add_compile_definitions(SPI_SCK=14)
add_compile_definitions(SPI_TX=15)

add_compile_definitions(TFT_ENABLE_RESET TFT_ENABLE_BLACK TFT_ENABLE_TEXT
                        TFT_ENABLE_SHAPES TFT_ENABLE_ROTATE)
add_compile_definitions(ENABLE_TESTR ENABLE_TEST1 ENABLE_TEST1A
                        ENABLE_TEST2 ENABLE_TEST3 ENABLE_TEST4)

# add preprocessor-constant DEBUG for Debug-builds
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_VERBOSE_MAKEFILE 1)
  add_compile_definitions(DEBUG)
else()
endif()

add_subdirectory(lib-st7735)
add_subdirectory(demo)
