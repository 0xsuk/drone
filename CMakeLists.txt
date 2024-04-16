cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(PICO_SDK_PATH ../../pico-sdk)
set(PICO_BOARD pico_w)

include(pico_sdk_import.cmake)

project(drone C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(drone
  pwm.c
)

pico_enable_stdio_usb(drone 1)
pico_enable_stdio_uart(drone 0)

pico_add_extra_outputs(drone)

target_link_libraries(drone pico_stdlib hardware_pwm pico_cyw43_arch_none)
