#pragma once
#include "main.h"

extern bool anglerDisabled;
//Controller
extern Controller controller;
//extern std::shared_ptr<okapi::ChassisModel> model;
//GUI
int GUI();
void flat();

//Controller Buttons
extern ControllerButton intakeButton;
extern ControllerButton trayButton;
extern ControllerButton stopPIDButton;
extern ControllerButton outtakeButton;

extern ControllerButton liftUpButton;
extern ControllerButton liftDownButton;
extern ControllerButton liftToggleButton;

extern ControllerButton anglerUpButton;
extern ControllerButton anglerDownButton;

//  SENSORS  //
extern Potentiometer autonPot;
//  MOTORS  //

//ports
extern int anglerPort;
extern int liftPort;

//drive motor points
extern int frontLeftPort;
extern int backLeftPort;
extern int frontRightPort;
extern int backRightPort;
//intake motor ports
extern int intakeRightPort;
extern int intakeLeftPort;

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

//Chassis controllers
extern AsyncMotionProfileControllerBuilder fast;
extern AsyncMotionProfileControllerBuilder slow;

extern ChassisControllerBuilder aut;
extern ChassisControllerBuilder chassis;
