#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/285Z_Subsystems/pid.hpp"

const double GLOBAL_kP = 0.35;
const double GLOBAL_kI = 0;
const double GLOBAL_kD = 0;

void calibrate(){
  imuSensor.reset();
}

double deg = 0;
bool absolute = true;

void turnTask(void* param){
  //double deg: turn deg degrees (0, 360)
  //*Should be 360 counting down cc, 0 to up
  double sensorValue = imuSensor.get_heading();
  std::cout << sensorValue;

  double turnTarget = deg;
  // if (absolute) {
  //   //Keeps all angles between -180 and 180, turns to closest
  //   if (deg < 180) {
  //     turnTarget = deg;
  //   } else {
  //     turnTarget = deg - 360;
  //   }
  // } else if (!absolute) {
  //   turnTarget = sensorValue + deg;
  // }

  double error = turnTarget - sensorValue;
  double oldError = error;
  double sumError = 0;

  bool TURN_NOT_FINISH = true;
  while (TURN_NOT_FINISH) {
    sensorValue = imuSensor.get_heading();
    printf("IN PID LOOP");
    //PROPORTIONAL
    error = turnTarget - sensorValue;
    //DERIVATIVE
    double changeInError = error - oldError;
    //INTEGRAL
    if (abs(error) < 50) {
      sumError += error;
    } else {
      sumError = 0; //might be += 0?
    }

    //P, I, D
    double P = GLOBAL_kP * error;
    double I = GLOBAL_kI * sumError;
    double D = GLOBAL_kD * changeInError;

    double sum = P + I + D;

    driveL.moveVelocity(sum);
    driveR.moveVelocity(-sum);

    double errorThreshold = 5;
    double velocityThreshold = 5;

    TURN_NOT_FINISH = !((abs(error) < errorThreshold) && (abs(changeInError) < velocityThreshold));
    pros::delay(10);
  }
}

void turn(double degrees){
  // std::cout << "INTURN" << std::endl;
  // deg = degrees;
  // pros::Task turn_task(turnTask, (void*)"PROS", TASK_PRIORITY_DEFAULT,
  //                   TASK_STACK_DEPTH_DEFAULT, "Turn Task");

  //double deg: turn deg degrees (0, 360)
  //*Should be 360 counting down cc, 0 to up
  double sensorValue = imuSensor.get_heading();
  std::cout << sensorValue;

  double turnTarget = degrees;
  // if (absolute) {
  //   //Keeps all angles between -180 and 180, turns to closest
  //   if (deg < 180) {
  //     turnTarget = deg;
  //   } else {
  //     turnTarget = deg - 360;
  //   }
  // } else if (!absolute) {
  //   turnTarget = sensorValue + deg;
  // }

  double error = turnTarget - sensorValue;
  double oldError = error;
  double sumError = 0;

  bool TURN_NOT_FINISH = true;
  while (TURN_NOT_FINISH) {
    sensorValue = imuSensor.get_heading();
    printf("TARGET: %.4f\n", turnTarget);
    printf("IMU: %.4f\n", sensorValue);
    //PROPORTIONAL
    error = turnTarget - sensorValue;
    printf("ERROR: %.4f\n", error);
    //DERIVATIVE
    double changeInError = error - oldError;
    //INTEGRAL
    if (abs(error) < 50) {
      sumError += error;
    } else {
      sumError = 0; //might be += 0?
    }

    //P, I, D
    double P = GLOBAL_kP * error;
    double I = GLOBAL_kI * sumError;
    double D = GLOBAL_kD * changeInError;

    double sum = P + I + D;

    driveL.moveVelocity(sum);
    driveR.moveVelocity(-sum);

    double errorThreshold = 5;
    double velocityThreshold = 5;

    TURN_NOT_FINISH = !((abs(error) < errorThreshold) && (abs(changeInError) < velocityThreshold));
    pros::delay(10);
  }
}
