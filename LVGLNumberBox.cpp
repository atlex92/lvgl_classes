#include "LVGLNumberBox.hpp"

LVGLNumberBox::LVGLNumberBox(lv_obj_t* parent, const int minValue, const int maxValue, const size_t step)
    :   AbstractRangeValueContainer(/*parent, */minValue, maxValue, step),
        LVGLRow(parent),
        // _row{new LVGLRow(parent)},
        _leftBtn{new LVGLButton("-", this)},
        _valueLbl{new LVGLLabel("", this)},
        _rightBtn{new LVGLButton("+", this)} {
    
    _leftBtn->setSize(30,30);
    _rightBtn->setSize(30,30);
    _valueLbl->setSize(90, 40);

    _valueLbl->setText(minValue);
    _valueLbl->setAlignMode(LV_LABEL_ALIGN_CENTER);

    auto minusCb = [this](const lv_event_t event) {
        if(LV_EVENT_CLICKED == event) {
            decrement();
        }
    };

    auto plusCb = [this](const lv_event_t event) {
        if(LV_EVENT_CLICKED == event) {
            increment();
        }
    };

    auto onChangedCb = [this](AbstractRangeValueContainer* obj, const int value) {
        // LVGL_DBG_PRINT("handling signal..");
        this->_valueLbl->setText(value);
    };
    
    _leftBtn->setEventCallBack(minusCb);
    _rightBtn->setEventCallBack(plusCb);
    onChanged(onChangedCb);
}

void LVGLNumberBox::redrawText() {
    _valueLbl->setText(value());
}

