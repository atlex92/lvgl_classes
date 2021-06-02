#include "LVGLLabel.hpp"


LVGLLabel::LVGLLabel(const std::string& txt, LVGLBase* const parent)
    :   LVGLBase(lv_label_create(parent? parent->innerData() : lv_disp_get_scr_act(NULL), NULL), parent) {

    LVGL_DBG_PRINT("LVGLLabel #1 constructor");
    lv_label_set_text(_obj, txt.c_str());
    lv_label_set_long_mode(_obj, LV_LABEL_LONG_BREAK);

    // lv_obj_align_origo_y(_obj,  NULL, LV_ALIGN_IN_RIGHT_MID, 0);
    // lv_style_set_border_color(&_style, LV_STATE_DEFAULT, LV_COLOR_RED);
    // lv_style_set_border_width(&_style, LV_STATE_DEFAULT, 4);

    lv_obj_add_style(_obj, LV_OBJ_PART_MAIN, &_style);
}

LVGLLabel::LVGLLabel(const std::string& txt, lv_obj_t* const parent)
    :   LVGLBase(lv_label_create(parent, NULL), parent) {

    LVGL_DBG_PRINT("LVGLLabel #2 constructor");
    lv_label_set_text(_obj, txt.c_str());
    lv_label_set_long_mode(_obj, LV_LABEL_LONG_DOT);
}

LVGLLabel::LVGLLabel(lv_obj_t* const src, LVGLBase* const parent)
    : LVGLBase(src, parent) {
    LVGL_DBG_PRINT("LVGLLabel #3 constructor");
    lv_label_set_long_mode(_obj, LV_LABEL_LONG_DOT);
}