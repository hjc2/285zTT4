#include "../include/285z/initrobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"


//*****************************   RED: FIVE CUBES    **********************//
void redFiveCube(std::shared_ptr<okapi::OdomChassisController> chassis){
  Tray angler;

  //       RED AUTON       //
  //Intake On
  intake.moveVelocity(200);
  //Move to blocks
  chassis->setState({0_ft,9.9_ft,0_deg});
  chassis->driveToPoint({4_ft, 9.9_ft});
  chassis->waitUntilSettled();
  pros::Task::delay(1000);
  //need to work out deceleration program
  //sqiggle backwards to line up with second row
  chassis->moveDistance({-3_ft});
  intake.moveVelocity(5);
  //back up

  //need to work out deceleration program
  //sqiggle backwards to line up with second row
  pros::Task::delay(200);

  chassis->turnToAngle(270_deg);
  chassis->waitUntilSettled();
  intake.moveVelocity(-5);
  chassis->setState({0_ft,0_ft,0_deg});
  chassis->driveToPoint({4_ft,0_ft});

  angler.moveToState(1);
  pros::Task::delay(1000);

  chassis->moveDistance(-1_ft);
}

//************************   BLUE: FIVE CUBES   ****************************//
void blueFiveCube(std::shared_ptr<okapi::OdomChassisController> chassis){
  Tray angler;

  //       BLUE AUTON       //
  intake.moveVelocity(200);
  //Move to blocks
  chassis->setState({0_ft,9.9_ft,0_deg});
  chassis->driveToPoint({4_ft, 9.9_ft});
  chassis->waitUntilSettled();
  pros::Task::delay(1000);
  //need to work out deceleration program
  //sqiggle backwards to line up with second row
  chassis->moveDistance({-3_ft});
  intake.moveVelocity(5);
  //back up

  //need to work out deceleration program
  //sqiggle backwards to line up with second row
  pros::Task::delay(200);

  chassis->turnToAngle(-120_deg);
  intake.moveVelocity(-5);
  chassis->setState({0_ft,0_ft,0_deg});
  chassis->driveToPoint({4_ft,0_ft});

  angler.moveToState(1);
  pros::Task::delay(2000);

  chassis->moveDistance(-1_ft);
}

//************************   RED: NINE CUBES   ****************************//
void redNineCube(std::shared_ptr<okapi::OdomChassisController> chassis){

}


//************************   BLUE: NINE CUBES   ****************************//
void blueNineCube(std::shared_ptr<okapi::OdomChassisController> chassis){

}
