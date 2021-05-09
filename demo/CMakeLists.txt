cmake_minimum_required(VERSION 3.0)

project(demo)

add_executable(${PROJECT_NAME} demo.c tst_funcs.c)

pico_set_program_name(${PROJECT_NAME} "pico-st7735")
pico_set_program_version(${PROJECT_NAME} "0.1")

pico_enable_stdio_uart(${PROJECT_NAME} 1)
pico_enable_stdio_usb(${PROJECT_NAME} 0)

# add libraries
target_link_libraries(${PROJECT_NAME} PUBLIC pico_stdlib)
target_link_libraries(${PROJECT_NAME} PUBLIC lib-st7735)
target_link_libraries(${PROJECT_NAME} PUBLIC hardware_spi)

pico_add_extra_outputs(${PROJECT_NAME})
