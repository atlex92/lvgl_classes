#pragma once

#include <functional>

template<typename ValueType> 
class AbstractValueChangable {

    public:
        typedef std::function<void(AbstractValueChangable<ValueType>*)> valueChangedCallback_t;
        virtual ~AbstractValueChangable() = default;
        AbstractValueChangable()
            :   _value{}, _prevValue{}, _innerValueChangedCallback{}, _extValueChangedCallback {} {

        }
        void setValue(const ValueType value) {
            _value = value;
            emitChangedSignal();
        }
        ValueType value() const {
            return _value;
        }

        void onValueChanged(valueChangedCallback_t cb) {
            _extValueChangedCallback = cb;            
        }
    protected:
        void setInnerValueChangedCallback(valueChangedCallback_t cb) {
            _innerValueChangedCallback = cb;
        }
        void emitChangedSignal() {
            
            if (_prevValue != _value) {
                _prevValue = _value;
                if (_innerValueChangedCallback) {
                    _innerValueChangedCallback(this);
                }
                if (_extValueChangedCallback) {
                    _extValueChangedCallback(this);
                }
            }
        }
        ValueType _value;  
        ValueType _prevValue;
    private:
        valueChangedCallback_t _innerValueChangedCallback;
        valueChangedCallback_t _extValueChangedCallback;
};