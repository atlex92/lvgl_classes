// #pragma once
// #include "LVGLBase.hpp"
// #include "AbstractValueChangable.hpp"

// enum class eBatteryState {
//     BATTERY_EMPTY,
//     BATTERY_25,
//     BATTERY_50,
//     BATTERY_75,
//     BATTERY_FULL
// };

// class LVGLBatteryIndicator : public AbstractValueChangable<eBatteryState>, public LVGLBase {
//     public:
//         eLvglType type() const override {return eLvglType::LVGL_CLASS_BATTERY_IND;}
//         explicit LVGLBatteryIndicator(LVGLBase* const parent = NULL);
//         // void setSize(const size_t w, const size_t h) override;
// };