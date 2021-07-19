#include "LVGLButton.hpp"

LVGLButton::LVGLButton(const std::string& txt, lv_obj_t* const parent)
    :   LVGLBase(lv_btn_create(parent, NULL), parent),
        _lbl{new LVGLLabel(txt, this)} {
    applyTheme();
    init();
}

LVGLButton::LVGLButton(const std::string& txt, LVGLBase* const parent)
    :   LVGLBase(lv_btn_create(parent? parent->innerData() : lv_disp_get_scr_act(NULL), NULL), parent),
        _lbl{new LVGLLabel(txt, this)} {
    applyTheme();
    init();
}

LVGLButton::LVGLButton(lv_obj_t* const src, LVGLBase* const parent)
    :   LVGLBase(src, parent),
        _lbl{new LVGLLabel("", this)} {
    applyTheme();
    init();
}

void LVGLButton::setSize(const size_t w, const size_t h) {
    LVGLBase::setSize(w, h);
    _lbl->setSize(width(), _lbl->height());
}

void LVGLButton::init() {
    _lbl->setLabelLongMode(LV_LABEL_LONG_DOT);
    _lbl->setSize(width(), _lbl->height());
    // _lbl->setPaddings(LV_CONT_PART_MAIN, LV_STATE_DEFAULT, 10, 0);
    auto eventCb = [this](const lv_event_t event) {
        switch (event) {
            case LV_EVENT_CLICKED:
                if (this->_onClickedCb) {
                    this->_onClickedCb(this);
                }
            break;
            case LV_EVENT_LONG_PRESSED_REPEAT:
                if (this->_onLongPressedRepeatCb) {
                    this->_onLongPressedRepeatCb(this);
                }
            break;
            case LV_EVENT_LONG_PRESSED:
                if (this->_onLongPressedCb) {
                    this->_onLongPressedCb(this);
                }
            break;

            default:
                break;
        }
    };

    setEventCallBack(eventCb);
    _lbl->setAlignMode(LV_LABEL_ALIGN_CENTER);
    _lbl->align(this, LV_ALIGN_CENTER, 0, 0);
}

void LVGLButton::setStyleTextColor(const lv_part_style_t part, const lv_state_t state, const lv_color_t color) {
    _lbl->setStyleTextColor(part, state, color);
}

void LVGLButton::onClicked(buttonCbType cb) {
    _onClickedCb = cb;
}

void LVGLButton::onLongPressed(buttonCbType cb) {
    _onLongPressedCb = cb;
}

void LVGLButton::onLongPressedRepeat(buttonCbType cb) {
    _onLongPressedRepeatCb = cb;
}

void LVGLButton::disable() {
    setState(LV_STATE_DISABLED);
    _lbl->setState(LV_STATE_DISABLED);
}

void LVGLButton::enable() {
    setState(LV_BTN_STATE_RELEASED);
    _lbl->setState(LV_STATE_DEFAULT);
}