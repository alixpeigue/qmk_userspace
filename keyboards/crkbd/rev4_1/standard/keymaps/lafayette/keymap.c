/*
Copyright 2024

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

#include "lafayette.h"
#include "dead_keys.h"

/*
 * Qwerty-Lafayette on a 46-key Corne v4.1 (LAYOUT_split_3x6_3_ex2),
 * for a French AZERTY host using the fr(oss) variant.
 *
 * The keymap sends the AZERTY keycodes producing the Lafayette characters;
 * the extra AltGr keys of fr(oss) provide É, È, œ, ≤, ≥, … natively.
 *
 * Base layer (Lafayette levels 1 and 2):
 *
 *   Tab   Q   W   E   R   T  Alt | Bspc  Y   U   I   O   P  Bspc
 *   Esc   A   S   D   F   G  Esc | Ent   H   J   K   L  ODK   '
 *   Meta  Z   X   C   V   B      |       N   M   ,   .   /  RShift
 *            Ctrl Sym Space   Enter/WM Num Shift
 *
 * ODK latches level 5 (accented characters) for the next key; Shift+Sym
 * selects level 4 (dead keys and extra symbols).  Holding Enter activates
 * the window-manager layer, which replays the Hyprland SUPER bindings.
 */

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x6_3_ex2(
  // ,-----------------------------------------------------------------------------. ,-------------------------. ,-----------------------------------------------------------------------------.
      KC_TAB,      FR_Q,        FR_W,        FR_E,        FR_R,        FR_T,          KC_LALT,     KC_BSPC,       FR_Y,        FR_U,        FR_I,        FR_O,        FR_P,        KC_BSPC,
  // |------------+------------+------------+------------+------------+------------| |------------+------------| |------------+------------+------------+------------+------------+------------|
  // ,-----------------------------------------------------------------------------. ,-------------------------. ,-----------------------------------------------------------------------------.
      KC_ESC,      FR_A,        FR_S,        FR_D,        FR_F,        FR_G,          MO(MGT),     MO(MGT),       FR_H,        FR_J,        FR_K,        FR_L,        OSL(DK),     LF_APOS,
  // |------------+------------+------------+------------+------------+------------| |------------+------------| |------------+------------+------------+------------+------------+------------|
  // ,-----------------------------------------------------------------------------.                             ,-----------------------------------------------------------------------------.
      KC_LGUI,     FR_Z,        FR_X,        FR_C,        FR_V,        FR_B,                                      FR_N,        FR_M,        LF_COMM,     LF_DOT,      LF_SLSH,     KC_RSFT,
  // |------------+------------+------------+------------+------------+------------|                             |------------+------------+------------+------------+------------+------------|
                                                        //`--------------------------------------'  `--------------------------------------'
                                                          KC_LCTL,     MO(SYM),     KC_SPC,         LF_ENT,      MO(NUM),     KC_LSFT    // LF_ENT = LT(WM, KC_ENT)
    ),

    [SYM] = LAYOUT_split_3x6_3_ex2(
  // ,-----------------------------------------------------------------------------. ,-------------------------. ,-----------------------------------------------------------------------------.
      _______,     LF_CIRC,     FR_LABK,     FR_RABK,     FR_DLR,      FR_PERC,       _______,     _______,       FR_AT,       FR_AMPR,     FR_ASTR,     FR_QUOT,     FR_GRV,      _______,
  // |------------+------------+------------+------------+------------+------------| |------------+------------| |------------+------------+------------+------------+------------+------------|
  // ,-----------------------------------------------------------------------------. ,-------------------------. ,-----------------------------------------------------------------------------.
      _______,     FR_LCBR,     FR_LPRN,     FR_RPRN,     FR_RCBR,     FR_EQL,        _______,     _______,       FR_BSLS,     FR_PLUS,     FR_MINS,     FR_SLSH,     FR_DQUO,     XXXXXXX,
  // |------------+------------+------------+------------+------------+------------| |------------+------------| |------------+------------+------------+------------+------------+------------|
  // ,-----------------------------------------------------------------------------.                             ,-----------------------------------------------------------------------------.
      _______,     FR_TILD,     FR_LBRC,     FR_RBRC,     FR_UNDS,     FR_HASH,                                   FR_PIPE,     FR_EXLM,     FR_SCLN,     FR_COLN,     FR_QUES,     _______,
  // |------------+------------+------------+------------+------------+------------|                             |------------+------------+------------+------------+------------+------------|
                                                        //`--------------------------------------'  `--------------------------------------'
                                                          _______,     _______,     _______,        _______,     _______,     _______
    ),

    [SYM4] = LAYOUT_split_3x6_3_ex2(
  // ,-----------------------------------------------------------------------------. ,-------------------------. ,-----------------------------------------------------------------------------.
      _______,     LF_DK_CIRC,  LF_U_LTEQ,   LF_U_GTEQ,   LF_DK_CURR,  LF_U_MIL,      _______,     _______,       LF_DK_RING,  XXXXXXX,     LF_U_TIMES,  LF_DK_ACUTE, LF_DK_GRAVE, _______,
  // |------------+------------+------------+------------+------------+------------| |------------+------------| |------------+------------+------------+------------+------------+------------|
  // ,-----------------------------------------------------------------------------. ,-------------------------. ,-----------------------------------------------------------------------------.
      _______,     LF_DK_CARON, LF_U_SUPLP,  LF_U_SUPRP,  LF_DK_DOT,   LF_U_NEQ,      _______,     _______,       LF_DK_STK,   LF_U_PM,     LF_DK_MAC,   LF_U_DIV,    LF_DK_DA,    XXXXXXX,
  // |------------+------------+------------+------------+------------+------------| |------------+------------| |------------+------------+------------+------------+------------+------------|
  // ,-----------------------------------------------------------------------------.                             ,-----------------------------------------------------------------------------.
      _______,     LF_DK_TILDE, LF_DK_CB,    LF_DK_OGO,   LF_U_ENDASH, XXXXXXX,                                   LF_U_BAR,    LF_U_NOT,    LF_DK_CEDIL, LF_COLON,    LF_DK_BREVE, _______,
  // |------------+------------+------------+------------+------------+------------|                             |------------+------------+------------+------------+------------+------------|
                                                        //`--------------------------------------'  `--------------------------------------'
                                                          _______,     _______,     _______,        _______,     _______,     _______
    ),

    [NUM] = LAYOUT_split_3x6_3_ex2(
  // ,-----------------------------------------------------------------------------. ,-------------------------. ,-----------------------------------------------------------------------------.
      FR_1,        FR_2,        FR_3,        FR_4,        FR_5,        FR_6,          _______,     _______,       FR_7,        FR_8,        FR_9,        FR_0,        FR_MINS,     FR_EQL,
  // |------------+------------+------------+------------+------------+------------| |------------+------------| |------------+------------+------------+------------+------------+------------|
  // ,-----------------------------------------------------------------------------. ,-------------------------. ,-----------------------------------------------------------------------------.
      KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_F6,         _______,     _______,       KC_LEFT,     KC_DOWN,     KC_UP,       KC_RIGHT,    KC_HOME,     KC_END,
  // |------------+------------+------------+------------+------------+------------| |------------+------------| |------------+------------+------------+------------+------------+------------|
  // ,-----------------------------------------------------------------------------.                             ,-----------------------------------------------------------------------------.
      KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_F11,      KC_F12,                                    KC_PGUP,     KC_PGDN,     KC_INS,      KC_DEL,      KC_VOLD,     KC_VOLU,
  // |------------+------------+------------+------------+------------+------------|                             |------------+------------+------------+------------+------------+------------|
                                                        //`--------------------------------------'  `--------------------------------------'
                                                          _______,     _______,     _______,        _______,     _______,     KC_MPLY
    ),

    [WM] = LAYOUT_split_3x6_3_ex2(
  // ,-----------------------------------------------------------------------------. ,-------------------------. ,-----------------------------------------------------------------------------.
      _______,     WM_WS_1,     WM_WS_2,     WM_WS_3,     WM_WS_4,     WM_WS_5,       _______,     _______,       WM_WS_6,     WM_WS_7,     WM_WS_8,     WM_WS_9,     WM_WS_10,    _______,
  // |------------+------------+------------+------------+------------+------------| |------------+------------| |------------+------------+------------+------------+------------+------------|
  // ,-----------------------------------------------------------------------------. ,-------------------------. ,-----------------------------------------------------------------------------.
      _______,     WM_MONITOR,  WM_TERM,     WM_FILES,    WM_FLOAT,    WM_BROWSER,    _______,     _______,       WM_LEFT,     WM_DOWN,     WM_UP,       WM_RIGHT,    WM_LAUNCHER, WM_DISPLAY,
  // |------------+------------+------------+------------+------------+------------| |------------+------------| |------------+------------+------------+------------+------------+------------|
  // ,-----------------------------------------------------------------------------.                             ,-----------------------------------------------------------------------------.
      _______,     _______,     _______,     WM_CLOSE,    WM_CLIP,     _______,                                   WM_SHOT,     WM_POWER,    _______,     _______,     _______,     _______,
  // |------------+------------+------------+------------+------------+------------|                             |------------+------------+------------+------------+------------+------------|
                                                        //`--------------------------------------'  `--------------------------------------'
                                                          _______,     _______,     KC_LSFT,        _______,     _______,     _______
    ),

    [DK] = LAYOUT_split_3x6_3_ex2(
  // ,-----------------------------------------------------------------------------. ,-------------------------. ,-----------------------------------------------------------------------------.
      _______,     LF_L5_AE,    LF_L5_EACU,  LF_L5_EGRV,  _______,     _______,       _______,     _______,       _______,     LF_L5_UGRV,  LF_L5_IDIA,  LF_L5_OE,    _______,     _______,
  // |------------+------------+------------+------------+------------+------------| |------------+------------| |------------+------------+------------+------------+------------+------------|
  // ,-----------------------------------------------------------------------------. ,-------------------------. ,-----------------------------------------------------------------------------.
      _______,     LF_L5_AGRV,  LF_L5_SS,    LF_L5_ECRC,  LF_L5_MINS,  LF_L5_NDASH,   _______,     _______,       LF_L5_YCRC,  LF_L5_UCRC,  LF_L5_ICRC,  LF_L5_OCRC,  LF_DK_DIAE,  _______,
  // |------------+------------+------------+------------+------------+------------| |------------+------------| |------------+------------+------------+------------+------------+------------|
  // ,-----------------------------------------------------------------------------.                             ,-----------------------------------------------------------------------------.
      _______,     LF_L5_ACRC,  LF_L5_TIMES, LF_L5_CCED,  LF_L5_UNDS,  LF_L5_MDASH,                               LF_L5_NTLD,  LF_L5_MICRO, LF_L5_MDOT,  LF_L5_ELL,   LF_L5_IQUE,  _______,
  // |------------+------------+------------+------------+------------+------------|                             |------------+------------+------------+------------+------------+------------|
                                                        //`--------------------------------------'  `--------------------------------------'
                                                          _______,     _______,     LF_L5_RSQUO,    _______,     _______,     _______
    ),

    [MGT] = LAYOUT_split_3x6_3_ex2(
  // ,-----------------------------------------------------------------------------. ,-------------------------. ,-----------------------------------------------------------------------------.
      QK_BOOT,     QK_RBT,      EE_CLR,      _______,     _______,     _______,       _______,     _______,       _______,     _______,     _______,     _______,     _______,     _______,
  // |------------+------------+------------+------------+------------+------------| |------------+------------| |------------+------------+------------+------------+------------+------------|
  // ,-----------------------------------------------------------------------------. ,-------------------------. ,-----------------------------------------------------------------------------.
      RM_TOGG,     RM_NEXT,     RM_PREV,     RM_HUEU,     RM_HUED,     RM_SATU,       _______,     _______,       RM_SATD,     RM_VALU,     RM_VALD,     RM_SPDU,     RM_SPDD,     _______,
  // |------------+------------+------------+------------+------------+------------| |------------+------------| |------------+------------+------------+------------+------------+------------|
  // ,-----------------------------------------------------------------------------.                             ,-----------------------------------------------------------------------------.
      _______,     _______,     _______,     _______,     _______,     _______,                                   _______,     _______,     _______,     _______,     _______,     _______,
  // |------------+------------+------------+------------+------------+------------|                             |------------+------------+------------+------------+------------+------------|
                                                        //`--------------------------------------'  `--------------------------------------'
                                                          _______,     _______,     _______,        _______,     _______,     _______
    )
};
// clang-format on

