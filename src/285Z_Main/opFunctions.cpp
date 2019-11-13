#include "../include/285z/functions.hpp"
#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"

bool anglerPositionBool = false;
bool intakeToggleBool = false;
bool liftPositionBool = true;
double liftPosReal = 0.0;
double liftPosReq = 0.0;


//           DRIVE         //
/*void tankDrive(){
  model->tank(controller.getAnalog(okapi::ControllerAnalog::rightY),
        controller.getAnalog(okapi::ControllerAnalog::leftY));

}

void arcadeDrive(){
  model->arcade(controller.getAnalog(okapi::ControllerAnalog::leftY),
    -controller.getAnalog(okapi::ControllerAnalog::rightX));
}*/


//******************* INTAKE ********************//

//Toggles intake
void toggleIntake(){
  if (intakeButton.changedToPressed())
  {
    intakeToggleBool = !intakeToggleBool;
  }
  else if(intakeToggleBool)
  {
    intake.setBrakeMode(AbstractMotor::brakeMode::coast);
    intake.moveVelocity   (600);
  }
  else
  {
    intake.moveVelocity	(0);
    intake.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
}

//Reverse intake
void intakeRev(){
  if (outtakeButton.isPressed())
  {
    intake.moveVelocity (-150);
    intake.setBrakeMode(AbstractMotor::brakeMode::coast);
  } else {
    intake.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
}

//****************** ANGLER ********************//

Tray angler;

void anglerManual(){
  if(anglerUpButton.isPressed()){
    anglerMotor.moveVelocity(100);
    anglerMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
  } else if(anglerDownButton.isPressed()){
    anglerMotor.moveVelocity(-100);
    anglerMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
  } else if(!anglerUpButton.isPressed() && !anglerDownButton.isPressed()){
    anglerMotor.moveVelocity(0);
    anglerMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
  }
}

void anglerToggle(){
  anglerUp();
  anglerDown();
}



void anglerUp() {
  if (trayButton.changedToPressed())
  {
    angler.moveToUp();
  }
}

void anglerDown(){
  if (trayDownButton.changedToPressed())
  {
    angler.moveToDown();
  }
}

//******************** LIFT *******************//

Lift lift;
//MANUAL liftup
void liftUp(){
  if(liftUpButton.changedToPressed()){
    lift.moveToUp();
    angler.moveToLift();
  }
}

//MANUAL liftdown
void liftDown(){
  if(liftDownButton.changedToPressed()){
    lift.moveToDown();
    angler.moveToDown();
  }
}




//MANUAL DUAL CONTROL
//runs
//
void liftManual(){
  liftManualUp();
  liftManualDown();
  liftManualStop();
}

//liftManualUp
//will check if the liftUpButton is pressed,
//if it's pressed it will coast and set velocity positive
void liftManualUp(){
  if(liftUpButton.isPressed()){
    angler.moveToLift();
    anglerMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
    liftMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
    liftMotor.moveVelocity(100);
  }
}
//liftManualDown
//will check if the liftDownButton is pressed,
//if it's pressed it will coast and set velocity positive
void liftManualDown(){
  if(liftDownButton.isPressed()){
    anglerMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
    angler.moveToDown();
    liftMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
    liftMotor.moveVelocity(100);
  }
}

//liftManualStop
//will check if either lift buttons are pressed
//if either pressed, it will make velocity 0 and brake hold
void liftManualStop(){
  if(!liftDownButton.isPressed() && !liftUpButton.isPressed()) {
    liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
    liftMotor.moveVelocity(-100);
  }
}

void toggleLiftHeight(){
  if(liftToggleButton.changedToPressed()){
    if(liftPositionBool == false){
      liftMotor.moveAbsolute(900,100);
      liftPositionBool = !liftPositionBool;
    } else {
      liftMotor.moveAbsolute(-900,100);
      liftPositionBool = !liftPositionBool;
    }
  }
}
