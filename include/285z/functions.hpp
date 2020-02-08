#pragma once
#include "../include/285z/initRobot.hpp"

//  **TELEOP FUNCTIONS**   //
void lcdStart();
void displayAuton();
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
void liftControl();
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

void autoStackDeploy();
void selectAuton(std::shared_ptr<okapi::OdomChassisController>, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast);
/*****************************   RED: FIVE CUBES    **********************/
void shortGoalFiveRed(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast);
//******************************   RED: NINE CUBES   ****************************//
void shortGoalNineRed(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast);
//************************   RED: LONG GOAL   ****************************//
void longGoalRed(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast);


//************************   BLUE: FIVE CUBES   ****************************//
void shortGoalFiveBlue(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast);
//************************   BLUE: SHORT GOAL, NINE CUBES   ****************************//
void shortGoalNineBlue(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast);
//************************   BLUE: LONG GOAL   ****************************//
void longGoalBlue(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void robotDeploy();
void stackDeploy();

void blueSmallManual();
void redSmallManual();
//INITIALIZE
void profileControllers();

void deployOne();
void deployTray();

Motor autonLift();