// Level 5 characters, indexed by keycode - LF_L5_FIRST.
static const uint16_t l5_lower[] = {
    0x00E6, // æ
    0x00E9, // é
    0x00E8, // è
    0x00F9, // ù
    0x00EF, // ï
    0x0153, // œ
    0x00E0, // à
    0x00DF, // ß
    0x00EA, // ê
    0x002D, // -
    0x2013, // –
    0x0177, // ŷ
    0x00FB, // û
    0x00EE, // î
    0x00F4, // ô
    0x00E2, // â
    0x00D7, // ×
    0x00E7, // ç
    0x005F, // _
    0x2014, // —
    0x00F1, // ñ
    0x00B5, // µ
    0x00B7, // ·
    0x2026, // …
    0x00BF, // ¿
    0x2019, // ’
};

static const uint16_t l5_upper[] = {
    0x00C6, // Æ
    0x00C9, // É
    0x00C8, // È
    0x00D9, // Ù
    0x00CF, // Ï
    0x0152, // Œ
    0x00C0, // À
    0x1E9E, // ẞ
    0x00CA, // Ê
    0x00AA, // ª
    0x2013, // –
    0x0176, // Ŷ
    0x00DB, // Û
    0x00CE, // Î
    0x00D4, // Ô
    0x00C2, // Â
    0x00D7, // ×
    0x00C7, // Ç
    0x005F, // _
    0x2014, // —
    0x00D1, // Ñ
    0x00BA, // º
    0x2022, // •
    0x2026, // …
    0x00F7, // ÷
    0x2019, // ’
};

