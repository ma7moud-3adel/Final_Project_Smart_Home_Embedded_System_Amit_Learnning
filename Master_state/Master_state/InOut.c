/*
 * InOut.c
 *
 * Created: 2/26/2021 11:51:04 AM
 */ 
#include "InOut.h"
 void BUTTON0_Initialize()
 {
	 DIO_SetPin_Direction(BUTTON0_PORT,BUTTON0,InOut_INPUT);
 }
 Uint8t BUTTON0_Read(void)
 {
	 return DIO_ReadPin_Value(BUTTON0_PORT,BUTTON0);
 }
 void BUTTON1_Initialize()
 {
	 DIO_SetPin_Direction(BUTTON1_PORT,BUTTON1,InOut_INPUT);
 }
 Uint8t BUTTON1_Read(void)
 {
	 return DIO_ReadPin_Value(BUTTON1_PORT,BUTTON1);
 }