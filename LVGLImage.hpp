#pragma once
#include "LVGLBase.hpp"

class LVGLImage : public LVGLBase {

    public:
        eLvglType type() const override {return eLvglType::LVGL_CLASS_BATTERY_MAGE;}
        explicit LVGLImage(const lv_img_dsc_t* img, LVGLBase* const parent = NULL);
        void zoomOut(const size_t percent);
    private:
        const lv_img_dsc_t* _img;
};