#include "LVGLButton.hpp"
#include "assert.h"

LVGLButton::LVGLButton(const std::string& txt, lv_obj_t* const parent)
    :   LVGLBase(lv_btn_create(parent, NULL), parent),
        _lbl{new LVGLLabel(txt, this)} {
    assert(_obj);
    assert(_lbl);
    LVGL_DBG_PRINT("LVGLButton #1 constructor");
}

LVGLButton::LVGLButton(const std::string& txt, LVGLBase* const parent)
    :   LVGLBase(lv_btn_create(parent? parent->innerData() : lv_disp_get_scr_act(NULL), NULL), parent),
        _lbl{new LVGLLabel(txt, this)} {
    assert(_obj);
    assert(_lbl);
    LVGL_DBG_PRINT("LVGLButton #2 constructor");
}

LVGLButton::LVGLButton(lv_obj_t* const src, LVGLBase* const parent)
    : LVGLBase(src, parent) {
    LVGL_DBG_PRINT("LVGLButton #4 constructor");
}

void LVGLButton::setSize(const size_t w, const size_t h) {

    lv_btn_set_fit(_obj, LV_FIT_NONE);
    lv_obj_set_auto_realign(_obj, false);
    LVGLBase::setSize(w, h);
}

void LVGLButton::disable() {
    lv_btn_set_state(_obj, LV_BTN_STATE_DISABLED);
}

void LVGLButton::enable() {
    lv_btn_set_state(_obj, LV_BTN_STATE_RELEASED);
}