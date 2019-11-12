#pragma once
#include "main.h"

//Controller
extern Controller controller;
//extern std::shared_ptr<okapi::ChassisModel> model;

//Controller Buttons
extern ControllerButton intakeButton;
extern ControllerButton trayButton;
extern ControllerButton trayDownButton;
extern ControllerButton outtakeButton;
extern ControllerButton liftUpButton;
extern ControllerButton liftDownButton;
extern ControllerButton liftToggleButton;
extern ControllerButton anglerUpButton;
extern ControllerButton anglerDownButton;
//  MOTORS  //

//ports
extern int anglerPort;
extern int liftPort;

//Drivetrain motors
extern Motor frontLeftMotor;
extern Motor backLeftMotor;
extern Motor frontRightMotor;
extern Motor backRightMotor;

//Drive motor groups
extern MotorGroup driveL;
extern MotorGroup driveR;

extern ChassisScales scales;

extern Motor intakeRightMotor;
extern Motor intakeLeftMotor;

 //Angler
extern Motor anglerMotor;
extern Motor liftMotor;

//Intake
extern MotorGroup intake;
