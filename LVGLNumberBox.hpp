#pragma once

#include "LVGLButton.hpp"
#include "LVGLRow.hpp"
#include "LVGLLabel.hpp"
#include "AbstractRangeValueContainer.hpp"

class LVGLNumberBox : public AbstractRangeValueContainer, public LVGLRow {

    public:
        // constructors
        explicit LVGLNumberBox(const int minValue, const int maxValue, const size_t step, LVGLBase* const parent);
        explicit LVGLNumberBox(const int minValue, const int maxValue, const size_t step, lv_obj_t* const parent);

    private:
        void redrawText();
        void init();

        LVGLButton* _leftBtn;
        LVGLLabel* _valueLbl;
        LVGLButton* _rightBtn;
};