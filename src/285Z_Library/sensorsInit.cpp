#include "../include/285z/initRobot.hpp"



//POTENTIOMETER AUTON SELECTOR
 char potentiometerPort = 'A';
 Potentiometer autonPot(potentiometerPort);

 char cubeSensorPort = 'B';
 pros::ADILineSensor cubeSensor(cubeSensorPort);
