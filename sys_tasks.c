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
#include "ASW.h"

void TASK_Inits()
{
    MCAL_vInit();
    GPIO_u8SetPortPin(PORT_A, 10, DIGITAL, OUTPUT);	
	vInit_Everything();
}

void TASK_1ms()
{

}

void TASK_5ms()
{
	vFollower();
}

void TASK_10ms()
{   
	
}

void TASK_100ms()
{ 

}
 
void TASK_500ms()
{ 

}

void TASK_1000ms()
{

}