#include "main.h"
#include "opfunc.h"

using namespace okapi;


void opcontrol()
{
  strafe.setBrakeMode(AbstractMotor::brakeMode::coast);
  dr4bL.setReversed(false);
  right.setReversed(false);
  dr4bL.setBrakeMode(AbstractMotor::brakeMode::hold);
  dr4bR.setBrakeMode(AbstractMotor::brakeMode::hold);
  // Joystick to read analog values for tank or arcade control
  // Master controller by default
  Controller masterController;

  int l;
  int r;

  int ldr4b;
  int rdr4b;

  int c;

  /*int[50] ls;
  int[50] rs;
  int[50] ldr4bs;
  int[50] rdr4bs;*/

  std::string ls = "";
  std::string rs = "";
  std::string ldr4bs = "";
  std::string rdr4bs = "";
  std::string cs = "";

  int counter = 0;
  bool oneTime = false;


  pros::lcd::set_text(1, "working?");

  while (true)
  {
    // Tank drive with left and right sticks
    chassis.arcade(masterController.getAnalog(ControllerAnalog::leftX),
                   masterController.getAnalog(ControllerAnalog::leftY));
    dr4b.arcade(0, -masterController.getAnalog(ControllerAnalog::rightY));
    strafeCont(masterController.getDigital(ControllerDigital::up),
      masterController.getDigital(ControllerDigital::down), masterController.getDigital(ControllerDigital::X), masterController.getDigital(ControllerDigital::B));
    //dr4bControl(armUpButton.isPressed(), armDownButton.isPressed(), 0);
    clawControl(clawOut.isPressed(), holdHalf.isPressed(), holdQuarter.isPressed());
    pros::delay(10);

    /*RERUN----------------------------------------------------------------------*/

    /*l = left.getTargetVelocity();
    //lb = leftBack.getVoltage();
    r = right.getTargetVelocity();
    //rb = rightBack.getTargetVelocity();
    ldr4b = dr4bL.getTargetVelocity();
    rdr4b = dr4bR.getTargetVelocity();
    c = claw.getTargetVelocity();*/



    /*--------------------

    std::string l = std::to_string(left.getTargetVelocity());
    //lb = leftBack.getVoltage();
    std::string r = std::to_string(right.getTargetVelocity());
    //rb = rightBack.getTargetVelocity();
    std::string ldr4b = std::to_string(dr4bL.getTargetVelocity());
    std::string rdr4b = std::to_string(dr4bR.getTargetVelocity());
    std::string c = std::to_string(claw.getTargetVelocity());

    if(counter<2000){ -----------------------*/
      /*ls[counter] = l;
      rs[counter] = r;
      ldr4bs[counter] = ldr4b;
      rdr4bs[counter] = rdr4b;*/
      /*--------------------------------------
      ls = ls+ "\n"+l;
      rs = rs+ "\n" +r;
      ldr4bs = ldr4bs+ "\n" + ldr4b;
      rdr4bs = rdr4bs + "\n" + rdr4b;
      pros::delay(50);
      counter++;
    }
    if(counter>50 && !oneTime){

    FILE *usd_file_write = fopen("/usd/rerun.txt", "w");
    fputs("test", usd_file_write);
    //fprintf(usd_file_write, "test2");

    fprintf(usd_file_write, "******************Left Side velocity: %s\n", ls.c_str());
    fprintf(usd_file_write, "******************Right Side velocity: %s\n", rs.c_str());
    fprintf(usd_file_write, "******************Leftdr4b velocity: %s\n", ldr4bs.c_str());
    fprintf(usd_file_write, "******************Rightdr4b velocity: %s\n", rdr4bs.c_str());
    fprintf(usd_file_write, "******************Claw velocity: %s\n", cs.c_str());

    oneTime = true;
    fclose(usd_file_write);
  } ---------------*/
  }
}
