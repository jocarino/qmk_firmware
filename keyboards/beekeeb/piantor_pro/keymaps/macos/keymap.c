// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(0,KC_COMM):     // ,<
            if (!record->tap.count && record->event.pressed) {
                tap_code16(S(KC_COMM)); 
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_DOT):     // .>
            if (!record->tap.count && record->event.pressed) {
                tap_code16(S(KC_DOT)); // Intercept hold function to send Ctrl-C
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_SLSH): // /?
            if (!record->tap.count && record->event.pressed) {
                tap_code16(S(KC_SLSH)); 
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(2,KC_NUBS): // \|
            if (!record->tap.count && record->event.pressed) {
                tap_code16(S(KC_NUBS));
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_SCLN): // ;:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(S(KC_SCLN));
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(2,KC_NUHS): // #~
            if (!record->tap.count && record->event.pressed) {
                tap_code16(S(KC_NUHS));
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_QUOT): // '@
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_QUOT); // Intercept tap function to send '
            } else if (record->event.pressed) {
                tap_code16(S(KC_QUOT)); // Intercept hold function to send @
            }
            return false;
        case LT(1,KC_QUOT): // '@
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_QUOT); // Intercept tap function to send '
            } else if (record->event.pressed) {
                tap_code16(S(KC_QUOT)); // Intercept hold function to send @
            }
            return false;
        case LT(1,KC_MINS): // -_
            if (!record->tap.count && record->event.pressed) {
                tap_code16(S(KC_MINS));
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(1,KC_EQL): // =+
            if (!record->tap.count && record->event.pressed) {
                tap_code16(S(KC_EQL));
                return false;
            }
            return true;
    }   
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {          
        [0] = LAYOUT_split_3x6_3(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,               KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL,
        KC_LALT, KC_A, KC_S, KC_D, KC_F, KC_G,              KC_H, KC_J, KC_K, KC_L, LT(0,KC_SCLN), LT(0,KC_QUOT),
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,              KC_N, KC_M, LT(0,KC_COMM), LT(0,KC_DOT), LT(0,KC_SLSH), KC_ESC,
                    KC_LSFT, HYPR_T(KC_SPC), MO(1), MO(2), LGUI_T(KC_ENT), KC_BSPC
        ),
        [1] = LAYOUT_split_3x6_3(
        KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                    KC_CIRC, KC_AMPR, KC_PAST, LT(1,KC_MINS), LT(1,KC_EQL), LALT(KC_BSPC),
        KC_LALT, LGUI(KC_A), LGUI(KC_S), KC_TAB, KC_LALT, KC_LSFT,               KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, LT(1,KC_QUOT), KC_HASH,
        KC_LCTL, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LALT(KC_SPC),     KC_NO, KC_HOME, KC_END, KC_PGUP, KC_PGDN, KC_NO,
                                            KC_LSFT, KC_SPC, KC_NO, MO(3), KC_ESC, KC_LGUI
        ),
        [2] = LAYOUT_split_3x6_3(
        KC_TAB, KC_GRV, KC_1, KC_2, KC_3, KC_NO,                 KC_NO, KC_LCBR, KC_RCBR, KC_NO, KC_NO, KC_NO,
        KC_LALT, LT(2,KC_NUHS), KC_4, KC_5, KC_6, KC_NO,          KC_NO, KC_LPRN, KC_RPRN, KC_NO, KC_NO, KC_NO,
        KC_LCTL, LT(2,KC_NUBS), KC_7, KC_8, KC_9, KC_0,           KC_NO, KC_LBRC, KC_RBRC, KC_COMM, KC_GT, KC_NO,
                                 KC_LSFT, KC_SPC, MO(3), KC_NO, KC_ESC, KC_LALT
        ),
        [3] = LAYOUT_split_3x6_3(
        QK_BOOT, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO,             KC_WH_U, KC_BRIU,      KC_MNXT, KC_VOLU, KC_PSCR, KC_NO,
        KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO,               KC_WH_D, LGUI(KC_ENT), KC_MSTP, KC_MUTE, KC_NO, KC_NO, 
        KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,            KC_NO,   KC_BRID,      KC_MPRV, KC_VOLD, KC_NO, KC_NO,
                                KC_LSFT, KC_SPC, KC_NO, KC_NO, KC_ESC, KC_LALT
        )                                                              
};
                                                                        
// #if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)              
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {  
                                                                        
// };                                                                      
// #endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)        
                                                                        
                                                                        
                                                                        
                                                                        

