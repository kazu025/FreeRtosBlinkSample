cmake_minimum_required(VERSION 3.12)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
project(hello_world C CXX ASM)
set(PICO_SDK_FREERTOS_SOURCE FreeRTOS-Kernel)
# initialize the Pico SDK
pico_sdk_init()


add_executable(hello_world
    src/main.cpp 
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(hello_world pico_stdlib)
add_library(FreeRTOS
    ${PICO_SDK_FREERTOS_SOURCE}/event_groups.c
    ${PICO_SDK_FREERTOS_SOURCE}/list.c
    ${PICO_SDK_FREERTOS_SOURCE}/queue.c
    ${PICO_SDK_FREERTOS_SOURCE}/stream_buffer.c
    ${PICO_SDK_FREERTOS_SOURCE}/tasks.c
    ${PICO_SDK_FREERTOS_SOURCE}/timers.c
    ${PICO_SDK_FREERTOS_SOURCE}/portable/MemMang/heap_3.c
    ${PICO_SDK_FREERTOS_SOURCE}/portable/GCC/ARM_CM0/port.c
)
target_include_directories(FreeRTOS PUBLIC FreeRTOS-Kernel/include include/ FreeRTOS-Kernel/portable/GCC/ARM_CM0)
# USBシリアルを有効化する場合は以下を追加
pico_enable_stdio_usb(hello_world 1)
pico_enable_stdio_uart(hello_world 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(hello_world)
target_link_libraries(hello_world FreeRTOS)
add_custom_command(TARGET hello_world
        POST_BUILD
        COMMAND arm-none-eabi-size hello_world.elf
        )
# rest of your project
