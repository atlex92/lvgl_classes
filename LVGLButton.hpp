#pragma once
#include "LVGLBase.hpp"
#include "LVGLLabel.hpp"
#include <string>

class LVGLButton : public LVGLBase{
    friend class LVGLFactory;
    public:
        eLvglType type() const override {return eLvglType::LVGL_CLASS_BUTTON;}
        explicit LVGLButton(const std::string& txt, LVGLBase* const parent = NULL);
        explicit LVGLButton(const std::string& txt, lv_obj_t* const parent);
        explicit LVGLButton(lv_obj_t* const src, LVGLBase* const parent = NULL);
        void setSize(const size_t w, const size_t h) override;
        void disable();
        void enable();
    private:
        LVGLLabel* _lbl;
};
