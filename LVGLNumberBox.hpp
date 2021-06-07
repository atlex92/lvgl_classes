#pragma once

#include "LVGLButton.hpp"
#include "LVGLRow.hpp"
#include "LVGLLabel.hpp"
#include "AbstractRangeValueContainer.hpp"
class LVGLNumberBox : public AbstractRangeValueContainer<int>, public LVGLRow {

    public:
        // constructors
        explicit LVGLNumberBox(const int minValue, const int maxValue, const size_t step, const std::string& label, LVGLBase* const parent);
        explicit LVGLNumberBox(const int minValue, const int maxValue, const size_t step, const std::string& label, lv_obj_t* const parent);
        void setButtonsStyle(const uint8_t part, lv_style_t* const style);
        void setLabelStyle(const uint8_t part, lv_style_t* const style);
    private:
        void redrawText();
        void init();

        LVGLButton* _leftBtn;
        LVGLLabel* _valueLbl;
        LVGLButton* _rightBtn;
        std::string _label;
};