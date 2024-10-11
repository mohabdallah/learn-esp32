/*
 * DIO.h
 * Description : Header file for DIO module which deals directly with HW components
 * Created: 12/27/2014 4:11:15 PM
 *  Author: Mohamed Abdallah
 */ 

/*Make sure that the file is not included before*/
#ifndef DIO_H_
#define DIO_H_

/*Header file for all macros used inside project*/
#include "COMMON_MACROS.h"

/*Header file for types declarations and required includes*/
#include "STD_TYPES.h"

#include "driver/gpio.h"


/*Define the meaning of signals deals directly with HW*/
#define INPUT 0
#define OUTPUT 1
#define LOGIC_HIGH 1
#define LOGIC_LOW 0

/*----------------------------------------------------------------------------
Description : contains all information about a specific pin in a specific port
			  used for configuring this pin
Members : .port : port name to configure
		  .pin_num : pin number to configure
		  .direction : pin direction INPUT or OUTPUT
		  .value : initial value for pin if it is output
----------------------------------------------------------------------------*/
typedef struct {
		/*port name to configure*/
		uint8 port ;
		/*pin number to configure*/
		uint8 pin_num ;
		/* pin direction > input , output*/
		uint8 direction ;
		/*value of pin if it is output*/
		uint8 value ;
	}DIO_Config;


/*--------------------------------------------------------------------
Description : function used to configure a specific port
			  using port configuration inside a_s_Config_Msg_ptr
Input : *a_s_Config_Msg_ptr : pointer to structure of type DIO_Config
output : void
--------------------------------------------------------------------*/
void DIO_setDircetion(const DIO_Config *a_s_Config_Msg_ptr) ;

/*-----------------------------------------------------------------------------
Description : function used to write on a specific pin inside
			  a specific port using pin configuration inside a_s_PinStruct_ptr
Input : *a_s_PinStruct_ptr : pointer to structure of type DIO_Config
output : void
-----------------------------------------------------------------------------*/
void DIO_writePin(const DIO_Config *a_s_PinStruct_ptr) ;

/*-------------------------------------------------------------------------------
Description : function used to read a specific pin inside
			  a specific port using port configuration inside a_s_Config_Msg_ptr
Input : *a_s_Config_Msg_ptr : pointer to structure of type DIO_Config
output : uint8 : the current value of the required pin
-------------------------------------------------------------------------------*/
uint8 DIO_readPin(const DIO_Config *a_s_PinStruct_ptr) ;

/*-----------------------------------------------------------------------------
Description : function used to write on a specific port using pin
			  configuration inside a_s_PortStruct_ptr
Input : *a_s_PortStruct_ptr : pointer to structure of type DIO_Config
output : void
-----------------------------------------------------------------------------*/
void DIO_writePort(const DIO_Config *a_s_PortStruct_ptr,uint8 a_value) ;


#endif /* DIO_H_ */