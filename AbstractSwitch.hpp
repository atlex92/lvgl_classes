#pragma once

#include "AbstractValueChangable.hpp"

class AbstractSwitch : public AbstractValueChangable<bool>{

    public:
        virtual ~AbstractSwitch() = default;
        
        void toggle() {
            setValue(!_value);
        }
    private:
};