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
  intake.moveVelocity(200);
  //Move to blocks
  chassis->setState({0.5_ft,9.9_ft,0_deg});
  chassis->driveToPoint({4.5_ft, 9.9_ft});
  pros::Task::delay(500);

  chassis->driveToPoint({3.5_ft, 9.9_ft}, true);
	chassis->turnToPoint({1.5_ft, 9.0_ft});
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
  angler.moveToDown(false);
}

//************************   BLUE: FIVE CUBES   ****************************//
void blueFiveCube(std::shared_ptr<okapi::OdomChassisController> chassis){
  Tray angler;

  //       BLUE AUTON       //
  intake.moveVelocity(200);
  //Move to blocks
  chassis->setState({11.5_ft,9.9_ft,0_deg});
  chassis->driveToPoint({7.5_ft, 9.9_ft});

  pros::Task::delay(500);

  chassis->driveToPoint({8.25_ft, 9.75_ft}, true);
	chassis->turnToPoint({10_ft, 8.75_ft});
  pros::Task::delay(300);

  chassis->setState({0.5_ft,9.9_ft,0_deg});
  chassis->driveToPoint({3.5_ft, 9.9_ft});
  intake.moveVelocity(3);
  pros::Task::delay(200);

  intake.moveRelative(-700, 50);
  angler.moveToUp(false);
  pros::Task::delay(2000);

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

  chassis->driveToPoint({1_ft, 6.9ft}, true);
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
