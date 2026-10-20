add_executable(lab4_test_signal test_signal.c signaling.c)
target_link_libraries(lab4_test_signal PRIVATE
  pico_stdlib
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
  pico_cyw43_arch_none
  unity
)
target_include_directories(lab4_test_signal PRIVATE ${CMAKE_SOURCE_DIR}/include)

pico_enable_stdio_uart(lab4_test_signal 0)
pico_enable_stdio_usb(lab4_test_signal 1)
add_custom_target(flash_test_signal
    picotool load -f $<TARGET_FILE:lab4_test_signal> DEPENDS lab4_test_signal)
