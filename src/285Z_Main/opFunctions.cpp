#include "../include/285z/functions.hpp"
#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
bool anglerUpBool = false;
bool anglerDisabled = false;

bool intakeToggleBool = false;
bool intakeToggleHold = true;
bool liftPositionBool = true;

double outtakeSpeed = 15;


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

//TOGGLE INTAKE
void toggleIntake(){
//  if (anglerController->!isDisabled()){
    if (intakeButton.changedToPressed())
    {
      intakeToggleBool = !intakeToggleBool;
    }
    else if(intakeToggleBool)
    {
      intake.setBrakeMode(AbstractMotor::brakeMode::hold);
      intake.moveVelocity   (600);
    }
    else
    {
      intake.moveVelocity	(0);
      if(intakeToggleHold){
        intake.setBrakeMode(AbstractMotor::brakeMode::hold);
      }

    }
}

//REVERSE INTAKE WHEN BUTTON HELD
void intakeRev(){
  if (outtakeButton.isPressed())
  {
    if(heightNow == 2 || intakeButton.isPressed()){
      intake.moveVelocity (-200);
    } else {
      intake.moveVelocity (-100);
    }
    intake.setBrakeMode(AbstractMotor::brakeMode::coast);
  } else {
    if(intakeToggleHold){
      intake.setBrakeMode(AbstractMotor::brakeMode::hold);
    }
  }
}


//****************** ANGLER ********************//

//TOGGLE ANGLER
void anglerToggle(){
  if(trayButton.changedToPressed()){
    anglerDisabled = false;
    anglerUpBool = !anglerUpBool;
    intake.moveVelocity(0);
  }

  if(anglerUpBool && !anglerDisabled){
    intakeToggleHold = false;
    angler.moveToUp(true);
  } else if(!anglerUpBool && !anglerDisabled){
    angler.moveToDown(true);
  }
}

//STOP PID IF ERROR
void stopPID(){
  if(stopPIDButton.changedToPressed()){
    anglerDisabled = true;
    angler.stopPID();
  }
}

//******************** LIFT *******************//

//TOGGLE LIFT WITH PID
void liftToggle(){
  if(angler.getHeightPos() == 0){
    anglerDisabled = true;
    lift.liftToggle(angler);
  }
}

//MANUAL DUAL CONTROL
void liftControl() {
  if(liftUpButton.isPressed()) {
    lift.move(200);
  }
  else if(liftDownButton.isPressed()) {
    lift.move(-170);
  }
  else {
    lift.move(0);
  }
}

//TASK FOR LIFT CONTROL
void liftTask(void* param) {
  while(true) {
    liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
    liftToggle();
    pros::Task::delay(10);
  }
}


//*********************MACROS*******************************//

//BACK UP AFTER STACK
void stackDeploy()
{
    if(deployButton.changedToPressed())
    {

      //ratio is 0.860776764973 intake:drive
      angler.moveToDown(true);
      anglerUpBool = false;

      intake.moveVelocity(-90);

      driveL.moveVelocity(-outtakeSpeed);
      driveR.moveVelocity(-outtakeSpeed);

      pros::Task::delay(1250);
      intake.moveVelocity(0);

      driveL.moveVelocity(0);
      driveR.moveVelocity(0);
  }
}
