#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"

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
  angler.moveToUp(true);

  pros::Task::delay(stackDelay); //time to wait before backing up

  intake.moveVelocity(-100); //time to wait before backing up
}

//****************** SKILLS ***********************************//
void skills(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift lift;
  //lift.deploy();
  // angler.moveToDeploy(false);
  // angler.moveToDown(false);
  intake.moveVelocity(200);

  // move(slow, 4_ft, fwd);
  // turn(20);
  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {4.75_ft,-0.375_ft,-0_deg}},
    "F1"
  );

  //PART 1: INTAKE 10 CUBES AND TURN TO GOAL
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
  slow->waitUntilSettled();//goes forward to get 4 cubes
  slow->removePath("F2");
  intake.moveVelocity(0);
  turn(43);

  //PART 2: MOVE TO GOAL, DEPLOY, BACK UP, TURN TO TOWER CUBE
  move(medium, 1.45_ft, fwd);
  tenCubeDeploy(2300);
  move(medium, 1.7_ft, bwd);
  angler.moveToDown(false);
  intake.moveVelocity(200);
  turn(250);
  move(medium, 1.3_ft, bwd);
  move(slow, 0.3_ft, bwd);

}

//****************** ONE CUBE ***********************************//
void one(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  move(slow, 1_ft, bwd);
}
