// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

/*
 * Custom tap/hold handlers
 * ------------------------
 * This keymap uses the LT(layer, kc) Layer-Tap construct as a trick to build
 * custom "tap = kc, hold = something else" behaviour on non-alpha keys.
 *
 *   - LT(0, kc):   tap sends `kc`; hold sends the shifted version of `kc`.
 *                  Layer 0 is the base layer, so the "layer switch" part of
 *                  LT is a no-op and we only use the tap/hold discrimination
 *                  that QMK gives us for free (`record->tap.count`).
 *
 *   - LT(1, kc) / LT(2, kc): tap sends `kc` (or a custom tap), hold sends a
 *                  custom symbol. Used as a pure tap/hold handler: both the
 *                  hold press and the hold release are swallowed, otherwise
 *                  QMK would layer_off() on release and drop the layer while
 *                  its MO key is still held.
 *
 * When `record->tap.count == 0` the key was held past TAPPING_TERM (200 ms,
 * see config.h) and we emit the "hold" action ourselves via tap_code16().
 * Returning `false` tells QMK to skip its default handling for that event.
 * Returning `true` lets QMK handle the tap normally (send `kc`).
 *
 * Note on macOS mappings used below:
 *   - LGUI = Command (⌘), LALT = Option (⌥), LCTL = Control (⌃), LSFT = Shift (⇧)
 *   - LALT(KC_3)   sends `#` on the macOS UK layout (Option+3)
 *   - S(KC_GRAVE)  sends `~` on the US layout; paired with KC_NUHS so the
 *                  same physical key gives `#` on tap and `~` on hold when
 *                  switching between US and ISO layouts at the OS level.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(0,KC_COMM):     // ,<
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(S(KC_COMM)); 
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_DOT):     // .>
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(S(KC_DOT)); 
                return false;
            }
            return true;
        case LT(0,KC_SLSH): // /?
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(S(KC_SLSH)); 
                return false;
            }
            return true;
        case LT(2,KC_BSLS): // pipe/backslash
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(KC_BSLS); // Hold sends backslash
                return false;
            }
            // For tap, we need to send the shifted version (pipe)
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_BSLS)); // Tap sends pipe
                return false;
            }
            return true;
        case LT(0,KC_SCLN): // ;:
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(S(KC_SCLN));
                return false;
            }
            return true;
        case LT(2,KC_NUHS): // #~
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(S(KC_GRAVE)); // Hold sends tilde
                return false;
            }
            // For tap, we need to send the shifted version (hash)
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_NUHS); // Tap sends hash
                return false;
            }
            return true;
        case LT(0,KC_QUOT): // '"
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(S(KC_QUOT)); 
                return false;
            }
            return true;
        case LT(1,KC_QUOT): // '"
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(S(KC_QUOT)); 
                return false;
            }
            return true;
        case LT(1,KC_MINS): // -_
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(S(KC_MINS));
                return false;
            }
            return true;
        case LT(1,KC_EQL): // =+
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(S(KC_EQL));
                return false;
            }
            return true;
        case LT(2,KC_1): // Press -> 1 ; hold CMD+1
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(LGUI(KC_1));
                return false;
            }
            return true;
        case LT(2,KC_2): // Press -> 2 ; hold CMD+2
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(LGUI(KC_2));
                return false;
            }
            return true;
        case LT(2,KC_3): // Press -> 3 ; hold CMD+3
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(LGUI(KC_3));
                return false;
            }
            return true;
        case LT(2,KC_4): // Press -> 4 ; hold CMD+4
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(LGUI(KC_4));
                return false;
            }
            return true;
        case LT(2,KC_5): // Press -> 5 ; hold CMD+5
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(LGUI(KC_5));
                return false;
            }
            return true;
        case LT(2,KC_6): // Press -> 6 ; hold CMD+6
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(LGUI(KC_6));
                return false;
            }
            return true;
        case LT(2,KC_7): // Press -> 7 ; hold CMD+7
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(LGUI(KC_7));
                return false;
            }
            return true;
        case LT(2,KC_8): // Press -> 8 ; hold CMD+8
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(LGUI(KC_8));
                return false;
            }
            return true;
        case LT(2,KC_9): // Press -> 9 ; hold CMD+9
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(LGUI(KC_9));
                return false;
            }
            return true;
        case LT(2,KC_0): // Press -> 0 ; hold CMD+0
            if (!record->tap.count) {
                if (record->event.pressed) tap_code16(LGUI(KC_0));
                return false;
            }
            return true;
    }   
    return true;
}

/*
 * Flow Tap (FLOW_TAP_TERM, see config.h)
 * -------------------------------------
 * While typing, a thumb mod-tap pressed right after another key is always a
 * tap. This stops fast "space, letter" / "enter, letter" overlaps from firing
 * Hyper+letter or Cmd+letter under PERMISSIVE_HOLD. Only the two thumb keys
 * opt in: the punctuation and number tap/hold keys above must still resolve
 * as holds straight after a letter (e.g. `word:`).
 */
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
    switch (keycode) {
        case HYPR_T(KC_SPC):
        case LGUI_T(KC_ENT):
            if (is_flow_tap_key(prev_keycode)) {
                return FLOW_TAP_TERM;
            }
    }
    return 0;
}

