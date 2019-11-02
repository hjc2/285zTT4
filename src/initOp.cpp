#include "285z/functions.hpp"
#include "285z/initRobot.hpp"

bool anglerPositionBool = false;

void toggleIntake(){
  intake.moveVelocity(200);
}

void liftUp(){
  liftMotor.moveVelocity(100);
}

void liftDown(){
  liftMotor.moveVelocity(-100);
}

void trayFlat(){
  anglerMotor.moveAbsolute(-1690, 100);
}

void trayVert(){
  anglerMotor.moveAbsolute(1690, 100);
}

//if(liftDownButton.isPressed()) {
//lift.moveAbsolute(13903, 100);
//}


void checkLiftUp(){
  if(liftUpButton.isPressed()){
    liftUp();
  } else {
    liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
}

void checkLiftDown(){
  if(liftDownButton.isPressed()){
    liftDown();
  } else {
    liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
}
//kachow
//angler toggle function that is able to be button checked
void anglerToggle(){
  if(trayButton.changedToPressed()){
    if(anglerPositionBool == true){
      trayFlat();
      anglerPositionBool = !anglerPositionBool;
    } else {
      trayVert();
      anglerPositionBool = !anglerPositionBool;
    }
  }
}
