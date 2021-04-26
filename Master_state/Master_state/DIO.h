/*
* DIO.h
*
* Created: 2/27/2021 8:55:04 AM
*/


#ifndef DIO_H_
#define DIO_H_

#include "DIO_CONFIG.h"

void DIO_SetDirection(Uint8t pin, Uint8t direction);
void DIO_SetValue(Uint8t pin, Uint8t state);
Uint8t DIO_ReadValue(Uint8t pin);

void DIO_SetPin_Direction(Uint8t port, Uint8t pin, Uint8t direction);
void DIO_SetPin_Value(Uint8t port, Uint8t pin, Uint8t state);
void DIO_TogglePin_Value(Uint8t port, Uint8t pin);
Uint8t DIO_ReadPin_Value(Uint8t port, Uint8t pin);

void DIO_SetPort_Direction(Uint8t port, Uint8t direction);
void DIO_SetPort_Value(Uint8t port, Uint8t state);
void DIO_TogglePort_Value(Uint8t port, Uint8t pin);
Uint8t DIO_ReadPort_Value(Uint8t port);


#endif /* DIO_H_ */