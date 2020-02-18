#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"


//*****************************   RED: FIVE CUBES    **********************//
void sgSixRed(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){
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
  turn(340);

  fast->setTarget("F2", fwd);
  fast->waitUntilSettled();

  fast->setTarget("B1", bwd);
  fast->waitUntilSettled();
  intake.moveVelocity(0);
  turn(135);

  slow->setTarget("G");//drives to goal zone
  slow->waitUntilSettled();

  autoStackDeploy();

  fast->setTarget("B2");
  fast->waitUntilSettled();
}

//******************************   RED: NINE CUBES   ****************************//
void sgNineRed(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
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
  turn(330);

  fast->setTarget("B1", bwd);
  fast->waitUntilSettled();//moves backward to align with other 4 cubes
  turn(0);

  slow->setTarget("F2", fwd);
  slow->waitUntilSettled();//intakes last 4 cubes
  turn(150);

  fast->setTarget("F3", fwd);//drives to goal zone
  fast->waitUntilSettled();

  autoStackDeploy();

  slow->setTarget("B2", bwd);
  slow->waitUntilSettled();
}

//************************   RED: LONG GOAL   ****************************//
void lgRed(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;

  //************** INIT PATHS *******************//
  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {4.5_ft,0_ft,0_deg}},
    "F1"
  );

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {3.5_ft,0_ft,0_deg}},
    "B1"
  );

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {4_ft,0_ft,0_deg}},
    "F2"
  );
  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {1.5_ft,0_ft,0_deg}},
    "G"
  );
  //************** RUN AUTON *******************//
  slow->setTarget("F1", fwd);
  slow->waitUntilSettled();//goes forward to get 2 cubes from VERTICAL Stack

  chassis->turnToAngle(-35_deg); //intake cube in front of tower
  chassis->turnToAngle(35_deg);
  fast->setTarget("B1", bwd);
  fast->waitUntilSettled();//move backwards straight

  chassis->turnToAngle(-95_deg); //turn to cube next to long goal
  slow->setTarget("F2", fwd);
  slow->waitUntilSettled();//intakes one cube

  chassis->turnToAngle(-50_deg);
  fast->setTarget("G");//drives to goal zone
  fast->waitUntilSettled();

  //deploy
  intake.moveAbsolute(-90, 60);
  autoStackDeploy();
}
