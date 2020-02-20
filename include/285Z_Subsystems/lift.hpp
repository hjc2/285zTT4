#pragma once
#include "main.h"
#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"

extern int heightNow;

class Lift{

  public:
  void liftToggle(Tray);
  void deploy();
  void move(int);
  void moveTo(int);
};
