#include <stdio.h>
#include "swc1.h"

static const char *TAG = "swc1";

void swc1_init(void)
{
    PLATFORM_LOGI(TAG, "Init of swc1 component");

    status_report_init();
}

void swc1_task(void)
{
    PLATFORM_LOGI(TAG, "Starting swc1 component task");

    

    while(1)
    {
        
        status_report_set_status(STATUS_REPORT_WIFI_CONNECTED_STATUS);

        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    }
}