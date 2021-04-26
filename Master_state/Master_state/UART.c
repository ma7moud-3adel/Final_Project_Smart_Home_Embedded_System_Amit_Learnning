/*
* UART.c
*
* Created: 2/13/2021 9:11:14 PM
*/


#include "UART.h"


void UART_Init(void)
{
	
	/*Define Direction of Tx*/
	SET_BIT(DDRD, PD1);
	/*Define Direction of Rx*/
	CLR_BIT(DDRD, PD0);
	/*Baud rate value variable*/
	Uint16t UBRR_Val = 0;
	/*Enable Transmitter and Receiver bits*/
	UCSRB = (1 << RXEN) | (1 << TXEN)| (1<<RXCIE);
	/*Full configuration for UART*/
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
	/*Baud Rate Calculations*/
	UBRR_Val = (((FRQ) / (16 * BAUDRATE)) - 1);// 11110101 00111001
	UBRRL = UBRR_Val;//00111001
	UBRRH = UBRR_Val >> 8;//11110101
	
}
void UART_Transmit(Uint8t data)
{
	UDR = data;
	while (GET_BIT(UCSRA, TXC) != 1);
}
Uint8t UART_Receive(void)
{
	while (GET_BIT(UCSRA, RXC) != 1);
	return UDR;
}
/*
Uint8t UART_Receive_Intrrupt(void)
{
	sei();
	
	
}*/
UART_Status UART_RECEIVE(Uint8t* data)
{
	while (GET_BIT(UCSRA, RXC) != 1);
	if(GET_BIT(UCSRA, PE) != 1 && GET_BIT(UCSRA, FE) != 1)
	{
		*data = UDR;
		return UART_OK;
	}
	else
	{
		return UART_NOK;
	}
}
