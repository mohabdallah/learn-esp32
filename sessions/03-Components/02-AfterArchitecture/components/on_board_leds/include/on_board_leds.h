#ifndef ON_BOARD_LEDS_H
#define ON_BOARD_LEDS_H

#include "stdbool.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "platform_logger.h"

void on_board_leds_init(void);

void on_board_leds_setLed1Status(bool status);

void on_board_leds_setLed2Status(bool status);

void on_board_leds_setLed3Status(bool status);

void on_board_leds_setLed4Status(bool status);



#endif