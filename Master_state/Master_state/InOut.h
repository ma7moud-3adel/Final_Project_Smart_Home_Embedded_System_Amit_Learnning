/*
 * InOut.h
 *
 * Created: 2/26/2021 11:50:45 AM
 */ 


#ifndef INOUT_H_
#define INOUT_H_

#include "InOut_CONFIG.h"

void BUZZER_Initialize(void);
void BUZZER_ON(void);
void BUZZER_OFF(void);
void BUZZER_TGL(void);

void RELAY_Initialize(void);
void RELAY_ON(void);
void RELAY_OFF(void);
void RELAY_TGL(void);

void BUTTON0_Initialize(void);
Uint8t BUTTON0_Read(void);

void BUTTON1_Initialize(void);
Uint8t BUTTON1_Read(void);

void BUTTON2_Initialize(void);
Uint8t BUTTON2_Read(void);

#endif /* INOUT_H_ */