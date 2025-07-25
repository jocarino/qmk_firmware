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
                tap_code16(S(KC_DOT)); 
                return false;
            }
            return true;
        case LT(0,KC_SLSH): // /?
            if (!record->tap.count && record->event.pressed) {
                tap_code16(S(KC_SLSH)); 
                return false;
            }
            return true;
        case LT(2,KC_BSLS): // pipe/backslash
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_BSLS); // Hold sends backslash
                return false;
            }
            // For tap, we need to send the shifted version (pipe)
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_BSLS)); // Tap sends pipe
                return false;
            }
            return true;
        case LT(0,KC_SCLN): // ;:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(S(KC_SCLN));
                return false;
            }
            return true;
        case LT(2,KC_NUHS): // #~
            if (!record->tap.count && record->event.pressed) {
                tap_code16(S(KC_NUHS));
                return false;
            }
            return true;
        case LT(0,KC_QUOT): // '"
            if (!record->tap.count && record->event.pressed) {
                tap_code16(S(KC_QUOT)); 
                return false;
            }
            return true;
        case LT(1,KC_QUOT): // '"
            if (!record->tap.count && record->event.pressed) {
                tap_code16(S(KC_QUOT)); 
                return false;
            }
            return true;
        case LT(1,KC_MINS): // -_
            if (!record->tap.count && record->event.pressed) {
                tap_code16(S(KC_MINS));
                return false;
            }
            return true;
        case LT(1,KC_EQL): // =+
            if (!record->tap.count && record->event.pressed) {
                tap_code16(S(KC_EQL));
                return false;
            }
            return true;
        case LT(2,KC_1): // Press -> 1 ; hold CMD+1
            if (!record->tap.count && record->event.pressed) {
                tap_code16(LGUI(KC_1));
                return false;
            }
            return true;
        case LT(2,KC_2): // Press -> 2 ; hold CMD+2
            if (!record->tap.count && record->event.pressed) {
                tap_code16(LGUI(KC_2));
                return false;
            }
            return true;
        case LT(2,KC_3): // Press -> 3 ; hold CMD+3
            if (!record->tap.count && record->event.pressed) {
                tap_code16(LGUI(KC_3));
                return false;
            }
            return true;
        case LT(2,KC_4): // Press -> 4 ; hold CMD+4
            if (!record->tap.count && record->event.pressed) {
                tap_code16(LGUI(KC_4));
                return false;
            }
            return true;
        case LT(2,KC_5): // Press -> 5 ; hold CMD+5
            if (!record->tap.count && record->event.pressed) {
                tap_code16(LGUI(KC_5));
                return false;
            }
            return true;
        case LT(2,KC_6): // Press -> 6 ; hold CMD+6
            if (!record->tap.count && record->event.pressed) {
                tap_code16(LGUI(KC_6));
                return false;
            }
            return true;
        case LT(2,KC_7): // Press -> 7 ; hold CMD+7
            if (!record->tap.count && record->event.pressed) {
                tap_code16(LGUI(KC_7));
                return false;
            }
            return true;
        case LT(2,KC_8): // Press -> 8 ; hold CMD+8
            if (!record->tap.count && record->event.pressed) {
                tap_code16(LGUI(KC_8));
                return false;
            }
            return true;
        case LT(2,KC_9): // Press -> 9 ; hold CMD+9
            if (!record->tap.count && record->event.pressed) {
                tap_code16(LGUI(KC_9));
                return false;
            }
            return true;
        case LT(2,KC_0): // Press -> 0 ; hold CMD+0
            if (!record->tap.count && record->event.pressed) {
                tap_code16(LGUI(KC_0));
                return false;
            }
            return true;
    }   
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {          
        [0] = LAYOUT_split_3x6_3(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,               KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL,
        KC_LGUI, KC_A, KC_S, KC_D, KC_F, KC_G,              KC_H, KC_J, KC_K, KC_L, LT(0,KC_SCLN), LT(0,KC_QUOT),
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,              KC_N, KC_M, LT(0,KC_COMM), LT(0,KC_DOT), LT(0,KC_SLSH), KC_LGUI,
                    KC_LSFT, HYPR_T(KC_SPC), MO(1), MO(2), LGUI_T(KC_ENT), KC_BSPC
        ),
        [1] = LAYOUT_split_3x6_3(
        KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                    KC_CIRC, KC_AMPR, KC_PAST, LT(1,KC_MINS), LT(1,KC_EQL), LALT(KC_BSPC),
        KC_LGUI, LGUI(KC_A), LGUI(KC_S), KC_TAB, KC_LALT, KC_LSFT,               KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, LT(1,KC_QUOT), LALT(KC_3),
        KC_LCTL, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LALT(KC_SPC),     KC_NO, KC_HOME, KC_END, KC_PGUP, KC_PGDN, KC_NO,
                                            KC_LSFT, KC_LGUI, KC_NO, MO(3), KC_ESC, KC_LGUI
        ),
        [2] = LAYOUT_split_3x6_3(
        KC_TAB, KC_GRV, LT(2,KC_1), LT(2,KC_2), LT(2,KC_3), LGUI(KC_PLUS),                 LGUI(LSFT(KC_5)), KC_LCBR, KC_RCBR, KC_NO, KC_NO, KC_NO,
        KC_LGUI, LT(2,KC_NUHS), LT(2,KC_4), LT(2,KC_5), LT(2,KC_6), LGUI(KC_MINS),          LGUI(LSFT(LCTL(KC_4))), KC_LPRN, KC_RPRN, KC_NO, KC_NO, KC_NO,
        KC_LCTL, LT(2,KC_BSLS), LT(2,KC_7), LT(2,KC_8), LT(2,KC_9), LT(2,KC_0),           KC_NO, KC_LBRC, KC_RBRC, KC_COMM, KC_GT, KC_NO,
                                 KC_LSFT, LGUI(KC_LALT), MO(3), KC_NO, KC_ESC, KC_LALT
        ),
        [3] = LAYOUT_split_3x6_3(
        QK_BOOT, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO,             KC_WH_U, KC_BRIU,      KC_MNXT, KC_VOLU, KC_PSCR, KC_NO,
        KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO,               KC_WH_D, LGUI(KC_ENT), KC_MSTP, KC_MUTE, KC_NO, KC_NO, 
        KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,            KC_NO,   KC_BRID,      KC_MPRV, KC_VOLD, KC_NO, KC_NO,
                                KC_LSFT, KC_SPC, KC_NO, KC_NO, KC_ESC, KC_LALT
        )                                                              
};
