#include "LVGLArc.hpp"

LVGLArc::LVGLArc(const bool adjustable, const size_t startAngle,
            const size_t endAngle, const std::string& label, LVGLBase* const parent)
    :   LVGLBase(lv_arc_create(parent? parent->innerData() : lv_disp_get_scr_act(NULL), NULL), parent),
        _valueString{label},
        _valueLbl {new LVGLLabel("value", this)},
        _isAdjustable {adjustable},
        _startAngle(startAngle),
        _endAngle(endAngle) {

    LVGL_DBG_PRINT("LVGLArc #1 constructor");
    init();
    applyTheme();
}

LVGLArc::LVGLArc(const bool adjustable, const size_t startAngle,
            const size_t endAngle, const std::string& label, lv_obj_t* const parent) 
    :   LVGLBase(lv_arc_create(parent, NULL), parent),
        _valueString{label},
        _valueLbl {new LVGLLabel("value", this)},
        _isAdjustable {adjustable},
        _startAngle(startAngle),
        _endAngle(endAngle) {

    LVGL_DBG_PRINT("LVGLArc #2 constructor");
    init();
    applyTheme();
}


void LVGLArc::init() {
    _valueLbl->align(this, LV_ALIGN_CENTER, 0, 0);
    setClickable(_isAdjustable);
    lv_arc_set_adjustable(_obj, _isAdjustable);
    lv_arc_set_bg_angles(_obj, _startAngle, _endAngle);
    lv_arc_set_angles(_obj, _startAngle, _startAngle);

    

    auto eventCb = [this](const lv_event_t event) {
        switch (event) {
            case LV_EVENT_RELEASED:
                this->setValue(lv_arc_get_value(this->_obj));
                LVGL_DBG_PRINT("LVGLArc : LV_EVENT_RELEASED");
                // LVGL_DBG_PRINT(value());

            break;
            default:
                break;
        }
    };

    auto onChangedCb = [this](AbstractValueChangable<int>*) {
        redrawText();
        if (lv_arc_get_value(this->_obj) != this->value()) {
            lv_arc_set_value(_obj, this->value());
            LVGL_DBG_PRINT("LVGLArc : setted!");
        }
    };

    setEventCallBack(eventCb);
    setInnerValueChangedCallback(onChangedCb);
}

void LVGLArc::redrawText() {
    _valueLbl->setText("%d %s", value(), _valueString.c_str());
}