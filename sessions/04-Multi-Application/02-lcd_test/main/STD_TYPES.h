/*
 * STD_TYPES.h
 * Description : Header file for types declarations and required includes
 * Created: 12/27/2014
 *  Author: Mohamed Abdallah
 */ 

/*Make sure that the file is not included before*/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define _delay_ms(MSEC) vTaskDelay(MSEC/portTICK_PERIOD_MS);

/*8 bit integer type define*/
typedef unsigned char uint8 ;

/*16 bit integer type define*/
typedef unsigned short uint16 ;

/*32 bit integer type define*/
typedef unsigned long uint32 ;

#endif /* STD_TYPES_H_ */