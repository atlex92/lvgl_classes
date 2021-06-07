#include "LVGLSwitch.hpp"

LVGLSwitch::LVGLSwitch(const size_t animTime, LVGLBase* const parent)
    :   LVGLBase(lv_switch_create(parent? parent->innerData() : lv_disp_get_scr_act(NULL), NULL), parent),
        _animTime(animTime) {
    
    init();  
}

LVGLSwitch::LVGLSwitch(const size_t animTime, lv_obj_t* const parent)
    :   LVGLBase(lv_switch_create(parent, NULL), parent),
        _animTime(animTime) {
    
    init();   
}

void LVGLSwitch::init() {
    auto onChangedCb = [this](AbstractValueChangable* obj) {
        this->value() ? lv_switch_on(this->_obj, _animTime) : lv_switch_off(this->_obj, _animTime);
    };

    lv_switch_set_anim_time(_obj, _animTime);
    auto clickCb = [this](const lv_event_t event) {
        if(LV_EVENT_CLICKED == event) {
            toogle();
        }
    };

    setEventCallBack(clickCb);

    setInnerValueChangedCallback(onChangedCb);
}