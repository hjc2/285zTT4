#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"

void autoStackDeploy() {
  Tray angler;
  intake.moveRelative(-600, 110);
  intake.setBrakeMode(AbstractMotor::brakeMode::coast);
  angler.moveToUp(false);
  pros::Task::delay(3000);
  intake.moveRelative(-75, 110);
  //fast->setTarget("C",bwd); //drives away
}

//****************** ONE CUBE ***********************************//
void skills(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){

}

//****************** ONE CUBE ***********************************//
void one(std::shared_ptr<okapi::OdomChassisController> chassis, std::shared_ptr<okapi::AsyncMotionProfileController> slow,std::shared_ptr<okapi::AsyncMotionProfileController> fast){

}
