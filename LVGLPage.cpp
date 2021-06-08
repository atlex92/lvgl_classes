#include "LVGLPage.hpp"

LVGLPage::LVGLPage(LVGLBase* const parent)
    :   LVGLBase(lv_page_create(
                    parent ? parent->innerData() : lv_disp_get_scr_act(NULL),
                    NULL),
                parent) {

    LVGL_DBG_PRINT("LVGLPage #1 constructor ");
}

LVGLPage::LVGLPage(lv_obj_t* const parent)
    :   LVGLBase(lv_page_create(parent, NULL)) {

    LVGL_DBG_PRINT("LVGLPage #2 constructor ");
    lv_page_set_scrollbar_mode(_obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_auto_realign(_obj, true);
    lv_obj_align_origo(_obj, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_cont_set_fit(_obj, LV_FIT_TIGHT);
}

LVGLPage::LVGLPage(lv_obj_t* const src, LVGLBase* const parent)
    :   LVGLBase(src, parent) {
    LVGL_DBG_PRINT("LVGLPage #3 constructor ");
    // lv_obj_set_auto_realign(_obj, true);

    // lv_page_set_scrollbar_mode(_obj, LV_SCROLLBAR_MODE_OFF);
    // lv_obj_set_auto_realign(_obj, true);
    // lv_obj_align_origo(_obj, NULL, LV_ALIGN_CENTER, 0, 0);
    // lv_cont_set_fit(_obj, LV_FIT_TIGHT);
}

void LVGLPage::setScrollBarMode(const lv_scrollbar_mode_t mode) {
    lv_page_set_scrlbar_mode(_obj, mode);    
}

void LVGLPage::setScrollPropogation(const bool val) { 
    lv_page_set_scroll_propagation(_obj, val);
}