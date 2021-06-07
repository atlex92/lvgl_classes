#pragma once

#include "stdint.h"
#include "AbstractValueChangable.hpp"
#include <math.h>

template<typename ValueType> 
class AbstractRangeValueContainer : public AbstractValueChangable<ValueType> {
    public:
        explicit AbstractRangeValueContainer(const ValueType minValue, const ValueType maxValue, const ValueType step) 
            :   _minValue{minValue},
                _maxValue{maxValue},
                _step{static_cast<ValueType>(std::fabs(step))} {

        }
        // getters
        ValueType step() const { return _step; }
        ValueType minValue() const { return _minValue; }
        ValueType maxValue() const { return _maxValue; }
        // int value() const { return _currentValue; }
        // setters
        // void setValue(const int value);
        void setRange(const ValueType min, const ValueType max) {
            _minValue = min;
            _maxValue = max;
        }
        void setMinValue(const ValueType min) {
            _minValue =  min;
        }
        void setMaxValue(const ValueType max) {
            _maxValue = max;
        }
        void setStep(const ValueType step) {
            _step = std::fabs(step);
        }

        void increment() {
            this->_value += _step;
            if (this->_value > _maxValue){
                this->_value = _maxValue;
            }
            this->emitChangedSignal();
        }

        void decrement() {
            this->_value -= _step;
            if (this->_value < _minValue){
                this->_value = _minValue;
            }
            this->emitChangedSignal();
        }

        AbstractRangeValueContainer& operator++() {
            increment();
            return *this;
        }

        AbstractRangeValueContainer& operator--() {
            decrement();
            return *this;
        }

        // void onValueChanged(valueChangedCallback_t cb);

    protected:
        // void setInnerValueChangedCallback(valueChangedCallback_t cb);
    private:
        // valueChangedCallback_t _innerValueChangedCallback;
        // valueChangedCallback_t _extValueChangedCallback;
        // void emitChangedSignal();
        ValueType _minValue;
        ValueType _maxValue;
        ValueType _step;
        // int _currentValue;
        // int _prevValue;
};
