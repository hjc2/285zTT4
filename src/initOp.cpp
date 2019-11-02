#include "285z/functions.hpp"
#include "285z/initRobot.hpp"

bool anglerPositionBool = false;
bool intakeToggleBool = false;

//           DRIVE         //
/*void tankDrive(){
  model->tank(controller.getAnalog(okapi::ControllerAnalog::rightY),
        controller.getAnalog(okapi::ControllerAnalog::leftY));

}

void arcadeDrive(){
  model->arcade(controller.getAnalog(okapi::ControllerAnalog::leftY),
    -controller.getAnalog(okapi::ControllerAnalog::rightX));
}*/


//          INTAKE         //
void toggleIntake(){
  if (intakeButton.changedToPressed())
  {
    intakeToggleBool = !intakeToggleBool;
  }
  else if(intakeToggleBool)
  {
    intake.moveVelocity   (-600);
  }
  else
  {
    intake.moveVelocity	(0);
    intake.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
  //intake.moveVelocity(200);
}

//          LIFT         //

//      OUTPUT        //
void liftUp(){
  liftMotor.moveVelocity(100);
}

void liftDown(){
  liftMotor.moveVelocity(-100);
}

//      INPUT         //
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

//       ANGLER       //
void trayFlat(){
  anglerMotor.moveAbsolute(-1690, 70);

}

void trayVert(){
  anglerMotor.moveAbsolute(1690, 50);
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

//if(liftDownButton.isPressed()) {
//lift.moveAbsolute(13903, 100);
//}
