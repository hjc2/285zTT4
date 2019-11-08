#pragma once
#include "main.h"
#include "../include/285z/initRobot.hpp"

int UP;
int DOWN;

class Tray {
  //Tray Class Attributes
  public:
    int pos;

  // Tray Constructor
  Tray(int);

  //Tray Functions
  void moveToState(bool);
};
