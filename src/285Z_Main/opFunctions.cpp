#include "../include/285z/functions.hpp"
#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"

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
    //anglerMotor.moveRelative(1690, 100);
    //angler.moveToState(1);
  }
}

void anglerDown(){
  if (trayDownButton.changedToPressed())
  {
    angler.moveToState(0);
  }
}

//******************** LIFT *******************//

//MANUAL liftup
void liftUp(){
  if(liftUpButton.isPressed()){
    liftMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
    liftMotor.moveVelocity(-100);
  } else if(!liftUpButton.isPressed()&&!liftDownButton.isPressed()){
    liftMotor.moveVelocity(0);
    liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
}

//MANUAL liftdown
void liftDown(){
  if(liftDownButton.isPressed()){
    liftMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
    liftMotor.moveVelocity(100);
  } else if(!liftUpButton.isPressed()&&!liftDownButton.isPressed()){
    liftMotor.moveVelocity(0);
    liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
}
//MANUAL DUAL CONTROL
void liftManual(){
  liftDown();
  liftUp();
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

void liftPID(){

  liftPosReal =  liftMotor.getPosition();
  liftPosReq = 1600;
  if(liftPosReal < liftPosReq){
      liftMotor.moveVelocity(50);
    } else {
      liftMotor.moveVelocity(-50);
    }
}
