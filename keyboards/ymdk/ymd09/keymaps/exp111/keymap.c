#include QMK_KEYBOARD_H

// Layer Definitions
#define LAYER_BASE 0
#define LAYER_1 1

// Color Definitions (in HSV)
#define CLR_LAYER_1 128, 255, 128
#define CLR_LAYER_2 234, 255, 128


// Default effect (here static)
#define RGB_BASE_EFFECT RGBLIGHT_MODE_STATIC_LIGHT

//FIXME: currently brightness is hardcoded here, maybe read it dynamically in? prolly can't use light layers for that
/* ### Lighting Layers ### */
// Layer 0: Cyan
/*const rgblight_segment_t PROGMEM layer0[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, CLR_LAYER_1}
);*/
// Layer 1: Pink
const rgblight_segment_t PROGMEM layer1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 4, CLR_LAYER_2},
    {5, 4, CLR_LAYER_2}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer1
);

void keyboard_post_init_user(void)
{
    rgblight_enable();
    rgblight_sethsv(CLR_LAYER_1);
    rgblight_mode(RGB_BASE_EFFECT);

    //rgblight_sethsv_range_noeeprom(CLR_LAYER_1, 0, 9);
    //rgblight_mode_noeeprom(RGB_BASE_EFFECT);
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    //rgblight_set_layer_state(0, layer_state_cmp(state, LAYER_BASE));
    rgblight_set_layer_state(0, layer_state_cmp(state, LAYER_1));
    return state;
}

/* ### Keymaps ### */
//TODO: add debug layer with restart and reset?
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [LAYER_BASE] =    LAYOUT(KC_F13, KC_F14, KC_F15,
                    KC_F16, TG(LAYER_1), KC_F18,
                    KC_MRWD, KC_MPLY, KC_MFFD),

  [LAYER_1]     =   LAYOUT(RGB_TOG, RGB_VAI, RGB_MOD,
                    RGB_HUI, KC_TRNS, RGB_SAI,
                    RGB_HUD, RGB_VAD, RGB_SAD),

};
