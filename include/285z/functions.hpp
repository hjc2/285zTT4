#pragma once
#include "../include/285z/initRobot.hpp"

//  **TELEOP FUNCTIONS**   //
void lcdStart();
//Drive
void tankDrive();

//Intake
void toggleIntake();
void intakeRev();

//Tray
void anglerManual();
void anglerToggle();
void stopPID();

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

const bool fwd {false};
const bool bwd {true};

void selectAuton(std::shared_ptr<okapi::OdomChassisController>, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void redFiveCube(std::shared_ptr<okapi::OdomChassisController>);
void blueFiveCube(std::shared_ptr<okapi::OdomChassisController>);

void redLongGoal(std::shared_ptr<okapi::OdomChassisController>);
void blueLongGoal(std::shared_ptr<okapi::OdomChassisController>);

void redNineCube(std::shared_ptr<okapi::OdomChassisController>);
void blueNineCube(std::shared_ptr<okapi::OdomChassisController>);

void test(std::shared_ptr<okapi::OdomChassisController>);

void robotDeploy();
void stackDeploy();

//INITIALIZE
void profileControllers();
