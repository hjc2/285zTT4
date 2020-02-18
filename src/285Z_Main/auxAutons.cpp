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

void autoStackDeploy() {
  Tray angler;
  intake.moveRelative(-680, 110);
  intake.setBrakeMode(AbstractMotor::brakeMode::coast);
  angler.moveToUp(false);
  pros::Task::delay(2000);
  //intake.moveRelative(-75, 110);
  //fast->setTarget("C",bwd); //drives away
}

//****************** SKILLS ***********************************//
void skills(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift lift;
  lift.deploy();

  intake.moveVelocity(200);

  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {6_ft,0_ft,0_deg}},
    "F1"
  );

  //PART 1: INTAKE 10 CUBES AND TURN TO GOAL
  slow->setTarget("F1", fwd);
  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {0.9_ft,0_ft,0_deg}},
    "G"
  );
  slow->waitUntilSettled();//goes forward to get 4 cubes
  slow->removePath("F1");

  turn(45);
  intake.moveVelocity(0);

  //PART 2: MOVE TO GOAL, DEPLOY, BACK UP, TURN TO TOWER CUBE
  slow->setTarget("G", fwd);
  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {0.5_ft,0_ft,0_deg}},
    "B1"
  );
  slow->waitUntilSettled();
  slow->removePath("G");

  autoStackDeploy();

  fast->setTarget("B1", bwd);
  fast->waitUntilSettled();
  fast->removePath("B1");
  turn(270);

  //PART 3: INTAKE NEXT BATCH OF CUBES

}

//****************** ONE CUBE ***********************************//
void one(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  move(slow, 1_ft, bwd);
}
