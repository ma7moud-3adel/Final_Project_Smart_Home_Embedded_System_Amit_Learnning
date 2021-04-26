/*
 * InOut_CONFIG.h
 *
 * Created: 2/26/2021 11:50:30 AM
 */ 


#ifndef INOUT_CONFIG_H_
#define INOUT_CONFIG_H_

#include "CPU_CONFIGURATION.h"
/*Renaming Data direction registers*/

/*Renaming Ports*/
#define BUZZER_PORT DIO_PORTA
#define RELAY_PORT  DIO_PORTA
#define BUTTON0_PORT DIO_PORTB
#define BUTTON1_PORT DIO_PORTD
#define BUTTON2_PORT DIO_PORTD
/*Renaming Pins according to it's position*/
#define BUZZER      DIO_PIN3
#define RELAY       DIO_PIN2
#define BUTTON0     DIO_PIN0
#define BUTTON1     DIO_PIN6
#define BUTTON2     DIO_PIN2
/*Renaming Status*/
#define InOut_INPUT  DIO_PIN_INPUT
#define InOut_OUTPUT DIO_PIN_OUTPUT
#define InOut_LOW  DIO_PIN_LOW
#define InOut_HIGH DIO_PIN_HIGH

#endif /* INOUT_CONFIG_H_ */