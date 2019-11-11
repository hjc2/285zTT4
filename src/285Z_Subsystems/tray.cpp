#include "../include/285z/initRobot.hpp"

const int DOWN = 0;
const int UP = 1;

double traykP = 0.001;
double traykI = 0.0001;
double traykD = 0.00001;

auto anglerController = AsyncPosControllerBuilder().withMotor(anglerPort)
                        .withGains({traykP, traykI, traykD})
                        .build();

class Tray {


  //TRAY CLASS ATTRIBUTES
  public:
  int ANGLER_MOTOR_PORT;


  //TRAY CONSTRUCTOR
  Tray(){}

  //TRAY FUNCTIONS
  void moveToState(int pos){
    switch(pos){
      case UP:
        anglerController->setTarget(1690);
        anglerController->waitUntilSettled();
        //anglerMotor.moveAbsolute(1690, 100);
      case DOWN:
        //DOWN
        anglerController->setTarget(0);
        anglerController->waitUntilSettled();
        //anglerMotor.moveAbsolute(0, -100);
      break;
    }
  }



};
