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

        void setStyle(const uint8_t part, lv_style_t* const style);
        void resetStyle(const uint8_t part);
        virtual void setSize(const size_t w, const size_t h);
        void setParent(LVGLBase* const parent);
        void setParent(lv_obj_t* const parent);
        
        void setEventCallBack(eventCallback_t cb) {
            _eventCallback = cb;
        }


        lv_obj_t* innerData() const {
            return _obj;
        }
    private:
        static void eventHandler(lv_obj_t * obj, lv_event_t event);

    protected:
        lv_style_t _style;
        LVGLBase* _parent;
        lv_obj_t* _obj;
        eventCallback_t _eventCallback;
};