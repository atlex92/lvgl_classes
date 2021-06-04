#include "LVGLColumn.hpp"

LVGLColumn::LVGLColumn(LVGLBase*  parent)
    :   LVGLContainer(parent) {
    LVGL_DBG_PRINT("LVGLColumn #1 constructor");

    setClickable(false);
    setFit(LV_FIT_TIGHT);
    setLayout(LV_LAYOUT_COLUMN_MID);

    // lv_obj_set_click(_obj, false);
    // lv_obj_set_fit
    // lv_obj_set_auto_realign(_obj, true);
    // lv_obj_align_origo_x(_obj, NULL, LV_ALIGN_IN_TOP_LEFT, 0);
    // lv_obj_align_origo_y(_obj, NULL, LV_ALIGN_IN_TOP_LEFT, 0);
    // lv_obj_align

    // lv_obj_align_origo(_obj, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);
    // lv_cont_set_fit(_obj, LV_FIT_TIGHT);
    // lv_cont_set_layout(_obj, LV_LAYOUT_COLUMN_LEFT);
    // // lv_obj_set_style_local_pad_all(_obj, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, 0);
}

LVGLColumn::LVGLColumn(lv_obj_t* const parent)
    :   LVGLContainer(parent){

    LVGL_DBG_PRINT("LVGLColumn #2 constructor");
    setClickable(false);
    setFit(LV_FIT_TIGHT);
    setLayout(LV_LAYOUT_ROW_MID);  
    // lv_obj_set_click(_obj, false);
    // lv_obj_set_auto_realign(_obj, true);
    // lv_obj_align_origo(_obj, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);
    // lv_cont_set_fit(_obj, LV_FIT_TIGHT);
    // lv_cont_set_layout(_obj, LV_LAYOUT_COLUMN_LEFT);
    // lv_obj_set_click(_obj, false);
    // lv_obj_set_style_local_pad_all(_obj, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, 0);
    // lv_obj_set_style_local_margin_all(_obj, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, 0);
}

LVGLColumn::LVGLColumn(lv_obj_t* const src, LVGLBase* const parent)
    :   LVGLContainer(src, parent) {

    LVGL_DBG_PRINT("LVGLColumn #3 constructor");
}

