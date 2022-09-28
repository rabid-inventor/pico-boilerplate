cmake_minimum_required(VERSION 3.12)

# Change your executable name to something creative!
set(NAME pico-boilerplate) # <-- Name your project/executable here!

include(pimoroni_pico_import.cmake)
include(pico_sdk_import.cmake)

# Gooey boilerplate
project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# Add your source files
add_executable(${NAME}
    main.cpp # <-- Add source files here!
)

# Include required libraries
# This assumes `pimoroni-pico` is stored alongside your project
include(common/pimoroni_i2c)
include(libraries/pico_explorer/pico_explorer)
include(libraries/bitmap_fonts/bitmap_fonts)
include(libraries/hershey_fonts/hershey_fonts)

target_include_directories(${NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        )
# Don't forget to link the libraries you need!
target_link_libraries(${NAME}
    pimoroni_i2c
    pico_stdlib              # for core functionality
    pico_cyw43_arch_lwip_poll     # we need Wifi to access the GPIO, but we don't need anything else
    hardware_spi 
    hardware_pwm 
    hardware_dma  
    hardware_rtc
    pico_graphics)

# enable usb output
pico_enable_stdio_usb(${NAME} 1)


# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

# Set up files for the release packages
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${NAME}.uf2
    ${CMAKE_CURRENT_LIST_DIR}/README.md
    DESTINATION .
)

set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_GENERATOR "ZIP" "TGZ")
include(CPack)
