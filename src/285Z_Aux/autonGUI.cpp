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
/*
void lcdStart(){
  pros::lcd::initialize();
}
void on_center_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
    pros::lcd::set_text(2, "I was pressed!");
  } else {
    pros::lcd::clear_line(2);
  }
}

void initialize() {
  pros::lcd::initialize();
  pros::lcd::register_btn2_cb(on_center_button);
}
*/
