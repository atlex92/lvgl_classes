#pragma once

#include "LVGLContainer.hpp"

class LVGLRow : public LVGLContainer {

    public:
        explicit LVGLRow(LVGLBase* const parent = NULL);
        explicit LVGLRow(lv_obj_t* const parent);
        explicit LVGLRow(lv_obj_t* const src, LVGLBase* const parent);        
};