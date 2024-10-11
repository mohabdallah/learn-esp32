/*
 * LCD.c
 * Description : LCD module that initializes,controls, and sends data to the LCD
 * Created: 1/10/2015 7:08:35 AM
 *  Author: Mohamed Abdallah
 */ 

/*Header file of current module (LCD module)*/
#include "LCD.h"

/*global Structure contains LCD data port configurations */
DIO_Config g_s_lcdDataPortConfig ;

/*global Structure contains LCD control port(first 3 pins for control bits RS,RW,E) configurations */
DIO_Config g_s_lcdControlPortConfig ;


/*---------------------------------------------------------------
Description : Function fills the global structure g_s_lcdDataPortConfig
			  with LCD information , called by LCD_init function
Input : None
Output : None
---------------------------------------------------------------*/
 static void LCD_config (void) {
	 /*configure which port connected to LCD Data pins*/
	 g_s_lcdDataPortConfig.port = LCD_DATA_COMMANDS_PORT ;
	 /*configure which pin is used now, used in configuration step*/
	 g_s_lcdDataPortConfig.pin_num = 0 ;	/*initially will start configuration fro pin 0*/
	 /*configure PORT status as output*/
	 g_s_lcdDataPortConfig.direction = OUTPUT ;
	 
	 /*configure which port connected to LCD Control pins*/
	 g_s_lcdControlPortConfig.port = LCD_CONTROL_PORT ;
	 /*configure PORT status as output*/
	 g_s_lcdControlPortConfig.direction = OUTPUT ;
 }
 
 
 
 /*--------------------------------------------------------------
 Description : Function used to configure and initialize the LCD
			   Data/Commands Port pins as output
 Input : None
 Output : None
 --------------------------------------------------------------*/
 static void LCD_initDataCommandsPort(void) {
	 /*counter used inside for loops*/
	 uint8  i = 0 ;
	 
	 /*Check on mode of operation*/
	if ((LCD_FUNCTION_SET_COMMAND==LCD_8BITS_1LINE_COMMAND) || (LCD_FUNCTION_SET_COMMAND==LCD_8BITS_2LINE_COMMAND)) {	/*one of the two (8-bits modes)*/
		for (i=0;i<8;i++) {		/*loop on all 8 Pins and configure them as output*/
			/*Set pin to be configured to current counter value*/
			g_s_lcdDataPortConfig.pin_num = i ;
			/*Call the DIO to configure the pin direction of LCD as output*/
			DIO_setDircetion(&g_s_lcdDataPortConfig) ;
		}
	} else if ((LCD_FUNCTION_SET_COMMAND==LCD_4BITS_1LINE_COMMAND) || (LCD_FUNCTION_SET_COMMAND==LCD_4BITS_2LINE_COMMAND)) {	/*one of the two (4-bits modes)*/
		for (i=LCD_4BITS_MODE_STARTING_PIN;i<(LCD_4BITS_MODE_STARTING_PIN+4);i++) {		/*loop on second 4 Pins of LCD PORT and configure them as output*/
			/*Set pin to be configured to current counter value*/
			g_s_lcdDataPortConfig.pin_num = i ;
			/*Call the DIO to configure the pin direction of LCD as output*/
			DIO_setDircetion(&g_s_lcdDataPortConfig) ;
		}
	} else {
		/*NOTHING*/
	}
 }
 
 
  /*--------------------------------------------------------------
 Description : Function used to configure and initialize the LCD
			   Control-Port pins as output
 Input : None
 Output : None
 --------------------------------------------------------------*/
 static void LCD_initControlPort(void) {
	 /*Configure RS control-bit pin*/
	 g_s_lcdControlPortConfig.pin_num = LCD_RS_PIN_NUM ;
	 DIO_setDircetion(&g_s_lcdControlPortConfig) ;
	 
	 /*Configure RW control-bit pin*/
	 g_s_lcdControlPortConfig.pin_num = LCD_RW_PIN_NUM ;
	 DIO_setDircetion(&g_s_lcdControlPortConfig) ;
	 
	 /*Configure E control-bit pin*/
	 g_s_lcdControlPortConfig.pin_num = LCD_E_PIN_NUM ;
	 DIO_setDircetion(&g_s_lcdControlPortConfig) ;
 }


