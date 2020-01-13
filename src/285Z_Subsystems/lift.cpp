#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285Z_Subsystems/tray.hpp"

const int NUM_HEIGHTS = 3;
const int height0 = 5;
const int height1 = 1600;
const int height2 = 2300;

const int heights[NUM_HEIGHTS] = {height0, height1, height2};

double liftkP = 0.001;
double liftkI = 0.0;
double liftkD = 0.0;

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
      // angler.moveAbsolute(1400, 500);

    } else if (liftDownButton.changedToPressed() && heightNow > 0) {
      // angler.stopPID();
      heightNow--;
      liftController->setTarget(heights[heightNow]);
      // if(heightNow == 0){
      //   angler.moveAbsolute(200, -100);
    }

}

int Lift::getHeightPos(){
  return heightNow;
}

void Lift::deploy(){
  liftMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
  liftMotor.moveAbsolute(400, 200);
  liftMotor.moveAbsolute(50, -200);
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
