#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/285Z_Subsystems/pid.hpp"

const double GLOBAL_kP = 0.35;
const double GLOBAL_kI = 0.13;
const double GLOBAL_kD = 0.35;

void PID::calibrate(){
  imuSensor.reset();
}

void PID::turnClockwise(int deg){
  //int deg: turn deg degrees
  //*Should be 360 counting down cc, 0 to up
  imuSensor.reset();
  double sensorValue = imuSensor.get_heading();
  std::cout << sensorValue;

  double turnTarget = deg;
  double error = turnTarget - sensorValue;
  double oldError = error;
  double sumError = 0;

  bool TURN_NOT_FINISH = true;
  while (TURN_NOT_FINISH) {
    sensorValue = imuSensor.get_heading();
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

    double errorThreshold = 2.5;
    double velocityThreshold = 2.5;

    TURN_NOT_FINISH = !((abs(error) < errorThreshold) && (abs(changeInError) < velocityThreshold));
  }
}
