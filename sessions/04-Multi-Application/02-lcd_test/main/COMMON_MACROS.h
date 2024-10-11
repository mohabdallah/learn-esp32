/*
 * COMMON_MACROS.h
 * Description : Header file for all macros used inside project
 * Created: 12/27/2014
 *  Author: Mohamed Abdallah
 */ 

/*Make sure that the file is not included before*/
#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/*--------------------------------------------------
Description : Macro used to check if a specific bit in a specific register is set
Input : .Register : register name
		.Pin_Num : Pin number to check
--------------------------------------------------*/
#define BIT_IS_SET(Register,Pin_Num) ((Register) & (1<<(Pin_Num)))

/*END OF MACROS DECLARATION*/
#endif /* COMMON_MACROS_H_ */