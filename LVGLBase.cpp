#include "LVGLBase.hpp"

#include <iostream>
using namespace std;

AbstractTheme* LVGLBase::_theme {nullptr};

void LVGLBase::setTheme(AbstractTheme* const theme) {
    _theme = theme;
}

void LVGLBase::eventHandler(lv_obj_t * obj, lv_event_t event) {

    // LVGL_DBG_PRINT("Event handler");
    LVGLBase* base = (LVGLBase*)lv_obj_get_user_data(obj);

    if (!base) {
        LVGL_DBG_PRINT("Base object not found");
        return;
    }
    if(base->_eventCallback) {
        base->_eventCallback(event);
    }
    else {
        // LVGL_DBG_PRINT("callback not found");
    }
}

LVGLBase::LVGLBase(lv_obj_t* const lvglObj, LVGLBase* const parent)
    :   _parent{parent},
        _obj{lvglObj},
        _eventCallback{nullptr} {
    
    LVGL_DBG_PRINT("LVGLBase #1 constructor");
    lv_obj_set_user_data(_obj, this);
    lv_obj_set_event_cb(_obj, eventHandler);
}

LVGLBase::LVGLBase(lv_obj_t* const lvglObj, lv_obj_t* const parent)
    :   _parent{NULL},
        _obj{lvglObj},
        _eventCallback{nullptr} {

    LVGL_DBG_PRINT("LVGLBase #2 constructor");
    lv_obj_set_user_data(_obj, this);
    lv_obj_set_event_cb(_obj, eventHandler);
}

void LVGLBase::hide() {
    lv_obj_set_hidden(_obj, true);
}

void LVGLBase::applyTheme() {

    if (_theme) {
        LVGL_DBG_PRINT("applying theme for object");
        // LVGL_DBG_PRINT((size_t)type());
        switch (type()) {
            case eLvglType::LVGL_CLASS_BUTTON:
                resetStyle(LV_BTN_PART_MAIN);
                setStyle(LV_BTN_PART_MAIN, _theme->commonBgStyle());
                setStyle(LV_BTN_PART_MAIN, _theme->commonBorderStyle());
                setStyle(LV_BTN_PART_MAIN, _theme->commonOutlineStyle());
                setStyle(LV_BTN_PART_MAIN, _theme->commonShapeStyle());
            break;

            case eLvglType::LVGL_CLASS_PAGE:
                resetStyle(LV_PAGE_PART_BG);
                setStyle(LV_PAGE_PART_BG, _theme->commonBgStyle());
            break;

             case eLvglType::LVGL_CLASS_COLUMN:
             case eLvglType::LVGL_CLASS_ROW:
                resetStyle(LV_CONT_PART_MAIN);
                setStyle(LV_CONT_PART_MAIN, _theme->commonBgStyle());
                setStyle(LV_CONT_PART_MAIN, _theme->containerPadStyle());
            break;

            case eLvglType::LVGL_CLASS_TABVIEW:
                resetStyle(LV_TABVIEW_PART_TAB_BG);
                resetStyle(LV_TABVIEW_PART_TAB_BTN);
                resetStyle(LV_TABVIEW_PART_INDIC);

                setStyle(LV_TABVIEW_PART_TAB_BG, _theme->commonBgStyle());
                setStyle(LV_TABVIEW_PART_TAB_BTN, _theme->tabButtonStyle());
                setStyle(LV_TABVIEW_PART_INDIC, _theme->indicatorStyle());
            break;

            case eLvglType::LVGL_CLASS_SWITCH:
                resetStyle(LV_SWITCH_PART_BG);
                resetStyle(LV_SWITCH_PART_INDIC);
                resetStyle(LV_SWITCH_PART_KNOB);
                setStyle(LV_SWITCH_PART_BG, _theme->commonBgStyle());
                setStyle(LV_SWITCH_PART_BG, _theme->commonBorderStyle());
                setStyle(LV_SWITCH_PART_BG, _theme->commonOutlineStyle());
                setStyle(LV_SWITCH_PART_BG, _theme->commonShapeStyle());   
                setStyle(LV_SWITCH_PART_INDIC, _theme->indicatorStyle());     
                setStyle(LV_SWITCH_PART_KNOB, _theme->knobStyle());  
            break;

            case eLvglType::LVGL_CLASS_UNLOCKER:
                resetStyle(LV_SLIDER_PART_INDIC);
                resetStyle(LV_SLIDER_PART_BG);
                setStyle(LV_SLIDER_PART_BG, _theme->commonShapeStyle());   
                setStyle(LV_SLIDER_PART_BG, _theme->commonBgStyle());
                setStyle(LV_SLIDER_PART_BG, _theme->commonBorderStyle());
                setStyle(LV_SLIDER_PART_BG, _theme->commonOutlineStyle());
                setStyle(LV_SLIDER_PART_INDIC, _theme->indicatorStyle());    
                setStyle(LV_SLIDER_PART_KNOB, _theme->unlockerKnobStyle());  
            break;

            case eLvglType::LVGL_CLASS_ARC:
                resetStyle(LV_ARC_PART_BG);
                resetStyle(LV_ARC_PART_INDIC);
                setStyle(LV_ARC_PART_BG, _theme->commonShapeStyle());   
                setStyle(LV_ARC_PART_BG, _theme->commonBgStyle());
                setStyle(LV_ARC_PART_INDIC, _theme->indicatorStyle());
            break;

            case eLvglType::LVGL_CLASS_LABEL:
                resetStyle(LV_LABEL_PART_MAIN);
                setStyle(LV_LABEL_PART_MAIN, _theme->commonTextStyle());          
            break;
            default:
            break;
        }
    }
}

