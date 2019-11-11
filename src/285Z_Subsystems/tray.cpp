#include "../include/285z/initRobot.hpp"

const int UP = 1;
const int DOWN = 0;

class Tray {

  //Tray Class Attributes
  public:
    int pos;

  // Tray Constructor
  Tray(int initPos){
    pos = initPos;
  }

  //Tray Functions
  void moveToState(bool pos){
    switch(pos){
      case true:
        //UP
        anglerMotor.moveAbsolute(1690, 100);
      case false:
        //DOWN
        anglerMotor.moveAbsolute(0, -100);
      break;
    }
  }

};
