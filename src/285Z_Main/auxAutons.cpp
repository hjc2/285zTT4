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

void autoStackDeploy(double stackDelay) {
  Tray angler;
  intake.moveRelative(-680, 110);
  intake.setBrakeMode(AbstractMotor::brakeMode::coast);
  angler.moveToUp(false);

  pros::Task::delay(stackDelay);

  intake.moveVelocity(-120);
  angler.moveToDown(false);

  //intake.moveRelative(-75, 110);
  //fast->setTarget("C",bwd); //drives away
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
    {4.75_ft,-0.5_ft,-10_deg}},
    "F1"
  );

  //PART 1: INTAKE 10 CUBES AND TURN TO GOAL
  slow->setTarget("F1", fwd);
  slow->waitUntilSettled();//goes forward to get 4 cubes
  slow->removePath("F1");

  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {4.75_ft,-0.2_ft,0_deg}},
    "F2"
  );
  slow->setTarget("F2", fwd);
  slow->waitUntilSettled();//goes forward to get 4 cubes
  slow->removePath("F2");

  turn(65);
  intake.moveVelocity(0);

  //PART 2: MOVE TO GOAL, DEPLOY, BACK UP, TURN TO TOWER CUBE
  move(medium, 0.9_ft, fwd);
  autoStackDeploy(2300);
  move(fast, 0.9_ft, bwd);
  turn(270);

  //PART 3: INTAKE NEXT BATCH OF CUBES

}

//****************** ONE CUBE ***********************************//
void one(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  move(slow, 1_ft, bwd);
}
