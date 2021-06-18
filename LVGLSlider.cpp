#include "LVGLSlider.hpp"

LVGLSlider::LVGLSlider(const int minValue, const int maxValue, const size_t step, LVGLBase* const parent) 
    :   AbstractRangeValueContainer(minValue, maxValue, step),
        LVGLBase(lv_slider_create(parent ? parent->innerData() : lv_disp_get_scr_act(NULL), NULL), parent) {
    LVGL_DBG_PRINT("LVGLSlider #1 constructor");

    init();
    applyTheme();
}

LVGLSlider::LVGLSlider(const int minValue, const int maxValue, const size_t step, lv_obj_t* const parent)
    :   AbstractRangeValueContainer(minValue, maxValue, step),
        LVGLBase(lv_slider_create(parent, NULL), parent) {
    LVGL_DBG_PRINT("LVGLSlider #2 constructor");

    init();
    applyTheme();
}

void LVGLSlider::init() {

    lv_slider_set_range(_obj, minValue(), maxValue());
    LVGL_DBG_PRINT("LVGLSlider:init");

    setValue(minValue());

    auto eventCb = [this](const lv_event_t event) {
        switch (event) {
            case LV_EVENT_RELEASED:
                this->setValue(lv_slider_get_value(this->_obj));
                LVGL_DBG_PRINT("LV_EVENT_RELEASED");
            break;
            default:
                break;
        }
    };

    auto onChangedCb = [this](AbstractValueChangable<int>*) {
        if (lv_slider_get_value(this->_obj) != this->value()) {
            lv_slider_set_value(_obj, this->value(), 100);
            LVGL_DBG_PRINT("setted!");
        }
    };


    setEventCallBack(eventCb);
    setInnerValueChangedCallback(onChangedCb);
}
