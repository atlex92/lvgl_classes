#pragma once

#include "LVGLBase.hpp"

class LVGLRow : public LVGLBase {

    public:

        explicit LVGLRow(LVGLBase* const parent = NULL);
        explicit LVGLRow(lv_obj_t* const parent);
        explicit LVGLRow(lv_obj_t* const src, LVGLBase* const parent);

        void addObject(LVGLBase* const obj);
    private:
        
};