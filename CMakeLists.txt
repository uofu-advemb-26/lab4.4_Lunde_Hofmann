cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set board variant to pico_w
set (PICO_BOARD pico_w CACHE STRING "Board type")

# Import Pico SDK
include(lib/pico-sdk/pico_sdk_init.cmake)

# Import FreeRTOS library configurations
include(lib/freertos/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

# Add Unity library and include directories
include(unity.cmake)

project(threading C CXX ASM)

pico_sdk_init()

# Preprocessor values
# add_compile_defintions(
#     configNUMBER_OF_CORES=1
#     PICO_ENTER_USB_BOOT_ON_EXIT=1
# )

# add_executable(lab4_test_fifo test_fifo.c)
# target_link_libraries(lab4_test_fifo PRIVATE
#   pico_stdlib
#   pico_async_context_freertos
#   FreeRTOS-Kernel-Heap4
#   pico_cyw43_arch_none
#   unity
# )
# pico_enable_stdio_uart(lab4_test_fifo 0)
# pico_enable_stdio_usb(lab4_test_fifo 1)
# add_custom_target(flash_test_
#     picotool load -f $<TARGET_FILE:lab4_test_fifo> DEPENDS lab4_test_fifo)


add_executable(lab4_test_signal test_signal.c)
target_link_libraries(lab4_test_signal PRIVATE
  pico_stdlib
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
  pico_cyw43_arch_none
  unity
)
target_include_directories(lab4_test_signal PRIVATE include)

pico_enable_stdio_uart(lab4_test_signal 0)
pico_enable_stdio_usb(lab4_test_signal 1)
add_custom_target(flash_test_signal
    picotool load -f $<TARGET_FILE:lab4_test_signal> DEPENDS lab4_test_signal)
