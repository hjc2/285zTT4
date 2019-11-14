#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"

const int DOWN = 0;
const int UP = 1;

const int LIFTUP = 2;

int trayHeightPos = 0;

double traykP = 0.0005;
double traykI = 0.00001;
double traykD = 0.00001;

auto anglerController = AsyncPosControllerBuilder().withMotor(anglerPort)
                        .withGains({traykP, traykI, traykD})
                        .build();

void Tray::moveToState(int pos){
  switch(pos){
    case DOWN:
      //DOWN
      anglerController->setTarget(0);
      anglerController->waitUntilSettled();
      //anglerMotor.moveAbsolute(0, -100);
    case UP:
      anglerController->setTarget(3800);
      anglerController->waitUntilSettled();
      //anglerMotor.moveAbsolute(1690, 100);
    case LIFTUP:
      anglerController->setTarget(1600);
      anglerController->waitUntilSettled();
    break;
  }
}

void Tray::moveToUp(){
  trayHeightPos = 1;
  if(anglerController->isDisabled()){
    anglerController->flipDisable();
  }
  anglerController->setTarget(3800);
}

void Tray::moveToDown(){
  trayHeightPos = 0;
  if(anglerController->isDisabled()){
    anglerController->flipDisable();
  }
  anglerController->setTarget(0);
}

void Tray::moveToLift(){
  trayHeightPos = 2;
  if(anglerController->isDisabled()){
    anglerController->flipDisable();
  }
  anglerController->setTarget(1300);
}

int Tray::getHeightPos(){
  return trayHeightPos;
}

void Tray::stopPID(){
  if(!(anglerController->isDisabled())){
    anglerController->flipDisable();
  }
}

void Tray::moveAbsolute(double position, int velocity){
  anglerMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
  anglerMotor.moveAbsolute(position, velocity);
}

void Tray::moveVel(int velocity){
  anglerMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
  anglerMotor.moveVelocity(-velocity);
}
