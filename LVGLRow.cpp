#include "LVGLRow.hpp"

LVGLRow::LVGLRow(LVGLBase*  parent)
    :   LVGLContainer(parent) {

    LVGL_DBG_PRINT("LVGLRow #1 constructor");
    setClickable(false);
    setFit(LV_FIT_TIGHT);
    setLayout(LV_LAYOUT_ROW_MID);
    applyTheme();
}

LVGLRow::LVGLRow(lv_obj_t* const parent)
    :   LVGLContainer(parent) {

    LVGL_DBG_PRINT("LVGLRow #2 constructor");
    setClickable(false);
    setFit(LV_FIT_TIGHT);
    setLayout(LV_LAYOUT_ROW_MID);  
    applyTheme();
}

LVGLRow::LVGLRow(lv_obj_t* const src, LVGLBase* const parent)
    :   LVGLContainer(src, parent) {

    LVGL_DBG_PRINT("LVGLRow #3 constructor");
    applyTheme();
}