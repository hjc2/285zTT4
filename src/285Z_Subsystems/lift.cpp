#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/lift.hpp"

const int DOWN = 0;
const int UP = 1;

const int NUM_HEIGHTS = 2;
const int height0 = 0;
const int height1 = 1000;

double liftkP = 0.0005;
double liftkI = 0.00001;
double liftkD = 0.00001;

auto liftController = AsyncPosControllerBuilder().withMotor(anglerPort)
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
      liftController->setTarget(3200);
      liftController->waitUntilSettled();
      //anglerMotor.moveAbsolute(1690, 100);
    break;
  }
}

void Lift::moveToUp(){
  anglerController->setTarget(3600);
}

void Lift::moveToDown(){
  anglerController->setTarget(0);
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
