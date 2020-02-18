#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"

//*************BLUE AUTONOMOUS PROGRAMS********************//

//************************   BLUE: FIVE CUBES   ****************************//
void sgSixBlue(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift lift;
  lift.deploy();

  intake.moveVelocity(200);
  //************** INIT PATHS *******************//
  move(slow, 3.25_ft, fwd);
  turn(22);

  move(fast, 0.85_ft, fwd);
  move(fast, 2_ft, bwd);
  intake.moveVelocity(0);
  turn(230);

  move(slow, 1.5_ft, fwd);

  autoStackDeploy();

  intake.moveVelocity(-120);
  move(fast, 1_ft, bwd);
  angler.moveToDown(false);
}
//************************   BLUE: SHORT GOAL, NINE CUBES   ****************************//
void sgNineBlue(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift lift;

  lift.deploy();

  intake.moveVelocity(200);

  move(fast, 3.20_ft, fwd);
  turn(30);

  move(fast, 3.20_ft, bwd);
  turn(0);

  move(fast, 3.1_ft, fwd);

  move(fast, 2_ft, bwd);
  intake.moveVelocity(0);
  turn(230);

  move(slow, 1.3_ft, fwd);

  autoStackDeploy();

  intake.moveVelocity(-120);
  move(fast, 1_ft, bwd);
  angler.moveToDown(false);
}


//************************   BLUE: LONG GOAL   ****************************//
void lgBlue(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;

  //************** INIT PATHS *******************//
  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {4_ft,0_ft,0_deg}},
    "F1"
  );

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {2_ft,0_ft,0_deg}},
    "F2"
  );

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {5_ft,0_ft,0_deg}},
    "B1"
  );

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {0.5_ft,0_ft,0_deg}},
    "G"
  );
  //************** RUN AUTON *******************//

  slow->setTarget("F1", fwd);
  slow->waitUntilSettled();
  turn(45);

  fast->setTarget("F2", fwd);
  fast->waitUntilSettled();
  turn(330);

  slow->setTarget("B1", fwd);
  slow->waitUntilSettled();
  turn(120);

  fast->setTarget("G", fwd);
  fast->waitUntilSettled();
  turn(90);

  fast->setTarget("G", bwd);//drives to goal zone
  fast->waitUntilSettled();

  autoStackDeploy();

}
