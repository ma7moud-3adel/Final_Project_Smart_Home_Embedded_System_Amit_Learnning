/*
* UART_CONFIG.h
*
* Created: 2/13/2021 9:10:53 PM
*/


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#include "CPU_CONFIGURATION.h"
/*
#define UBRRL (*(volatile Uint8t*)(0x29))
#define UBRRH (*(volatile Uint8t*)(0x40))
#define UCSRA (*(volatile Uint8t*)(0x2B))
#define UCSRB (*(volatile Uint8t*)(0x29A)
#define UCSRC (*(volatile Uint8t*)(0x40))
#define UDR   (*(volatile Uint8t*)(0x2C))
*/
#define FRQ      160000
#define BAUDRATE 96

typedef enum
{
	UART_NOK = 0,
	UART_OK = 1
}UART_Status;



#endif /* UART_CONFIG_H_ */