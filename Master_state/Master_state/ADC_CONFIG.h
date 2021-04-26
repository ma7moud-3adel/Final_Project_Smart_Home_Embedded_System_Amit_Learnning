/*
 * ADC_CONFIG.h
 *
 * Created: 2/5/2021 9:51:29 PM
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_
/*Macros needed for ADC library*/
#include "CPU_CONFIGURATION.h"
/*Define ADC register address in memory*/
/*
#define ADMUX  (*(volatile Uint8t*)(0x27))
#define ADCSRA (*(volatile Uint8t*)(0x26))
#define ADCH   (*(volatile Uint8t*)(0x25))
#define ADCL   (*(volatile Uint8t*)(0x24))
*/
#define ADC    (*(volatile Uint16t*)(0x24))
/*Define names for channel*/
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7
#endif /* ADC_CONFIG_H_ */