#pragma once

#include <string>

#include "LVGLBase.hpp"

class LVGLLabel : public LVGLBase{

    public:
        explicit LVGLLabel(const std::string& txt, LVGLBase* const parent = NULL);
        explicit LVGLLabel(const std::string& txt, lv_obj_t* const parent);
        explicit LVGLLabel(lv_obj_t* const src, LVGLBase* const parent = NULL);

        void setText(const std::string& txt) {
            lv_label_set_text(_obj, txt.c_str());
        }

        template<typename ... Args>
        void setText(const char * const frmt, Args ... args) {
            lv_label_set_text_fmt(_obj, frmt, args ...);
            // lv_obj_align_mid(_obj, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
            // lv_obj_align_origo_y(_obj, NULL, LV_ALIGN_IN_RIGHT_MID, 0);
        }

        void setText(const int value) {
            lv_label_set_text_fmt(_obj, "%d", value);
        }

        std::string text() const {
            return lv_label_get_text(_obj);
        }

        void setAlignMode(const lv_label_align_t mode) {
            lv_label_set_align(_obj, mode);
        }
};