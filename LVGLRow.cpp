#include "LVGLRow.hpp"

LVGLRow::LVGLRow(LVGLBase*  parent)
    :   LVGLBase(lv_cont_create(parent->innerData(), NULL)) {
    LVGL_DBG_PRINT("LVGLRow #1 constructor");

    lv_obj_set_click(_obj, false);
    lv_obj_set_auto_realign(_obj, true);
    lv_obj_align_origo(_obj, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_cont_set_fit(_obj, LV_FIT_TIGHT);
    lv_cont_set_layout(_obj, LV_LAYOUT_ROW_MID);
    lv_obj_set_click(_obj, false);
}

LVGLRow::LVGLRow(lv_obj_t* const parent)
    :   LVGLBase(lv_cont_create(parent, NULL)){

    LVGL_DBG_PRINT("LVGLRow #2 constructor");
    
    lv_obj_set_click(_obj, false);
    lv_obj_set_auto_realign(_obj, true);
    lv_obj_align_origo(_obj, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_cont_set_fit(_obj, LV_FIT_TIGHT);
    lv_cont_set_layout(_obj, LV_LAYOUT_ROW_MID);
    lv_obj_set_click(_obj, false);
}

LVGLRow::LVGLRow(lv_obj_t* const src, LVGLBase* const parent)
    :   LVGLBase(src, parent) {

    LVGL_DBG_PRINT("LVGLRow #3 constructor");
}

void LVGLRow::addObject(LVGLBase* const obj) {
    obj->setParent(this);
}