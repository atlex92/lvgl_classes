#include "LVGLToaster.hpp"

#define DEFALT_TOAST_TIME_MS        3000UL
#define DEFALT_TOAST_ANIMATION_TIME 500UL


static void changeOpacityCb(lv_obj_t* obj, uint16_t val) {
    lv_obj_set_style_local_opa_scale(obj, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, val);
    lv_obj_set_style_local_opa_scale(obj, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, val);
}

void LVGLToaster::animationReadyCb(lv_anim_t* old_anim) {

    LVGLToaster* toaster = static_cast<LVGLToaster*>(old_anim->var);
    LVGL_DBG_PRINT("animationReadyCb");
    lv_anim_set_ready_cb(old_anim, NULL);

    lv_anim_set_exec_cb(old_anim, (lv_anim_exec_xcb_t)changeOpacityCb);

    lv_anim_set_delay(old_anim, 3000);
    lv_anim_set_values(old_anim, LV_OPA_100, LV_OPA_0);
    lv_anim_start(old_anim);
}

LVGLToaster::LVGLToaster(LVGLBase* const parent)
    :   LVGLLabel("", parent),
        _toastTimeMs{DEFALT_TOAST_TIME_MS} {
    
    
    setAlignMode(LV_LABEL_ALIGN_CENTER);
    setAutoRealign(true);
    applyTheme();
    hide();
}

LVGLToaster::LVGLToaster(lv_obj_t* const parent)
    :   LVGLLabel("", parent),
        _toastTimeMs{DEFALT_TOAST_TIME_MS} {

    setAlignMode(LV_LABEL_ALIGN_CENTER);
    applyTheme();
    hide();
}

void LVGLToaster::setToast(const std::string& txt) {

    setText(txt);
    show();  

    lv_anim_init(&_anim);
    lv_anim_set_var(&_anim, this->_obj);

    lv_anim_set_exec_cb(&_anim, (lv_anim_exec_xcb_t)changeOpacityCb);
    lv_anim_set_repeat_count(&_anim, 1);

    lv_anim_set_values(&_anim, LV_OPA_0, LV_OPA_100);
    lv_anim_set_time(&_anim, DEFALT_TOAST_ANIMATION_TIME);
    lv_anim_set_ready_cb(&_anim, animationReadyCb);
    lv_anim_start(&_anim);
}


void LVGLToaster::setTime(const size_t timeMs) {
    _toastTimeMs = timeMs;
}