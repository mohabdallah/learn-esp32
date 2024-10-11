#ifndef APP_KEYPAD_H
#define APP_KEYPAD_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

void App_initAndStart_keypad(void);

#endif