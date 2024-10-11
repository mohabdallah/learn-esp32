#ifndef APP_LEDS_H
#define APP_LEDS_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

void App_initAndStart_leds(void);

#endif