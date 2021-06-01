#pragma once
#include "LVGLBase.hpp"
#include "LVGLLabel.hpp"
#include <string>

class LVGLButton : public LVGLBase{
    public:

        explicit LVGLButton(const std::string& txt, LVGLBase* const parent);
        explicit LVGLButton(const std::string& txt, lv_obj_t* const parent = lv_disp_get_scr_act(NULL));
        explicit LVGLButton(LVGLBase* const parent = NULL);
        explicit LVGLButton(lv_obj_t* const src, LVGLBase* const parent = NULL);
        void setSize(const size_t w, const size_t h) override;

    private:
        LVGLLabel* _lbl;
};
