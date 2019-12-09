#include "main.h"
#include "okapi/api.hpp"
#ifndef _PROS_MOTOR_H_
#define _PROS_MOTOR_H

using namespace okapi;

/*
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor dr4b_left(15);
pros::Motor dr4b_right(16);
pros::Motor claw(8, true);

pros::Motor rightFront(10, true);
pros::Motor rightBack(20, true);
pros::Motor leftFront(1);
pros::Motor leftBack(11);
*/

//Below this line is okapi above is old motor stuff
okapi:: MotorGroup right2({10, 20});
okapi:: MotorGroup left2({1, 11});


auto rightEB2 = IntegratedEncoder(11);
auto leftEF2 = IntegratedEncoder(1);
auto rightEF2 = IntegratedEncoder(20);
auto leftEB2 = IntegratedEncoder(10);

const auto WHEEL_DIAMETER = 4.25_in;
const auto CHASSIS_WIDTH = 13.5_in;
auto chassis2 = ChassisControllerFactory::create(
  left2, right2,
  AbstractMotor::gearset::green,
  {WHEEL_DIAMETER, CHASSIS_WIDTH}
);

Motor dr4bL2 = 15;
Motor dr4bR2 = 16;
Motor claw2 = 7;
Motor strafe2 = 4;
auto dr4bLe2 = IntegratedEncoder(15);
auto dr4bRe2 = IntegratedEncoder(16);

auto dr4b2 = ChassisControllerFactory::create(
  dr4bL2, dr4bR2,
  AbstractMotor::gearset::red
);

// Arm related objects
//ADIButton armLimitSwitch('H');
//ControllerButton armUpButton(ControllerDigital::R1);
//ControllerButton armDownButton(ControllerDigital::R2);
//ControllerButton clawOut2(ControllerDigital::L1);
//ControllerButton holdHalf2(ControllerDigital::R1);
//ControllerButton holdQuarter2(ControllerDigital::R2);
//Motor armMotor = 7_rmtr;

//most simple PID initiation (don't know whether to use std and dont know whether to use create or createPTR)
auto PIDsimple2 = ChassisControllerFactory::create(left2, right2, AbstractMotor::gearset::green,{WHEEL_DIAMETER, CHASSIS_WIDTH});
ADIGyro gyro = ADIGyro('A', .1);

#endif
