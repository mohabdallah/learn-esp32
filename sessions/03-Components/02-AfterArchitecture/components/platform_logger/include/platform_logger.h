#ifndef PLATFORM_LOGGER_H
#define PLATFORM_LOGGER_H

#include "esp_log.h"

#define PLATFORM_LOGI( tag, format, ... ) ESP_LOGI(tag, format __VA_OPT__(,) __VA_ARGS__)

#endif