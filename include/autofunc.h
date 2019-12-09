#include "motorcopy.h"
#include "main.h"
const auto BAR = 14.5;
using namespace okapi;
//Aditya said don't use this
void dr4bControlA(float inches)
{
    float inchesUp = 7.0*inches/2.0;
    float radians = inchesUp/BAR;
    double degrees = radians*(180/3.14159265);
    dr4bL2.moveRelative(degrees, 70);
    dr4bR2.moveRelative(degrees, 70);
}

void dr4bControl2(float inches)
{
    float inchesUp = 7.0 * inches / 2.0;
    float radians = inchesUp / BAR;
    double degrees = radians * (180 / 3.14159265);
    dr4bL2.moveRelative(degrees, 40);
    dr4bR2.moveRelative(degrees, 40);
}

void releaseClaw()
{
    claw2.moveVelocity(-127);
    pros::delay(150);
    claw2.moveVelocity(0);

}

void polynomial(float distance, int max_power){
    distance = distance + .0451*distance -.427;
    rightEF2.reset();
    leftEF2.reset();
    float dist_traveled_right = 0;
    float dist_traveled_left = 0;
    int power_right;
    int power_left;
    while((dist_traveled_right < distance/2.0) || (dist_traveled_left < distance/2.0)){
        dist_traveled_right = rightEF2.get() * (3.14159265 / 180) * 2.125;
        dist_traveled_left = leftEF2.get() * (3.14159265 / 180) * 2.125;
        power_right = (dist_traveled_right*2*(max_power-30))/distance + 30;
        power_left = (dist_traveled_left * 2 * (max_power - 30)) / distance + 30;
        right2.moveVelocity(power_right);
        left2.moveVelocity(power_left);
    }
    while(dist_traveled_right < distance || dist_traveled_left < distance){
        dist_traveled_right = rightEF2.get() * (3.14159265 / 180) * 2.125;
        dist_traveled_left = leftEF2.get() * (3.14159265 / 180) * 2.125;
        power_right = (dist_traveled_right * 2 * (10-max_power)) / distance + 2*max_power -10;
        power_left = (dist_traveled_left * 2 * (10-max_power)) / distance + 2*max_power -10;
        right2.moveVelocity(power_right);
        left2.moveVelocity(power_left);
    }
    right2.moveVelocity(0);
    left2.moveVelocity(0);
}

void polynomialB(float distance, int max_power)
{
    distance = distance + .0451 * distance - .427;
    rightEF2.reset();
    leftEF2.reset();
    float dist_traveled_right = 0;
    float dist_traveled_left = 0;
    int power_right;
    int power_left;
    while ((dist_traveled_right < distance / 2.0) || (dist_traveled_left < distance / 2.0))
    {
        dist_traveled_right = -1 * rightEF2.get() * (3.14159265 / 180) * 2.125;
        dist_traveled_left = -1 * leftEF2.get() * (3.14159265 / 180) * 2.125;
        power_right = (dist_traveled_right * 2 * (max_power - 30)) / distance + 30;
        power_left = (dist_traveled_left * 2 * (max_power - 30)) / distance + 30;
        right2.moveVelocity(-1 *power_right);
        left2.moveVelocity(-1 * power_left);
    }
    while (dist_traveled_right < distance || dist_traveled_left < distance)
    {
        dist_traveled_right = -1 *rightEF2.get() * (3.14159265 / 180) * 2.125;
        dist_traveled_left = -1 * leftEF2.get() * (3.14159265 / 180) * 2.125;
        power_right = (dist_traveled_right * 2 * (10 - max_power)) / distance + 2 * max_power - 10;
        power_left = (dist_traveled_left * 2 * (10 - max_power)) / distance + 2 * max_power - 10;
        right2.moveVelocity(-1 * power_right);
        left2.moveVelocity(-1 * power_left);
    }
    right2.moveVelocity(0);
    left2.moveVelocity(0);
}
void polyTurn(float angle, int max, float scale){
    float angle_traveled = 0;
    int power;
    gyro.reset();
    while(angle_traveled < angle/2.0){
        angle_traveled = gyro.get() * scale;
        power = ((2 * (max - 40))/angle)*angle_traveled + 40;
        left2.moveVelocity(power);
        right2.moveVelocity(-1*power);
    }
    while (angle_traveled < angle)
    {
        angle_traveled = gyro.get() * scale;
        power = ((2 * (20-max)) / angle) * angle_traveled + 2*max -20;
        left2.moveVelocity(power);
        right2.moveVelocity(-1 * power);
    }
    left2.moveVelocity(0);
    right2.moveVelocity(0);
}

