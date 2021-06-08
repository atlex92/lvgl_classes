#pragma once
#include "lvgl.h"
#include "lvgl_debug.hpp"
#include <functional>


typedef std::function<void(const lv_event_t event)> eventCallback_t;

class LVGLBase {
    
    public:
        virtual ~LVGLBase();
        explicit LVGLBase(lv_obj_t* const lvglObj, LVGLBase* const parent);
        explicit LVGLBase(lv_obj_t* const lvglObj, lv_obj_t* const parent = lv_disp_get_scr_act(NULL));
        
        // style API
        void setStyle(const uint8_t part, lv_style_t* const style);
        void resetStyle(const uint8_t part);
        // void setStyleTextFont(const lv_part_style_t part, const lv_state_t state, const lv_font_t* font);
        void setStyleTextColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color);
        void setStyleBgColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color);

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
        void setFitMode(const uint8_t fitMode);

        //style
        void setEventCallBack(eventCallback_t cb) {
            _eventCallback = cb;
        }

        lv_obj_t* innerData() const {
            return _obj;
        }
    private:
        static void eventHandler(lv_obj_t * obj, lv_event_t event);

    protected:
        LVGLBase* _parent;
        lv_obj_t* _obj;
        eventCallback_t _eventCallback;
};