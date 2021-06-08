#include "LVGLNumberBox.hpp"

LVGLNumberBox::LVGLNumberBox(const int minValue, const int maxValue, const size_t step, const std::string& label, lv_obj_t* const parent)
    :   AbstractRangeValueContainer(minValue, maxValue, step),
        LVGLRow(parent),
        _leftBtn{new LVGLButton("-", this)},
        _valueLbl{new LVGLLabel("", this)},
        _rightBtn{new LVGLButton("+", this)},
        _label{label} {
    LVGL_DBG_PRINT("LVGLNumberBox #1 constructor");
    init();
}

LVGLNumberBox::LVGLNumberBox(const int minValue, const int maxValue, const size_t step,  const std::string& label, LVGLBase* const parent) 
    : AbstractRangeValueContainer(minValue, maxValue, step),
        LVGLRow(parent),
        _leftBtn{new LVGLButton("-", this)},
        _valueLbl{new LVGLLabel("", this)},
        _rightBtn{new LVGLButton("+", this)},
        _label{label} {
    LVGL_DBG_PRINT("LVGLNumberBox #2 constructor");
    init();
}

void LVGLNumberBox::init() {
    
    setValue(minValue());
    _leftBtn->setSize(30,30);
    _rightBtn->setSize(30,30);
    _valueLbl->setSize(90, 40);
    
    _valueLbl->setAlignMode(LV_LABEL_ALIGN_CENTER);

    this->_valueLbl->setText("%d %s", this->value(), _label.c_str());

    _leftBtn->disable();

    auto minusCb = [this](const lv_event_t event) {
        switch (event) {
            case LV_EVENT_CLICKED:
            case LV_EVENT_LONG_PRESSED_REPEAT:
                decrement();
            break;

            default:
                break;
        }
    };

    auto plusCb = [this](const lv_event_t event) {
        switch (event) {
            case LV_EVENT_CLICKED:
            case LV_EVENT_LONG_PRESSED_REPEAT:
                increment();
            break;

            default:
                break;
        }
    };

    auto onChangedCb = [this](AbstractValueChangable<int>*) {
        this->_valueLbl->setText("%d\t%s", value(), _label.c_str());

        this->value() == this->minValue() ?
            this->_leftBtn->disable() :
            this->_leftBtn->enable();

        this->value() == this->maxValue() ?
            this->_rightBtn->disable() :
            this->_rightBtn->enable();
    };

    _leftBtn->setEventCallBack(minusCb);
    _rightBtn->setEventCallBack(plusCb);
    setInnerValueChangedCallback(onChangedCb);
}

void LVGLNumberBox::redrawText() {
    _valueLbl->setText(value());
}

void LVGLNumberBox::setButtonsStyle(const uint8_t part, lv_style_t* const style) {
    _leftBtn->setStyle(part, style);
    _rightBtn->setStyle(part, style);
}

void LVGLNumberBox::setLabelStyle(const uint8_t part, lv_style_t* const style) {
    _valueLbl->setStyle(part, style);
}
