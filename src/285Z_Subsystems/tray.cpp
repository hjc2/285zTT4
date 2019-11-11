#include "../include/285z/initRobot.hpp"

const int UP = 1;
const int DOWN = 0;

class Tray {

  //TRAY CLASS ATTRIBUTES
  public:

  int ANGLER_MOTOR_PORT;

  //TRAY CONSTRUCTOR
  Tray(int port, double kP, double kI, double kD){

    ANGLER_MOTOR_PORT = port;
    auto anglerController = AsyncPosControllerBuilder()
                            .withMotor(ANGLER_MOTOR_PORT) // lift motor port 3
                            .withGains({kP, kI, kD})
                            .build();
  }

  //TRAY FUNCTIONS
  void moveToState(int pos){
    switch(pos){
      case UP:
        //UP
        anglerMotor.moveAbsolute(1690, 100);
      case DOWN:
        //DOWN
        anglerMotor.moveAbsolute(0, -100);
      break;
    }
  }



};