/*--------------------------------------------------------------
Description : Function used to configure and initialize the LCD
Input : None
Output : None
--------------------------------------------------------------*/
void LCD_init(void) {
	/*Complete the LCD configuration structure*/
	LCD_config() ;
	
	/*configure and initialize the LCD Data/Commands Port pins as output*/
	LCD_initDataCommandsPort() ;
	
	/*configure and initialize the LCD Control Port pins as output*/
	LCD_initControlPort() ;
	
	/*Send initialization commands to LED*/
	if ((LCD_FUNCTION_SET_COMMAND==LCD_4BITS_1LINE_COMMAND) || (LCD_FUNCTION_SET_COMMAND==LCD_4BITS_2LINE_COMMAND)) {	/*one of the two (4-bits modes)*/
		LCD_sendCommand(0x33) ;		/*should send 0x33 and 0x32 commands first before the next commands(from data sheet)*/
		LCD_sendCommand(0x32) ;
	}		
	
	/*Do the following in all cases (8bits or 4bits mode)*/
	LCD_sendCommand(LCD_FUNCTION_SET_COMMAND) ;	/*Define LCD mode of operation*/
	LCD_sendCommand(LCD_ON_COMMAND) ;	/*Clear LCD screen*/
	LCD_sendCommand(LCD_CLEAR_COMMAND) ;	/*Display on,and specific Cursor status(On,Off)*/
}



