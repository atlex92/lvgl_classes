#pragma once
#include "AbstractSwitch.hpp"
#include "LVGLBase.hpp"

class LVGLSwitch : public AbstractSwitch, public LVGLBase {

    public:
        explicit LVGLSwitch(const size_t animTime, LVGLBase* const parent = NULL);
        explicit LVGLSwitch(const size_t animTime, lv_obj_t* const parent);
    private:
        size_t _animTime;
        void init();
};