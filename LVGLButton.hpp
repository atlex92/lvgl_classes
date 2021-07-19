#pragma once
#include "LVGLBase.hpp"
#include "LVGLLabel.hpp"
#include <string>

class LVGLButton : public LVGLBase{
    typedef std::function<void(LVGLButton*)> buttonCbType;
    public:
        eLvglType type() const override {return eLvglType::LVGL_CLASS_BUTTON;}
        explicit LVGLButton(const std::string& txt, LVGLBase* const parent = NULL);
        explicit LVGLButton(const std::string& txt, lv_obj_t* const parent);
        explicit LVGLButton(lv_obj_t* const src, LVGLBase* const parent = NULL);
        void disable();
        void enable();
        void onClicked(buttonCbType cb);
        void onLongPressed(buttonCbType cb);
        void onLongPressedRepeat(buttonCbType cb);
        void init();
        void setStyleTextColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color) override;
        void setSize(const size_t w, const size_t h) override;
        void setLabelText(const std::string& txt);
    private:
        LVGLLabel* _lbl;
        buttonCbType _onClickedCb = nullptr;
        buttonCbType _onLongPressedCb = nullptr;
        buttonCbType _onLongPressedRepeatCb = nullptr;
};
