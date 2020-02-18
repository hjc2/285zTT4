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
  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {3.25_ft,0_ft,0_deg}},
    "F1"
  );

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {0.85_ft,0_ft,0_deg}},
    "F2"
  );

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {1.5_ft,0_ft,0_deg}},
    "F3"
  );

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {2_ft,0_ft,0_deg}},
    "B1"
  );

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {0.25_ft,0_ft,0_deg}},
    "B2"
  );

  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {1.75_ft,0_ft,0_deg}},
    "G"
  );

  slow->setTarget("F1", fwd);
  slow->waitUntilSettled();//goes forward to get 4 cubes
  slow->removePath("F1");
  turn(20);

  fast->setTarget("F2", fwd);
  fast->waitUntilSettled();

  fast->setTarget("B1", bwd);
  fast->waitUntilSettled();
  intake.moveVelocity(0);
  turn(225);

  slow->setTarget("G", fwd);//drives to goal zone
  slow->waitUntilSettled();

  autoStackDeploy();

  fast->setTarget("B2", bwd);
  fast->waitUntilSettled();
}
//************************   BLUE: SHORT GOAL, NINE CUBES   ****************************//
void sgNineBlue(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift theLift;

  //************** INIT PATHS *******************//
  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {4_ft,0_ft,0_deg}},
    "F1"
  );

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {3_ft,0_ft,0_deg}},
    "B1"
  );
  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {3.75_ft,0_ft,0_deg}},
    "F2"
  );

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {5_ft,0_ft,0_deg}},
    "F3"
  );

  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {0.5_ft,0_ft,0_deg}},
    "B2"
  );
  theLift.deploy();

  intake.moveVelocity(200);

  slow->setTarget("F1", fwd);
  slow->waitUntilSettled();//goes forward to get 4 cubes
  turn(30);

  fast->setTarget("B1", bwd);
  fast->waitUntilSettled();//moves backward to align with other 4 cubes
  turn(0);

  slow->setTarget("F2", fwd);
  slow->waitUntilSettled();//intakes last 4 cubes
  turn(210);

  fast->setTarget("F3", fwd);//drives to goal zone
  fast->waitUntilSettled();

  autoStackDeploy();

  slow->setTarget("B2", bwd);
  slow->waitUntilSettled();
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
