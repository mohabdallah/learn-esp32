#ifndef SWC1_H
#define SWC1_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

void swc1_init(void);

void swc1_task(void);


#endif