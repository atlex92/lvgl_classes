#pragma once

#include "LVGLSlider.hpp"

class LVGLUnlocker : public LVGLSlider {
    typedef std::function<void(LVGLUnlocker*)> unlockCallBack_t;
    public:
        eLvglType type() const override {return eLvglType::LVGL_CLASS_UNLOCKER;}
        explicit LVGLUnlocker(LVGLBase* const parent = NULL);
        explicit LVGLUnlocker(lv_obj_t* const parent);
        void onUnlock(unlockCallBack_t cb);
    private:
        void init() override;
        unlockCallBack_t _onUnlockCallback = nullptr;
};
