#pragma once
#include "LVGLBase.hpp"

class LVGLPage : public LVGLBase {

    public:       
        eLvglType type() const override {return eLvglType::LVGL_CLASS_PAGE;}
        explicit LVGLPage(LVGLBase* const parent = NULL);
        explicit LVGLPage(lv_obj_t* const parent);
        explicit LVGLPage(lv_obj_t* const src, LVGLBase* const parent);

        void setScrollBarMode(const lv_scrollbar_mode_t mode);
        void setScrollPropogation(const bool val);
        void setScrollableFit(const lv_fit_t fit);
};