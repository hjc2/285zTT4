#include "285z/initRobot.hpp"
#include "285z/functions.hpp"
#include "285Z_Subsystems/tray.hpp"
#include "285Z_Subsystems/lift.hpp"
#include "285Z_Subsystems/pid.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/pros/llemu.hpp"
//
 /** Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.

 */

//**************** INITIALIZE ALL CHASSIS FOR AUTON ********************//
 auto chassisauto = okapi::ChassisControllerBuilder()
     .withMotors(driveL, driveR) // left motor is 1, right motor is 2 (reversed)
     .withGains(
        {0.001, 0.001, 0.00009}, // Distance controller gains 0.005, 0, 0.001
        {0.00075, 0.001, 0.00009}, // Turn controller gains
        {0.001, 0.001, 0.0001}  // Angle controller gains (helps drive straight)
      )
     .withDimensions(AbstractMotor::gearset::green, scales)
     .withOdometry() // use the same scales as the chassis (above)
     .withMaxVelocity(200)
     .buildOdometry(); // build an odometry chassis

 auto motion =
   ChassisControllerBuilder()
     .withMotors({frontLeftPort,backLeftPort}, {frontRightPort,backRightPort})
     .withDimensions(AbstractMotor::gearset::green, scales)
     .withMaxVelocity(200)
     .build();

 auto fastauto =
   AsyncMotionProfileControllerBuilder()
     .withLimits({
       1.1,  //max velocity
       2.5,  //max acceleration
       10.0  //max jerk
     })
     .withOutput(motion)
     .buildMotionProfileController();
 auto slowauto =
   AsyncMotionProfileControllerBuilder()
     .withLimits({
       0.325,  //max velocity
       2.0,  //max acceleration
       10.0  //max jerk
     })
     .withOutput(motion)
     .buildMotionProfileController();
void initialize() {
  //FOR NOW, WILL NOT DO THIS UNTIL SURE IT WORKS REGULARLY
  // slowauto->generatePath({
  //   {0_ft,0_ft,0_deg},
  //   {3.5_ft,0_ft,0_deg}},
  //   "A"
  // );
  // fastauto->generatePath({
  //   {0_ft,0_ft,0_deg},
  //   {4.5_ft,0_ft,0_deg}},
  //   "B"
  // );
  // fastauto->generatePath({
  //   {0_ft,0_ft,0_deg},
  //   {4_ft,2_ft,0_deg}},
  //   "S"
  // );
  // fastauto->generatePath({
  //   {0_ft,0_ft,0_deg},
  //   {1.5_ft,0_ft,0_deg}},
  //   "C"
  // );
  imuSensor.reset();

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
-+
 */
void disabled() {}

void competition_initialize() {
  calibrate(); //Calibrate IMU Sensor
  while(true) {
    initScreen();
    pros::delay(10);
  }
}

void autonomous() {
  //TEST CASE
  // selectAuton(chassisauto, slowauto, fastauto);
  robotDeploy();
  redFiveCube(chassisauto, slowauto, fastauto);
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
  liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  while(true){
    displayAuton();
    // TANK DRIVE CODE //
    model->tank(controller.getAnalog(okapi::ControllerAnalog::leftY),
              controller.getAnalog(okapi::ControllerAnalog::rightY));

    // INTAKE TOGGLE CODE  //
    toggleIntake();
    intakeRev();

    // ANGLER TOGGLE CODE
    anglerToggle();
    stopPID();
    // MACRO CODE
    stackDeploy();

    pros::delay(10);
  }
}