void LVGLBase::setPaddings(const lv_part_style_t part,const lv_state_t state, const int hor, const int ver) {
    lv_obj_set_style_local_pad_hor(_obj, part, state, hor);
    lv_obj_set_style_local_pad_ver(_obj, part, state, ver);
}

void LVGLBase::setInnerPadding(const lv_part_style_t part,const lv_state_t state, const int value) {
    lv_obj_set_style_local_pad_inner(_obj, part, state, value);
}

void LVGLBase::show() {
    lv_obj_set_hidden(_obj, false);
}

void LVGLBase::setParent(LVGLBase* const parent){
    _parent = parent;
    if (_parent) {
        lv_obj_set_parent(_obj, parent->_obj);
    }
}

void LVGLBase::setStyle(const uint8_t part, lv_style_t* const style) {
    lv_obj_add_style(_obj, part, style);
}

void LVGLBase::setStyle(const uint8_t part, LVGLStyle& style) {
    setStyle(part, style.style());
}


void LVGLBase::resetStyle(const uint8_t part) {
    lv_obj_reset_style_list(_obj, part);
}

void LVGLBase::setSize(const size_t w, const size_t h) {
    lv_obj_set_size(_obj, w, h);
}

void LVGLBase::setClickable(const bool value) {
    lv_obj_set_click(_obj, value);
}

void LVGLBase::setFitMode(const uint8_t fitMode) {
    lv_cont_set_fit(_obj, fitMode);
}

void LVGLBase::align(LVGLBase* const ref, const lv_align_t align, const lv_coord_t x_ofs, const lv_coord_t y_ofs) {
    lv_obj_align(_obj, ref->innerData() ? ref->innerData() : NULL, align, x_ofs, y_ofs);
}

// void LVGLBase::setStyleTextFont(const lv_part_style_t part, const lv_state_t state, const lv_font_t* font) {
//     lv_obj_set_style_local_text_font(_obj, part, state, font);
// }

void LVGLBase::setStyleTextColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color) {
    lv_obj_set_style_local_text_color(_obj, part, state, color);
}

void LVGLBase::setStyleBgColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color) {
    lv_obj_set_style_local_bg_color(_obj, part, state, color);
}

void LVGLBase::setStyleBorderColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color) {
    lv_obj_set_style_local_border_color(_obj, part, state, color);
}

void LVGLBase::setStyleBorderWidth(const lv_part_style_t part, const lv_state_t state, const size_t width) {
    lv_obj_set_style_local_border_width(_obj, part, state, width);
}

void LVGLBase::setStyleOutlineWidth(const lv_part_style_t part, const lv_state_t state, const size_t width) {
    lv_obj_set_style_local_outline_width(_obj, part, state, width);
}

void LVGLBase::setStyleOutlineColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color) {
    lv_obj_set_style_local_outline_color(_obj, part, state, color);
}

void LVGLBase::setState(const lv_state_t state) {
    lv_obj_set_state(_obj, state);
}


LVGLBase::~LVGLBase() {
    LVGL_DBG_PRINT("LVGLBase destructor");
    lv_obj_del(_obj);
}