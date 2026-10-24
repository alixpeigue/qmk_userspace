#pragma once

#include QMK_KEYBOARD_H
#include "keymap_french.h"

/*
 * This keymap targets a host configured with the French AZERTY layout,
 * "oss" variant (`fr(oss)`, "French (alt.)").  It has the same letter and
 * AltGr basics as the classic layout, but it also provides native keys for
 * all the Lafayette characters (É, È, œ, ≤, ≥, ≠, …, —, etc.).
 *
 * In Hyprland:  input.kb_layout = "fr",  input.kb_variant = "oss"
 *
 * Every key sends the AZERTY keycode that produces the Qwerty-Lafayette
 * character for that position.
 */

enum layers {
    DEF,  // Qwerty-Lafayette base layer
    SYM,  // Qwerty-Lafayette AltGr (level 3)
    SYM4, // Qwerty-Lafayette Shift+AltGr (level 4)
    NUM,  // Numbers, function keys and navigation
    DK,   // OneDeadKey latch (level 5)
    WM,   // Window-manager layer (Hyprland, Meta-based bindings)
    MGT,  // Management: bootloader, EEPROM reset, RGB matrix
};

enum lafayette_keycodes {
    // Punctuation whose shifted form differs from AZERTY's.
    LF_APOS = SAFE_RANGE, // ' / "
    LF_COMM,              // , / ;
    LF_DOT,               // . / :
    LF_SLSH,              // / / ?
    LF_COLON,             // : (always, even with Shift held)

    // Dead keys, in the same order as the DKID_* identifiers in dead_keys.h.
    LF_DK_CIRC,
    LF_DK_ACUTE,
    LF_DK_GRAVE,
    LF_DK_TILDE,
    LF_DK_DIAE,
    LF_DK_CEDIL,
    LF_DK_CARON,
    LF_DK_OGO,
    LF_DK_RING,
    LF_DK_DOT,
    LF_DK_MAC,
    LF_DK_BREVE,
    LF_DK_DA,
    LF_DK_CB,
    LF_DK_STK,
    LF_DK_CURR,

    // Level 5 (OneDeadKey latch) precomposed characters, lowercase/uppercase.
    LF_L5_AE,       // æ Æ
    LF_L5_EACU,     // é É
    LF_L5_EGRV,     // è È
    LF_L5_UGRV,     // ù Ù
    LF_L5_IDIA,     // ï Ï
    LF_L5_OE,       // œ Œ
    LF_L5_AGRV,     // à À
    LF_L5_SS,       // ß ẞ
    LF_L5_ECRC,     // ê Ê
    LF_L5_MINS,     // - ª
    LF_L5_NDASH,   // – –
    LF_L5_YCRC,     // ŷ Ŷ
    LF_L5_UCRC,     // û Û
    LF_L5_ICRC,     // î Î
    LF_L5_OCRC,     // ô Ô
    LF_L5_ACRC,     // â Â
    LF_L5_TIMES,    // × ×
    LF_L5_CCED,     // ç Ç
    LF_L5_UNDS,     // _ _
    LF_L5_MDASH,   // — —
    LF_L5_NTLD,     // ñ Ñ
    LF_L5_MICRO,    // µ º
    LF_L5_MDOT,     // · •
    LF_L5_ELL, // … …
    LF_L5_IQUE,     // ¿ ÷
    LF_L5_RSQUO,    // ’ ’

    // Level 4 symbols with no direct AZERTY keycode (sent with Unicode).
    LF_U_LTEQ,      // ≤
    LF_U_GTEQ,      // ≥
    LF_U_MIL,  // ‰
    LF_U_TIMES,     // ×
    LF_U_SUPLP,     // ⁽
    LF_U_SUPRP,     // ⁾
    LF_U_NEQ,       // ≠
    LF_U_PM, // ±
    LF_U_DIV,       // ÷
    LF_U_ENDASH,    // –
    LF_U_BAR, // ¦
    LF_U_NOT,       // ¬
};

#define LF_L5_FIRST LF_L5_AE
#define LF_L5_LAST LF_L5_RSQUO
#define LF_U_FIRST LF_U_LTEQ
#define LF_U_LAST LF_U_NOT

// Literal circumflex: AltGr+9 on AZERTY.
#define LF_CIRC ALGR(FR_CCED)

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
#define LF_ENT LT(WM, KC_ENT)

// Keycode that starts Unicode input on Linux (IBus/GTK).
#define LF_UNICODE_START LCTL(LSFT(KC_U))
#define LF_UNICODE_DELAY 20