/*---------------------------------------------------------------
Description : Function handles command sending to LCD process
Input : uint8 a_command : the command to be sent to LCD
Output : None
---------------------------------------------------------------*/
void LCD_sendCommand(uint8 a_command) {
	/*counter used inside for loops*/
	uint8  i = 0,j=0 ;
	
	/*RS=0 > CLD command mode select*/
	g_s_lcdControlPortConfig.pin_num = LCD_RS_PIN_NUM ;
	g_s_lcdControlPortConfig.value = LOGIC_LOW ;
	DIO_writePin(&g_s_lcdControlPortConfig) ;
	
	/*RW=0 > Write operation to LCD*/
	g_s_lcdControlPortConfig.pin_num = LCD_RW_PIN_NUM ;
	g_s_lcdControlPortConfig.value = LOGIC_LOW ;
	DIO_writePin(&g_s_lcdControlPortConfig) ;
	
	/*delay before next steps > a must step obtained form LCD datasheet*/
	_delay_ms(30) ;
	
	/*Send command to LCD , if 8-bit mode send data in on step using all port pins , if 4-bit mode send only to the required 4 pins*/
	if ((LCD_FUNCTION_SET_COMMAND==LCD_8BITS_1LINE_COMMAND) || (LCD_FUNCTION_SET_COMMAND==LCD_8BITS_2LINE_COMMAND)) {	/*one of the two (8-bits modes)*/

		/*E=1 > Enable the LCD to start receiving the command*/
		g_s_lcdControlPortConfig.pin_num = LCD_E_PIN_NUM ;
		g_s_lcdControlPortConfig.value = LOGIC_HIGH ;
		DIO_writePin(&g_s_lcdControlPortConfig) ;
		
		/*delay before next steps > a must step obtained form LCD datasheet*/
		_delay_ms(30) ;
		
		/*send command to LCD*/
		DIO_writePort(&g_s_lcdDataPortConfig,a_command) ;
		
		/*delay before next steps > a must step obtained form LCD datasheet*/
		_delay_ms(30) ;
		
	} else if ((LCD_FUNCTION_SET_COMMAND==LCD_4BITS_1LINE_COMMAND) || (LCD_FUNCTION_SET_COMMAND==LCD_4BITS_2LINE_COMMAND)) {	/*one of the two (4-bits modes)*/
		/*send command to LCD, this will send the most significant nipple*/
		for (i=LCD_4BITS_MODE_STARTING_PIN,j=4;i<(LCD_4BITS_MODE_STARTING_PIN+4);i++,j++) {		/*Loop on the 4 pins connected to LCD data pins starting from LCD_4BITS_MODE_STARTING_PIN to > LCD_4BITS_MODE_STARTING_PIN+3 (must be sequentially connected)*/
			/*start at pin i*/
			g_s_lcdDataPortConfig.pin_num = i ;
			/*check if the corresponding bit is LOGIC_HIGH or LOGIC_LOW*/
			if (BIT_IS_SET(a_command,j)) {
				/*if LOGIC_HIGH then set the corresponding Pin to LOGIC_HIGH*/
				g_s_lcdDataPortConfig.value = LOGIC_HIGH ;
			} else {	/*if LOGIC_LOW then set the corresponding Pin to LOGIC_LOW*/
				g_s_lcdDataPortConfig.value = LOGIC_LOW ;
			}
			/*Send the data to LCD*/
			DIO_writePin(&g_s_lcdDataPortConfig) ;
		}
		
		/*E=1 > Then enable the LCD to start receiving the command*/
		g_s_lcdControlPortConfig.pin_num = LCD_E_PIN_NUM ;
		g_s_lcdControlPortConfig.value = LOGIC_HIGH ;
		DIO_writePin(&g_s_lcdControlPortConfig) ;
			
		/*delay before next steps > a must step obtained form LCD datasheet*/
		_delay_ms(30) ;
		
		/*E=0 > Disables the LCD to stop receiving commands*/
		g_s_lcdControlPortConfig.pin_num = LCD_E_PIN_NUM ;
		g_s_lcdControlPortConfig.value = LOGIC_LOW ;
		DIO_writePin(&g_s_lcdControlPortConfig) ;
			
		/*delay before next steps > a must step obtained form LCD datasheet*/
		_delay_ms(30) ;
			
		/*shift command left 4 steps to send the command least significant nipple*/
		a_command = (a_command<<4) ;
		
		/*send command to LCD, this will send the least significant nipple*/
		for (i=LCD_4BITS_MODE_STARTING_PIN,j=4;i<(LCD_4BITS_MODE_STARTING_PIN+4);i++,j++) {		/*Loop on the 4 pins connected to LCD data pins starting from LCD_4BITS_MODE_STARTING_PIN to > LCD_4BITS_MODE_STARTING_PIN+3 (must be sequentially connected)*/
			/*start at pin i*/
			g_s_lcdDataPortConfig.pin_num = i ;
			/*check if the corresponding bit is LOGIC_HIGH or LOGIC_LOW*/
			if (BIT_IS_SET(a_command,j)) {
				/*if LOGIC_HIGH then set the corresponding Pin to LOGIC_HIGH*/
				g_s_lcdDataPortConfig.value = LOGIC_HIGH ;
			} else {
				/*if LOGIC_LOW then set the corresponding Pin to LOGIC_LOW*/
				g_s_lcdDataPortConfig.value = LOGIC_LOW ;
			}
			/*Send the data to LCD*/
			DIO_writePin(&g_s_lcdDataPortConfig) ;
		}
			
		/*E=1 > Then enable the LCD to start receiving the command*/
		g_s_lcdControlPortConfig.pin_num = LCD_E_PIN_NUM ;
		g_s_lcdControlPortConfig.value = LOGIC_HIGH ;
		DIO_writePin(&g_s_lcdControlPortConfig) ;
			
		/*delay before next steps > a must step obtained form LCD datasheet*/
		_delay_ms(30) ;
		
	} else {
		/*Nothing*/
	}
	
	/*E=0 > Disables the LCD to stop receiving commands*/
	g_s_lcdControlPortConfig.pin_num = LCD_E_PIN_NUM ;
	g_s_lcdControlPortConfig.value = LOGIC_LOW ;
	DIO_writePin(&g_s_lcdControlPortConfig) ;
	
	/*delay before next steps > a must step obtained form LCD datasheet*/
	_delay_ms(30) ;
}



