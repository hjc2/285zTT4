#include "../include/285z/initRobot.hpp"

//POTENTIOMETER AUTON SELECTOR
char potentiometerPort = 'A';
Potentiometer autonPot(potentiometerPort);

char cubeSensorPort = 'B';
pros::ADILineSensor cubeSensor(cubeSensorPort);

const std::uint8_t imuPort = 21;
pros::Imu imuSensor(imuPort);
