#pragma once
#include "lvgl.h"
#include "lvgl_debug.hpp"
#include <functional>
#include "LVGLStyle.hpp"
#include "AbstractTheme.hpp"

typedef std::function<void(const lv_event_t event)> eventCallback_t;
enum class eLvglType {
    LVGL_CLASS_SWITCH,
    LVGL_CLASS_PAGE,
    LVGL_CLASS_ROW,
    LVGL_CLASS_COLUMN,
    LVGL_CLASS_LABEL,
    LVGL_CLASS_TABVIEW,
    LVGL_CLASS_BUTTON,
    LVGL_CLASS_SLIDER,
    LVGL_CLASS_UNLOCKER,
    LVGL_CLASS_ARC,
    LVGL_CLASS_BATTERY_IND,
    LVGL_CLASS_BATTERY_MAGE,
    LVGL_CLASS_MAX   
};
class LVGLBase {
    
    public:
        virtual ~LVGLBase();
        explicit LVGLBase(lv_obj_t* const lvglObj, LVGLBase* const parent);
        explicit LVGLBase(lv_obj_t* const lvglObj, lv_obj_t* const parent = lv_disp_get_scr_act(NULL));
        virtual eLvglType type() const = 0;
        static void setTheme(AbstractTheme* const theme);
        
        void setAutoRealign(const bool value);
        void setState(const lv_state_t state);
        // style API
        void setStyle(const uint8_t part, lv_style_t* const style);
        void setStyle(const uint8_t part, LVGLStyle& style);
        void resetStyle(const uint8_t part);
        // void setStyleTextFont(const lv_part_style_t part, const lv_state_t state, const lv_font_t* font);
        // style color
        void setStyleTextColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color);
        void setStyleBgColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color);
        void setStyleBorderColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color);
        void setStyleOutlineColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color);
        void setStyleLineColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color);
        // paddings
        void setPaddings(const lv_part_style_t part, const lv_state_t state, const int hor, const int ver);
        void setInnerPadding(const lv_part_style_t part,const lv_state_t state, const int value);
        // fonts
        void setFont(const lv_part_style_t part,const lv_state_t state, lv_font_t* const font);

        void setStyleBorderWidth(const lv_part_style_t part, const lv_state_t state, const size_t width);
        void setStyleOutlineWidth(const lv_part_style_t part, const lv_state_t state, const size_t width);

        void align(LVGLBase* const ref, const lv_align_t align, const lv_coord_t x_ofs, const lv_coord_t y_ofs);
        void hide();
        void show();

        // size API
        virtual void setSize(const size_t w, const size_t h);
        size_t width() const {
            return lv_obj_get_width(_obj);
        }
        size_t height() const{ 
            return lv_obj_get_height(_obj);
        }

        void setParent(LVGLBase* const parent);
        void setClickable(const bool value);

        //style
        void setEventCallBack(eventCallback_t cb) {
            _eventCallback = cb;
        }

        lv_obj_t* innerData() const {
            return _obj;
        }
    private:
        static void eventHandler(lv_obj_t * obj, lv_event_t event);
        static AbstractTheme* _theme;
    protected:
        void applyTheme();
        LVGLBase* _parent;
        lv_obj_t* _obj;
        eventCallback_t _eventCallback;
};