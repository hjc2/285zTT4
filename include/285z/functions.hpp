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

//OP MACROS
void stackDeploy();

//   **AUTON FUNCTIONS**    //

const bool fwd {false};
const bool bwd {true};

void selectAuton(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast);

/*****************************   AUX AUTONS    **********************/
void move(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir);
void skills(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast);
void one(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast);

/*****************************   RED: FIVE CUBES    **********************/
void sgSixRed(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast);
//******************************   RED: NINE CUBES   ****************************//
void sgNineRed(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast);
//************************   RED: LONG GOAL   ****************************//
void lgRed(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast);


//************************   BLUE: FIVE CUBES   ****************************//
void sgSixBlue(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast);
//************************   BLUE: SHORT GOAL, NINE CUBES   ****************************//
void sgNineBlue(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast);
//************************   BLUE: LONG GOAL   ****************************//
void lgBlue(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void autoStackDeploy(double stackDelay);

//INITIALIZE
void profileControllers();

void redSmallManual();
void deployTray();

Motor autonLift();
