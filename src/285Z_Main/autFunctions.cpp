#include "../include/285z/initrobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"


//TODO: Look up turntoPoint function

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
  chassis->waitUntilSettled();
	chassis->turnToAngle(160_deg);
  chassis->waitUntilSettled();


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

  chassis->driveToPoint({1.5_ft, 9.9_ft}, true);
  chassis->waitUntilSettled();
	chassis->turnToPoint({0.25_ft, 8.5_ft});
  chassis->waitUntilSettled();


  chassis->setState({0.5_ft,9.9_ft,0_deg});
  intake.moveRelative(-725, 30);
  chassis->driveToPoint({1_ft, 9.9_ft});

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

void redLongGoal(std::shared_ptr<okapi::OdomChassisController> chassis){
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

  chassis->driveToPoint({2.5_ft, 9.9_ft}, true);
  chassis->waitUntilSettled();
	chassis->turnToAngle(160_deg);
  chassis->waitUntilSettled();


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

void blueLongGoal(std::shared_ptr<okapi::OdomChassisController> chassis){
  Tray angler;

  //       RED AUTON       //
  //Intake On
  intake.moveVelocity(270);
  //Move to blocks
  chassis->setState({0.5_ft,9.9_ft,0_deg});
  chassis->driveToPoint({4.5_ft, 9.9_ft});
  pros::Task::delay(500);
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

  pros::Task::delay(2300);
  intake.moveRelative(-300, 110);
  pros::Task::delay(200);
  chassis->moveDistance(-1.5_ft);
  angler.moveToDown(false);
}
//************************   BLUE: NINE CUBES   ****************************//
void blueNineCube(std::shared_ptr<okapi::OdomChassisController> chassis){

}
