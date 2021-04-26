/*
* LCD_CONFIG.h
*
* Created: 2/27/2021 12:31:31 PM
*/


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "CPU_CONFIGURATION.h"

#define LCD_CNTRL_PORT    DIO_PORTB
#define LCD_DATA_PORT     DIO_PORTA
					      
#define LCD_PIN0          DIO_PIN0
#define LCD_PIN1          DIO_PIN1
#define LCD_PIN2          DIO_PIN2
#define LCD_PIN3          DIO_PIN3
#define LCD_PIN4          DIO_PIN4
#define LCD_PIN5          DIO_PIN5
#define LCD_PIN6          DIO_PIN6
#define LCD_PIN7          DIO_PIN7

#define LCD_RS            DIO_PIN1
#define LCD_RW            DIO_PIN2
#define LCD_EN            DIO_PIN3

#define LCD_OUTPUT        DIO_PIN_OUTPUT
#define LCD_LOW           DIO_PIN_LOW
#define LCD_HIGH          DIO_PIN_HIGH

#endif /* LCD_CONFIG_H_ */