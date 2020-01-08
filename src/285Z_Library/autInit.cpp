#include "../include/285z/initRobot.hpp"


auto aut =
  ChassisControllerBuilder()
    .withMotors({1, 2}, {-3, -4})
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.5_in}, imev5GreenTPR})
    .build();

auto fast =
  AsyncMotionProfileControllerBuilder()
    .withLimits({1.0, 2.0, 10.0})
    .withOutput(aut)
    .buildMotionProfileController();

auto slow =
  AsyncMotionProfileControllerBuilder()
    .withLimits({1.0, 2.0, 10.0})
    .withOutput(aut)
    .buildMotionProfileController();
