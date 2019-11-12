#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/lift.hpp"

const int DOWN = 0;
const int UP = 1;

const int NUM_HEIGHTS = 2;
const int height0 = 0;
const int height1 = 1000;

double liftkP = 0.001;
double liftkI = 0.00001;
double liftkD = 0.00001;

auto liftController = AsyncPosControllerBuilder().withMotor(-liftPort)
                        .withGains({liftkP, liftkI, liftkD})
                        .build();

void Lift::moveToState(int pos){
  switch(pos){
    case DOWN:
      //DOWN
      liftController->setTarget(0);
      liftController->waitUntilSettled();
      //anglerMotor.moveAbsolute(0, -100);
    case UP:
      liftController->setTarget(1000);
      liftController->waitUntilSettled();
      //anglerMotor.moveAbsolute(1690, 100);
    break;
  }
}

void Lift::moveToUp(){
  liftController->setTarget(2300);
}

void Lift::moveToDown(){
  liftController->setTarget(0);
}

void Lift::move(int vel){
  anglerMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  liftMotor.moveVelocity(-vel);
}

/*
class lift{
public

  double liftAngle;
  bool liftState;
  void liftPosition(int position){
    liftMotor.moveAbsolute(position);

void liftUp(){
  if(liftUpButton.isPressed()){
    liftMotor.moveVelocity(-100);
  }
  if (!liftUpButton.isPressed()&&!liftDownButton.isPressed()){
    liftMotor.moveVelocity(0);
    liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
}
void liftDown(){
  if(liftDownButton.isPressed()){
    liftMotor.moveVelocity(100);
  }
  if (!liftUpButton.isPressed()&&!liftDownButton.isPressed()){
    liftMotor.moveVelocity(0);
    liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
}

void manualLiftControl(){
  liftUp();
  liftDown();
}
*/
