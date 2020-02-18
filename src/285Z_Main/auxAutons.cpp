#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"

void autoStackDeploy() {
  Tray angler;
  intake.moveRelative(-600, 110);
  intake.setBrakeMode(AbstractMotor::brakeMode::coast);
  angler.moveToUp(false);
  pros::Task::delay(3000);
  intake.moveRelative(-75, 110);
  //fast->setTarget("C",bwd); //drives away
}

//****************** ONE CUBE ***********************************//
void skills(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift lift;
  lift.deploy();

  intake.moveVelocity(200);
  //************** INIT PATHS *******************//
  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {6_ft,0_ft,0_deg}},
    "F1"
  );

  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {1.85_ft,0_ft,0_deg}},
    "F2"
  );

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {0.5_ft,0_ft,0_deg}},
    "B1"
  );

  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {0.9_ft,0_ft,0_deg}},
    "G"
  );

  //PART 1: INTAKE 10 CUBES AND TURN TO GOAL
  slow->setTarget("F1", fwd);
  slow->waitUntilSettled();//goes forward to get 4 cubes
  turn(45);
  intake.moveVelocity(0);

  //PART 2: MOVE TO GOAL, DEPLOY, BACK UP, TURN TO TOWER CUBE
  slow->setTarget("G", fwd);
  slow->waitUntilSettled();

  autoStackDeploy();

  fast->setTarget("B1", bwd);
  fast->waitUntilSettled();
  turn(270);

  //PART 3: INTAKE NEXT BATCH OF CUBES
  
}

//****************** ONE CUBE ***********************************//
void one(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){

}
