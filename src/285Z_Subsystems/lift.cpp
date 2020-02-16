#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285Z_Subsystems/tray.hpp"

const int NUM_HEIGHTS = 3;
const int height0 = 5;
const int height1 = 1800;
const int height2 = 2300;

const int heights[NUM_HEIGHTS] = {height0, height1, height2};
double liftkP = 0.004;
double liftkI = 0.000001;
double liftkD = 0.00009;
// Old vals kp = 0.001, kI = 0.0001, kd = 0.0001

int heightNow = 0;

auto liftController = AsyncPosControllerBuilder().withMotor(liftPort)
                        .build();

void Lift::liftToggle(Tray angler){

  if (liftUpButton.changedToPressed() && heightNow < NUM_HEIGHTS - 1) {
      // If the goal height is not at maximum and the up button is pressed, increase the setpoint
      heightNow++;
      liftController->setTarget(heights[heightNow]);

    } else if (liftDownButton.changedToPressed() && heightNow > 0) {
      heightNow--;
      liftController->setTarget(heights[heightNow]);
    }

}

void Lift::deploy(){
  intake.moveVelocity(-60);
  liftController -> setTarget(1000);
  liftController-> waitUntilSettled();
  pros::delay(600);

  intake.moveVelocity(-100);
  pros::delay(200);

  intake.moveVelocity(-30);
  liftController -> setTarget(100);
  intake.moveVelocity(-10);
  pros::delay(200);

  intake.moveVelocity(-30);
  liftController -> setTarget(800);
  pros::delay(400);

  intake.moveVelocity(-100);
  pros::delay(50);

  liftController -> setTarget(100);
  liftController -> waitUntilSettled();
}

void Lift::move(int vel){
  liftMotor.moveVelocity(-vel);
  liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
}
