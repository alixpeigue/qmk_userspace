#pragma once

#include "azerty_keycodes.h"
#include "wm.h"
#include QMK_KEYBOARD_H

enum Layers { DEF, SYM, NAV, SPC, WM };

enum keycodes {
    // OS_LSFT = SAFE_RANGE,
    // OS_RSFT,
    // OS_LCTL,
    // OS_RCTL,
    // OS_LALT,
    // OS_RALT,
    // OS_LGUI,
    // OS_RGUI,
    // OS_BTN1,
    // OS_BTN2,
    // OS_BTN3,
    NAV_LCK = SAFE_RANGE,
    SW_ESC,
    SW_TAB,
    SW_GRV,
    KC_HSCL,
#ifdef AZERTY
    KF_ACRC,
    KF_ECRC,
    KF_OCRC,
    KF_ICRC,
    KF_UCRC,
    KF_EDIA,
    KF_IDIA,
    KF_UDIA,
#endif
};
