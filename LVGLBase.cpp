#include "LVGLBase.hpp"

#include <iostream>
using namespace std;

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
        LVGL_DBG_PRINT("callback not found");
    }
}

LVGLBase::LVGLBase(lv_obj_t* const lvglObj, LVGLBase* const parent)
    :   _parent{parent},
        _obj{lvglObj},
        _eventCallback{nullptr} {
    
    LVGL_DBG_PRINT("LVGLBase #1 constructor");
    lv_style_init(&_style);
    lv_obj_set_user_data(_obj, this);
    lv_obj_set_event_cb(_obj, eventHandler);
}

LVGLBase::LVGLBase(lv_obj_t* const lvglObj, lv_obj_t* const parent)
    :   _parent{NULL},
        _obj{lvglObj},
        _eventCallback{nullptr} {
    LVGL_DBG_PRINT("LVGLBase #2 constructor");
    lv_style_init(&_style);
    lv_obj_set_user_data(_obj, this);
    lv_obj_set_event_cb(_obj, eventHandler);
}

void LVGLBase::setParent(LVGLBase* const parent){
    _parent = parent;
    if (_parent) {
        lv_obj_set_parent(_obj, parent->_obj);
    }
}

void LVGLBase::setParent(lv_obj_t* const parent) {
    if (parent) {
        lv_obj_set_parent(_obj, parent);
    }
}

void LVGLBase::setStyle(const uint8_t part, lv_style_t* const style) {
    
    lv_obj_add_style(_obj, part, style);
}

void LVGLBase::resetStyle(const uint8_t part) {
    lv_obj_reset_style_list(_obj, part);
}

void LVGLBase::setSize(const size_t w, const size_t h) {
    lv_obj_set_size(_obj, w, h);
}

LVGLBase::~LVGLBase() {
    LVGL_DBG_PRINT("LVGLBase destructor");
    lv_obj_del(_obj);
}