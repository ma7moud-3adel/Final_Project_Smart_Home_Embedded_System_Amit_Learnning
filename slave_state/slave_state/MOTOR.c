/*
* MOTOR.c
*
* Created: 10/10/2020 6:50:59 PM
*/

#include "MOTOR.h"

/*Motor Initialization and define direction*/
Motor_Status Motor_Init(Motor_Channel channel)
{
	switch (channel)
	{
		case Motor1:
		DIO_SetPin_Direction(DIO_PORTD, DIO_PIN4, DIO_PIN_OUTPUT);/*Define direction for the enable as output*/
		DIO_SetPin_Direction(DIO_PORTC, DIO_PIN3, DIO_PIN_OUTPUT);/*Define direction for the direction A1*/
		DIO_SetPin_Direction(DIO_PORTC, DIO_PIN4, DIO_PIN_OUTPUT);/*Define direction for the direction A2*/
		/*
		SET_BIT(DDRD, PD4);
		SET_BIT(DDRC, PC3);
		SET_BIT(DDRC, PC4);
		*/
		break;
		case Motor2:
		DIO_SetPin_Direction(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);/*Define direction for the enable as output*/
		DIO_SetPin_Direction(DIO_PORTC, DIO_PIN5, DIO_PIN_OUTPUT);/*Define direction for the direction A3*/
		DIO_SetPin_Direction(DIO_PORTC, DIO_PIN6, DIO_PIN_OUTPUT);/*Define direction for the direction A4*/
		/*
		SET_BIT(DDRD, PD5);
		SET_BIT(DDRC, PC5);
		SET_BIT(DDRC, PC6);
		*/
		break;
	}
	return Motor_OK;
}
/*Motor1 Enable*/
Motor_Status Motor1_Enable(void)
{
	SET_BIT(PORTD, PD4);/*Enable Motor*/
	return Motor_OK;
}
/*Motor1 Disable*/
Motor_Status Motor1_Disable(void)
{
	SET_BIT(PORTD, PD4);/*Disable Motor*/
	return Motor_OK;
}
/*Motor1 Direction*/
Motor_Status Motor1_Direction(Motor_Direction direction)
{
	switch (direction)
	{
		case Forward:
		SET_BIT(PORTC, PC3);
		CLR_BIT(PORTC, PC4);
		break;
		case Backward:
		SET_BIT(PORTC, PC4);
		CLR_BIT(PORTC, PC3);
		break;
		case Stop:
		CLR_BIT(PORTC, PC3);
		CLR_BIT(PORTC, PC4);
		break;
	}
	return Motor_OK;
}
/*Motor2 Enable*/
Motor_Status Motor2_Enable(void)
{
	SET_BIT(PORTD, PD5);/*Motor Enable*/
	return Motor_OK;
}
/*Motor2 Disable*/
Motor_Status Motor2_Disable(void)
{
	CLR_BIT(PORTD, PD5);/*Motor Disable*/
	return Motor_OK;
}
/*Motor2 Direction*/
Motor_Status Motor2_Direction(Motor_Direction direction)
{
	switch (direction)
	{
		case Forward:
		SET_BIT(PORTC, PC5);
		CLR_BIT(PORTC, PC6);
		break;
		case Backward:
		SET_BIT(PORTC, PC6);
		CLR_BIT(PORTC, PC5);
		break;
		case Stop:
		CLR_BIT(PORTC, PC5);
		CLR_BIT(PORTC, PC6);
		break;
	}
	return Motor_OK;
}