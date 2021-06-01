#include "LVGLLabel.hpp"


LVGLLabel::LVGLLabel(const std::string& txt, LVGLBase* const parent)
    :   LVGLBase(lv_label_create(lv_disp_get_scr_act(NULL), NULL), parent) {

    LVGL_DBG_PRINT("LVGLLabel #1 constructor");
    lv_label_set_text(_obj, txt.c_str());
}

LVGLLabel::LVGLLabel(const std::string& txt, lv_obj_t* const parent)
    :   LVGLBase(lv_label_create(parent, NULL), parent) {

    LVGL_DBG_PRINT("LVGLLabel #2 constructor");
    lv_label_set_text(_obj, txt.c_str());
}

LVGLLabel::LVGLLabel(lv_obj_t* const src, LVGLBase* const parent)
    : LVGLBase(src, parent) {
    LVGL_DBG_PRINT("LVGLLabel #3 constructor");
}



LVGLLabel::LVGLLabel(LVGLBase* const parent)
    :   LVGLLabel("text", parent) {
    LVGL_DBG_PRINT("LVGLLabel #4 constructor");
}