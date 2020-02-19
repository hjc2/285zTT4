#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"

//*************BLUE AUTONOMOUS PROGRAMS********************//

//************************   BLUE: FIVE CUBES   ****************************//
void sgSixBlue(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift lift;
  lift.deploy();

  intake.moveVelocity(200);
  //************** INIT PATHS *******************//
  move(slow, 3.25_ft, fwd);
  turn(22);

  move(fast, 0.85_ft, fwd);
  move(fast, 2_ft, bwd);
  turn(230);

  move(slow, 1.5_ft, fwd);

  intake.moveVelocity(0);

  autoStackDeploy();

  move(medium, 1_ft, bwd);
}
//************************   BLUE: SHORT GOAL, NINE CUBES   ****************************//
void sgNineBlue(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift lift;

  lift.deploy();

  intake.moveVelocity(200);

  move(fast, 3.20_ft, fwd);
  turn(30);

  move(fast, 3.20_ft, bwd);
  turn(0);

  move(fast, 3.1_ft, fwd);

  move(fast, 2_ft, bwd);
  intake.moveVelocity(0);
  turn(230);

  move(slow, 1.3_ft, fwd);

  autoStackDeploy();

  move(medium, 1_ft, bwd);
}


//************************   BLUE: LONG GOAL   ****************************//
void lgBlue(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift lift;
  lift.deploy();

  intake.moveVelocity(200);
  move(fast, 1_ft, fwd);
  turn(30);

  move(fast, 2_ft, fwd);
  move(fast, 1.7_ft, bwd);
  turn(95);

  move(fast, 1.75_ft, fwd);
  move(fast, 2_ft, bwd);
  turn(220);

  move(slow, 0.5_ft, fwd);

  autoStackDeploy();

  move(fast, 0.5_ft, bwd);

}
