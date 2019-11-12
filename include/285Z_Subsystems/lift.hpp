#pragma once
#include "main.h"
#include "../include/285z/initRobot.hpp"

class Lift{

  public:

  double liftAngle;
  bool liftState;

  void moveToState(int);
  void moveToUp();
  void moveToDown();
  void move(int);

};
