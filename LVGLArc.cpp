#include "LVGLArc.hpp"

LVGLArc::LVGLArc(const bool adjustable, const size_t startAngle,
            const size_t endAngle, const std::string& label, LVGLBase* const parent)
    :   LVGLBase(lv_arc_create(parent? parent->innerData() : lv_disp_get_scr_act(NULL), NULL), parent),
        _valueString{label},
        _valueLbl {new LVGLLabel("value", this)},
        _isAdjustable {adjustable},
        _startAngle(startAngle),
        _endAngle(endAngle) {

    LVGL_DBG_PRINT("LVGLArc #1 constructor");
    init();
    applyTheme();
}

LVGLArc::LVGLArc(const bool adjustable, const size_t startAngle,
            const size_t endAngle, const std::string& label, lv_obj_t* const parent) 
    :   LVGLBase(lv_arc_create(parent, NULL), parent),
        _valueString{label},
        _valueLbl {new LVGLLabel("value", this)},
        _isAdjustable {adjustable},
        _startAngle(startAngle),
        _endAngle(endAngle) {

    LVGL_DBG_PRINT("LVGLArc #2 constructor");
    init();
    applyTheme();
}

static void arcAnimCb(void * ptr, lv_anim_value_t val)
{
    lv_obj_t* arc     = static_cast<lv_obj_t*>(ptr);

    // lv_spinner_ext_t * ext = lv_obj_get_ext_attr(arc);

    // const int currValue{lv_arc_get_value(arc)};
    // const int startAnngle {150/*(lv_arc_get_angle_end(arc) - lv_arc_get_angle_start(arc)) * currValue/100*/};
    // const int endAnngle {280/*(lv_arc_get_angle_end(arc) - lv_arc_get_angle_start(arc)) * val/100*/};


    // lv_arc_ext_t * ext = ( lv_arc_ext_t *)lv_obj_get_ext_attr(arc);
    // const uint16_t angleStart {ext->arc_angle_start};
    // const float delta {((int)ext->bg_angle_end - angleStart) * (float)val / 100};
    // LVGL_DBG_PRINT(delta);

    // const uint16_t angleEnd = angleStart + delta;

    // LVGL_DBG_PRINT(angleStart);
    // LVGL_DBG_PRINT(angleEnd);
    // LVGL_DBG_PRINT(val);

    // LVGL_DBG_PRINT("");


    // lv_arc_set_angles(arc, angleStart, angleEnd);
    lv_arc_set_value(arc, val);
}


void LVGLArc::init() {

    lv_obj_set_auto_realign(_valueLbl->innerData(), true);
    _valueLbl->align(this, LV_ALIGN_CENTER, 0, 0);
    setClickable(_isAdjustable);
    lv_arc_set_adjustable(_obj, _isAdjustable);
    lv_arc_set_bg_angles(_obj, _startAngle, _endAngle);
    lv_arc_set_angles(_obj, _startAngle, _startAngle);

    auto eventCb = [this](const lv_event_t event) {
        switch (event) {
            case LV_EVENT_RELEASED:
                this->setValue(lv_arc_get_value(this->_obj));
                LVGL_DBG_PRINT("LVGLArc : LV_EVENT_RELEASED");
                // LVGL_DBG_PRINT(value());

            break;
            default:
                break;
        }
    };

    auto onChangedCb = [this](AbstractValueChangable<int>*) {
        redrawText();
        if (lv_arc_get_value(this->_obj) != this->value()) {
            
            // LVGL_DBG_PRINT("LVGLArc : setted!");

            static lv_anim_path_t path;
            lv_anim_path_init(&path);
            lv_anim_path_set_cb(&path, lv_anim_path_linear);

            lv_anim_t a;
            lv_anim_init(&a);
            lv_anim_set_var(&a, _obj);
            lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)arcAnimCb);
            lv_anim_set_time(&a, 500);
            lv_anim_set_path(&a, &path);
            lv_anim_set_repeat_count(&a, 1);
            lv_anim_set_values(&a, lv_arc_get_value(this->_obj), this->value());
            // lv_arc_set_value(_obj, this->value());
            // lv_arc_set_angles();
            lv_anim_start(&a);
        }
    };

    setEventCallBack(eventCb);
    setInnerValueChangedCallback(onChangedCb);
}

void LVGLArc::redrawText() {
    _valueLbl->setText("%d %s", value(), _valueString.c_str());
}