#include "../include/285z/initrobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"

//function called in main.cpp
//will select auton then run it

void selectAuton(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){

  liftMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
  liftMotor.moveAbsolute(400, 200);
  liftMotor.moveAbsolute(50, -200);
  pros::delay(300);

  if(autonPot.get() >= 0 && autonPot.get() < 1023){
    redFiveCube(chassis);
  }
  if(autonPot.get() >= 1023 && autonPot.get() < 2047){
    blueFiveCube(chassis);
  }
  if(autonPot.get() >= 2047 && autonPot.get() < 3072){
    redLongGoal(chassis);
  }
  if(autonPot.get() >= 3072 && autonPot.get() < 4096){
    blueLongGoal(chassis);
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
//*****************************   RED: FIVE CUBES    **********************//
void redFiveCube(std::shared_ptr<okapi::OdomChassisController> chassis){
  Tray angler;


  //       RED AUTON       //
  //Intake On
  intake.moveVelocity(270);
  //Move to blocks
  chassis->setState({0.5_ft,9.9_ft,0_deg});
  chassis->driveToPoint({5.05_ft, 9.9_ft});
  pros::Task::delay(500);
//  chassis->turnToAngle(135_deg);
  intake.setBrakeMode(AbstractMotor::brakeMode::hold);
  intake.moveVelocity(0);

  chassis->driveToPoint({3.0_ft, 9.9_ft}, true);
  // chassis->waitUntilSettled();
	chassis->turnToAngle(160_deg);
  // chassis->waitUntilSettled();


  chassis->setState({0.5_ft,9.9_ft,0_deg});
  intake.moveRelative(-725, 30);
  chassis->driveToPoint({2_ft, 9.9_ft});

  angler.moveToUp(false);
  //false means its auton
  //intake.moveRelative(-700, 50);

  pros::Task::delay(2300);
  intake.moveRelative(-300, 110);
  pros::Task::delay(200);
  chassis->moveDistance(-1.5_ft);
  angler.moveToDown(false);
}

//************************   BLUE: FIVE CUBES   ****************************//
void blueFiveCube(std::shared_ptr<okapi::OdomChassisController> chassis){
  Tray angler;

  //       RED AUTON       //
  //Intake On
  intake.moveVelocity(270);
  //Move to blocks
  chassis->setState({0.5_ft,9.9_ft,0_deg});
  chassis->driveToPoint({5.05_ft, 9.9_ft});
  pros::Task::delay(500);

  intake.setBrakeMode(AbstractMotor::brakeMode::hold);
  intake.moveVelocity(0);

  chassis->driveToPoint({1.6_ft, 9.9_ft}, true);
  chassis->waitUntilSettled();
	chassis->turnToPoint({0.25_ft, 8.5_ft});
  chassis->waitUntilSettled();


  chassis->setState({0.5_ft,9.9_ft,0_deg});
  intake.moveRelative(-725, 30);
  chassis->driveToPoint({1.25_ft, 9.9_ft});

  angler.moveToUp(false);
  //false means its auton
  //intake.moveRelative(-700, 50);

  pros::Task::delay(2300);
  intake.moveRelative(-300, 110);
  pros::Task::delay(200);
  chassis->moveDistance(-1.5_ft);
  angler.moveToDown(false);
}

void test(std::shared_ptr<okapi::OdomChassisController> chassis) {
  chassis->setState({0.5_ft,9.9_ft,0_deg});
  chassis->driveToPoint({2.5_ft, 9.9_ft});
}

void longGoalRed(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
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
}

void nineCubeTestRed(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  Tray angler;

  slow->setTarget("A", fwd);
  slow->waitUntilSettled();//goes forward to get 4 cubes

  fast->setTarget("S", bwd);
  fast->waitUntilSettled();//splines backwards to line up for second row

  slow->setTarget("A", fwd);
  slow->waitUntilSettled();//intakes last 3 CUBES

  chassis->turnToAngle(-135_deg);
  fast->setTarget("B");//drives to goal zone
  fast->waitUntilSettled();

  stackDeploy();
}


/*
==========================
NEW AUTON STRUCTURE
place all the relevant autons here.
Describe exact position for each
  //RED
    //LONG GOAL RED

    //SHORT GOAL RED

  //BLUE
    //LONG GOAL BLUE

    //SHORT GOAL BLUE
*/
