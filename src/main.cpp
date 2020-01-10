#include "285z/initRobot.hpp"
#include "285z/functions.hpp"
#include "285Z_Subsystems/tray.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/pros/llemu.hpp"

//
 /** Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  profileControllers();
}

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
void competition_initialize() {
  while(true) {
  initScreen();
  pros::delay(10);
  }
}


void autonomous() {
  auto chassis = okapi::ChassisControllerBuilder()
      .withMotors(driveL, driveR) // left motor is 1, right motor is 2 (reversed)
      .withGains(
         {0.001, 0.001, 0.00009}, // Distance controller gains 0.005, 0, 0.001
         {0.001, 0.001, 0.00001}, // Turn controller gains
         {0.001, 0.001, 0.0001}  // Angle controller gains (helps drive straight)
       )
      .withDimensions(AbstractMotor::gearset::green, scales)
      .withOdometry() // use the same scales as the chassis (above)
      .withMaxVelocity(200)
      .buildOdometry(); // build an odometry chassis

  robotDeploy();
  selectAuton(chassis);
  }


void opcontrol() {

// CHASSIS CONTROLLER
  auto chassis = okapi::ChassisControllerBuilder()
      .withMotors(driveL, driveR)
      .withDimensions(AbstractMotor::gearset::green, scales)
      .withMaxVelocity(200)
      .build(); // build an odometry chassis
      std::shared_ptr<okapi::ChassisModel> model = std::dynamic_pointer_cast<okapi::ChassisModel>(chassis->getModel());

// LIFT TASK
  pros::Task intakeThread(liftTask, (void*)"PROS", TASK_PRIORITY_DEFAULT,
                    TASK_STACK_DEPTH_DEFAULT, "Lift Task");

  while(true){

    // TANK DRIVE CODE //
    model->tank(controller.getAnalog(okapi::ControllerAnalog::leftY),
              controller.getAnalog(okapi::ControllerAnalog::rightY));

    // INTAKE TOGGLE CODE  //
    toggleIntake();
    intakeRev();

  // ANGLER TOGGLE CODE
    anglerToggle();
    stopPID();

    pros::delay(10);
  }
}
