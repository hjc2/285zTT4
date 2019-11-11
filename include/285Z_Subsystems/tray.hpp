#pragma once
#include "main.h"
#include "../include/285z/initRobot.hpp"

int UP;
int DOWN;

class Tray {
  //Tray Class Attributes
  public:

  // Tray Constructor
  Tray(int, double, double, double);

  //Tray Functions
  void moveToState(int);
};
