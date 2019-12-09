//#include "main.h"
#include "autofunc.h"
using namespace okapi;
void autonomous()
{
	dr4bL2.setBrakeMode(AbstractMotor::brakeMode::hold);
  dr4bR2.setBrakeMode(AbstractMotor::brakeMode::hold);
  strafe2.setBrakeMode(AbstractMotor::brakeMode::hold);
  dr4bL2.setReversed(true);
  right2.setReversed(true);
  
  //releaseClaw();
  //pros::delay(100);
  polynomial(8, 70);
  claw2.moveVelocity(127);
  pros::delay(300);
  //claw2.moveVelocity(0);
  dr4bControlA(28);
  polynomial(26, 70);
  dr4bControl2(-5.0);
  pros::delay(400);
  claw2.moveVelocity(-127);
  pros::delay(300);
  dr4bControl2(-21.0);
  pros::delay(1000);
  claw2.moveVelocity(127);
  pros::delay(1000);
  claw2.moveVelocity(30);
  polyTurnReverse(103, 150, 1.0);
  dr4bControl2(12.0);
  pros::delay(500);
  polynomial(42.0, 175);
  dr4bControl2(-3.0);
  pros::delay(300);
  claw2.moveVelocity(-127);
  pros::delay(300);
  polynomialB(20, 150);
  claw2.moveVelocity(0);




  /*
  //Get first cube
	claw2.moveVelocity(-127);
	pros::delay(100);
	dr4bControlA(6);
  polynomial(3, 127);
	claw2.moveVelocity(127);
	dr4bControlA(-6);
	claw2.moveVelocity(-127);

	//Get 4 stack
	dr4bControlA(24);
	polynomial(23, 100);
	claw2.moveVelocity(127);
	pros::delay(50);
	dr4bControlA(-5);
	claw2.moveVelocity(-50);
	dr4bL2.moveVelocity(20);
	dr4bR2.moveVelocity(20);

	//turn and score
	polyTurn(135, 127, .98);
	polynomial(30, 127);
	dr4bControlA(6);
	polynomial(3, 127);
	claw2.moveVelocity(127);
	pros::delay(100);
	polynomialB(15, 127);
  */
}
