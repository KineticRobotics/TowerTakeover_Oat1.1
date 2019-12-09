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
okapi:: MotorGroup right({10, 20});
okapi:: MotorGroup left({1, 11});


auto rightEB = IntegratedEncoder(11);
auto leftEF = IntegratedEncoder(1);
auto rightEF = IntegratedEncoder(20);
auto leftEB = IntegratedEncoder(10);

const auto WHEEL_DIAMETER = 4.25_in;
const auto CHASSIS_WIDTH = 13.5_in;
auto chassis = ChassisControllerFactory::create(
  left, right,
  AbstractMotor::gearset::green,
  {WHEEL_DIAMETER, CHASSIS_WIDTH}
);

Motor dr4bL = 15;
Motor dr4bR = 16;
Motor claw = 7;
Motor strafe = 4;
auto dr4bLe = IntegratedEncoder(15);
auto dr4bRe = IntegratedEncoder(16);

auto dr4b = ChassisControllerFactory::create(
  dr4bL, dr4bR,
  AbstractMotor::gearset::red
);

// Arm related objects
//ADIButton armLimitSwitch('H');
//ControllerButton armUpButton(ControllerDigital::R1);
//ControllerButton armDownButton(ControllerDigital::R2);
ControllerButton clawOut(ControllerDigital::L1);
ControllerButton holdHalf(ControllerDigital::R1);
ControllerButton holdQuarter(ControllerDigital::R2);
Motor armMotor = 7_rmtr;

//most simple PID initiation (don't know whether to use std and dont know whether to use create or createPTR)
auto PIDsimple = ChassisControllerFactory::create(left, right, AbstractMotor::gearset::green,{WHEEL_DIAMETER, CHASSIS_WIDTH});

#endif
