#pragma once
#include "main.h"
#include "../include/285z/initRobot.hpp"

int UP;
int DOWN;

extern double traykP;
extern double traykI;
extern double traykD;

class Tray {
  //Tray Class Attributes
  public:

  // Tray Constructor
  Tray();

  //Tray Functions
  void moveToState(int);
  void moveVel(int);
};
