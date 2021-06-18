#include "LVGLImage.hpp"

LVGLImage::LVGLImage(const lv_img_dsc_t* img,  LVGLBase* const parent)
    :   LVGLBase(lv_img_create(parent? parent->innerData() : lv_disp_get_scr_act(NULL), NULL), parent),
        _img(img) {

    lv_img_set_src(_obj, _img);
    lv_obj_set_style_local_image_recolor_opa(_obj, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_obj_set_style_local_image_recolor(_obj, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    setStyleBgColor(LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_RED);
    setStyleBorderWidth(LV_IMG_PART_MAIN, LV_STATE_DEFAULT, 2);
    // lv_obj_align(_obj, NULL, LV_ALIGN_CENTER, 0, 0);


}

void LVGLImage::zoomOut(const size_t percent) {
    lv_img_set_pivot(_obj, 100, 45);  //To zoom from the left top corner
    lv_img_set_zoom(_obj, 64);
    // lv_img_set_offset_x(_obj, 45); //Select the second image
    // lv_img_set_pivot(_obj, 100, 45);  //To zoom from the left top corner
    lv_obj_set_size(_obj, 150, 80);
}