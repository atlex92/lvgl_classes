#include "LVGLNumberBox.hpp"

LVGLNumberBox::LVGLNumberBox(const int minValue, const int maxValue, const size_t step, lv_obj_t* const parent)
    :   AbstractRangeValueContainer(minValue, maxValue, step),
        LVGLRow(parent),
        _leftBtn{new LVGLButton("-", this)},
        _valueLbl{new LVGLLabel("", this)},
        _rightBtn{new LVGLButton("+", this)} {
    LVGL_DBG_PRINT("LVGLNumberBox #1 constructor");
    init();
}

LVGLNumberBox::LVGLNumberBox(const int minValue, const int maxValue, const size_t step, LVGLBase* const parent) 
    : AbstractRangeValueContainer(minValue, maxValue, step),
        LVGLRow(parent),
        _leftBtn{new LVGLButton("-", this)},
        _valueLbl{new LVGLLabel("", this)},
        _rightBtn{new LVGLButton("+", this)} {
    LVGL_DBG_PRINT("LVGLNumberBox #2 constructor");
    init();
}

void LVGLNumberBox::init() {
    
    _leftBtn->setSize(30,30);
    _rightBtn->setSize(30,30);
    _valueLbl->setSize(90, 40);
    _valueLbl->setText(minValue());
    _valueLbl->setAlignMode(LV_LABEL_ALIGN_CENTER);

    auto minusCb = [this](const lv_event_t event) {
        if(LV_EVENT_CLICKED == event) {
            decrement();
            this->_valueLbl->setText(this->value());
        }
    };

    auto plusCb = [this](const lv_event_t event) {
        if(LV_EVENT_CLICKED == event) {
            increment();
        }
    };

    auto onChangedCb = [this](AbstractRangeValueContainer*, const int value) {
        this->_valueLbl->setText(this->value());

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

