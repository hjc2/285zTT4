#pragma once
#include "main.h"
#include "../include/285z/initRobot.hpp"

#define RELATIVE 0
#define ABSOLUTE 1

extern double kP;
extern double kI;
extern double kD;

class PID {

  public:

    void calibrate();
    void turn(double, bool);

};