// Level 4 symbols, indexed by keycode - LF_U_FIRST.
static const uint16_t l4_symbols[] = {
    0x2264, // ≤
    0x2265, // ≥
    0x2030, // ‰
    0x00D7, // ×
    0x207D, // ⁽
    0x207E, // ⁾
    0x2260, // ≠
    0x00B1, // ±
    0x00F7, // ÷
    0x2013, // –
    0x00A6, // ¦
    0x00AC, // ¬
};

_Static_assert(ARRAY_SIZE(l5_lower) == LF_L5_LAST - LF_L5_FIRST + 1, "l5_lower out of sync");
_Static_assert(ARRAY_SIZE(l5_upper) == LF_L5_LAST - LF_L5_FIRST + 1, "l5_upper out of sync");
_Static_assert(ARRAY_SIZE(l4_symbols) == LF_U_LAST - LF_U_FIRST + 1, "l4_symbols out of sync");

// AZERTY keycodes for the hexadecimal digits used by Unicode input.
static const uint16_t azerty_hex[] = {
    FR_0, FR_1, FR_2, FR_3, FR_4, FR_5, FR_6, FR_7, FR_8, FR_9, FR_A, FR_B, FR_C, FR_D, FR_E, FR_F,
};

static uint16_t pending_dead       = 0;
static uint16_t suppressed_keycode = 0;
static bool     lshift_down        = false;
static bool     rshift_down        = false;

