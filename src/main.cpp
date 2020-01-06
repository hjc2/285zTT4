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
void initialize() {}
void disabled() {}
void competition_initialize() {}
void autonomous() {
  std::shared_ptr<okapi::OdomChassisController> chassis = okapi::ChassisControllerBuilder()
                    .withMotors({ frontLeftMotor, backLeftMotor }, { frontRightMotor, backRightMotor }) //the motors it uses
                    .withGearset(okapi::AbstractMotor::gearset::green) //we are using the green gearset
                    .withDimensions(scales)
                    .withMaxVelocity(120) //is not allowed to go faster than 120
                    .withGains(
                 {0.001, 0.001, 0.00009}, // Distance controller gains 0.005, 0, 0.001
                 {0.001, 0.001, 0.00001}, // Turn controller gains
                 {0.001, 0.001, 0.0001}  // Angle controller gains (helps drive straight)
             )
                    .withOdometry(okapi::StateMode::FRAME_TRANSFORMATION, 0_mm, 0_deg, 0.00001_mps)
                    .buildOdometry();
  std::shared_ptr<okapi::ChassisModel> model = std::dynamic_pointer_cast<okapi::ChassisModel>(chassis->getModel());

}


void opcontrol() {
  std::shared_ptr<okapi::OdomChassisController> chassis = okapi::ChassisControllerBuilder()
										.withMotors({ frontLeftMotor, backLeftMotor }, { frontRightMotor, backRightMotor })
										.withGearset(okapi::AbstractMotor::gearset::green)
										.withDimensions(scales)
										.withOdometry(okapi::StateMode::FRAME_TRANSFORMATION, 0_mm, 0_deg, 0.0001_mps)
										.buildOdometry();
	std::shared_ptr<okapi::ChassisModel> model = std::dynamic_pointer_cast<okapi::ChassisModel>(chassis->getModel());

  lcdStart();
  while(true){

    //GUI CODE

    pros::lcd::register_btn0_cb(on_center_button);

    //GUI
    // TANK DRIVE CODE //
    model->tank(controller.getAnalog(okapi::ControllerAnalog::leftY),
          controller.getAnalog(okapi::ControllerAnalog::rightY));


    //  INTAKE TOGGLE CODE  //

    //toggles the intake 600/0
    toggleIntake();
    //push to intake -150/0
    intakeRev();

  /* ANGLER TOGGLE CODE
  toggles the anglers position using the PID */
    anglerToggle();
    //stops the pid from running
    stopPID();


    //  LIFT  //
    liftToggle();

    //liftPID();
    pros::delay(10);
  }
}
