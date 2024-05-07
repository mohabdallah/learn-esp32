#ifndef STATUS_REPORT_H
#define STATUS_REPORT_H

#include "on_board_leds.h"


#define STATUS_REPORT_WIFI_DISCONNECTED_STATUS 4
#define STATUS_REPORT_WIFI_CONNECTED_STATUS 5

void status_report_init(void);

void status_report_set_status(unsigned char status);


#endif