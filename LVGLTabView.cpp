#include "LVGLTabView.hpp"

LVGLTabView::LVGLTabView(LVGLBase* const parent)
    :   LVGLBase(lv_tabview_create(parent? parent->innerData() : lv_disp_get_scr_act(NULL), NULL),
        parent) {

    applyTheme();
}

LVGLTabView::LVGLTabView(lv_obj_t* const parent)
    :   LVGLBase(lv_tabview_create(parent, NULL)) {
    applyTheme();
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

void LVGLTabView::setIndicatorWidth(const size_t w) {
    lv_obj_set_style_local_size(innerData(), LV_TABVIEW_PART_INDIC, LV_STATE_DEFAULT, w);
}