static bool shift_active(void) {
    return (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
}

static bool is_dead_key(uint16_t keycode) {
    return keycode >= LF_DK_CIRC && keycode <= LF_DK_CURR;
}

static uint8_t dead_id_for(uint16_t keycode) {
    return (uint8_t)(keycode - LF_DK_CIRC);
}

// Keys that should not cancel a pending dead key.
static bool keeps_dead_key_pending(uint16_t keycode) {
    return IS_MODIFIER_KEYCODE(keycode) || IS_QK_MOMENTARY(keycode) || IS_QK_ONE_SHOT_LAYER(keycode) || IS_QK_ONE_SHOT_MOD(keycode) || IS_QK_LAYER_TAP(keycode) || IS_QK_LAYER_MOD(keycode) || IS_QK_TOGGLE_LAYER(keycode) || IS_QK_LAYER_TAP_TOGGLE(keycode);
}

// AZERTY letter typed by each of KC_A..KC_Z (the physical key positions are
// the same as on a US keyboard, the letters are not).
static const char azerty_letters[] = {
    'q', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'a', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
};

_Static_assert(ARRAY_SIZE(azerty_letters) == KC_Z - KC_A + 1, "azerty_letters out of sync");

// Letter produced by a base-layer letter key, or 0 if it is not a letter.
static char letter_for_keycode(uint16_t keycode) {
    if (keycode >= KC_A && keycode <= KC_Z) {
        return azerty_letters[keycode - KC_A];
    }
    return 0;
}

// Type a Unicode code point using the Linux input method.  The hexadecimal
// digits are sent with AZERTY keycodes, since QMK's own Unicode output
// assumes a US host layout.
static void lf_type_unicode(uint16_t codepoint) {
    uint8_t mods = get_mods();
    clear_mods();
    clear_weak_mods();
    clear_oneshot_mods();

    tap_code16(LF_UNICODE_START);
    wait_ms(LF_UNICODE_DELAY);
    for (int8_t i = 3; i >= 0; i--) {
        tap_code16(azerty_hex[(codepoint >> (i * 4)) & 0xF]);
        wait_ms(LF_UNICODE_DELAY);
    }
    tap_code(KC_SPC);

    set_mods(mods);
}

// Tap a keycode with every modifier cleared, so that the character is not
// altered by a physically held Shift/Ctrl/Alt.
static void tap_native(uint16_t keycode) {
    uint8_t mods = get_mods();
    clear_mods();
    clear_weak_mods();
    clear_oneshot_mods();
    tap_code16(keycode);
    set_mods(mods);
}

// Characters that the fr(oss) AZERTY variant can type natively.
static const struct {
    uint16_t codepoint;
    uint16_t keycode;
} azerty_direct[] = {
    // Base layer
    {0x002D, FR_MINS}, // -
    {0x005F, FR_UNDS}, // _
    {0x00B5, FR_MICR}, // µ
    {0x00E0, FR_AGRV}, // à
    {0x00E7, FR_CCED}, // ç
    {0x00E8, FR_EGRV}, // è
    {0x00E9, FR_EACU}, // é
    {0x00F9, FR_UGRV}, // ù
    // Capital accented letters, AltGr+Shift+digit
    {0x00C0, ALGR(S(FR_AGRV))}, // À
    {0x00C7, ALGR(S(FR_CCED))}, // Ç
    {0x00C8, ALGR(S(FR_EGRV))}, // È
    {0x00C9, ALGR(S(FR_EACU))}, // É
    {0x00D9, ALGR(S(FR_UGRV))}, // Ù
    // Letters with a direct AltGr key (fr(oss))
    {0x00E6, ALGR(FR_A)},    // æ
    {0x00C6, ALGR(S(FR_A))}, // Æ
    {0x0153, ALGR(FR_O)},    // œ
    {0x0152, ALGR(S(FR_O))}, // Œ
    {0x00DF, ALGR(FR_S)},    // ß
    {0x00EF, ALGR(FR_K)},    // ï
    {0x00CF, ALGR(S(FR_K))}, // Ï
    {0x00EA, ALGR(FR_R)},    // ê
    {0x00CA, ALGR(S(FR_R))}, // Ê
    {0x00FB, ALGR(FR_U)},    // û
    {0x00DB, ALGR(S(FR_U))}, // Û
    {0x00EE, ALGR(FR_I)},    // î
    {0x00CE, ALGR(S(FR_I))}, // Î
    {0x00F4, ALGR(FR_P)},    // ô
    {0x00D4, ALGR(S(FR_P))}, // Ô
    {0x00E2, ALGR(FR_Z)},    // â
    {0x00C2, ALGR(S(FR_Z))}, // Â
    {0x00EB, ALGR(FR_D)},    // ë
    {0x00CB, ALGR(S(FR_D))}, // Ë
    {0x00FC, ALGR(FR_J)},    // ü
    {0x00DC, ALGR(S(FR_J))}, // Ü
    {0x00E4, ALGR(FR_Q)},    // ä
    {0x00C4, ALGR(S(FR_Q))}, // Ä
    {0x00F6, ALGR(FR_M)},    // ö
    {0x00D6, ALGR(S(FR_M))}, // Ö
    {0x00FF, ALGR(FR_Y)},    // ÿ
    {0x0178, ALGR(S(FR_Y))}, // Ÿ
    // Punctuation and symbols
    {0x00D7, ALGR(FR_SCLN)},    // ×
    {0x00F7, ALGR(FR_COLN)},    // ÷
    {0x00BF, ALGR(FR_COMM)},    // ¿
    {0x2026, ALGR(S(FR_COMM))}, // …
    {0x2019, ALGR(FR_G)},       // ’
    {0x2014, ALGR(S(FR_QUOT))}, // —
    {0x2013, ALGR(S(FR_LPRN))}, // –
    {0x00B1, ALGR(FR_PLUS)},    // ±
    {0x2260, ALGR(FR_DEG)},     // ≠
    {0x2264, ALGR(FR_LABK)},    // ≤
    {0x2265, ALGR(FR_RABK)},    // ≥
    {0x00AC, ALGR(FR_N)},       // ¬
    {0x00AB, ALGR(FR_W)},       // «
    {0x00BB, ALGR(FR_X)},       // »
    // Currency symbols (from the currency dead key)
    {0x0024, FR_DLR},        // $
    {0x00A2, ALGR(S(FR_E))}, // ¢
    {0x00A3, FR_PND},        // £
    {0x00A5, ALGR(S(FR_G))}, // ¥
    {0x20AC, ALGR(FR_E)},    // €
};

// Native keycode for a code point, or 0.
static uint16_t azerty_direct_keycode(uint16_t codepoint) {
    for (uint8_t i = 0; i < ARRAY_SIZE(azerty_direct); i++) {
        if (azerty_direct[i].codepoint == codepoint) {
            return azerty_direct[i].keycode;
        }
    }
    return 0;
}

// AZERTY dead key that can compose a character on the host, or 0.
// These are the dead keys of the fr(oss) variant.
static uint16_t azerty_host_dead_key(uint8_t dead) {
    switch (dead) {
        case DKID_CIRC:
            return FR_CIRC; // ^ (dead), AltGr not needed
        case DKID_DIAE:
            return FR_DIAE; // ¨ (dead), Shift+^
        case DKID_TILDE:
            return ALGR(FR_CIRC); // ~ (dead), AltGr+^
        case DKID_RING:
            return ALGR(FR_DIAE); // ˚ (dead), AltGr+Shift+^
        case DKID_CARON:
            return ALGR(FR_AMPR); // ˇ (dead), AltGr+&
        case DKID_OGONEK:
            return ALGR(S(FR_AMPR)); // ˛ (dead), AltGr+Shift+&
        case DKID_BREVE:
            return ALGR(S(FR_DQUO)); // ˘ (dead), AltGr+Shift+"
        case DKID_CEDIL:
            return ALGR(S(KC_GRV)); // ¸ (dead), AltGr+Shift+²
        case DKID_ACUTE:
            return ALGR(FR_UGRV); // ´ (dead), AltGr+ù
        case DKID_GRAVE:
            return ALGR(FR_ASTR); // ` (dead), AltGr+*
        case DKID_MACRON:
            return ALGR(S(FR_ASTR)); // ¯ (dead), AltGr+Shift+*
    }
    return 0;
}

// AZERTY keycode typing a plain ASCII letter, or 0.
static uint16_t keycode_for_letter(char letter) {
    for (uint8_t i = 0; i < ARRAY_SIZE(azerty_letters); i++) {
        if (azerty_letters[i] == letter) {
            return KC_A + i;
        }
    }
    return 0;
}

// Compose a character with one of the host's own AZERTY dead keys.
static bool host_dead_compose(uint16_t codepoint) {
    for (uint8_t dead = 0; dead < DKID_COUNT; dead++) {
        uint16_t dead_key = azerty_host_dead_key(dead);
        if (dead_key == 0) {
            continue;
        }
        for (uint16_t i = 0; i < ARRAY_SIZE(dead_compose_table); i++) {
            if (dead_compose_table[i].dead != dead) {
                continue;
            }
            bool upper;
            if (dead_compose_table[i].lower == codepoint) {
                upper = false;
            } else if (dead_compose_table[i].upper == codepoint) {
                upper = true;
            } else {
                continue;
            }
            uint16_t letter = keycode_for_letter(dead_compose_table[i].base);
            if (letter == 0) {
                continue;
            }
            uint8_t mods = get_mods();
            clear_mods();
            clear_weak_mods();
            clear_oneshot_mods();
            tap_code16(dead_key);
            tap_code16(upper ? S(letter) : letter);
            set_mods(mods);
            return true;
        }
    }
    return false;
}

// Output a character, preferring native AZERTY keys and dead keys over
// Unicode input.
static void lf_put_char(uint16_t codepoint) {
    uint16_t keycode = azerty_direct_keycode(codepoint);
    if (keycode != 0) {
        tap_native(keycode);
        return;
    }
    if (host_dead_compose(codepoint)) {
        return;
    }
    lf_type_unicode(codepoint);
}

// Output the stand-alone (spacing) form of a dead key.
static void lf_put_dead_spacing(uint8_t dead) {
    uint16_t dead_key = azerty_host_dead_key(dead);
    if (dead_key != 0) {
        uint8_t mods = get_mods();
        clear_mods();
        clear_weak_mods();
        clear_oneshot_mods();
        tap_code16(dead_key);
        tap_code(KC_SPC);
        set_mods(mods);
        return;
    }
    lf_put_char(dead_spacing[dead]);
}

// Tap a keycode as if Shift were not held: needed for characters whose
// Lafayette shifted form differs from the AZERTY one.
static void tap_literal(uint16_t keycode) {
    if (!shift_active()) {
        tap_code16(keycode);
        return;
    }
    uint8_t mods = get_mods();
    clear_mods();
    clear_oneshot_mods();
    tap_code16(keycode);
    set_mods(mods);
}

static void sync_sym4(void) {
    if (layer_state_is(SYM) && (lshift_down || rshift_down)) {
        layer_on(SYM4);
    } else {
        layer_off(SYM4);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if ((state & (1UL << SYM)) && (lshift_down || rshift_down)) {
        state |= (1UL << SYM4);
    } else {
        state &= ~(1UL << SYM4);
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Keep track of Shift so that Shift+AltGr selects level 4.
    if (keycode == KC_LSFT) {
        lshift_down = record->event.pressed;
        sync_sym4();
        return true;
    }
    if (keycode == KC_RSFT) {
        rshift_down = record->event.pressed;
        sync_sym4();
        return true;
    }

    if (!record->event.pressed) {
        if (keycode == suppressed_keycode) {
            suppressed_keycode = 0;
            return false;
        }
        return true;
    }

    // A dead key is waiting for its base character.
    if (pending_dead) {
        uint8_t  dead  = dead_id_for(pending_dead);
        char     base  = letter_for_keycode(keycode);
        bool     upper = shift_active();
        uint16_t composed;

        if (base != 0 && dead_compose_lookup(dead, base, upper, &composed)) {
            pending_dead       = 0;
            suppressed_keycode = keycode;
            lf_put_char(composed);
            return false;
        }
        if (keycode == KC_SPC) {
            pending_dead       = 0;
            suppressed_keycode = keycode;
            lf_put_dead_spacing(dead);
            return false;
        }
        if (keeps_dead_key_pending(keycode)) {
            return true;
        }
        // Not composable: type the stand-alone accent, then let the key
        // through (a second dead key simply replaces the first one).
        pending_dead = 0;
        lf_put_dead_spacing(dead);
    }

    if (is_dead_key(keycode)) {
        pending_dead = keycode;
        return false;
    }

    if (keycode >= LF_L5_FIRST && keycode <= LF_L5_LAST) {
        uint8_t i     = keycode - LF_L5_FIRST;
        bool    upper = shift_active();
        lf_put_char(upper ? l5_upper[i] : l5_lower[i]);
        return false;
    }

    if (keycode >= LF_U_FIRST && keycode <= LF_U_LAST) {
        lf_put_char(l4_symbols[keycode - LF_U_FIRST]);
        return false;
    }

    switch (keycode) {
        case LF_APOS:
            tap_literal(shift_active() ? FR_DQUO : FR_QUOT);
            return false;
        case LF_COMM:
            tap_literal(shift_active() ? FR_SCLN : FR_COMM);
            return false;
        case LF_DOT:
            tap_literal(shift_active() ? FR_COLN : FR_DOT);
            return false;
        case LF_SLSH:
            tap_literal(shift_active() ? FR_QUES : FR_SLSH);
            return false;
        case LF_COLON:
            tap_literal(FR_COLN);
            return false;
    }

    return true;
}

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [DEF]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT) },
  [SYM]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT) },
  [SYM4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT) },
  [NUM]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT) },
  [DK]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT) },
  [WM]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT) },
  [MGT]  = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
};
// clang-format on
#endif
