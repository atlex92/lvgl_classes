#pragma once

#include <string>

#include "LVGLBase.hpp"

class LVGLLabel : public LVGLBase{

    public:
        explicit LVGLLabel(const std::string& txt, LVGLBase* const parent);
        explicit LVGLLabel(const std::string& txt, lv_obj_t* const parent = lv_disp_get_scr_act(NULL));
        explicit LVGLLabel(LVGLBase* const parent = NULL);
        explicit LVGLLabel(lv_obj_t* const src, LVGLBase* const parent = NULL);

        void setText(const std::string& txt) {
            lv_label_set_text(_obj, txt.c_str());
        }
        std::string text() const {
            return lv_label_get_text(_obj);
        }
        void setTextColor(const lv_color_t color) {
            lv_style_set_text_color(&_style, LV_STATE_DEFAULT, color);
            lv_obj_add_style(_obj, LV_OBJ_PART_MAIN, &_style);
        }
};