#include "../include/285z/initRobot.hpp"

const int UP = 1;
const int DOWN = 0;

class Tray {

  //TRAY CLASS ATTRIBUTES
  public:
  int ANGLER_MOTOR_PORT;
  AsyncPosControllerBuilder anglerController;

  //TRAY CONSTRUCTOR
  Tray(int port, double kP, double kI, double kD){
    ANGLER_MOTOR_PORT = port;
    anglerController.withMotor(ANGLER_MOTOR_PORT)
                    .withGains({kP, kI, kD})
                    .build();
  }

  //TRAY FUNCTIONS
  void moveToState(int pos){
    switch(pos){
      case UP:
        //anglerController.setTarget(1690);
        //anglerMotor.moveAbsolute(1690, 100);
      case DOWN:
        //DOWN
        anglerMotor.moveAbsolute(0, -100);
      break;
    }
  }



};
