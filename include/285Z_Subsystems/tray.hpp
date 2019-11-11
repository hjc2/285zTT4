#pragma once
#include "main.h"
#include "../include/285z/initRobot.hpp"

extern const int UP;
extern const int DOWN;
extern const int LIFTUP;

extern double traykP;
extern double traykI;
extern double traykD;

class Tray {
  //Tray Class Attributes
  public:

  // Tray Constructor

  //Tray Functions
  void moveToState(int);
  void moveVel(int);
};
