/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "keymap_us.h"
#define AZERTY

#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KF_Q,    KF_C,    KF_O,    KF_P,    KF_W,                         KF_J,    KF_M,    KF_D,OSL(SPC),    KF_Y, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,    KF_A,    KF_S,    KF_E,    KF_N,    KF_F,                         KF_L,    KF_R,    KF_T,    KF_I,    KF_U,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KF_W,    KF_X, KF_QUES,    KF_V,    KF_B,                      KF_COLN,    KF_H,    KF_G, KF_SCLN,    KF_K, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, KC_LCTL, KC_LGUI,    MO(NAV),  KC_SPC, MO(SYM)
                                      //`--------------------------'  `--------------------------'

  ),

    [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KF_CIRC, KF_LABK, KF_RABK,  KF_DLR, KF_PERC,                        KF_AT, KF_AMPR, KF_ASTR, KF_QUOT,  KF_GRV, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KF_LCBR, KF_LPRN, KF_RPRN, KF_RCBR,  KF_EQL,                      KF_BSLS, KF_PLUS, KF_MINS, KF_SLSH, KF_DQUO, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KF_TILD, KF_LBRC, KF_RBRC, KF_UNDS, KF_HASH,                      KF_PIPE, KF_EXLM, KF_SCLN, KF_COLN, KF_QUES, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,  KC_TAB, XXXXXXX,   KC_UP, XXXXXXX, KC_PGUP,                      KF_SLSH,    KF_7,    KF_8,    KF_9, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGDN,                      KF_MINS,    KF_4,    KF_5,    KF_6,    KF_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QK_BOOT, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,                      KF_COMM,    KF_1,    KF_2,    KF_3,  KF_DOT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [SPC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KF_ACRC, KF_CCED,   KF_OE, KF_OCRC, XXXXXXX,                      XXXXXXX, KF_MICR, XXXXXXX, KF_DIAE, KF_UCRC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KF_AGRV, KF_EACU, KF_EGRV, KF_ECRC, KF_NTLD,                      KF_LPRN, KF_RPRN, KF_ICRC, KF_IDIA, KF_UGRV, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [WM] = LAYOUT_split_3x6_3(
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    WM_1,    WM_2,    WM_3,    WM_4,    WM_5,                         WM_6,    WM_7,    WM_8,    WM_9, KF_UCRC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  WM_MT1,  WM_MT2,  WM_MT3,  WM_MT4,  WM_MT5,                       WM_MT6,  WM_MT7,  WM_MT8,  WM_MT9, KF_UGRV, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

bool nav_held = false;
bool lgui_held = false;

bool is_spc_active(void) {
    return layer_state_is(SPC) || layer_state_cmp(layer_state, SPC);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (nav_held && lgui_held) {
        state |= (1UL << WM);
    } else {
        state &= ~(1UL << WM);
    }
    return state;
}

bool left_shift = false;
bool right_shift = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // --- Track Shift keys ---
    if (keycode == KC_LSFT) {
        left_shift = record->event.pressed;
    } else if (keycode == KC_RSFT) {
        right_shift = record->event.pressed;
    }

    if (keycode == KC_LSFT) left_shift = record->event.pressed;
    if (keycode == KC_RSFT) right_shift = record->event.pressed;
    bool shift_active = left_shift || right_shift;


    // --- Precomposed accented letters ---
    switch (keycode) {
        case KF_ACRC:  // â / Â
            if (record->event.pressed) {
                if (shift_active) {
                    register_code(KC_LSFT);
                    tap_code(KC_A);
                    unregister_code(KC_LSFT);
                } else {
                    tap_code(KC_A);
                }
            }
            return false;
    }

    return true;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
