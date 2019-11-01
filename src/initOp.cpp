#include "285z/functions.hpp"
#include "285z/initRobot.hpp"

bool anglerPositionBool = false;

void toggleIntake(){
  intake.moveVelocity(200);
}
void liftUp(){
  anglerMotor.moveVelocity(200);
}

void liftDown(){
  anglerMotor.moveVelocity(-200);
}


void anglerToggle(){
  if(liftUpButton.changedToPressed()){
    if(anglerPositionBool == true){
      liftDown();
      anglerPositionBool = !anglerPositionBool;
    } else {
      liftUp();
      anglerPositionBool = !anglerPositionBool;
    }
  }
}
