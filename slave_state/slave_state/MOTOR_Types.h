/*
* MOTOR_Types.h
*
* Created: 10/10/2020 6:50:13 PM
*/


#ifndef MOTOR_TYPES_H_
#define MOTOR_TYPES_H_

#include "CPU_CONFIGURATION.h"

/*Define Motor Types*/
typedef enum
{
	Motor1 = 0,
	Motor2 = 1
}Motor_Channel;
/*Define Motor Direction*/
typedef enum
{
	Forward = 0,
	Backward = 1,
	Stop = 3
}Motor_Direction;
/*Define Motor Status*/
typedef enum
{
	Motor_NOK = 0,
	Motor_OK = 1
}Motor_Status;


#endif /* MOTOR_TYPES_H_ */