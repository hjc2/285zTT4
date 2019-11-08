#include "../include/285z/functions.hpp"
#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"

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
    intake.moveVelocity   (600);
  }
  else
  {
    intake.moveVelocity	(0);
  }
  //intake.moveVelocity(200);
}

void intakeRev()
{
  if (outtakeButton.isPressed())
  {
    intake.moveVelocity (-100);
  }
}

//          LIFT         //

//      OUTPUT        //
void liftUp(){
  if(liftUpButton.isPressed()){
    liftMotor.moveVelocity(100);
  }

}

void liftDown(){
  if(liftDownButton.isPressed()){
    liftMotor.moveVelocity(-100);

  } else {
    //liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
}

//      INPUT         //
void checkLiftUp(){
  if(liftUpButton.isPressed()){
    liftUp();
  } else {
    //liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
}

void checkLiftDown(){

}

//       ANGLER       //

Tray angler(DOWN);
int cool_integer = 6;
int* same_cool_int = &cool_integer;
*same_cool_int++;
// void* pointer = &cool_integer;
// void* pointer = new int(8);


// * ->
int cool_func(int &position)
{
  return position++;
}

int newint = cool_func(angler.pos);
// int new_integer = cool_func(cool_integer);
// void*

//PID Controller
const double liftkP = 0.001;
const double liftkI = 0.0001;
const double liftkD = 0.00001;

//TODO: WILL HAVE TO MODIFY WHEN WE HAVE TWO MOTORS FOR ANGLER
const int ANGLER_MOTOR_PORT = 20;

auto anglerController = AsyncPosControllerBuilder()
                        .withMotor(ANGLER_MOTOR_PORT) // lift motor port 3
                        .withGains({liftkP, liftkI, liftkD})
                        .build();

void trayFlat(){
  anglerMotor.moveAbsolute(-1690, 80);

}

void trayVert(){
  anglerMotor.moveAbsolute(1690, 150);
}

//kachow
//angler toggle function that is able to be button checked

void liftVertOp() {
  //-1690 degrees
  //TODO: Change angler1 to angler when there are two motors
  if (trayButton.changedToPressed())
  {
    anglerMotor.moveAbsolute(1400, 600);
    pros::delay(200);
    anglerMotor.moveAbsolute(2000, 200);
    //anglerController->setTarget(1690);
    //anglerControllerLPID.setTarget(1690);
    //anglerControllerRPID.setTarget(1690);
  }
}

void lowerFlat(){
  if (trayDown.changedToPressed())
  {
    anglerMotor.moveAbsolute(0, -100);
    //anglerControllerLPID.setTarget(0);
    //anglerControllerRPID.setTarget(0);
    //anglerController->setTarget(0);
  }
}

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
