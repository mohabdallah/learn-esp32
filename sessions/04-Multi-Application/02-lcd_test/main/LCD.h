/*
 * LCD.h
 * Description : Header file for LCD module that initializes,controls, and sends data to the LCD
 * Created: 1/10/2015 6:57:52 AM
 *  Author: Mohamed Abdallah
 */ 


#ifndef LCD_H_
#define LCD_H_

/*Header file for DIO module which deals directly with HW components*/
#include "DIO.h"

/*Header file of AVR delay module*/
//#include <util/delay.h>

/*Define LCD Data Port, not needed here*/
#define LCD_DATA_COMMANDS_PORT 'A'

/*The start pin while operating in 4-bits mode , requires that the 4 bits to be sequential from LCD_4BITS_MODE_STARTING_PIN to > LCD_4BITS_MODE_STARTING_PIN+3*/
#define LCD_4BITS_MODE_STARTING_PIN 12

/*Define LCD Control bits Port(Not needed here) and Pins*/
#define LCD_CONTROL_PORT 'A'
#define LCD_RS_PIN_NUM 4
#define LCD_RW_PIN_NUM 5
#define LCD_E_PIN_NUM 2


/*Define LCD modes commands*/
#define LCD_8BITS_1LINE_COMMAND 0x30	/*command for 8 bits,1 line mode*/
#define LCD_8BITS_2LINE_COMMAND 0x38	/*command for 8 bits,2 line mode*/
#define LCD_4BITS_1LINE_COMMAND 0x20	/*command for 4 bits,1 line mode*/
#define LCD_4BITS_2LINE_COMMAND 0x28	/*command for 4 bits,2 line mode*/


/*Define LCD mode of operation----------------Choose one of the 4 above definitions and put it here*/
/*------------------------EDIT HERE TO CHANGE LCD MODE OF OPERATION--------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
#define LCD_FUNCTION_SET_COMMAND LCD_4BITS_2LINE_COMMAND


#define LCD_CLEAR_COMMAND 0x01	/*Clear LCD screen*/
#define LCD_ON_COMMAND 0x0C	/*Display on,and specific Cursor status(On,Off)*/


/*--------------------------------------------------------------
Description : Function used to configure and initialize the LCD
Input : None
Output : None
--------------------------------------------------------------*/
void LCD_init(void) ;


/*---------------------------------------------------------------
Description : Function handles command sending to LCD process
Input : uint8 a_command : the command to be sent to LCD
Output : None
---------------------------------------------------------------*/
void LCD_sendCommand(uint8 a_command) ;


/*---------------------------------------------------------------
Description : Function handles data sending to LCD process
Input : uint8 a_character : the data to be sent to LCD
Output : None
---------------------------------------------------------------*/
void LCD_sendCharacter(uint8 a_character) ;


/*---------------------------------------------------------------
Description : Function handles string sending to LCD process
Input : uint8 *a_string_ptr : pointer to the required string
Output : None
---------------------------------------------------------------*/
void LCD_sendString(uint8 *a_string_ptr) ;


/*---------------------------------------------------------------
Description : Function handles integer sending to LCD process
Input : uint8 a_value : Integer to be sent to LCD
Output : None
---------------------------------------------------------------*/
void LCD_sendInteger(uint8 a_value) ;


/*------------------------------------------------------------------------
Description : Function that sends the LCD cursor to specific (row,column)
			  Note : row and col ranges from 0 to max value
Input : uint8 a_row,uint8 a_col : required row and column
Output : None
------------------------------------------------------------------------*/
void LCD_goToRowCol(uint8 a_row,uint8 a_col) ;


/*------------------------------------------------------------------------
Description : Function that writes string on specific (row,column)
			  Note : row and col ranges from 0 to max value
Input : uint8 a_row,uint8 a_col : required row and column
		uint8 *a_string_ptr :  pointer to the required string
Output : None
------------------------------------------------------------------------*/
void LCD_sendStringRowCol(uint8 a_row,uint8 a_col,uint8 *a_string_ptr) ;

#endif /* LCD_H_ */