/*
 * Layer overview
 * --------------
 *   [0] Base     : QWERTY alphas + shifted punctuation via LT(0, kc) tricks.
 *   [1] Sym/Nav  : shifted number-row symbols, arrow cluster, macOS clipboard
 *                  shortcuts (⌘A/S/Z/X/C/V) on the home row.
 *   [2] Num/Mac  : number row, macOS zoom (⌘+/⌘-), screenshot shortcuts
 *                  (⌘⇧5, ⌘⇧⌃4), brackets, parentheses and arithmetic operators,
 *                  plus ⌘1…⌘0 on hold for fast tab/space switching in
 *                  Safari/Finder/etc.
 *   [3] Fn/Media : F1–F12, media transport, brightness, volume, boot.
 *
 * Layer 3 is reached via the "tri-layer" pattern: on layers [1] and [2] the
 * other layer's MO key is rebound to MO(3), so holding MO(1)+MO(2) together
 * (in either order) activates layer [3].
 *
 * Legend for the row diagrams below:
 *   ⌘ = Cmd / LGUI     ⌥ = Opt / LALT     ⌃ = Ctl / LCTL     ⇧ = Shft / LSFT
 *   `x/y` on a key = tap sends `x`, hold sends `y` (custom LT handler above)
 *   `x (hold)`     = mod-tap / layer-tap where hold has a modifier role
 *   ·               = KC_NO (disabled / transparent-style no-op)
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        /* Base layer — QWERTY for macOS
         * ,-----------------------------------------.                ,-----------------------------------------.
         * | Tab  |  Q  |  W  |  E  |  R  |  T       |                |  Y  |  U  |  I  |  O  |  P  |  Del     |
         * | Fn*  |  A  |  S  |  D  |  F  |  G       |                |  H  |  J  |  K  |  L  | ; : | ' "      |
         * | Ctl  |  Z  |  X  |  C  |  V  |  B       |                |  N  |  M  | , < | . > | / ? | Cmd      |
         * `------------------+------+------+--------'                `------+------+------+-----------------'
         *             Shft | Spc/Hypr | MO(Sym)    MO(Num) | Ent/Cmd | Bspc
         */
        [0] = LAYOUT_split_3x6_3(
        //  Tab  |  Q   |  W   |  E   |  R   |  T                      Y   |  U   |  I   |  O   |  P   |  Del
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,               KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL,
        //  Cmd   |  A   |  S   |  D   |  F   |  G                      H   |  J   |  K   |  L   | ;/:  |  '/"
        KC_LGUI, KC_A, KC_S, KC_D, KC_F, KC_G,              KC_H, KC_J, KC_K, KC_L, LT(0,KC_SCLN), LT(0,KC_QUOT),
        //  Ctl  |  Z   |  X   |  C   |  V   |  B                      N   |  M   | ,/<  | ./>  | //?  |  Cmd
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,              KC_N, KC_M, LT(0,KC_COMM), LT(0,KC_DOT), LT(0,KC_SLSH), KC_LGUI,
        //              Shft  | Spc/Hypr | MO(Sym)           MO(Num) | Ent/Cmd | Bspc
                    KC_LSFT, HYPR_T(KC_SPC), MO(1), MO(2), LGUI_T(KC_ENT), KC_BSPC
        ),

        /* Symbols & navigation layer — activated by holding MO(1)
         * ,-----------------------------------------.                ,-----------------------------------------.
         * | Tab  |  !  |  @  |  #  |  $  |  %       |                |  ^  |  &  |  *  | - _ | = + | ⌥⌫(delW) |
         * | Cmd  | ⌘A  | ⌘S  | Tab | Opt | Shft     |                |  ←  |  ↓  |  ↑  |  →  | ' " | ⌥3 (UK#) |
         * | Ctl  | ⌘Z  | ⌘X  | ⌘C  | ⌘V  | ⌥Spc     |                |  ·  | Home| End | PgUp| PgDn|  ·       |
         * `------------------+------+------+--------'                `------+------+------+-----------------'
         *             Shft | Cmd | (self)             MO(3) | Esc | Cmd
         *
         */
        [1] = LAYOUT_split_3x6_3(
        //  Tab  |  !  |  @  |  #   |  $   |  %                       ^   |  &   |  *   | -/_   | =/+   | ⌥⌫ (delete word)
        KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, LT(1,KC_MINS), LT(1,KC_EQL), LALT(KC_BSPC),
        //  Cmd  | ⌘A  | ⌘S  | Tab  | Opt  | Shft                     ←   |  ↓   |  ↑   |  →    | '/"   | ⌥3 (UK `#`)
        KC_LGUI, LGUI(KC_A), LGUI(KC_S), KC_TAB, KC_LALT, KC_LSFT,               KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, LT(1,KC_QUOT), LALT(KC_3),
        //  Ctl  | ⌘Z  | ⌘X  | ⌘C   | ⌘V   | ⌥Spc (nb-sp)             ·   | Home | End  | PgUp  | PgDn  |  ·
        KC_LCTL, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LALT(KC_SPC),     KC_NO, KC_HOME, KC_END, KC_PGUP, KC_PGDN, KC_NO,
        //                   Shft | Cmd | (self/·)               MO(3) | Esc | Cmd
                                            KC_LSFT, KC_LGUI, KC_NO, MO(3), KC_ESC, KC_LGUI
        ),

        /* Numbers & macOS shortcuts layer — activated by holding MO(2)
         * ,-----------------------------------------.                ,-----------------------------------------.
         * | Tab  |  `  | 1⌘1 | 2⌘2 | 3⌘3 |  ⌘=      |                | ⌘⇧5 |  {  |  }  |  -  |  =  |  ·       |
         * | Cmd  | #/~ | 4⌘4 | 5⌘5 | 6⌘6 |  ⌘-      |                |⌘⇧⌃4 |  (  |  )  |  +  |  *  |  /       |
         * | Ctl  | \|  | 7⌘7 | 8⌘8 | 9⌘9 |  0⌘0     |                |  ·  |  [  |  ]  |  ,  |  .  |  ·       |
         * `------------------+------+------+--------'                `------+------+------+-----------------'
         *             Shft | ⌘⌥ | MO(3)              (self) | Esc | Opt
         *
         */
        [2] = LAYOUT_split_3x6_3(
        //  Tab   |  `    | 1/⌘1       | 2/⌘2       | 3/⌘3       | ⌘= (zoom)        ⌘⇧5 (screenshot)   |  {    |  }    |  -   |  =   |  ·
        KC_TAB, KC_GRV, LT(2,KC_1), LT(2,KC_2), LT(2,KC_3), LGUI(KC_EQL),                  LGUI(LSFT(KC_5)), KC_LCBR, KC_RCBR, KC_MINS, KC_EQL, KC_NO,
        //  Cmd   | #/~   | 4/⌘4       | 5/⌘5       | 6/⌘6       | ⌘- (zoom)        ⌘⇧⌃4 (snip→clip)   |  (    |  )    |  +   |  *   |  /
        KC_LGUI, LT(2,KC_NUHS), LT(2,KC_4), LT(2,KC_5), LT(2,KC_6), LGUI(KC_MINS),          LGUI(LSFT(LCTL(KC_4))), KC_LPRN, KC_RPRN, KC_PLUS, KC_ASTR, KC_SLSH,
        //  Ctl   | \ / | | 7/⌘7       | 8/⌘8       | 9/⌘9       | 0/⌘0                  ·             |  [    |  ]    |  ,   |  .   |  ·
        KC_LCTL, LT(2,KC_BSLS), LT(2,KC_7), LT(2,KC_8), LT(2,KC_9), LT(2,KC_0),           KC_NO, KC_LBRC, KC_RBRC, KC_COMM, KC_DOT, KC_NO,
        //                        Shft | ⌘⌥ | MO(3)                            (self/·) | Esc | Opt
                                 KC_LSFT, LGUI(KC_LALT), MO(3), KC_NO, KC_ESC, KC_LALT
        ),

        /* Function / media / system layer — reached via MO(1)+MO(2)
         * ,-----------------------------------------.                ,-----------------------------------------.
         * | Boot |  F1 |  F2 |  F3 |  F4 |  ·       |                | WhUp| Bri+| Next| Vol+| PScr|  ·       |
         * |  ·   |  F5 |  F6 |  F7 |  F8 |  ·       |                | WhDn| ⌘Ent| Play| Mute|  ·  |  ·       |
         * |  ·   |  F9 | F10 | F11 | F12 |  ·       |                |  ·  | Bri-| Prev| Vol-|  ·  |  ·       |
         * `------------------+------+------+--------'                `------+------+------+-----------------'
         *             Shft | Spc |  ·                  ·  | Esc | Opt
         *
         */
        [3] = LAYOUT_split_3x6_3(
        //  Boot  |  F1   |  F2   |  F3   |  F4   |  ·                     WhUp  | Bri+  | Next  | Vol+  | PScr |  ·
        QK_BOOT, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO,             MS_WHLU, KC_BRIU,      KC_MNXT, KC_VOLU, KC_PSCR, KC_NO,
        //  ·     |  F5   |  F6   |  F7   |  F8   |  ·                     WhDn  | ⌘Ent  | Play  | Mute  |  ·   |  ·
        KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO,               MS_WHLD, LGUI(KC_ENT), KC_MPLY, KC_MUTE, KC_NO, KC_NO, 
        //  ·     |  F9   | F10   | F11   | F12   |  ·                       ·   | Bri-  | Prev  | Vol-  |  ·   |  ·
        KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,            KC_NO,   KC_BRID,      KC_MPRV, KC_VOLD, KC_NO, KC_NO,
        //                       Shft | Spc |  ·                 ·  | Esc | Opt
                                KC_LSFT, KC_SPC, KC_NO, KC_NO, KC_ESC, KC_LALT
        )                                                              
};
