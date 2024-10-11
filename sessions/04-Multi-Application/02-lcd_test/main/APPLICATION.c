/*
 * Description :  Application module used to initialize application and do the required function
 * Created: 1/10/2015 8:25:10 AM
 *  Author: Mohamed Abdallah
 */ 


/*Header file of current module (APPLICATION module)*/
#include "APPLICATION.h"

/* Keypad pins */
#define KEYPAD_COL1_PIN 5
#define KEYPAD_COL2_PIN 18
#define KEYPAD_COL3_PIN 19
#define KEYPAD_ROW1_PIN 23
#define KEYPAD_ROW2_PIN 22
#define KEYPAD_ROW3_PIN 21

void testKeypad(void);

/*--------------------------------------------------------
Description : Initialize the application components (LCD)
Input : None
Output : None
--------------------------------------------------------*/
void APP_init(void) {
	/*Configure and initialize the LCD*/
	LCD_init() ;
	/*Delay after configurations and before sending any data to LCD*/
	_delay_ms(10) ;
}


/*----------------------------------
Description : Start the application
Input : None
Output : None
----------------------------------*/
void APP_start(void) {
	/*arrays of characters used to store strings to be displayed on LCD*/
	uint8 string1[16] = {"IOTTest"} ;
	uint8 string2[16] = {"Board"} ;
	uint8 string3[16] = {"WELCOME ^_^"} ;
	
	/*CLear screen*/
	LCD_sendCommand(0x01) ;
	
	/*Display string in string1 array on LCD*/
	LCD_sendString(string1) ;
	/*Delay 1 Sec*/
	_delay_ms(1000) ;
	
	/*Go to specific row,column and display string in string2 array on LCD*/
	LCD_sendStringRowCol(1,5,string2) ;
	/*Delay 1 Sec*/
	_delay_ms(1000) ;
	
	/*CLear screen*/
	LCD_sendCommand(0x01) ;
	/*Display string in string3 array on LCD*/
	LCD_sendStringRowCol(1,3,string3) ;
	/*Delay 1 Sec*/
	_delay_ms(1000) ;
	
	/*CLear screen*/
	LCD_sendCommand(0x01) ;

	/* Wait for keypad press and display it on LCD */
	testKeypad();
}


void testKeypad(void)
{
    gpio_reset_pin(KEYPAD_COL1_PIN);
    gpio_set_direction(KEYPAD_COL1_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(KEYPAD_COL1_PIN, 0);

    gpio_reset_pin(KEYPAD_COL2_PIN);
    gpio_set_direction(KEYPAD_COL2_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(KEYPAD_COL2_PIN, 0);

    gpio_reset_pin(KEYPAD_COL3_PIN);
    gpio_set_direction(KEYPAD_COL3_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(KEYPAD_COL3_PIN, 0);

    gpio_reset_pin(KEYPAD_ROW1_PIN);
    gpio_set_direction(KEYPAD_ROW1_PIN, GPIO_MODE_INPUT);
    gpio_pullup_dis(KEYPAD_ROW1_PIN);
    gpio_pulldown_en(KEYPAD_ROW1_PIN);

    gpio_reset_pin(KEYPAD_ROW2_PIN);
    gpio_set_direction(KEYPAD_ROW2_PIN, GPIO_MODE_INPUT);
    gpio_pullup_dis(KEYPAD_ROW2_PIN);
    gpio_pulldown_en(KEYPAD_ROW2_PIN);

    gpio_reset_pin(KEYPAD_ROW3_PIN);
    gpio_set_direction(KEYPAD_ROW3_PIN, GPIO_MODE_INPUT);
    gpio_pullup_dis(KEYPAD_ROW3_PIN);
    gpio_pulldown_en(KEYPAD_ROW3_PIN);

    while (1)
    {
        /* Check COL 1, all rows */
        gpio_set_level(KEYPAD_COL1_PIN, 1);

        if (1 == gpio_get_level(KEYPAD_ROW1_PIN))
        {
			/*CLear screen*/
			LCD_sendCommand(0x01) ;
			uint8 string[11] = {"Pressed 1"} ;
			/*Display number on LCD*/
			LCD_sendStringRowCol(1,3,string) ;

            printf("Pressed 1\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }
        else if (1 == gpio_get_level(KEYPAD_ROW2_PIN))
        {
            /*CLear screen*/
			LCD_sendCommand(0x01) ;
			uint8 string[11] = {"Pressed 4"} ;
			/*Display number on LCD*/
			LCD_sendStringRowCol(1,3,string) ;

            printf("Pressed 4\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }
        else if (1 == gpio_get_level(KEYPAD_ROW3_PIN))
        {
            /*CLear screen*/
			LCD_sendCommand(0x01) ;
			uint8 string[11] = {"Pressed 7"} ;
			/*Display number on LCD*/
			LCD_sendStringRowCol(1,3,string) ;

            printf("Pressed 7\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }

        gpio_set_level(KEYPAD_COL1_PIN, 0);

        /* Check COL 2, all rows */
        gpio_set_level(KEYPAD_COL2_PIN, 1);

        if (1 == gpio_get_level(KEYPAD_ROW1_PIN))
        {
            /*CLear screen*/
			LCD_sendCommand(0x01) ;
			uint8 string[11] = {"Pressed 2"} ;
			/*Display number on LCD*/
			LCD_sendStringRowCol(1,3,string) ;

            printf("Pressed 2\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }
        else if (1 == gpio_get_level(KEYPAD_ROW2_PIN))
        {
            /*CLear screen*/
			LCD_sendCommand(0x01) ;
			uint8 string[11] = {"Pressed 5"} ;
			/*Display number on LCD*/
			LCD_sendStringRowCol(1,3,string) ;

            printf("Pressed 5\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }
        else if (1 == gpio_get_level(KEYPAD_ROW3_PIN))
        {
            /*CLear screen*/
			LCD_sendCommand(0x01) ;
			uint8 string[11] = {"Pressed 8"} ;
			/*Display number on LCD*/
			LCD_sendStringRowCol(1,3,string) ;

            printf("Pressed 8\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }

        gpio_set_level(KEYPAD_COL2_PIN, 0);

        /* Check COL 3, all rows */
        gpio_set_level(KEYPAD_COL3_PIN, 1);

        if (1 == gpio_get_level(KEYPAD_ROW1_PIN))
        {
            /*CLear screen*/
			LCD_sendCommand(0x01) ;
			uint8 string[11] = {"Pressed 3"} ;
			/*Display number on LCD*/
			LCD_sendStringRowCol(1,3,string) ;

            printf("Pressed 3\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }
        else if (1 == gpio_get_level(KEYPAD_ROW2_PIN))
        {
            /*CLear screen*/
			LCD_sendCommand(0x01) ;
			uint8 string[11] = {"Pressed 6"} ;
			/*Display number on LCD*/
			LCD_sendStringRowCol(1,3,string) ;

            printf("Pressed 6\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }
        else if (1 == gpio_get_level(KEYPAD_ROW3_PIN))
        {
            /*CLear screen*/
			LCD_sendCommand(0x01) ;
			uint8 string[11] = {"Pressed 9"} ;
			/*Display number on LCD*/
			LCD_sendStringRowCol(1,3,string) ;

            printf("Pressed 9\n");
            vTaskDelay(400 / portTICK_PERIOD_MS);
        }

        gpio_set_level(KEYPAD_COL3_PIN, 0);

        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}
