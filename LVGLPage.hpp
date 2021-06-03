#pragma once
#include "LVGLBase.hpp"

class LVGLPage : public LVGLBase {

    public:       
        explicit LVGLPage(LVGLBase* const parent = NULL);
        explicit LVGLPage(lv_obj_t* const parent);
        void setScrollBarMode(const lv_scrollbar_mode_t mode);
};