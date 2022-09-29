/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <string.h>
#include <time.h>
#include <cstdio>

#include "pico/stdlib.h"
#include "drivers/st7567/st7567.hpp"


int main(){

    stdio_init_all();
    sleep_ms(2000);
    printf("Hello world\n");
    return 1;
}