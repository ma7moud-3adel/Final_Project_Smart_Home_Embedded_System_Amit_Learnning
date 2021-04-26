/*
* UART.h
*
* Created: 2/13/2021 9:11:03 PM
*/


#ifndef UART_H_
#define UART_H_

#include "UART_CONFIG.h"

void UART_Init(void);
void UART_Transmit(Uint8t data);
Uint8t UART_Receive(void);
/*Uint8t UART_Receive_Intrrupt(void);*/
UART_Status UART_RECEIVE(Uint8t* data);

#endif /* UART_H_ */