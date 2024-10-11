/*
 * hello_world_main.c
 * Description : c file for app entry point
 * Created: 10/07/2023
 *  Author: Mohamed Abdallah
 */ 

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "APPLICATION.h"

void app_main(void)
{
    printf("Hello world!\n");

    /*Initialize the application components (LCD)*/
	APP_init() ;
	
	/*Start the application*/
	APP_start() ;

    while(1) {
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}
