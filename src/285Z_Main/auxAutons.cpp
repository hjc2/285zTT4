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

  intake.moveRelative(-760, 110); //outtakes stack
  intake.setBrakeMode(AbstractMotor::brakeMode::coast);
  angler.moveToUp(true);

  pros::Task::delay(stackDelay); //time to wait before backing up

  intake.moveVelocity(-100);

}

void tenCubeDeploy(double stackDelay) {
  Tray angler;
  intake.setBrakeMode(AbstractMotor::brakeMode::hold);
  // int threshold = 1000; //light threshold
  // while(cubeSensor.get_value() < threshold){
  //   intake.moveVelocity(-110);
  // }
  // intake.moveRelative(-40, 110); //outtakes stack
  angler.moveToUp(true);

  pros::Task::delay(stackDelay); //time to wait before backing up

  intake.moveVelocity(-100); //time to wait before backing up
}

void towerMacro(std::shared_ptr<okapi::AsyncMotionProfileController> slow){
  //Use when bot in front of tower and lift down
  Lift lift;
  intake.moveRelative(400, -170);
  move(slow, 0.5_ft, bwd);
  intake.moveVelocity(0);
  lift.moveTo(2300);
  move(slow, 0.5_ft, fwd);
  intake.moveRelative(-400, 200);
  pros::delay(500);
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
  // turn(41.5); //turn to goal
  chassisaut->turnToAngle(51.5_deg);
  intake.moveVelocity(0);

  move(slow, 1.575_ft, fwd);
  tenCubeDeploy(2300); //deploy
  move(slow, 1.9_ft, bwd);

  //POST DEPLOY
  pros::delay(1000);

  chassisaut-> setState({0_ft, 0_ft, 0_deg});
  //ALINIG OF THE ROBOT
  chassisaut->turnAngle(-138_deg);
  angler.moveToDown(true);
  chassisaut->setState({0_ft, 0_ft, 0_deg});
  move(medium, 1.6_ft, bwd); //RESETS AGAINST THE WALL

  // 2: TOWER ONE
  pros::delay(500);
  intake.moveVelocity(200);
  move(slow, 3.85_ft, fwd); //intake tower cube
  pros::delay(200);
  move(slow, 0.6_ft, bwd);
  move(slow, 0.8_ft, fwd);

  towerMacro(slow);

  pros::delay(500);
  intake.moveVelocity(0);
  chassisaut->turnToAngle(-80_deg);
  // turn(270); //turn to tower

  intake.moveVelocity(0);
  move(medium, 2_ft, bwd); //align against field wall
  chassisaut->setState({0_ft, 0_ft, 0_deg});

  pros::delay(500);

  //STARTING THE SECOND TOWER
  move(medium, 4_ft, fwd);
  chassisaut-> setState({0_ft, 0_ft, 0_deg});
  chassisaut->turnToAngle(90_deg);
  move(slow, 2.5_ft, fwd);
  towerMacro(slow);
  /*
  pros::delay(500);
  move(medium, 3.80_ft, fwd);
  intake.moveVelocity(0);
  chassisaut->turnToAngle(-40_deg);
  towerMacro(slow);

  pros::delay(4000);
  move(fast, 2.5_ft, bwd);
  chassisaut->turnToAngle(180_deg);
  move(slow, 0.5_ft, bwd);
  pros::delay(200);
  move(fast, 9_ft,fwd);
  */
}

//****************** ONE CUBE ***********************************//
void one(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  move(slow, 1_ft, bwd);
}
