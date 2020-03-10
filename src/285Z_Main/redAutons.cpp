#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"


//*****************************   RED: FIVE CUBES    **********************//

void sgFiveRed(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift lift;
  intake.moveVelocity(200);
  //************** INIT PATHS *******************//
  move(slow, 3.48_ft, fwd); //gets line of cubes
  angler.deploy(true);
  // chassisaut->turnToAngle(-25_deg);
  // turn(356);
  // move(slow, 0.80_ft, fwd);

  move(fast, 2.0_ft, bwd);
  // turn(160);
  chassisaut->turnToAngle(146_deg);

  move(fast, 1.575_ft, fwd);

  intake.moveVelocity(0);

  autoStackDeploy(1400);

  intake.moveVelocity(-120);
  move(fast, 1.2_ft, bwd);
  angler.moveToDown(false);
}

void sgSixRed(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift lift;
  intake.moveVelocity(200);
  //************** INIT PATHS *******************//
  move(medium, 3.43_ft, fwd); //gets line of cubes
  angler.deploy(true);
  // chassisaut->turnToAngle(-30_deg);
  turn(356);

  move(slow, 0.80_ft, fwd);
  move(fast, 1.8_ft, bwd);
  // turn(160);
  chassisaut->turnToAngle(168_deg);

  move(medium, 1.60_ft, fwd);

  intake.moveVelocity(0);

  autoStackDeploy(1400);

  intake.moveVelocity(-120);
  move(fast, 1.2_ft, bwd);
  angler.moveToDown(false);
}

//******************************   RED: NINE CUBES   ****************************//
void sgNineRed(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  Tray angler;
  Lift lift;

  lift.deploy();

  intake.moveVelocity(200);

  move(fast, 3.20_ft, fwd);
  turn(330);

  move(fast, 3.20_ft, bwd);
  turn(0);

  move(fast, 3.1_ft, fwd);

  move(fast, 2_ft, bwd);
  intake.moveVelocity(0);
  turn(145);

  move(slow, 1.3_ft, fwd);

  autoStackDeploy(1400);

  intake.moveVelocity(-120);
  move(fast, 1_ft, bwd);
  angler.moveToDown(false);
}

//************************   RED: LONG GOAL   ****************************//
void lgRed(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift lift;

  move(fast, 2_ft, fwd);
  angler.deploy(true);
  chassisaut->turnToAngle(100_deg);
  //turn(96);

  move(medium, 2.7_ft, fwd);
  move(fast, 2.4_ft, bwd);
  turn(210);

  move(fast, 1.05_ft, fwd);
  autoStackDeploy(1400);

  move(fast, 1.3_ft, bwd);
  angler.moveToDown(false);
}

void sgTenRed(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift lift;
  lift.deploy();
  //i used the color tags as the sections of planning in one note for the path
  //PLEASE CHECK THE ONE NOTE FOR PATH
  //Auton Sketches / 10 Cube Small Goal Red

  //RED
  intake.moveVelocity(200);
  move(fast, 2_ft, fwd); //intaking the preload and 2 cubes
  lift.moveTo(500); //grabbing the last 2 jn the tetris
  move(slow, 0.5_ft, fwd);
  pros::delay(200);
  lift.moveTo(0);
  pros::delay(300);

  //ORANGE
  intake.moveVelocity(10);
  move(fast, 0.5_ft, bwd);

  //TURN A
  turn(-45);

  //YELLOW
  intake.moveVelocity(100);
  move(fast, 1.7_ft, fwd);

  //GREEN
  intake.moveVelocity(10);
  move(fast, 5_ft, bwd);
  move(fast, 4_ft, bwd);

  //TURN B
  turn(50);

  //CYAN
  intake.moveVelocity(100);
  move(fast, 5_ft, fwd);

  //MAGENTA
  move(fast, 3_ft, bwd);

  //TURN C
  turn(-45);

  //PINK
  intake.moveVelocity(-3);
  angler.moveToUp(true);
  move(fast, 3_ft, fwd);

  //PURPLE
  intake.moveVelocity(-20);
  move(slow, 3_ft, bwd);
  angler.moveToDown(true);
}
