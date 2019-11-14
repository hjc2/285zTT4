#include "../include/285z/functions.hpp"
#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"

bool anglerUpBool = false;
bool anglerDisabled = false;

bool intakeToggleBool = false;
bool liftPositionBool = true;


//***********************  INITIALIZE SUBSYSTEMS  ***************************//
Tray angler;
Lift lift;

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
  if(trayButton.changedToPressed()){
    anglerDisabled = false;
    anglerUpBool = !anglerUpBool;
  }

  if(anglerUpBool && !anglerDisabled && lift.getHeightPos() == 0){
    intake.setBrakeMode(AbstractMotor::brakeMode::coast);
    angler.moveToUp(true);
  } else if(!anglerUpBool && !anglerDisabled && lift.getHeightPos() == 0){
    angler.moveToDown(true);
  }
}

void stopPID(){
  if(stopPIDButton.changedToPressed()){
    anglerDisabled = true;
    angler.stopPID();
  }
}

//******************** LIFT *******************//



void liftToggle(){
  anglerDisabled = true;
  if(angler.getHeightPos() == 0){
    lift.liftToggle(angler);
  }

}

//Preset liftup
void liftUp(){
  if(liftUpButton.changedToPressed()){
    lift.moveToUp();
    angler.moveToLift();
  }
}

//Preset liftdown
void liftDown(){
  if(liftDownButton.changedToPressed()){
    lift.moveToDown();
    angler.moveToDown(true);
  }
}



//MANUAL DUAL CONTROL
void liftManual(){
  if(liftUpButton.isPressed()){
    lift.move(100);
  } else if(liftDownButton.isPressed()){
    lift.move(-100);
  } else {
    lift.move(0);
  }

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
    angler.moveToDown(true);
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