/*---------------------------------------------------------------
Description : Function handles character sending to LCD process
Input : uint8 a_character : the character to be sent to LCD
Output : None
---------------------------------------------------------------*/
 void LCD_sendCharacter(uint8 a_character) {
	 /*counter used inside for loops*/
	 uint8  i = 0,j=0 ;
	 
	 /*RS=1 > LCD data mode select*/
	 g_s_lcdControlPortConfig.pin_num = LCD_RS_PIN_NUM ;
	 g_s_lcdControlPortConfig.value = LOGIC_HIGH ;
	 DIO_writePin(&g_s_lcdControlPortConfig) ;
	 
	 /*RW=0 > Write operation to LCD*/
	 g_s_lcdControlPortConfig.pin_num = LCD_RW_PIN_NUM ;
	 g_s_lcdControlPortConfig.value = LOGIC_LOW ;
	 DIO_writePin(&g_s_lcdControlPortConfig) ;
	 
	 /*delay before next steps > a must step obtained form LCD datasheet*/
	 _delay_ms(30) ;
	 
	 /*Send character to LCD , if 8-bit mode send data in on step using all port pins , if 4-bit mode send only to the required 4 pins*/
	 if ((LCD_FUNCTION_SET_COMMAND==LCD_8BITS_1LINE_COMMAND) || (LCD_FUNCTION_SET_COMMAND==LCD_8BITS_2LINE_COMMAND)) {	/*one of the two (8-bits modes)*/
		
		/*E=1 > Enable the LCD to start receiving the command*/
		g_s_lcdControlPortConfig.pin_num = LCD_E_PIN_NUM ;
		g_s_lcdControlPortConfig.value = LOGIC_HIGH ;
		DIO_writePin(&g_s_lcdControlPortConfig) ;
		
		/*delay before next steps > a must step obtained form LCD datasheet*/
		_delay_ms(30) ;
		
		/*send character to LCD*/
		DIO_writePort(&g_s_lcdDataPortConfig,a_character) ;
		
		/*delay before next steps > a must step obtained form LCD datasheet*/
		_delay_ms(30) ;
		
	} else if ((LCD_FUNCTION_SET_COMMAND==LCD_4BITS_1LINE_COMMAND) || (LCD_FUNCTION_SET_COMMAND==LCD_4BITS_2LINE_COMMAND)) {	/*one of the two (4-bits modes)*/
			/*send character to LCD, this will send the most significant nipple*/
			for (i=LCD_4BITS_MODE_STARTING_PIN,j=4;i<(LCD_4BITS_MODE_STARTING_PIN+4);i++,j++) {/*Loop on the 4 pins connected to LCD data pins starting from LCD_4BITS_MODE_STARTING_PIN to > LCD_4BITS_MODE_STARTING_PIN+3 (must be sequentially connected)*/
				/*start at pin i*/
				g_s_lcdDataPortConfig.pin_num = i ;
				/*check if the corresponding bit is LOGIC_HIGH or LOGIC_LOW*/
				if (BIT_IS_SET(a_character,j)) {
					/*if LOGIC_HIGH then set the corresponding Pin to LOGIC_HIGH*/
					g_s_lcdDataPortConfig.value = LOGIC_HIGH ;
				} else {
					/*if LOGIC_LOW then set the corresponding Pin to LOGIC_LOW*/
					g_s_lcdDataPortConfig.value = LOGIC_LOW ;
				}
				/*Send the data to LCD*/
				DIO_writePin(&g_s_lcdDataPortConfig) ;
			}
			
			/*E=1 > Enable the LCD to start receiving the command*/
			g_s_lcdControlPortConfig.pin_num = LCD_E_PIN_NUM ;
			g_s_lcdControlPortConfig.value = LOGIC_HIGH ;
			DIO_writePin(&g_s_lcdControlPortConfig) ;
			
			/*delay before next steps > a must step obtained form LCD datasheet*/
			_delay_ms(30) ;
			
			/*E=0 > Disables the LCD to stop receiving commands*/
			g_s_lcdControlPortConfig.pin_num = LCD_E_PIN_NUM ;
			g_s_lcdControlPortConfig.value = LOGIC_LOW ;
			DIO_writePin(&g_s_lcdControlPortConfig) ;
			
			/*delay before next steps > a must step obtained form LCD datasheet*/
			_delay_ms(30) ;
			
			/*shift character left 4 steps to send the character least significant nipple*/
			a_character = (a_character<<4) ;
			
			/*send character to LCD, this will send the least significant nipple*/
			for (i=LCD_4BITS_MODE_STARTING_PIN,j=4;i<(LCD_4BITS_MODE_STARTING_PIN+4);i++,j++) {
				g_s_lcdDataPortConfig.pin_num = i ;
				if (BIT_IS_SET(a_character,j)) {
					g_s_lcdDataPortConfig.value = LOGIC_HIGH ;
				} else {
					g_s_lcdDataPortConfig.value = LOGIC_LOW ;
				}
				DIO_writePin(&g_s_lcdDataPortConfig) ;
			}
			
			/*E=1 > Enable the LCD to start receiving the command*/
			g_s_lcdControlPortConfig.pin_num = LCD_E_PIN_NUM ;
			g_s_lcdControlPortConfig.value = LOGIC_HIGH ;
			DIO_writePin(&g_s_lcdControlPortConfig) ;
			
			/*delay before next steps > a must step obtained form LCD datasheet*/
			_delay_ms(30) ;
			
	} else {
		/*Nothing*/
	}		
	 
	 /*E=0 > Disables the LCD to stop receiving data*/
	 g_s_lcdControlPortConfig.pin_num = LCD_E_PIN_NUM ;
	 g_s_lcdControlPortConfig.value = LOGIC_LOW ;
	 DIO_writePin(&g_s_lcdControlPortConfig) ;
	 
	 /*delay before next steps > a must step obtained form LCD datasheet*/
	 _delay_ms(30) ;
 }
 
 
