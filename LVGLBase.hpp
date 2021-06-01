#pragma once
#include "lvgl.h"
#include "lvgl_debug.hpp"

class LVGLBase {
    
    public:
        virtual ~LVGLBase();
        explicit LVGLBase(lv_obj_t* const lvglObj, LVGLBase* const parent);
        explicit LVGLBase(lv_obj_t* const lvglObj, lv_obj_t* const parent = lv_disp_get_scr_act(NULL));

        void setStyle(uint8_t part, lv_style_t* style);
        virtual void setSize(const size_t w, const size_t h);
        void setParent(LVGLBase* const parent);
        void setParent(lv_obj_t* const parent);

    protected:
        LVGLBase* _parent;
        lv_obj_t* _obj;
        lv_style_t _style;
};