#pragma once

#include "../include/285z/initRobot.hpp"

extern lv_obj_t * myButton;
extern lv_obj_t * myButtonLabel;
extern lv_obj_t * myLabel;

extern lv_style_t myButtonStyleREL; //relesed style
extern lv_style_t myButtonStylePR; //pressed style

static lv_res_t btn_click_action(lv_obj_t * btn);

lv_obj_t * createBtn(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height,
    int id, const char * title);

lv_style_t * createBtnStyle(lv_style_t * copy, lv_color_t rel, lv_color_t pr,
    lv_color_t tglRel, lv_color_t tglPr, lv_color_t tglBorder, lv_color_t textColor, lv_obj_t * btn);

void lv_aut_display(char*);

void setBtnStyle(lv_style_t * btnStyle, lv_obj_t * btn);

void btnSetToggled(lv_obj_t * btn, bool toggled);

void initScreen();

void testScreen();
