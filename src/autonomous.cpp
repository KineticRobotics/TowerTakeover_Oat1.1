//#include "main.h"
#include "autofunc.h"
using namespace okapi;
void autonomous()
{
	dr4bL2.setBrakeMode(AbstractMotor::brakeMode::hold);
  dr4bR2.setBrakeMode(AbstractMotor::brakeMode::hold);
  strafe2.setBrakeMode(AbstractMotor::brakeMode::coast);
  dr4bL2.setReversed(true);
  right2.setReversed(true);
  
  claw2.moveVelocity(127);
  pros::delay(150);
  claw2.moveVelocity(0);
  polynomial(5.0, 80);
  dr4bControlA(9.0);
  pros::delay(350);
  polynomial(11.0, 75);
  dr4bControl2(-2.0);
  pros::delay(100);
  claw2.moveVelocity(-127);
  pros::delay(300);
  dr4bControlA(-7.0);
  pros::delay(300);
  claw2.moveVelocity(127);
  pros::delay(800);
  claw2.moveVelocity(31);
  dr4bControlA(10.0);
  pros::delay(300);
  polynomial(6.0, 70);

  dr4bControl2(-2.0);
  pros::delay(100);
  claw2.moveVelocity(-127);
  pros::delay(300);
  dr4bControlA(-7.0);
  pros::delay(300);
  claw2.moveVelocity(127);
  pros::delay(800);
  claw2.moveVelocity(31);
  dr4bControlA(10.0);
  pros::delay(300);
  polynomial(6.0, 70);

  dr4bControl2(-2.0);
  pros::delay(100);
  claw2.moveVelocity(-127);
  pros::delay(300);
  dr4bControlA(-7.0);
  pros::delay(300);
  claw2.moveVelocity(127);
  pros::delay(800);
  claw2.moveVelocity(31);
  dr4bControlA(5.0);
  pros::delay(300);

  polynomialB(22.0, 140);
  polyTurn(135, 90, 1.0);
  polynomial(19.0, 120);
  dr4bControl2(-5.0);
  pros::delay(300);
  claw2.moveVelocity(-127);
  pros::delay(300);
  polynomialB(15.0, 100);
  claw2.moveVelocity(0);
  /*claw2.moveVelocity(-127);
  pros::delay(120);
  claw2.moveVelocity(0);
  dr4bControl2(-8.0);
  pros::delay(1000);
  claw2.moveVelocity(127);
  pros::delay(200);
  claw2.moveVelocity(36);
  dr4bControlA(7.0);
  pros::delay(150);*/

  /*polynomial(6.0, 75);
  claw2.moveVelocity(-127);
  pros::delay(120);
  dr4bControl2(-7.0);
  pros::delay(200);
  claw2.moveVelocity(127);
  pros::delay(200);
  claw2.moveVelocity(30);*/



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
