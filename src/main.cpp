#include "main.h"

 //button definitions
 okapi::ControllerButton intakeButton = okapi::ControllerDigital::R2;
 okapi::ControllerButton trayUp = okapi::ControllerDigital::L1;
 okapi::ControllerButton outtakeButton = okapi::ControllerDigital::R1;
 okapi::ControllerButton liftUp = okapi::ControllerDigital::A;
 okapi::ControllerButton LiftDown = okapi::ControllerDigital::B;

 	//motor port definitions

 	//angler motor port
 	int anglerPort = 15;

 	//drive motor points
 	int frontLeftPort = 11;
 	int backLeftPort = 12;
 	int frontRightPort = -13;
 	int backRightPort = -14;

 	//intake motor ports
 	int intakeRightPort = 16;
 	int intakeLeftPort = -19;

 	//lift motor port
 	int liftPort = 20;


 	//motors for the drivetrain
 	//could be incorrect
 	pros::Motor frontLeftMotor(frontLeftPort);
 	pros::Motor backLeftMotor(backLeftPort);
 	pros::Motor frontRightMotor(frontRightPort);
 	pros::Motor backRightMotor(backRightPort);

 	//motors for the intake. (looking from the front)
 	pros::Motor intakeRightMotor(intakeRightPort);
 	pros::Motor intakeLeftMotor(intakeLeftPort);

 	//angler motor is not sure
 	pros::Motor anglerMotor(anglerPort);
 	pros::Motor liftMotor(liftPort);

  MotorGroup intake({intakeRightPort, intakeLeftPort});
 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 okapi::ChassisScales scales
 {
 	{4.125_in, 9.75_in},
 	imev5GreenTPR
 };

 auto chassis = okapi::ChassisControllerBuilder()
                   .withMotors({ 11, 12 }, { -13, -14 })
                   .withGearset(okapi::AbstractMotor::gearset::green)
                   .withDimensions(scales)
                   .withMaxVelocity(200)
                   .withOdometry(okapi::StateMode::FRAME_TRANSFORMATION, 0_mm, 0_deg, 0.00001_mps)
                   .buildOdometry();
 std::shared_ptr<okapi::ChassisModel> model = std::dynamic_pointer_cast<okapi::ChassisModel>(chassis->getModel());



 /** Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

}
