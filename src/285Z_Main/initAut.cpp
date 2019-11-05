#include "../include/285z/initrobot.hpp"

//PID Controller
const double liftkP = 0.001;
const double liftkI = 0.0001;
const double liftkD = 0.0001;

//TODO: WILL HAVE TO MODIFY WHEN WE HAVE TWO MOTORS FOR ANGLER
const int ANGLER_MOTOR_PORT = 15;





//auto anglerControllerL = AsyncPosPIDController(
//auto anglerControllerL = AsyncControllerFactory::posPID(ANGLER_MOTOR_PORT_L, liftkP, liftkI, liftkD);
//auto anglerControllerR = AsyncControllerFactory::posPID(ANGLER_MOTOR_PORT_R, liftkP, liftkI, liftkD);
