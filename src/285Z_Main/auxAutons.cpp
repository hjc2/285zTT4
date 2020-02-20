#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285z/initSensors.hpp"

void move(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir){
  profile->generatePath({
    {0_ft,0_ft,0_deg},
    {distance, 0_ft,0_deg}},
    "M"
  );

  profile->setTarget("M", dir);
  profile->waitUntilSettled();
  profile->removePath("M");
}

void antiDeploy()
{
  anglerMotor.moveAbsolute(35, 200);
  pros::Task::delay(300);
  anglerMotor.moveAbsolute(0, 200);
}

//STACK DEPLOYS
void autoStackDeploy(double stackDelay) {
  Tray angler;

  intake.moveRelative(-720, 110); //outtakes stack
  intake.setBrakeMode(AbstractMotor::brakeMode::coast);
  angler.moveToUp(true);

  pros::Task::delay(stackDelay); //time to wait before backing up

  intake.moveVelocity(-100);

}

void tenCubeDeploy(double stackDelay) {
  Tray angler;
  intake.setBrakeMode(AbstractMotor::brakeMode::coast);
  int threshold = 1000; //light threshold
  while(cubeSensor.get_value() < threshold){
    intake.moveVelocity(-110);
  }
  // intake.moveRelative(-40, 110); //outtakes stack
  angler.moveToUp(true);

  pros::Task::delay(stackDelay); //time to wait before backing up

  intake.moveVelocity(-100); //time to wait before backing up
}

void towerMacro(std::shared_ptr<okapi::AsyncMotionProfileController> slow){
  //Use when bot in front of tower and lift down
  Lift lift;
  intake.moveVelocity(0);
  lift.moveTo(2300);
  move(slow, 1_ft, bwd);
  intake.moveRelative(-400, 200);
  lift.moveTo(5);
}
//****************** SKILLS ***********************************//
void skills(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift lift;

  intake.moveVelocity(200);

  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {4.75_ft,-0.345_ft,0_deg}},
    "F1"
  );

  //1: INTAKE 10 CUBES AND TURN TO GOAL
  slow->setTarget("F1", fwd);

  antiDeploy();

  slow->waitUntilSettled();//goes forward to get 4 cubes
  slow->removePath("F1");

  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {4.60_ft,0_ft,-3_deg}},
    "F2"
  );
  slow->setTarget("F2", fwd);
  slow->waitUntilSettled();//gets 4 cubes ahead of tower
  slow->removePath("F2");

  turn(43); //turn to goal
  intake.moveVelocity(0);

  move(medium, 1.575_ft, fwd);
  tenCubeDeploy(2300); //deploy
  move(slow, 1.7_ft, bwd);

  pros::delay(300);
  intake.moveVelocity(200);
  turn(270); //turn to align against rightmost wall
  angler.moveToDown(false);
  move(medium, 1.385_ft, bwd); //back against wall

  // 2: TOWER ONE
  calibrate(); //reset IMU
  pros::delay(500);
  intake.moveVelocity(200);
  move(medium, 3.85_ft, fwd); //intake tower cube
  towerMacro(slow); //place cube in high tower

  move(medium, 3.15_ft, bwd); //back up to next tower
  turn(270); //turn to tower
  move(medium, 2_ft, bwd); //align against field wall
  calibrate();
  pros::delay(500);
  move(medium, 3.80_ft, fwd);
  towerMacro(slow);
}

//****************** ONE CUBE ***********************************//
void one(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  move(slow, 1_ft, bwd);
}
