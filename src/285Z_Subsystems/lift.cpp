#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285Z_Subsystems/tray.hpp"

const int NUM_HEIGHTS = 4;
const int height0 = 5;
const int height1 = 20;
const int height2 = 1800;
const int height3 = 2300;

const int heights[NUM_HEIGHTS] = {height0, height1, height2, height3};
double liftkP = 0.004;
double liftkI = 0.000001;
double liftkD = 0.00009;
// Old vals kp = 0.001, kI = 0.0001, kd = 0.0001

int heightNow = 0;

auto liftController = AsyncPosControllerBuilder().withMotor(-liftPort)
                        .withGains({liftkP, liftkI, liftkD})
                        .build();

void Lift::moveToState(int pos){
  switch(pos){
    case 0:
      //DOWN
      liftController->setTarget(0);
      liftController->waitUntilSettled();
      //anglerMotor.moveAbsolute(0, -100);
    case 1:
      liftController->setTarget(1000);
      liftController->waitUntilSettled();
      //anglerMotor.moveAbsolute(1690, 100);
    break;
  }
}

void Lift::liftToggle(Tray angler){

  if (liftUpButton.changedToPressed() && heightNow < NUM_HEIGHTS - 1) {
      // angler.stopPID();
      // If the goal height is not at maximum and the up button is pressed, increase the setpoint
      heightNow++;
      liftController->setTarget(heights[heightNow]);
      // pros::delay(500);
      //liftMotor.moveAbsolute(heights[heightNow], 100);

    } else if (liftDownButton.changedToPressed() && heightNow > 1) {
      // angler.stopPID();
      heightNow = 1;
      liftController->setTarget(heights[1]);
      // if(heightNow == 0){
      //liftMotor.moveAbsolute(heights[heightNow], -70);
    }

}

int Lift::getHeightPos(){
  return heightNow;
}

void Lift::deploy(){
  liftController -> setTarget(1000);
  pros::delay(700);
  intake.moveVelocity(-100);
  pros::delay(700);
  liftController -> setTarget(100);
  intake.moveVelocity(100);

  pros::delay(1000);

  driveL.moveVelocity(45);
  driveR.moveVelocity(45);
  pros::delay(100);
  driveR.moveVelocity(-45);
  driveL.moveVelocity(-45);
  pros::delay(100);
  driveR.moveVelocity(0);
  driveL.moveVelocity(0);
}

void Lift::moveToDown(){
  liftController->setTarget(0);
}

void Lift::moveTo(int deg){
  liftController->setTarget(deg);
}

void Lift::move(int vel){
  liftMotor.moveVelocity(-vel);
  liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);

}
