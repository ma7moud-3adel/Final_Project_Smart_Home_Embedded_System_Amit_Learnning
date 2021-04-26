/*
* LED_CONFIG.h
*
* Created: 2/26/2021 11:30:29 AM
*/


#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_
/*
What should i write in the configuration file ?
1- Macros
2- Address of registers
3- Renaming Ports
4- Renaming Pins
5- Renaming status
*/
#include "CPU_CONFIGURATION.h"

#define LED0_PORT             DIO_PORTC
#define LED1_PORT             DIO_PORTC
#define LED2_PORT             DIO_PORTD

#define LED0_PIN              DIO_PIN2
#define LED1_PIN              DIO_PIN7
#define LED2_PIN              DIO_PIN3

#define LED_OUTPUT            DIO_PIN_OUTPUT

#define LED_LOW               DIO_PIN_LOW
#define LED_HIGH              DIO_PIN_HIGH

#endif /* LED_CONFIG_H_ */