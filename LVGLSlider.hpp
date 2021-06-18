#pragma once

#include "AbstractRangeValueContainer.hpp"
#include "LVGLBase.hpp"

class LVGLSlider : public AbstractRangeValueContainer<int>, public LVGLBase {

    public:
        eLvglType type() const override {return eLvglType::LVGL_CLASS_SLIDER;}
        explicit LVGLSlider(const int minValue, const int maxValue, const size_t step, LVGLBase* const parent);
        explicit LVGLSlider(const int minValue, const int maxValue, const size_t step, lv_obj_t* const parent);
    private:
        virtual void init();
};