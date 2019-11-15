#include "../include/285z/initRobot.hpp"

okapi::Controller controller;

//button definitions
okapi::ControllerButton intakeButton = okapi::ControllerDigital:: R2;
okapi::ControllerButton outtakeButton = okapi::ControllerDigital::R1;

okapi::ControllerButton trayButton = okapi::ControllerDigital:: A;
okapi::ControllerButton stopPIDButton = okapi::ControllerDigital:: Y;

okapi::ControllerButton liftUpButton = okapi::ControllerDigital::L1;
okapi::ControllerButton liftDownButton = okapi::ControllerDigital::L2;

// Broken Ports: 5, 14
 //motor port definitions

 //angler motor port
 int anglerPort = 20;

 //drive motor points
 int frontLeftPort = 11;
 int backLeftPort = 12;
 int frontRightPort = -13;
 int backRightPort = -5;

 //intake motor ports
 int intakeRightPort = 18;
 int intakeLeftPort = -2;

 //lift motor port
 int liftPort = 3;

//false is down
//true is up


 //motors for the drivetrain
 //could be incorrect
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
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

okapi::ChassisScales scales
{
 {4.125_in, 9.75_in},
 imev5GreenTPR
};

auto drive = okapi::ChassisControllerBuilder()
                  .withMotors({ 11, 12 }, { -13, -14 })
                  .withGearset(okapi::AbstractMotor::gearset::green)
                  .withDimensions(scales)
                  .withMaxVelocity(200)
                  .withOdometry(okapi::StateMode::FRAME_TRANSFORMATION, 0_mm, 0_deg, 0.00001_mps)
                  .buildOdometry();
std::shared_ptr<okapi::ChassisModel> model = std::dynamic_pointer_cast<okapi::ChassisModel>(drive->getModel());
