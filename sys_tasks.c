/* 
 * File:   sys_tasks.h
 * Author: Cristian T. A.
 *
 * Created on August 17, 2018, 1:26 PM
 */

#include "general.h"
#include "sys_tasks.h"
#include "cal_servo.h"
#include "hal_motor.h"
#include "mcal_init.h"

T_F16 speed = 30;
T_U8 step = 10;
T_U8 angle = 60;
BOOL Direction = FORWARD;

void TASK_Inits()
{
    MCAL_vInit();
    GPIO_u8SetPortPin(PORT_A, 10, DIGITAL, OUTPUT);	

	vSetAngle(angle);

	vMotorInit();
	vSetMotorDir(Direction);
	vSetMotorSpeed(0);
}

void TASK_1ms()
{

}

void TASK_5ms()
{

}

void TASK_10ms()
{   

}

void TASK_100ms()
{ 
//dc motor - test
    vSetMotorSpeed(speed);
}
 
void TASK_500ms()
{ 
//servo - test
	angle += step;
	vSetAngle(angle);
	if(angle > 120 || angle < 60)
	{
		step = -step;
	}
}

void TASK_1000ms()
{

}