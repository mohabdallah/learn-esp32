#include <stdio.h>
#include "status_report.h"

static const char *TAG = "status_report";

void status_report_init(void)
{
    on_board_leds_init();
}

void status_report_set_status(unsigned char status)
{
    switch (status)
    {
        case STATUS_REPORT_WIFI_DISCONNECTED_STATUS:
            on_board_leds_setLed1Status(true);
            break;
        
        case STATUS_REPORT_WIFI_CONNECTED_STATUS:
            on_board_leds_setLed1Status(false);
            on_board_leds_setLed2Status(true);
            break;
        
        default:
            break;
    }
}
