/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include "sdkconfig.h"
#include "swc1.h"
#include "platform_logger.h"

static const char *TAG = "example_main";

void app_main(void)
{
    PLATFORM_LOGI(TAG, "Starting main component");

    swc1_init();

    swc1_task();

    while (1) {
        
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    }
}
