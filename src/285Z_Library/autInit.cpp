#include "../include/285z/initRobot.hpp"


auto chassis =
  ChassisControllerBuilder()
    .withMotors({1, 2}, {-3, -4})
    .build();

auto fast =
  AsyncMotionProfileControllerBuilder()
    .withLimits({1.0, 2.0, 10.0})
    .withOutput(chassis)
    .buildMotionProfileController();

auto slow =
  AsyncMotionProfileControllerBuilder()
    .withLimits({1.0, 3.0, 10.0})
    .withOutput(chassis)
    .buildMotionProfileController();
