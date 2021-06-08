#pragma once

#include "LVGLSlider.hpp"

class LVGLUnlocker : public LVGLSlider {
    typedef std::function<void(LVGLUnlocker*)> unlockCallBack_t;
    public:
        explicit LVGLUnlocker(LVGLBase* const parent = NULL);
        explicit LVGLUnlocker(lv_obj_t* const parent);
        void onUnlock(unlockCallBack_t cb);
    private:
        void init() override;
        unlockCallBack_t _onUnlockCallback = nullptr;
};
