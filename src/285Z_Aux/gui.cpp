#include "../include/285z/initRobot.hpp"

int GUI() {
    flat();
    Brain.Screen.setFont(vex::fontType::prop40);

    int autonState = 10;
    while(true) {
        double potVal = Pot.value(vex::percentUnits::pct);
        if (potVal <= 10){
            if (autonState != 0) {
                flat();
                Brain.Screen.printAt(250,100,true,"RED FRONT      ");
                Brain.Screen.drawCircle(40,80,15,vex::color::green);
            }
            autonState = 0;
        } else if (potVal > 10 && potVal <= 20){
            if (autonState != 1) {
                flat();
                Brain.Screen.printAt(250,100,true,"RED BACK        ");
                Brain.Screen.drawCircle(40,160,15,vex::color::green);
            }
            autonState = 1;
        } else if (potVal > 20 && potVal <= 30){
            if (autonState != 2) {
                flat();
                Brain.Screen.printAt(250,100,true,"BLUE FRONT       ");
                Brain.Screen.drawCircle(200,80,15,vex::color::green);
            }
            autonState = 2;
        } else if (potVal > 30 && potVal < 40){
            if (autonState != 3) {
                flat();
                Brain.Screen.printAt(250,100,true,"BLUE BACK       ");
                Brain.Screen.drawCircle(200,160,15,vex::color::green);
            }
            autonState = 3;
        } else {
            if (autonState != 4) {
                flat();
                Brain.Screen.printAt(250,100,true,"SKILLS          ");
                Brain.Screen.drawCircle(40,80,15,vex::color::white);
            }
            autonState = 4;
        }
    }
    return(0);
}
