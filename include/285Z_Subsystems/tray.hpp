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

  void stopPID();

  int getHeightPos();

  void moveToUp(bool);
  void moveToDown(bool);
  void moveToLift();

  void moveAbsolute(double, int);
};
