#pragma once
#include "main.h"
#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"

class Lift{

  public:

  double liftAngle;
  bool liftState;

  void moveToState(int);
  void liftToggle(Tray);
  void moveToUp();
  void moveToDown();
  void move(int);

};
