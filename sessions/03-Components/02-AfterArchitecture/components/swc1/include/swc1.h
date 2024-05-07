#ifndef SWC1_H
#define SWC1_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"
#include "status_report.h"
#include "platform_logger.h"

void swc1_init(void);

void swc1_task(void);


#endif