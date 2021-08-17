#pragma once

#include "LVGLLabel.hpp"

class LVGLToaster : public LVGLLabel {

    public:
        eLvglType type() const override {return eLvglType::LVGL_CLASS_TOASTER;}
        explicit LVGLToaster(LVGLBase* const parent = NULL);
        explicit LVGLToaster(lv_obj_t* const parent);
        void setToast(const std::string& txt);
        void setTime(const size_t timeMs);
    private:
        static void animationReadyCb(lv_anim_t* old_anim);
        size_t _toastTimeMs;
        lv_anim_t _anim;
};