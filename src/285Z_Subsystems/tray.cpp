#include "../include/285z/initRobot.hpp"

const int UP = 1;
const int DOWN = 0;

class Tray {

  //Tray Class Attributes
  public:

  // Tray Constructor
  Tray(){}

  //Tray Functions
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
