/*
* DIO.c
*
* Created: 2/27/2021 8:55:16 AM
*/
#include "DIO.h"

void DIO_SetDirection(Uint8t pin, Uint8t direction)
{
	Uint8t port = pin / 8;
	Uint8t pins = pin % 8;
	switch(direction)
	{
		case DIO_PIN_INPUT:
		switch (port)
		{
			case DIO_PORTA:
			CLR_BIT(DDRA, pins);
			break;
			case DIO_PORTB:
			CLR_BIT(DDRB, pins);
			break;
			case DIO_PORTC:
			CLR_BIT(DDRC, pins);
			break;
			case DIO_PORTD:
			CLR_BIT(DDRD, pins);
			break;
		}
		break;
		case DIO_PIN_OUTPUT:
		switch (port)
		{
			case DIO_PORTA:
			SET_BIT(DDRA, pins);
			break;
			case DIO_PORTB:
			SET_BIT(DDRB, pins);
			break;
			case DIO_PORTC:
			SET_BIT(DDRC, pins);
			break;
			case DIO_PORTD:
			SET_BIT(DDRD, pins);
			break;
		}
		break;
	}
}
void DIO_SetValue(Uint8t pin, Uint8t state)
{
	Uint8t port = pin / 8;
	Uint8t pins = pin % 8;
	switch(state)
	{
		case DIO_PIN_LOW:
		switch (port)
		{
			case DIO_PORTA:
			CLR_BIT(PORTA, pins);
			break;
			case DIO_PORTB:
			CLR_BIT(PORTB, pins);
			break;
			case DIO_PORTC:
			CLR_BIT(PORTC, pins);
			break;
			case DIO_PORTD:
			CLR_BIT(PORTD, pins);
			break;
		}
		break;
		case DIO_PIN_HIGH:
		switch (port)
		{
			case DIO_PORTA:
			SET_BIT(PORTA, pins);
			break;
			case DIO_PORTB:
			SET_BIT(PORTB, pins);
			break;
			case DIO_PORTC:
			SET_BIT(PORTC, pins);
			break;
			case DIO_PORTD:
			SET_BIT(PORTD, pins);
			break;
		}
		break;
	}
}
Uint8t DIO_ReadValue(Uint8t pin)
{
	Uint8t port = pin / 8;
	Uint8t pins = pin % 8;
	Uint8t val = 0;
	switch(port)
	{
		case DIO_PORTA:
		val = GET_BIT(PINA, pins);
		break;
		case DIO_PORTB:
		val = GET_BIT(PINB, pins);
		break;
		case DIO_PORTC:
		val = GET_BIT(PINC, pins);
		break;
		case DIO_PORTD:
		val = GET_BIT(PIND, pins);
		break;
	}
	return val;
}

void DIO_SetPin_Direction(Uint8t port, Uint8t pin, Uint8t direction)
{
	switch(direction)
	{
		case DIO_PIN_INPUT:
		switch (port)
		{
			case DIO_PORTA:
			CLR_BIT(DDRA, pin);
			break;
			case DIO_PORTB:
			CLR_BIT(DDRB, pin);
			break;
			case DIO_PORTC:
			CLR_BIT(DDRC, pin);
			break;
			case DIO_PORTD:
			CLR_BIT(DDRD, pin);
			break;
		}
		break;
		case DIO_PIN_OUTPUT:
		switch (port)
		{
			case DIO_PORTA:
			SET_BIT(DDRA, pin);
			break;
			case DIO_PORTB:
			SET_BIT(DDRB, pin);
			break;
			case DIO_PORTC:
			SET_BIT(DDRC, pin);
			break;
			case DIO_PORTD:
			SET_BIT(DDRD, pin);
			break;
		}
		break;
	}
}
void DIO_SetPin_Value(Uint8t port, Uint8t pin, Uint8t state)
{
	switch(state)
	{
		case DIO_PIN_LOW:
		switch (port)
		{
			case DIO_PORTA:
			CLR_BIT(PORTA, pin);
			break;
			case DIO_PORTB:
			CLR_BIT(PORTB, pin);
			break;
			case DIO_PORTC:
			CLR_BIT(PORTC, pin);
			break;
			case DIO_PORTD:
			CLR_BIT(PORTD, pin);
			break;
		}
		break;
		case DIO_PIN_HIGH:
		switch (port)
		{
			case DIO_PORTA:
			SET_BIT(PORTA, pin);
			break;
			case DIO_PORTB:
			SET_BIT(PORTB, pin);
			break;
			case DIO_PORTC:
			SET_BIT(PORTC, pin);
			break;
			case DIO_PORTD:
			SET_BIT(PORTD, pin);
			break;
		}
		break;
	}
}
void DIO_TogglePin_Value(Uint8t port, Uint8t pin)
{
	switch(port)
	{
		case DIO_PORTA:
		TGL_BIT(PORTA, pin);
		break;
		case DIO_PORTB:
		TGL_BIT(PORTB, pin);
		break;
		case DIO_PORTC:
		TGL_BIT(PORTC, pin);
		break;
		case DIO_PORTD:
		TGL_BIT(PORTD, pin);
		break;
	}
}
Uint8t DIO_ReadPin_Value(Uint8t port, Uint8t pin)
{
	Uint8t val = 0;
	switch(port)
	{
		case DIO_PORTA:
		val = GET_BIT(PINA, pin);
		break;
		case DIO_PORTB:
		val = GET_BIT(PINB, pin);
		break;
		case DIO_PORTC:
		val = GET_BIT(PINC, pin);
		break;
		case DIO_PORTD:
		val = GET_BIT(PIND, pin);
		break;
	}
	return val;
}

void DIO_SetPort_Direction(Uint8t port, Uint8t direction)
{
	switch(direction)
	{
		case DIO_PORT_INPUT:
		switch (port)
		{
			case DIO_PORTA:
			DDRA = 0x00;
			break;
			case DIO_PORTB:
			DDRB = 0x00;
			break;
			case DIO_PORTC:
			DDRC = 0x00;
			break;
			case DIO_PORTD:
			DDRD = 0x00;
			break;
		}
		break;
		case DIO_PORT_OUTPUT:
		switch (port)
		{
			case DIO_PORTA:
			DDRA = 0xFF;
			break;
			case DIO_PORTB:
			DDRB = 0xFF;
			break;
			case DIO_PORTC:
			DDRC = 0xFF;
			break;
			case DIO_PORTD:
			DDRD = 0xFF;
			break;
		}
		break;
	}
}
void DIO_SetPort_Value(Uint8t port, Uint8t state)
{
	
}
void DIO_TogglePort_Value(Uint8t port, Uint8t pin)
{
	
}
Uint8t DIO_ReadPort_Value(Uint8t port)
{
	return 0;
}


