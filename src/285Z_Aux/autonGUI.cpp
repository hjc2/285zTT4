#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/pros/llemu.hpp"

void lcdSelect(){
  pros::lcd::print(0, "Buttons Bitmap: %d\n", pros::lcd::read_buttons());
}

void lcdRun(){
  while(1){
    lcdSelect();
  }
}

void lcdStart(){
  lcdSelect();
}
