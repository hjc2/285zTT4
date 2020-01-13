#include "../include/285z/initRobot.hpp"

okapi::Controller controller;

okapi::ControllerButton intakeButton = okapi::ControllerDigital:: R2; //Intake Buttons
okapi::ControllerButton outtakeButton = okapi::ControllerDigital::R1;

okapi::ControllerButton trayButton = okapi::ControllerDigital:: A;    //Tray Buttons
okapi::ControllerButton stopPIDButton = okapi::ControllerDigital:: Y;

okapi::ControllerButton liftUpButton = okapi::ControllerDigital::L1;  //Lift Buttons
okapi::ControllerButton liftDownButton = okapi::ControllerDigital::L2;

okapi::ControllerButton deployButton = okapi::ControllerDigital::B;  //Macro Buttons




 //drive motor points
 int frontLeftPort = 9;
 int backLeftPort = 3;
 int frontRightPort = -8; //reversed
 int backRightPort = -1;  //reversed

 //intake motor ports
 int intakeLeftPort = 18;
 int intakeRightPort = -15;

 //LIFT MOTOR PORT
 int liftPort = 16;
 //angler motor port
 int anglerPort = 2;

 Motor frontLeftMotor(frontLeftPort);
 Motor backLeftMotor(backLeftPort);
 Motor frontRightMotor(frontRightPort);
 Motor backRightMotor(backRightPort);

 Motor intakeRightMotor(intakeRightPort);
 Motor intakeLeftMotor(intakeLeftPort);

 Motor anglerMotor(anglerPort);
 Motor liftMotor(liftPort);

//motor groups
 MotorGroup intake({intakeRightPort, intakeLeftPort});

 MotorGroup driveL({frontLeftPort, backLeftPort});
 MotorGroup driveR({frontRightPort, backRightPort});

 double wheelSize = 4.125;
 double wheelBase = 9.75;

okapi::ChassisScales scales
{
  //4.125 is the wheelsize and 9.75 is the wheelbase
 {4.125_in, 9.75_in}, //dimensions of the chassis
 imev5GreenTPR
};


// auto chassis = okapi::ChassisControllerBuilder()
//     .withMotors({frontLeftPort,backLeftPort}, {frontRightPort,backRightPort}) // left motor is 1, right motor is 2 (reversed)
//     .withDimensions(AbstractMotor::gearset::green, {{4.125_in, 9.75_in}, imev5GreenTPR})
//     .withMaxVelocity(200)
//     .build(); // build an odometry chassis
