#include "LVGLTabView.hpp"

LVGLTabView::LVGLTabView(LVGLBase* const parent)
    :   LVGLBase(lv_tabview_create(parent? parent->innerData() : lv_disp_get_scr_act(NULL), NULL),
        parent) {

    LVGL_DBG_PRINT("LVGLTabView #1 constructor ");
    // lv_obj_set_style_local_bg_color(_obj, LV_TABVIEW_PART_TAB_BG, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    // lv_obj_set_style_local_bg_color(_obj, LV_TABVIEW_PART_BG, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    // lv_obj_set_style_local_bg_color(_obj, LV_TABVIEW_PART_INDIC, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    // lv_obj_set_style_local_text_color(_obj, LV_TABVIEW_PART_TAB_BTN, LV_STATE_DEFAULT, LV_COLOR_GRAY);
    // lv_obj_set_style_local_text_color(_obj, LV_TABVIEW_PART_TAB_BTN, LV_STATE_CHECKED, LV_COLOR_WHITE);
    // lv_obj_set_style_local_size(_obj, LV_TABVIEW_PART_INDIC, LV_STATE_DEFAULT, 2);
}

LVGLTabView::LVGLTabView(lv_obj_t* const parent)
    :   LVGLBase(lv_tabview_create(parent, NULL)) {
    LVGL_DBG_PRINT("LVGLTabView #2 constructor ");
}

LVGLPage* LVGLTabView::addTab(const std::string& title) {
    return new LVGLPage(lv_tabview_add_tab(_obj, title.c_str()));
}

void LVGLTabView::setNavigationBarsPosition(const uint8_t position) {
    lv_tabview_set_btns_pos(_obj, position);
}

void LVGLTabView::setAnimationTime(const size_t ms) {
    lv_tabview_set_anim_time(_obj, ms);
}