void polyTurnReverse(float angle, int max, float scale)
{
    float angle_traveled = 0;
    int power;
    gyro.reset();
    scale = scale*-1.0;
    while (angle_traveled < angle / 2.0)
    {
        angle_traveled = gyro.get() * scale;
        power = ((2 * (max - 40)) / angle) * angle_traveled + 40;
        left2.moveVelocity(-1 * power);
        right2.moveVelocity(power);
    }
    while (angle_traveled < angle)
    {
        angle_traveled = gyro.get() * scale;
        power = ((2 * (20 - max)) / angle) * angle_traveled + 2 * max - 20;
        left2.moveVelocity(-1 * power);
        right2.moveVelocity(power);
    }
    left2.moveVelocity(0);
    right2.moveVelocity(0);
}

void turnTicks(float degrees, int max_power){
    float arcLength = ((degrees*3.14159265*6.325)/180.0) * (.7255); //arcLength in inches
    int power_left;
    int power_right;
    float dist_traveled_right = 0.0;
    float dist_traveled_left = 0.0;
    rightEB2.reset();
    leftEB2.reset();
    while ((dist_traveled_right < arcLength / 2.0) || (dist_traveled_left < arcLength / 2.0))
    {
        dist_traveled_right = -1.0*rightEB2.get() * (3.14159265 / 180) * 2.125;
        dist_traveled_left = leftEB2.get() * (3.14159265 / 180) * 2.125;
        power_right = (dist_traveled_right * 2 * (max_power - 30)) / arcLength + 30;
        power_left = (dist_traveled_left * 2 * (max_power - 30)) / arcLength + 30;
        right2.moveVelocity(-1*power_right);
        left2.moveVelocity(power_left);
    }
    while (dist_traveled_right < arcLength || dist_traveled_left < arcLength)
    {
        dist_traveled_right = -1.0*rightEB2.get() * (3.14159265 / 180) * 2.125;
        dist_traveled_left = leftEB2.get() * (3.14159265 / 180) * 2.125;
        power_right = (dist_traveled_right * 2 * (10 - max_power)) / arcLength + 2 * max_power - 10;
        power_left = (dist_traveled_left * 2 * (10 - max_power)) / arcLength + 2 * max_power - 10;
        right2.moveVelocity(-1*power_right);
        left2.moveVelocity(power_left);
    }
    right2.moveVelocity(0);
    left2.moveVelocity(0);
}

void turnTicksCCW(float degrees, int max_power)
{
    float arcLength = ((degrees * 3.14159265 * 6.325) / 180.0) * (.7255); //arcLength in inches
    int power_left;
    int power_right;
    float dist_traveled_right = 0.0;
    float dist_traveled_left = 0.0;
    rightEB2.reset();
    leftEB2.reset();
    while ((dist_traveled_right < arcLength / 2.0) || (dist_traveled_left < arcLength / 2.0))
    {
        dist_traveled_right = rightEB2.get() * (3.14159265 / 180) * 2.125;
        dist_traveled_left = -1.0*leftEB2.get() * (3.14159265 / 180) * 2.125;
        power_right = (dist_traveled_right * 2 * (max_power - 30)) / arcLength + 30;
        power_left = (dist_traveled_left * 2 * (max_power - 30)) / arcLength + 30;
        right2.moveVelocity(power_right);
        left2.moveVelocity(-1.0*power_left);
    }
    while (dist_traveled_right < arcLength || dist_traveled_left < arcLength)
    {
        dist_traveled_right =  rightEB2.get() * (3.14159265 / 180) * 2.125;
        dist_traveled_left = -1.0*leftEB2.get() * (3.14159265 / 180) * 2.125;
        power_right = (dist_traveled_right * 2 * (10 - max_power)) / arcLength + 2 * max_power - 10;
        power_left = (dist_traveled_left * 2 * (10 - max_power)) / arcLength + 2 * max_power - 10;
        right2.moveVelocity(power_right);
        left2.moveVelocity(-1.0*power_left);
    }
    right2.moveVelocity(0);
    left2.moveVelocity(0);
}