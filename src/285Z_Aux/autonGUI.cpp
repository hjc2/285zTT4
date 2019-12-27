#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/pros/llemu.hpp"

std::string counter = "myString";

void lcdSelect(){
  pros::lcd::set_text(1, "hello world");

}

void lcdRun(){
  while(1){
    lcdSelect();
    pros::delay(10);
  }
}

void lcdStart(){
  pros::lcd::initialize();
  lcdRun();
}
