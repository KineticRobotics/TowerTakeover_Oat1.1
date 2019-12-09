#include "main.h"
#include "motor.h"

#ifndef _PROS_OPFUNC_H_
#define _PROS_OPFUNC_H_

void dr4bControl(int y)
{
	dr4bR.moveVelocity(y);
	dr4bL.moveVelocity(y);
}

void clawControl(int stateOut, int stateHalf, int stateQuarter)
{
	if (stateOut == 1 && stateHalf == 0 && stateQuarter == 0)
		claw.moveVelocity(-127);
	else if (stateOut == 0 && stateHalf == 1 && stateQuarter == 0)
	  	claw.moveVelocity(127);
	else if (stateOut == 0 && stateHalf == 0 && stateQuarter == 1)
		claw.moveVelocity(31);
	else
		claw.moveVelocity(0);
}

void strafeCont(int leftHalf, int leftQuarter, int rightHalf, int rightQuarter) {
	if(leftHalf == 1 && leftQuarter == 0 && rightHalf == 0 && rightQuarter == 0)
		strafe.moveVelocity(100);
	else if(leftHalf == 0 && leftQuarter == 1 && rightHalf == 0 && rightQuarter == 0)
		strafe.moveVelocity(50);
	else if(leftHalf == 0 && leftQuarter == 0 && rightHalf == 1 && rightQuarter == 0)
		strafe.moveVelocity(-100);
	else if(leftHalf == 0 && leftQuarter == 0 && rightHalf == 0 && rightQuarter == 1)
			strafe.moveVelocity(-50);
	else
		strafe.moveVelocity(0);
}

/*
void dr4bAngle(int angle){
	int point; int power; int scalar;
	if(angle<point){
		power = scalar*(angle/point);
		dr4bL.set(power);
		dr4bR.set(power);
		dr4b_left = power;
		dr4b_right = power;
	}
	else{
	}
}
*/

#endif
