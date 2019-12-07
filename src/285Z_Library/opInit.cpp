#include "../include/285z/initRobot.hpp"

okapi::Controller controller;

//button definitions
//button definitions for later
//okapi::ControllerButton myButton = okapi::ControllerDigital::A;

okapi::ControllerButton intakeButton = okapi::ControllerDigital:: R2;
okapi::ControllerButton outtakeButton = okapi::ControllerDigital::R1;

okapi::ControllerButton trayButton = okapi::ControllerDigital:: A;
okapi::ControllerButton stopPIDButton = okapi::ControllerDigital:: Y;

okapi::ControllerButton liftUpButton = okapi::ControllerDigital::L1;
okapi::ControllerButton liftDownButton = okapi::ControllerDigital::L2;

// Broken Ports: 5, 14
 //motor port definitions

 //int myMotorPort = 21;
 //angler motor port
 int anglerPort = 20;

 //drive motor points
 int frontLeftPort = 11;
 int backLeftPort = 12;
 int frontRightPort = -13;
 int backRightPort = -6;

 //intake motor ports
 int intakeRightPort = 10;
 int intakeLeftPort = -15;

 //lift motor port
 int liftPort = 7;

//sensor ports

 char potentiometerPort = 'A';
 Potentiometer autonPot(potentiometerPort);

//false is down
//true is up

//sensors
//pros::ADIPotentiometer selectorPort(potentiometerPort);

//declaring all the motors using the motor class
//made each port have a integer for easier reading

  //Motor myMotor(myMotorPort);
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
