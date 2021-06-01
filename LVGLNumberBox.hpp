// #pragma once

// #include "LVGLButton.hpp"
// #include "LVGLRow.hpp"

// class LVGLNumberBox : public LVGLBase {

//     public:
//         // constructors
//         explicit LVGLNumberBox(lv_obj_t* parent, const size_t minValue, const size_t maxValue, const size_t step);

//         // setters
//         void setValue(const size_t value) {
//             _currentValue = value;
//         }
//         void setRange(const size_t min, const size_t max) {
//             _minValue = min;
//             _maxValue = max;
//         }
//         void setMinValue(const size_t min) {
//             _minValue = min;
//         }
//         void setMaxValue(const size_t max) {
//             _maxValue = max;
//         }
//         void setStep(const size_t step) {
//             _step = step;
//         }

//         // getters
//         size_t step() const {
//             return _step;
//         }
//         size_t minValue() const {
//             return _minValue;
//         }
//         size_t maxValue() const {
//             return _maxValue;
//         }
//         size_t value() const {
//             return _currentValue;
//         }

//     private:

//         LVGLRow* _row;
//         LVGLButton* _leftBtn;
//         LVGLButton* _rightBtn;
//         size_t _minValue;
//         size_t _maxValue;
//         size_t _step;
//         size_t _currentValue;
// };