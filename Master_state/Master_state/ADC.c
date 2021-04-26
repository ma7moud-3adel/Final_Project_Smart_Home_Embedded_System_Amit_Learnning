/*
* ADC.c
*
* Created: 2/5/2021 9:51:45 PM
*/

#include "ADC.h"
/*Functions implementations*/
void ADC_Init(Uint8t channel)/*Initialize ADC*/
{
	/*Choose voltage source - AVCC*/
	CLR_BIT(ADMUX, REFS1);SET_BIT(ADMUX, REFS0);
	/*Choose right adjust*/
	CLR_BIT(ADMUX, ADLAR);
	/*Choose channel*/
	switch(channel)
	{
		case ADC0:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);CLR_BIT(ADMUX, MUX2);CLR_BIT(ADMUX, MUX1);CLR_BIT(ADMUX, MUX0);
		break;
		case ADC1:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);CLR_BIT(ADMUX, MUX2);CLR_BIT(ADMUX, MUX1);SET_BIT(ADMUX, MUX0);
		break;
		case ADC2:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);CLR_BIT(ADMUX, MUX2);SET_BIT(ADMUX, MUX1);CLR_BIT(ADMUX, MUX0);
		break;
		case ADC3:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);CLR_BIT(ADMUX, MUX2);SET_BIT(ADMUX, MUX1);SET_BIT(ADMUX, MUX0);
		break;
		case ADC4:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);SET_BIT(ADMUX, MUX2);CLR_BIT(ADMUX, MUX1);CLR_BIT(ADMUX, MUX0);
		break;
		case ADC5:
		break;
		case ADC6:
		break;
		case ADC7:
		break;
	}
	/*
	ADMUX |= 0x01;//Choose channel 0
	ADMUX |= (1 << 1) | (1 << 0);//Choose channel 3
	*/
	/*Use auto trigger mode*/
	//SET_BIT(ADCSRA, ADATE);
	/*Choose Prescaler*/
	SET_BIT(ADCSRA, ADPS2);SET_BIT(ADCSRA, ADPS1);SET_BIT(ADCSRA, ADPS0);
	/*ADC Enable*/
	SET_BIT(ADCSRA,ADIE);
	SET_BIT(ADCSRA, ADEN);
	sei();
	SET_BIT(ADCSRA,ADSC);
}
Uint16t ADC_Read(void)/*Read value of current ADC*/
{
	Uint16t var = 0;
	/*Start of conversion signal - SOC*/
	SET_BIT(ADCSRA, ADSC);
	/*Wait till flag is set automatically - EOC*/
	//while (GET_BIT(ADCSRA, ADIF) != 1);/*Polling mode*/
	/*Return value*/
	var = ADC;
	return var;
}