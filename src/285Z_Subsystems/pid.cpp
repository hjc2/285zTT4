#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/285Z_Subsystems/pid.hpp"

const double GLOBAL_kP = 1.05;
const double GLOBAL_kI = 0.00001;
const double GLOBAL_kD = 0.4;

void calibrate(){
  imuSensor.reset();
}

double deg = 0;
bool absolute = true;

void turnTest(double degrees){

  double thetaI = imuSensor.get_heading();
  double thetaF = degrees;

  double sensorValue = thetaI;
  double turnTarget = thetaF;

  double deltaI = abs(thetaF - thetaI);

  if (deltaI > 180){
    if (thetaF > 180) {
      turnTarget = thetaF - 360;
    } else {
      turnTarget = thetaF;
    }

    if (thetaI > 180) {
      sensorValue = thetaI - 360;
    } else {
      sensorValue = thetaI;
    }
  }

  double error = turnTarget - sensorValue;
  double oldError = error;
  double sumError = 0;

  bool TURN_NOT_FINISH = true;
  while (TURN_NOT_FINISH) {
    sensorValue = imuSensor.get_heading();
    printf("TARGET: %.4f\n", turnTarget);
    printf("IMU: %.4f\n", sensorValue);

    if (deltaI > 180){
      if (sensorValue > 180) {
        sensorValue = sensorValue - 360;
      }
    }

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

    oldError = error;
    double errorThreshold = 5;
    double velocityThreshold = 5;

    TURN_NOT_FINISH = !((abs(error) < errorThreshold) && (abs(changeInError) < velocityThreshold));
  }
  driveL.moveVelocity(0);
  driveR.moveVelocity(0);
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
