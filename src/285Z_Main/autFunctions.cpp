#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
                                                                                  // v
//function called in main.cpp
//will select auton then run it

void selectAuton(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){

  liftMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
  /*
  liftMotor.moveAbsolute(400, 200);
  liftMotor.moveAbsolute(50, -200);
  pros::delay(300);
  */
//
  if(autonPot.get() >= 0 && autonPot.get() < 1023){
    //shortGoalFiveRed(chassis, slow, fast);
    shortGoalFiveRed(chassis, slow, fast);
  }
  if(autonPot.get() >= 1023 && autonPot.get() < 2047){
    shortGoalFiveBlue(chassis, slow, fast);
  }
  if(autonPot.get() >= 2047 && autonPot.get() < 3072){
    longGoalRed(chassis, slow, fast);
  }
  if(autonPot.get() >= 3072 && autonPot.get() < 4096){
    longGoalBlue(chassis, slow, fast);
  }
}

//will write to the screen to say the auton

  void displayAuton(){
  double potVal = autonPot.get();
  if(potVal >= 0 && potVal < 1023){
    lv_aut_display("RED SHORT GOAL");
  }
  if(potVal >= 1023 && potVal < 2047){
    lv_aut_display("BLUE SHORT GOAL");
  }
  if(potVal >= 2047 && potVal < 3072){
    lv_aut_display("RED LONG GOAL");
  }
  if(potVal >= 3072 && potVal < 4096){
    lv_aut_display("BLUE LONG GOAL");
  }
}

//TODO: MAKE THIS RETURN FAST AND SLOW WITH GENERATED PATHS, USE THIS IN ITITIALIZE MAIN
void initAutoPaths(std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){

  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {3.5_ft,0_ft,0_deg}},
    "A"
  );
  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {4.5_ft,0_ft,0_deg}},
    "B"
  );
  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {4_ft,2_ft,0_deg}},
    "S"
  );
  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {1.5_ft,0_ft,0_deg}},
    "C"
  );
  std::shared_ptr<okapi::AsyncMotionProfileController> mp[2];
  mp[0] = slow;
  mp[1] = fast;

}

//******************AUXILIARY FUNCTIONS *************************//

void autoStackDeploy(){
  Tray angler;
  angler.moveToUp(0); //0 in
}

void robotDeploy()
{
  liftMotor.moveAbsolute(200, 100);

}

//***************** RED AUTONOMOUS PROGRAMS *********************//
//*****************************   RED: FIVE CUBES    **********************//
void shortGoalFiveRed(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift theLift;

  theLift.deploy();
  //************** INIT PATHS *******************//
  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {4.5_ft,0_ft,0_deg}},
    "F1"
  );

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {0.5_ft,0_ft,0_deg}},
    "F2"
  );

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {2_ft,0_ft,0_deg}},
    "B1"
  );
  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {4.5_ft,0_ft,0_deg}},
    "G"
  );
  //************** RUN AUTON *******************//
  robotDeploy();

  slow->setTarget("F1", fwd);
  slow->waitUntilSettled();//goes forward to get 4 cubes
  turn(320);

  fast->setTarget("F2", fwd);
  fast->waitUntilSettled();

  fast->setTarget("F2", bwd);
  fast->waitUntilSettled();
  turn(160);

  fast->setTarget("G");//drives to goal zone
  fast->waitUntilSettled();

  autoStackDeploy();
}

//******************************   RED: NINE CUBES   ****************************//
void shortGoalNineRed(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast)
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
void longGoalRed(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){
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


//*************BLUE AUTONOMOUS PROGRAMS********************//

//************************   BLUE: FIVE CUBES   ****************************//
void shortGoalFiveBlue(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift theLift;

  theLift.deploy();
  //************** INIT PATHS *******************//
/*
  slow->generatePath({
    {0_ft,0_ft,0_deg},
    {3.5_ft,0_ft,0_deg}},
    "F1"
  );
  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {4.5_ft,0_ft,0_deg}},
    "B1"
  );
  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {4_ft,2_ft,0_deg}},
    "F2"
  );
  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {1.5_ft,0_ft,0_deg}},
    "G"
  );
  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {0.5_ft,0.5_ft,0_deg}},
    "Z1"
  );
  //************** RUN AUTON *******************/

/*
  slow->setTarget("F1", fwd);
  slow->waitUntilSettled();//goes forward to get 4 cubes

  fast->setTarget("B1", bwd);
  fast->waitUntilSettled();//splines backwards to line up for second row

  slow->setTarget("F2", fwd);
  slow->waitUntilSettled();//intakes last 3 CUBES

  chassis->turnToAngle(-135_deg);
  fast->setTarget("G");//drives to goal zone
  fast->waitUntilSettled();
*/
  intake.moveVelocity(100);

  driveL.moveVelocity(30);
  driveR.moveVelocity(30);
  pros::delay(3000);
  driveL.moveVelocity(50);
  driveR.moveVelocity(-50);
  pros::delay(400);
  driveL.moveVelocity(30);
  driveR.moveVelocity(30);
  pros::delay(2000);
  driveL.moveVelocity(0);
  driveR.moveVelocity(0);
  autoStackDeploy();
  pros::delay(1000);
}


//************************   BLUE: SHORT GOAL, NINE CUBES   ****************************//
void shortGoalNineBlue(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){
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
void longGoalBlue(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){
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
  intake.moveVelocity(100);
  slow->setTarget("F1", fwd);
  slow->waitUntilSettled();//goes forward to get 2 cubes from VERTICAL Stack

  chassis->turnToAngle(35_deg); //intake cube in front of tower
  chassis->turnToAngle(5_deg); //turn back
  fast->setTarget("B1", bwd);
  fast->waitUntilSettled();//move backwards straight

  chassis->turnToAngle(110_deg); //turn to cube next to long goal
  slow->setTarget("F2", fwd);
  slow->waitUntilSettled();//intakes one cube

  intake.moveVelocity(0);
  chassis->turnToAngle(150_deg);
  fast->setTarget("G");//drives to goal zone
  fast->waitUntilSettled();

  //deploy
  intake.moveAbsolute(-90, 60);
  autoStackDeploy();
}

void oneCubeSad(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {1.5_ft,0_ft,0_deg}},
    "G"
  );
  fast->setTarget("G",bwd);
  fast->waitUntilSettled();
  fast->setTarget("G");
}

void redSmallManual(){
  deployTray();
}
void deployTray(){
  driveL.moveVelocity(200);
  driveR.moveVelocity(200);
  pros::delay(100);
  intake.moveVelocity(-100);
  pros::delay(200);
  intake.moveVelocity(100);
  pros::delay(500);
  driveL.moveVelocity(-100);
  driveR.moveVelocity(-100);
  pros::delay(200);
}
