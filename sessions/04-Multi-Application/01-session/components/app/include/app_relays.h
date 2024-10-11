#ifndef APP_RELAYS_H
#define APP_RELAYS_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

void App_initAndStart_relays(void);

#endif