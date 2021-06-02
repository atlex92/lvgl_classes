#pragma once

#include "LVGLButton.hpp"
#include "LVGLRow.hpp"
#include "LVGLLabel.hpp"
#include "AbstractRangeValueContainer.hpp"

class LVGLNumberBox : public AbstractRangeValueContainer, public LVGLRow {

    public:
        // constructors
        explicit LVGLNumberBox(lv_obj_t* parent, const int minValue, const int maxValue, const size_t step);

    private:
        void redrawText();

        LVGLButton* _leftBtn;
        LVGLLabel* _valueLbl;
        LVGLButton* _rightBtn;
};