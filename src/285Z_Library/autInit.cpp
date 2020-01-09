#include "../include/285z/initRobot.hpp"

void profileControllers()
{

auto motion =
  ChassisControllerBuilder()
    .withMotors({frontLeftPort,backLeftPort}, {frontRightPort,backRightPort})
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.5_in}, imev5GreenTPR})
    .build();

auto fast =
  AsyncMotionProfileControllerBuilder()
    .withLimits({
      5.0,  //max velocity
      3.0,  //max acceleration
      10.0  //max jerk
    })
    .withOutput(motion)
    .buildMotionProfileController();

auto slow =
  AsyncMotionProfileControllerBuilder()
    .withLimits({
      0.5,
      2.0,
      10.0
    })
    .withOutput(motion)
    .buildMotionProfileController();

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

  }
