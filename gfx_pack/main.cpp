/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <math.h>
#include <cstdlib>
#include <string.h>
#include <time.h>
#include <cstdio>

#include "pico/stdlib.h"
#include "libraries/pico_graphics/pico_graphics.hpp"
#include "libraries/gfx_pack/gfx_pack.hpp"
#include "drivers/st7567/st7567.hpp"
#include "drivers/button/button.hpp"

using namespace pimoroni;

ST7567 st7567(128, 64, get_spi_pins(BG_SPI_FRONT));
PicoGraphics_PenRGB332 graphics(st7567.width, st7567.height, nullptr);



Button button_a(gfx_pack::A);
Button button_b(gfx_pack::B);
Button button_x(gfx_pack::X);
Button button_y(gfx_pack::Y);


int main(){

    stdio_init_all();
    sleep_ms(2000);
    printf("Hello world\n");
    return 1;
}