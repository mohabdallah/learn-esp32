/*
 * DIO.c
 * Description : c file for DIO module which deals directly with HW components
 * Created: 12/27/2014 4:52:59 PM
 *  Author: Mohamed Abdallah
 */ 


/*Header file of current module (DIO module)*/
#include "DIO.h"


/*--------------------------------------------------------------------
Description : function used to configure a specific port
			  using port configuration inside a_s_Config_Msg_ptr
Input : *a_s_Config_Msg_ptr : pointer to structure of type DIO_Config
output : void
--------------------------------------------------------------------*/
void DIO_setDircetion(const DIO_Config *a_s_Config_Msg_ptr) {
	gpio_reset_pin(a_s_Config_Msg_ptr->pin_num);

	/*check direction if input then clear bit value*/
	if (a_s_Config_Msg_ptr->direction == INPUT) {
		gpio_set_direction(a_s_Config_Msg_ptr->pin_num, GPIO_MODE_INPUT);
    	gpio_pullup_dis(a_s_Config_Msg_ptr->pin_num);
    	gpio_pulldown_en(a_s_Config_Msg_ptr->pin_num);
	} else if (a_s_Config_Msg_ptr->direction == OUTPUT) {
		gpio_set_direction(a_s_Config_Msg_ptr->pin_num, GPIO_MODE_OUTPUT);
    	gpio_set_level(a_s_Config_Msg_ptr->pin_num, 0);
	} else {
		/*Nothing*/
	}
}


/*-----------------------------------------------------------------------------
Description : function used to write on a specific pin inside
			  a specific port using pin configuration inside a_s_PinStruct_ptr
Input : *a_s_PinStruct_ptr : pointer to structure of type DIO_Config
output : void
-----------------------------------------------------------------------------*/
void DIO_writePin(const DIO_Config *a_s_PinStruct_ptr) {
	/*check if value is logic low*/
	if (a_s_PinStruct_ptr->value == LOGIC_LOW) {
		gpio_set_level(a_s_PinStruct_ptr->pin_num, 0);
	} else if (a_s_PinStruct_ptr->value == LOGIC_HIGH) {
		gpio_set_level(a_s_PinStruct_ptr->pin_num, 1);
	} else {
		/*Nothing*/
	}
}


/*------------------------------------------------------------------------------
Description : function used to read a specific pin inside
			  a specific port using port configuration inside a_s_PinStruct_ptr
Input : *a_s_PinStruct_ptr : pointer to structure of type DIO_Config
output : uint8 : the current value of the required pin
------------------------------------------------------------------------------*/
uint8 DIO_readPin(const DIO_Config *a_s_PinStruct_ptr) {
	/*used to hold returned value*/
	uint8 pin_state ;
	
	/*check if value of pin is high then out is high*/
	if (1 == gpio_get_level(a_s_PinStruct_ptr->pin_num)) {
		pin_state = LOGIC_HIGH ;
	} else {
		pin_state = LOGIC_LOW ;
	}
	/*return pin state LOGIC_HIGH or LOGIC_LOW*/
	return pin_state ;
}


/*-----------------------------------------------------------------------------
Description : function used to write on a specific port using pin
			  configuration inside a_s_PortStruct_ptr
Input : *a_s_PortStruct_ptr : pointer to structure of type DIO_Config
output : void
-----------------------------------------------------------------------------*/
void DIO_writePort(const DIO_Config *a_s_PortStruct_ptr,uint8 a_value) {
	#warning "NOT IMPLEMENTED, ADAPT IMPLEMENTATION"
}