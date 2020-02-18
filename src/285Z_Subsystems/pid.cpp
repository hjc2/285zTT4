#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/285Z_Subsystems/pid.hpp"

const double GLOBAL_kP = 0.95;
const double GLOBAL_kI = 0;
const double GLOBAL_kD = 0.2;

void calibrate(){
  imuSensor.reset();
}

double deg = 0;
bool absolute = true;

void turn(double degrees){
  driveL.setBrakeMode(AbstractMotor::brakeMode::brake);
  driveR.setBrakeMode(AbstractMotor::brakeMode::brake);
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
    double errorThreshold = 2.5;
    double velocityThreshold = 2.5;

    TURN_NOT_FINISH = !((abs(error) < errorThreshold) && (abs(changeInError) < velocityThreshold));
  }
  driveL.moveVelocity(0);
  driveR.moveVelocity(0);
}
