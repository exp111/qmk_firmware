#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(KC_F13, KC_F14, KC_F15,
               KC_F16, TG(1), KC_F18,
               KC_MRWD, KC_MPLY, KC_MFFD),

  [1] = LAYOUT(RGB_RMOD, RGB_VAI, RGB_MOD,
               RGB_HUI, KC_TRNS, RGB_SAI,
               RGB_HUD, RGB_VAD, RGB_SAD),

};
