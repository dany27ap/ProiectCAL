#include "ASW.h"

void vInit_Everything()
{
	RTE_vMotorInit();
	RTE_vSetMotorDir(FORWARD);
	RTE_vSetMotorSpeed(0);
	RTE_vSetAngle(90);
}

void vFollower()
{
	T_U8 readPins = RTE_LF_u8ReadPins();
	static T_U8 angle = 90;
	static T_U8 lastAngle = 90;
	static T_U16 whiteCounter = 0;
	if(readPins != 0)
	{	
		RTE_vSetMotorSpeed(20);
		switch(readPins)
		{
			case 0b001100: 
				angle = 90;
				lastAngle = angle;
				break;
			case 0b000110: 
				angle = 110;
				lastAngle = angle;
				break;
			case 0b000011: 
				angle = 120;
				lastAngle = angle;
				break;
			case 0b000001: 
				angle = 120;
				lastAngle = angle;
				break;
			case 0b011000: 
				angle = 80;
				lastAngle = angle;
				break;
			case 0b110000: 
				angle = 60;
				lastAngle = angle;
				break;
			case 0b100000: 
				angle = 60;
				lastAngle = angle;
				break;
			default:
				angle = 120;
				lastAngle = angle;
		}
		RTE_vSetAngle(angle);
	}
	else
	{
		RTE_vSetMotorSpeed(0);
//		RTE_vSetAngle(lastAngle);
	}	

}	