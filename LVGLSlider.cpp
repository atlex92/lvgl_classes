#include "LVGLSlider.hpp"

LVGLSlider::LVGLSlider(const int minValue, const int maxValue, const size_t step, LVGLBase* const parent) 
    :   AbstractRangeValueContainer(minValue, maxValue, step),
        LVGLBase(lv_slider_create(parent ? parent->innerData() : lv_disp_get_scr_act(NULL), NULL), parent) {
    LVGL_DBG_PRINT("LVGLSlider #1 constructor");

    init();
}

LVGLSlider::LVGLSlider(const int minValue, const int maxValue, const size_t step, lv_obj_t* const parent)
    :   AbstractRangeValueContainer(minValue, maxValue, step),
        LVGLBase(lv_slider_create(parent, NULL), parent) {
    LVGL_DBG_PRINT("LVGLSlider #2 constructor");

    init();
}

void LVGLSlider::init() {

    // lv_slider_set_left_value(_obj, minValue(), 500);
    lv_slider_set_range(_obj, minValue(), maxValue());

    setValue(minValue());

    auto eventCb = [this](const lv_event_t event) {
        switch (event) {
            case LV_EVENT_VALUE_CHANGED:
                this->_value = lv_slider_get_value(this->_obj);
                LVGL_DBG_PRINT(value());
            break;

            default:
                break;
        }
    };

    auto onChangedCb = [this](AbstractValueChangable<int>*) {
        lv_slider_set_value(_obj, this->value(), 100);
    };


    setEventCallBack(eventCb);
    setInnerValueChangedCallback(onChangedCb);
}
