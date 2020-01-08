#include "../include/285z/initrobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"

//function called in main.cpp
//will select auton then run it
/*
void selectAuton(std::shared_ptr<okapi::OdomChassisController> chassis){
/*
  liftMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
  liftMotor.moveAbsolute(400, 200);
  liftMotor.moveAbsolute(50, -200);
  pros::delay(300);
*//*
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
*/

//will write to the screen to say the auton
/*
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
*/
//*****************************   RED: FIVE CUBES    **********************//
const bool fwd {false};
const bool bwd {true};

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

//************************   RED: NINE CUBES   ****************************//
void redNineCube(std::shared_ptr<okapi::OdomChassisController> chassis){
  Tray angler;

  //       RED AUTON       //
  //Intake On
  intake.moveVelocity(200);
  //Move to blocks
  chassis->setState({0.5_ft,9.9_ft,0_deg});
  chassis->driveToPoint({4.5_ft, 9.9_ft});
  pros::Task::delay(500);

  chassis->driveToPoint({1_ft, 6.9_ft}, true);
  chassis->turnToPoint({2_ft, 6.9_ft});
	/*chassis->turnToPoint({1.5_ft, 9.0_ft});
  pros::Task::delay(300);
  //second param means backwards

  chassis->setState({0.5_ft,9.9_ft,0_deg});
  chassis->driveToPoint({3.5_ft, 9.9_ft});
  intake.moveVelocity(3);
  //back up

  //need to work out deceleration program
  //sqiggle backwards to line up with second row
  pros::Task::delay(200);

  //false means its auton
  intake.moveRelative(-700, 50);
  angler.moveToUp(false);
  pros::Task::delay(2000);

  chassis->moveDistance(-1.5_ft);
  angler.moveToDown(false);*/
}

//************************   BLUE: NINE CUBES   ****************************//
void blueNineCube(std::shared_ptr<okapi::OdomChassisController> chassis){

}

//************************   RED: LONG GOAL   ****************************//
void redLongGoal(std::shared_ptr<okapi::OdomChassisController> chassis){
  Tray angler;

  //       RED AUTON       //
  //Intake On
  intake.moveVelocity(270);
  //Move to blocks
  chassis->setState({0.5_ft,9.9_ft,0_deg});
  chassis->driveToPoint({4.25_ft, 9.9_ft});
//  chassis->turnToAngle(135_deg);
  intake.setBrakeMode(AbstractMotor::brakeMode::hold);


  chassis->driveToPoint({2.5_ft, 9.9_ft}, true);
	chassis->turnToAngle(-100_deg);


  chassis->setState({0.5_ft,9.9_ft,0_deg});
  chassis->driveToPoint({2.0_ft, 9.9_ft});
  intake.moveVelocity(0);
  chassis->turnToAngle(-45_deg);
  intake.moveRelative(-725, 30);
  chassis->setState({0.5_ft,9.9_ft,0_deg});
  chassis->driveToPoint({2_ft, 9.9_ft});
  angler.moveToUp(false);
  //false means its auton
  //intake.moveRelative(-700, 50);

  pros::Task::delay(1500);
  intake.moveRelative(-300, 110);
  pros::Task::delay(200);
  chassis->moveDistance(-1.5_ft);
  angler.moveToDown(false);
}

//************************   BLUE: LONG GOAL   ****************************//
void blueLongGoal(std::shared_ptr<okapi::OdomChassisController> chassis){
  Tray angler;

  //       RED AUTON       //
  //Intake On
  intake.moveVelocity(270);
  //Move to blocks
  chassis->setState({0.5_ft,9.9_ft,0_deg});
  chassis->driveToPoint({4.25_ft, 9.9_ft});
//  chassis->turnToAngle(135_deg);
  intake.setBrakeMode(AbstractMotor::brakeMode::hold);


  chassis->driveToPoint({2.5_ft, 9.9_ft}, true);
	chassis->turnToAngle(100_deg);


  chassis->setState({0.5_ft,9.9_ft,0_deg});
  chassis->driveToPoint({2.0_ft, 9.9_ft});
  intake.moveVelocity(0);
  chassis->turnToAngle(45_deg);
  intake.moveRelative(-725, 30);
  chassis->setState({0.5_ft,9.9_ft,0_deg});
  chassis->driveToPoint({1.75_ft, 9.9_ft});
  angler.moveToUp(false);
  //false means its auton
  //intake.moveRelative(-700, 50);

  pros::Task::delay(1500);
  intake.moveRelative(-300, 110);
  pros::Task::delay(200);
  chassis->moveDistance(-1.5_ft);
  angler.moveToDown(false);
}

void test(std::shared_ptr<okapi::OdomChassisController> chassis) {
  chassis->setState({0.5_ft,9.9_ft,0_deg});
  chassis->driveToPoint({2.5_ft, 9.9_ft});
}

void nineCubeTestRed(std::shared_ptr<okapi::OdomChassisController> chassis)
{
  Tray angler;

  slow.generatePath({
    {0_ft,0_ft,0_deg},
    {3.5_ft,0_ft,0_deg}},
    "A"
  );//4"
  fast.generatePath({
    {0_ft,0_ft,0_deg}
    ,{4.5_ft,0_ft,0_deg}},
    "B"
  );
  fast.generatePath({
    {0_ft,0_ft,0_deg}
    ,{4_ft,2_ft,0_deg}},
    "S"
  );
  fast.generatePath({
    {0_ft,0_ft,0_deg}
    ,{1.5_ft,0_ft,0_deg}},
    "C"
  );

  intake.moveVelocity(-200);
  pros::Task::delay(500);
  intake.moveVelocity(200);//deploy

  slow.setTarget("A", fwd);
  slow.waitUntilSettled();//goes forward to get 4 cubes

  fast.setTarget("S", bwd);
  fast.waitUntilSettled();//splines backwards to line up for second row

  slow.setTarget("A", fwd);
  slow.waitUntilSettled();//intakes last 3 CUBES

  chassis->turnToAngle(-135_deg);
  fast.setTarget("B");//drives to goal zone
  fast.waitUntilSettled();

  angler.moveToUp(false);
  pros::Task::delay(2300);
  intake.moveRelative(-300, 110);
  pros::Task::delay(200);
  fast.setTarget("C",bwd);
  angler.moveToDown(false);//stack deploy
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
