#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/lift.hpp"

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
