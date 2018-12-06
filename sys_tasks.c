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
#include "hal_lf.h"

T_F16 speed = 30;
T_U8 step = 10;
T_U8 angle = 90;
BOOL Direction = FORWARD;
T_U8 lfVal = 0;

void TASK_Inits()
{
    MCAL_vInit();
    GPIO_u8SetPortPin(PORT_A, 10, DIGITAL, OUTPUT);	
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
//line follower test
	lfVal = LF_u8ReadPins();
	if(lfVal != 0)
	{
		vSetMotorSpeed(20); 
	}
	else
	{
		vSetMotorSpeed(0); 
	}			
}

void TASK_100ms()
{ 
//dc motor - test
}
 
void TASK_500ms()
{ 
//servo - test
}

void TASK_1000ms()
{

}