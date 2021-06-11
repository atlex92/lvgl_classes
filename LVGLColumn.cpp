#include "LVGLColumn.hpp"

LVGLColumn::LVGLColumn(LVGLBase*  parent)
    :   LVGLContainer(parent) {
    LVGL_DBG_PRINT("LVGLColumn #1 constructor");

    setClickable(false);
    setFit(LV_FIT_TIGHT);
    setLayout(LV_LAYOUT_COLUMN_MID);
    applyTheme();
}

LVGLColumn::LVGLColumn(lv_obj_t* const parent)
    :   LVGLContainer(parent){

    LVGL_DBG_PRINT("LVGLColumn #2 constructor");
    setClickable(false);
    setFit(LV_FIT_TIGHT);
    setLayout(LV_LAYOUT_ROW_MID);  
    applyTheme();
}

LVGLColumn::LVGLColumn(lv_obj_t* const src, LVGLBase* const parent)
    :   LVGLContainer(src, parent) {

    LVGL_DBG_PRINT("LVGLColumn #3 constructor");
}

