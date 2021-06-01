// #include "LVGLNumberBox.hpp"

// LVGLNumberBox::LVGLNumberBox(lv_obj_t* parent, const size_t minValue, const size_t maxValue, const size_t step)
//     :   LVGLBase(nullptr),
//         _row{new LVGLRow(parent)},
//         _leftBtn{new LVGLButton(_row->rawObject(), "-")},
//         _rightBtn{new LVGLButton(_row->rawObject(), "+")},
//         _minValue{minValue},
//         _maxValue{maxValue},
//         _step{step},
//         _currentValue{minValue} {

//     _obj = _row->rawObject();
//     _row->addObject(_leftBtn);
//     _row->addObject(_rightBtn);

// }