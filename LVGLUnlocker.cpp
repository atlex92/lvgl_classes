#include "LVGLUnlocker.hpp"



LVGLUnlocker::LVGLUnlocker(LVGLBase* const parent) 
    :   LVGLSlider(0, 100, 1, parent) {
    LVGL_DBG_PRINT("LVGLUnlocker #1 constructor");

    init();
}

LVGLUnlocker::LVGLUnlocker(lv_obj_t* const parent)
    :   LVGLSlider(0, 100, 1, parent) {
    LVGL_DBG_PRINT("LVGLUnlocker #2 constructor");

    init();
}


void LVGLUnlocker::init() {

    LVGL_DBG_PRINT("LVGLUnlocker:init");

    lv_obj_set_adv_hittest(_obj, true);

    static lv_style_t defaultKnobStyle;

    lv_style_init(&defaultKnobStyle);
    lv_style_set_radius(&defaultKnobStyle, LV_STATE_DEFAULT, 5);

    lv_style_set_pad_hor(&defaultKnobStyle, LV_STATE_DEFAULT, width() * 0.04);
    lv_style_set_pad_ver(&defaultKnobStyle, LV_STATE_DEFAULT, height() * 0.6);

    lv_slider_set_range(_obj, minValue(), maxValue());

    setStyle(LV_SLIDER_PART_KNOB, &defaultKnobStyle);

    auto eventCb = [this](const lv_event_t event) {
        switch (event) {
            case LV_EVENT_VALUE_CHANGED:
            break;

            case LV_EVENT_RELEASED:
                LVGL_DBG_PRINT("LV_EVENT_RELEASED");
                if (lv_slider_get_value(this->_obj) == maxValue()) {
                    LVGL_DBG_PRINT("UNLOCK_DETECTED");
                    if (_onUnlockCallback) {
                        _onUnlockCallback(this);
                    }
                }
                else {
                    LVGL_DBG_PRINT("NO ULNLOCk");
                }
                lv_slider_set_value(_obj, minValue(), 100);
            break;

            default:
                break;
        }
    };

    setEventCallBack(eventCb);
}

void LVGLUnlocker::onUnlock(unlockCallBack_t cb) {
    _onUnlockCallback = cb;
}