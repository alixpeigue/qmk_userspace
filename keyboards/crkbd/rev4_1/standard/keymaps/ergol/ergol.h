#pragma once

#include QMK_KEYBOARD_H
#include "keymap_french.h"

/*
 * Ergo-L keymap, using the Qwerty-Lafayette implementation: the host runs
 * the French AZERTY layout, "oss" variant (`fr(oss)`, "French (alt.)"),
 * and every key sends the AZERTY keycode that produces the Ergo-L
 * character for that position.
 *
 * In Hyprland:  input.kb_layout = "fr",  input.kb_variant = "oss"
 *
 * Letters, symbols and accents are Ergo-L's; the navigation, window-manager
 * and management layers, the thumb keys and the four extra keys (and the
 * Shift/Meta swap) are the Lafayette keymap's.
 */

enum layers {
    DEF,  // Ergo-L base layer
    SYM,  // Ergo-L symbols (AltGr)
    SYM4, // Shift+AltGr: dead keys and extra symbols (Lafayette level 4)
    NUM,  // Numbers, function keys and navigation
    DK,   // Typography latch (Ergo-L's star key)
    WM,   // Window-manager layer (Hyprland, Meta-based bindings)
    MGT,  // Management: bootloader, EEPROM reset, RGB matrix
};

enum ergol_keycodes {
    // Punctuation whose shifted form differs from AZERTY's.
    EG_APOS = SAFE_RANGE, // ' / "
    EG_COMM,              // , / ;
    EG_DOT,               // . / :
    EG_SLSH,              // / / ?
    EG_COLON,             // : (always, even with Shift held)
    EG_MINS,              // - / ?

    // Dead keys, in the same order as the DKID_* identifiers in dead_keys.h.
    EG_DK_CIRC,
    EG_DK_ACUTE,
    EG_DK_GRAVE,
    EG_DK_TILDE,
    EG_DK_DIAE,
    EG_DK_CEDIL,
    EG_DK_CARON,
    EG_DK_OGO,
    EG_DK_RING,
    EG_DK_DOT,
    EG_DK_MAC,
    EG_DK_BREVE,
    EG_DK_DA,
    EG_DK_CB,
    EG_DK_STK,
    EG_DK_CURR,

    // Level 5 (OneDeadKey latch) precomposed characters, lowercase/uppercase.
    EG_L5_AE,       // æ Æ
    EG_L5_EACU,     // é É
    EG_L5_EGRV,     // è È
    EG_L5_UGRV,     // ù Ù
    EG_L5_IDIA,     // ï Ï
    EG_L5_OE,       // œ Œ
    EG_L5_AGRV,     // à À
    EG_L5_SS,       // ß ẞ
    EG_L5_ECRC,     // ê Ê
    EG_L5_MINS,     // - ª
    EG_L5_NDASH,   // – –
    EG_L5_YCRC,     // ŷ Ŷ
    EG_L5_UCRC,     // û Û
    EG_L5_ICRC,     // î Î
    EG_L5_OCRC,     // ô Ô
    EG_L5_ACRC,     // â Â
    EG_L5_TIMES,    // × ×
    EG_L5_CCED,     // ç Ç
    EG_L5_UNDS,     // _ _
    EG_L5_MDASH,   // — —
    EG_L5_NTLD,     // ñ Ñ
    EG_L5_MICRO,    // µ º
    EG_L5_MDOT,     // · •
    EG_L5_ELL, // … …
    EG_L5_IQUE,     // ¿ ÷
    EG_L5_RSQUO,    // ’ ’

    // Level 4 symbols with no direct AZERTY keycode (sent with Unicode).
    EG_U_LTEQ,      // ≤
    EG_U_GTEQ,      // ≥
    EG_U_MIL,  // ‰
    EG_U_TIMES,     // ×
    EG_U_SUPLP,     // ⁽
    EG_U_SUPRP,     // ⁾
    EG_U_NEQ,       // ≠
    EG_U_PM, // ±
    EG_U_DIV,       // ÷
    EG_U_ENDASH,    // –
    EG_U_BAR, // ¦
    EG_U_NOT,       // ¬
};

#define EG_L5_FIRST EG_L5_AE
#define EG_L5_LAST EG_L5_RSQUO
#define EG_U_FIRST EG_U_LTEQ
#define EG_U_LAST EG_U_NOT

// Literal circumflex: AltGr+9 on AZERTY.
#define EG_CIRC ALGR(FR_CCED)

// Window-manager layer.  These replay the combinations bound in
// ~/.config/hypr/hyprland.lua with mainMod = SUPER.
//
// Workspaces are bound to the *unshifted* AZERTY digit keys, i.e.
// SUPER + &, SUPER + eacute, ... SUPER + agrave.  Shift (held physically)
// turns them into "move the window to workspace N", as in the config.
#define WM_WS_1 LGUI(FR_AMPR)  // SUPER + &   -> workspace 1
#define WM_WS_2 LGUI(FR_EACU)  // SUPER + é   -> workspace 2
#define WM_WS_3 LGUI(FR_DQUO)  // SUPER + "   -> workspace 3
#define WM_WS_4 LGUI(FR_QUOT)  // SUPER + '   -> workspace 4
#define WM_WS_5 LGUI(FR_LPRN)  // SUPER + (   -> workspace 5
#define WM_WS_6 LGUI(FR_MINS)  // SUPER + -   -> workspace 6
#define WM_WS_7 LGUI(FR_EGRV)  // SUPER + è   -> workspace 7
#define WM_WS_8 LGUI(FR_UNDS)  // SUPER + _   -> workspace 8
#define WM_WS_9 LGUI(FR_CCED)  // SUPER + ç   -> workspace 9
#define WM_WS_10 LGUI(FR_AGRV) // SUPER + à   -> workspace 10

#define WM_LEFT LGUI(FR_H)  // SUPER + h: focus left  (Shift: move, Ctrl: resize)
#define WM_DOWN LGUI(FR_J)  // SUPER + j: focus down
#define WM_UP LGUI(FR_K)    // SUPER + k: focus up
#define WM_RIGHT LGUI(FR_L) // SUPER + l: focus right

#define WM_MONITOR LGUI(FR_A)   // SUPER + a: focus next monitor
#define WM_FLOAT LGUI(FR_F)     // SUPER + f: toggle floating (Shift: fullscreen)
#define WM_CLOSE LGUI(FR_C)     // SUPER + c: close window
#define WM_CLIP LGUI(FR_V) // SUPER + v: clipboard history

// Application shortcuts (so the Meta key is not needed any more).
#define WM_TERM LGUI(FR_Q)       // SUPER + q: terminal (Shift: terminal in cwd)
#define WM_FILES LGUI(FR_E)      // SUPER + e: file manager
#define WM_BROWSER LGUI(FR_I)    // SUPER + i: browser
#define WM_LAUNCHER LGUI(FR_R)   // SUPER + r: launcher
#define WM_DISPLAY LGUI(FR_P)    // SUPER + p: display mode menu
#define WM_POWER LGUI(FR_M)      // SUPER + m: power menu
#define WM_SHOT LGUI(LALT(FR_S)) // SUPER + ALT + s: region screenshot

// Enter on the right inner thumb; hold it for the WM layer.
#define EG_ENT LT(WM, KC_ENT)

// Keycode that starts Unicode input on Linux (IBus/GTK).
#define EG_UNICODE_START LCTL(LSFT(KC_U))
#define EG_UNICODE_DELAY 20
