#pragma once
#include "lvgl.h"
#include "lvgl_debug.hpp"
#include <functional>
#include "LVGLStyle.hpp"
#include "AbstractTheme.hpp"
#include <vector>

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
    LVGL_CLASS_SPINNER,
    LVGL_CLASS_MAX   
};
class LVGLBase {
    
    public:
        typedef std::function<void(LVGLBase* obj)> eventCb_t;
        // Creation and deletion
        virtual ~LVGLBase();
        explicit LVGLBase(lv_obj_t* const lvglObj, LVGLBase* const parent);
        explicit LVGLBase(lv_obj_t* const lvglObj, lv_obj_t* const parent = lv_disp_get_scr_act(NULL));
        // callbacks
        void onDragStopped(eventCb_t cb);
        void onDefocused(eventCb_t cb);
        void onFocused(eventCb_t cb);
        // style API
        void setStyle(const uint8_t part, lv_style_t* const style);
        void setStyle(const uint8_t part, LVGLStyle& style);
        void resetStyle(const uint8_t part);
        // aligning
        void align(LVGLBase* const ref, const lv_align_t align, const lv_coord_t x_ofs, const lv_coord_t y_ofs);
        void alignHorizontally(LVGLBase* const ref, const lv_align_t align, const lv_coord_t x_ofs);
        void alignVertically(LVGLBase* const ref, const lv_align_t align, const lv_coord_t y_ofs);


        virtual eLvglType type() const = 0;
        static void setTheme(AbstractTheme* const theme);

        
        void setAutoRealign(const bool value);
        void setState(const lv_state_t state);
        uint8_t state() const;
        // style color
        virtual void setStyleTextColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color);
        void setStyleBgColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color);
        void setStyleBgOpacity(const lv_part_style_t part, const lv_state_t state, const lv_opa_t opa);
        void setStyleBorderColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color);
        void setStyleOutlineColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color);
        void setStyleLineColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color);

        void setPosition(const lv_coord_t x, const lv_coord_t y);

        // paddings
        void setPaddings(const lv_part_style_t part, const lv_state_t state, const int hor, const int ver);
        void setPaddings(const lv_part_style_t part, const lv_state_t state, const int up,
            const int bottom, const int left, const int right);
        void setInnerPadding(const lv_part_style_t part,const lv_state_t state, const int value);
        // fonts
        void setFont(const lv_part_style_t part,const lv_state_t state, lv_font_t* const font);

        void setStyleBorderWidth(const lv_part_style_t part, const lv_state_t state, const size_t width);
        void setStyleOutlineWidth(const lv_part_style_t part, const lv_state_t state, const size_t width);

        void setDragEnabled(const bool value);
        void setDragThrowEnabled(const bool value);
        void setDragDirection(const lv_drag_dir_t value);

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
        void addChild(LVGLBase* child) {
            _children.emplace_back(child);
        }
        static AbstractTheme* _theme;
    protected:
        void applyTheme();
        LVGLBase* _parent;
        lv_obj_t* _obj;
        eventCallback_t _eventCallback;
        eventCb_t _onDragStoppedCb = nullptr;
        eventCb_t _onDefocused = nullptr;
        eventCb_t _onFocused = nullptr;
        std::vector<LVGLBase*> _children;
};