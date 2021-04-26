/*
 * ADC.h
 *
 * Created: 2/5/2021 9:51:38 PM
 */ 


#ifndef ADC_H_
#define ADC_H_

/*Include configuration file for ADC*/
#include "ADC_CONFIG.h"
/*Function prototypes*/
void ADC_Init(Uint8t channel);/*Initialize ADC*/
Uint16t ADC_Read(void);/*Read value of current ADC*/


#endif /* ADC_H_ */