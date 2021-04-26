/*
* MOTOR.h
*
* Created: 10/10/2020 6:50:27 PM
*/


#ifndef MOTOR_H_
#define MOTOR_H_


#include "MOTOR_Types.h"

/*Motor Initialization*/
Motor_Status Motor_Init(Motor_Channel channel);
/*Motor1 Enable*/
Motor_Status Motor1_Enable(void);
/*Motor1 Disable*/
Motor_Status Motor1_Disable(void);
/*Motor1 Direction*/
Motor_Status Motor1_Direction(Motor_Direction direction);
/*Motor1 Enable*/
Motor_Status Motor2_Enable(void);
/*Motor1 Disable*/
Motor_Status Motor2_Disable(void);
/*Motor1 Direction*/
Motor_Status Motor2_Direction(Motor_Direction direction);

#endif /* MOTOR_H_ */