#include "general.h"
#include "hal_motor.h"

int main()
{
    T_F16 speed = 0;
	T_U8 step = 1;
	BOOL Direction = FORWARD;
	vMotorInit();
	vSetMotorDir(Direction);
	vSetMotorSpeed(0);
    while(1)
    {
		vSetMotorSpeed(speed);
		__delay_ms(100);
		speed += step;
		if(speed>100)
		{
			Direction = !Direction;
			vSetMotorDir(Direction);	
			step = -step;
		}	
				
	}	
    return 0;
}