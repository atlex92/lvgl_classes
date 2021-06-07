#pragma once

#include "AbstractValueChangable.hpp"

class AbstractSwitch : public AbstractValueChangable<bool>{

    public:
        virtual ~AbstractSwitch() = default;
        
        void toogle() {
            setValue(!_value);
        }
    private:
};