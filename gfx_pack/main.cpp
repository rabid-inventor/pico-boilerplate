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

ST7567 st7567(128, 64, {PIMORONI_SPI_DEFAULT_INSTANCE, 17, SPI_DEFAULT_SCK, SPI_DEFAULT_MOSI, PIN_UNUSED, 16, SPI_BG_FRONT_PWM});
PicoGraphics_Pen1Bit graphics(st7567.width, st7567.height, nullptr);



Button button_a(gfx_pack::A);
Button button_b(gfx_pack::B);
Button button_x(gfx_pack::X);
Button button_y(gfx_pack::Y);


int main(){

    stdio_init_all();
    sleep_ms(2000);
    //graphics.set_thickness(2);
    while (1){
    graphics.set_pen(0);
    graphics.clear();
    graphics.set_pen(15);
    
    graphics.set_pixel(Point(7,0));
    graphics.set_pixel(Point(120,6));
    graphics.set_pixel(Point(64,4));
    //graphics.set_pixel(Point(64,64)); 
    //graphics.line(Point(0,0),Point(64,8));
    //graphics.text(message, 10, 20, 0.6f);
    
    for (uint8_t x=0 ; x < 70 ; x ++){
        graphics.set_pen(0);
        graphics.clear();
        graphics.set_pen(15);
        graphics.text("(TEST TEXT)", Point(x, 0),60, 0.8f);
        st7567.update(&graphics);
        //sleep_ms(100);
    }
    for (uint8_t x=70 ; x > 0 ; x --){
        graphics.set_pen(0);
        graphics.clear();
        graphics.set_pen(15);
        graphics.text("(TEST TEXT)", Point(x, 0),60, 0.8f);
        st7567.update(&graphics);
        //sleep_ms(100);
    }
    sleep_ms(5000);
    printf("Hello world\n");
    st7567.update(&graphics);
    }

    //return 1;
}