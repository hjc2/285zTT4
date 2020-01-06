#include "../include/285z/initRobot.hpp"

okapi::Controller controller;

okapi::ControllerButton intakeButton = okapi::ControllerDigital:: R2;
okapi::ControllerButton outtakeButton = okapi::ControllerDigital::R1;

okapi::ControllerButton trayButton = okapi::ControllerDigital:: A;
okapi::ControllerButton stopPIDButton = okapi::ControllerDigital:: Y;

okapi::ControllerButton liftUpButton = okapi::ControllerDigital::L1;
okapi::ControllerButton liftDownButton = okapi::ControllerDigital::L2;

 //drive motor points
 int frontLeftPort = 1;
 int backLeftPort = 2;
 int frontRightPort = -3;
 int backRightPort = -4;

 //intake motor ports
 int intakeRightPort = 5;
 int intakeLeftPort = 6;

 //LIFT MOTOR PORT
 int liftPort = 7;
 //angler motor port
 int anglerPort = 8;

 Motor frontLeftMotor(frontLeftPort);
 Motor backLeftMotor(backLeftPort);
 Motor frontRightMotor(frontRightPort);
 Motor backRightMotor(backRightPort);

  //motors for the intake. (looking from the front)
 Motor intakeRightMotor(intakeRightPort);
 Motor intakeLeftMotor(intakeLeftPort);

  //angler motor is not sure
 Motor anglerMotor(anglerPort);
 Motor liftMotor(liftPort);

 MotorGroup intake({intakeRightPort, intakeLeftPort});

 double wheelSize = 4.125;
 double wheelBase = 9.75;
okapi::ChassisScales scales
{
  //4.125 is the wheelsize and 9.75 is the wheelbase
 {4.125_in, 9.75_in}, //dimensions of the chassis
 imev5GreenTPR
};

auto drive = okapi::ChassisControllerBuilder()
                  .withMotors({frontLeftPort, backLeftPort }, {frontRightPort, backRightPort}) //drive motors
                  .withGearset(okapi::AbstractMotor::gearset::green)
                  .withDimensions(scales)
                  .withMaxVelocity(200)
                  .withOdometry(okapi::StateMode::FRAME_TRANSFORMATION, 0_mm, 0_deg, 0.00001_mps)
                  .buildOdometry();
std::shared_ptr<okapi::ChassisModel> model = std::dynamic_pointer_cast<okapi::ChassisModel>(drive->getModel());