/*---------------------------------------------------------------
Description : Function handles string sending to LCD process
Input : uint8 *a_string_ptr : pointer to the required string
Output : None
---------------------------------------------------------------*/
 void LCD_sendString(uint8 *a_string_ptr) {
	 /*counter used inside for loops*/
	 uint8  i = 0 ;
	 
	 /*send characters of string one by one to LCD till reaching the NULL*/
	 for (i=0;a_string_ptr[i]!='\0';i++) {
		 LCD_sendCharacter(a_string_ptr[i]) ;
	}
}


/*---------------------------------------------------------------
Description : Function converts integer to string to be able to
			  display it on LCD, then  display it
Input : uint8 a_value : Integer to be converted and sent to LCD
Output : None
---------------------------------------------------------------*/
static void LCD_integerToString(uint8 a_value) {
	/*Temporary array to hold the output of integer to string conversion*/
	char temp[16] ;	/*size is 16 given that LCD max characters per line is 16 character*/
	
	/*Convert the given integer to string and store result in temp*/
	itoa(a_value,temp,10) ;
	
	/*Display result on LCD*/
	LCD_sendString((uint8*)temp);
}


/*---------------------------------------------------------------
Description : Function handles integer sending to LCD process
Input : uint8 a_value : Integer to be sent to LCD
Output : None
---------------------------------------------------------------*/
void LCD_sendInteger(uint8 a_value) {
	/*Converts integer to string to be able to display it on LCD, then  display it*/
	LCD_integerToString(a_value) ;
}


/*------------------------------------------------------------------------
Description : Function that sends the LCD cursor to specific (row,column)
			  Note : row and col ranges from 0 to max value
Input : uint8 a_row,uint8 a_col : required row and column
Output : None
------------------------------------------------------------------------*/
void LCD_goToRowCol(uint8 a_row,uint8 a_col) {
	/*Used to store the address of the required cursor place*/
	uint8 address = 0 ;
	
	/*check which row is required*/
	switch (a_row) {
		case 0 :	/*if row = 0 , then address is same as col value(from LCD data sheet)*/
			address = a_col ;
			break ;
		
		case 1 :	/*if row = 1 , then address is col value + 0x40(from LCD data sheet)*/
			address = a_col + 0x40 ;
			break ;
			
		case 2 :	/*if row = 2 , then address is col value + 0x10(from LCD data sheet)*/
		address = a_col + 0x10 ;
		break ;
		
		case 3 :	/*if row = 3 , then address is col value + 0x50(from LCD data sheet)*/
		address = a_col + 0x50 ;
		break ;
		
		default :
			/*Nothing*/
			break ;
	}
	
	/*Send address of required position as a command to LCD, ORed with(Added to) 0x80(from LCD data sheet)*/
	LCD_sendCommand(address | 0x80) ;
}



/*------------------------------------------------------------------------
Description : Function that writes string on specific (row,column)
			  Note : row and col ranges from 0 to max value
Input : uint8 a_row,uint8 a_col : required row and column
		uint8 *a_string_ptr : required string
Output : None
------------------------------------------------------------------------*/
void LCD_sendStringRowCol(uint8 a_row,uint8 a_col,uint8 *a_string_ptr) {
	/*Send LCD cursor to (row=a_row,column=a_col)*/
	LCD_goToRowCol(a_row,a_col) ;

	/*Write required string on LCD*/
	LCD_sendString(a_string_ptr) ;
}