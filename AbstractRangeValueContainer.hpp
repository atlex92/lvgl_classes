#pragma once

#include "LVGLBase.hpp"
#include "stdint.h"
#include <functional>



class AbstractRangeValueContainer /*: public LVGLBase */{

    public:
        typedef std::function<void(AbstractRangeValueContainer*, const int)> valueChangedCallback_t;
        explicit AbstractRangeValueContainer(/*lv_obj_t* parent, */const int minValue, const int maxValue,
            const size_t step);
        // getters
        size_t step() const { return _step; }
        int minValue() const { return _minValue; }
        int maxValue() const { return _maxValue; }
        int value() const { return _currentValue; }
        // setters
        void setValue(const int value);
        void setRange(const int min, const int max);
        void setMinValue(const int min);
        void setMaxValue(const int max);
        void setStep(const size_t step);

        void increment();
        void decrement();
        AbstractRangeValueContainer& operator++(); 
        AbstractRangeValueContainer& operator--();

        void onChanged(valueChangedCallback_t cb);
    private:
        valueChangedCallback_t _onValueChangedCb;
        void emitChangedSignal();
        int _minValue;
        int _maxValue;
        size_t _step;
        int _currentValue;
        int _prevValue;
};
