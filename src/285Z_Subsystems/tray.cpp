#include "../include/285z/initRobot.hpp"

class Tray {

  const int UP = true;
  const bool DOWN = false;

  //Tray Class Attributes
  public:
    bool pos;

  // Tray Constructor
  Tray(int initPos){
    pos = initPos;
  }

  //Tray Functions
  void moveToState(bool pos){
    switch(pos){
      case true:
        //UP
      case false:
        //DOWN
        
      break;
    }
  }

};
