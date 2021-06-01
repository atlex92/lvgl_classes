#include "LVGLBase.hpp"

#include <iostream>
using namespace std;

LVGLBase::LVGLBase(lv_obj_t* const lvglObj, LVGLBase* const parent)
    :   _parent{parent},
        _obj{lvglObj} {
    LVGL_DBG_PRINT("LVGLBase #1 constructor");
    lv_style_init(&_style);
    setParent(parent);
}

LVGLBase::LVGLBase(lv_obj_t* const lvglObj, lv_obj_t* const parent)
    :   _parent{NULL},  _obj{lvglObj} {
    LVGL_DBG_PRINT("LVGLBase #2 constructor");
    setParent(parent);
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

void LVGLBase::setStyle(uint8_t part, lv_style_t* style) {
    lv_obj_reset_style_list(_obj, part);
    lv_obj_add_style(_obj, part, style);
}

void LVGLBase::setSize(const size_t w, const size_t h) {
    lv_obj_set_size(_obj, w, h);
}

LVGLBase::~LVGLBase() {
    LVGL_DBG_PRINT("LVGLBase destructor");
    lv_obj_del(_obj);
}