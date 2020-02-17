#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"

void profileControllers()
{

auto motion =
  ChassisControllerBuilder()
    .withMotors({frontLeftPort,backLeftPort}, {frontRightPort,backRightPort})
    .withDimensions(AbstractMotor::gearset::green, scales)
    .withMaxVelocity(200)
    .build();

auto fast =
  AsyncMotionProfileControllerBuilder()
    .withLimits({
      1.1,  //max velocity
      2.5,  //max acceleration
      10.0  //max jerk
    })
    .withOutput(motion)
    .buildMotionProfileController();

auto slow =
  AsyncMotionProfileControllerBuilder()
    .withLimits({
      0.3,  //max velocity
      2.0,  //max acceleration
      10.0  //max jerk
    })
    .withOutput(motion)
    .buildMotionProfileController();

/*
auto chassis = okapi::ChassisControllerBuilder()
    .withMotors({frontLeftPort,backLeftPort}, {frontRightPort,backRightPort}) // left motor is 1, right motor is 2 (reversed)
    .withGains(
       {0.001, 0.001, 0.00009}, // Distance controller gains 0.005, 0, 0.001
       {0.001, 0.001, 0.00001}, // Turn controller gains
       {0.001, 0.001, 0.0001}  // Angle controller gains (helps drive straight)
     )
    .withDimensions(AbstractMotor::gearset::green, {{4.125_in, 9.75_in}, imev5GreenTPR})
    .withOdometry() // use the same scales as the chassis (above)
    .withMaxVelocity(200)
    .buildOdometry(); // build an odometry chassis
    */
  }

  void autoStackDeploy()
  {
    Tray angler;
    intake.moveRelative(-600, 110);
    intake.setBrakeMode(AbstractMotor::brakeMode::coast);
    angler.moveToUp(false);
    pros::Task::delay(3000);
    intake.moveRelative(-75, 110);
    //fast->setTarget("C",bwd); //drives away
  }
