#include "LVGLTabView.hpp"

LVGLTabView::LVGLTabView(LVGLBase* const parent)
    :   LVGLBase(lv_tabview_create(parent? parent->innerData() : lv_disp_get_scr_act(NULL), NULL),
        parent) {

    LVGL_DBG_PRINT("LVGLTabView #1 constructor ");
}

LVGLTabView::LVGLTabView(lv_obj_t* const parent)
    :   LVGLBase(lv_tabview_create(parent, NULL)) {
    LVGL_DBG_PRINT("LVGLTabView #2 constructor ");
}

LVGLPage* LVGLTabView::addTab(const std::string& title) {
    return new LVGLPage(lv_tabview_add_tab(_obj, title.c_str()), this);
}

void LVGLTabView::setNavigationBarsPosition(const uint8_t position) {
    lv_tabview_set_btns_pos(_obj, position);
}

void LVGLTabView::setAnimationTime(const size_t ms) {
    lv_tabview_set_anim_time(_obj, ms);
}