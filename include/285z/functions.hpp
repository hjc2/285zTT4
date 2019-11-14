#pragma once
#include "../include/285z/initRobot.hpp"

//  **TELEOP FUNCTIONS**   //

//Drive
void tankDrive();

//Intake
void toggleIntake();
void intakeRev();

//Tray
void anglerManual();
void anglerToggle();
void anglerUp();
void anglerDown();

//Lift
void liftUp();
void liftDown();
void liftToggle();
void liftPID();

//MANUAL LIFT CONTROL
void liftManual();
void liftManualUp();
void liftManualDown();
void liftManualStop();

void anglerToggle();

void liftPositionToggleFunction();
//   **AUTON FUNCTIONS**    //

void redFiveCube(std::shared_ptr<okapi::OdomChassisController>);
void blueFiveCube(std::shared_ptr<okapi::OdomChassisController>);

void redNineCube(std::shared_ptr<okapi::OdomChassisController>);
void blueNineCube(std::shared_ptr<okapi::OdomChassisController>);
