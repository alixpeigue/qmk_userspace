#pragma once

// Dead-key composition data for the Qwerty-Lafayette keymap.
// Generated from Unicode NFC data; edit carefully.

#include <stdint.h>
#include <stdbool.h>

enum dead_ids {
    DKID_CIRC,
    DKID_ACUTE,
    DKID_GRAVE,
    DKID_TILDE,
    DKID_DIAE,
    DKID_CEDIL,
    DKID_CARON,
    DKID_OGONEK,
    DKID_RING,
    DKID_DOT,
    DKID_MACRON,
    DKID_BREVE,
    DKID_DBLACUTE,
    DKID_BELOWCOMMA,
    DKID_STROKE,
    DKID_CURR,
    DKID_COUNT
};

typedef struct {
    uint8_t  dead;
    char     base;
    uint16_t lower;
    uint16_t upper;
} dead_compose_t;

static const dead_compose_t dead_compose_table[] = {
    {DKID_CIRC    , 'a', 0x00E2, 0x00C2},
    {DKID_CIRC    , 'c', 0x0109, 0x0108},
    {DKID_CIRC    , 'e', 0x00EA, 0x00CA},
    {DKID_CIRC    , 'g', 0x011D, 0x011C},
    {DKID_CIRC    , 'h', 0x0125, 0x0124},
    {DKID_CIRC    , 'i', 0x00EE, 0x00CE},
    {DKID_CIRC    , 'j', 0x0135, 0x0134},
    {DKID_CIRC    , 'o', 0x00F4, 0x00D4},
    {DKID_CIRC    , 's', 0x015D, 0x015C},
    {DKID_CIRC    , 'u', 0x00FB, 0x00DB},
    {DKID_CIRC    , 'w', 0x0175, 0x0174},
    {DKID_CIRC    , 'y', 0x0177, 0x0176},
    {DKID_CIRC    , 'z', 0x1E91, 0x1E90},
    {DKID_ACUTE   , 'a', 0x00E1, 0x00C1},
    {DKID_ACUTE   , 'c', 0x0107, 0x0106},
    {DKID_ACUTE   , 'e', 0x00E9, 0x00C9},
    {DKID_ACUTE   , 'g', 0x01F5, 0x01F4},
    {DKID_ACUTE   , 'i', 0x00ED, 0x00CD},
    {DKID_ACUTE   , 'k', 0x1E31, 0x1E30},
    {DKID_ACUTE   , 'l', 0x013A, 0x0139},
    {DKID_ACUTE   , 'm', 0x1E3F, 0x1E3E},
    {DKID_ACUTE   , 'n', 0x0144, 0x0143},
    {DKID_ACUTE   , 'o', 0x00F3, 0x00D3},
    {DKID_ACUTE   , 'p', 0x1E55, 0x1E54},
    {DKID_ACUTE   , 'r', 0x0155, 0x0154},
    {DKID_ACUTE   , 's', 0x015B, 0x015A},
    {DKID_ACUTE   , 'u', 0x00FA, 0x00DA},
    {DKID_ACUTE   , 'w', 0x1E83, 0x1E82},
    {DKID_ACUTE   , 'y', 0x00FD, 0x00DD},
    {DKID_ACUTE   , 'z', 0x017A, 0x0179},
    {DKID_GRAVE   , 'a', 0x00E0, 0x00C0},
    {DKID_GRAVE   , 'e', 0x00E8, 0x00C8},
    {DKID_GRAVE   , 'i', 0x00EC, 0x00CC},
    {DKID_GRAVE   , 'n', 0x01F9, 0x01F8},
    {DKID_GRAVE   , 'o', 0x00F2, 0x00D2},
    {DKID_GRAVE   , 'u', 0x00F9, 0x00D9},
    {DKID_GRAVE   , 'w', 0x1E81, 0x1E80},
    {DKID_GRAVE   , 'y', 0x1EF3, 0x1EF2},
    {DKID_TILDE   , 'a', 0x00E3, 0x00C3},
    {DKID_TILDE   , 'e', 0x1EBD, 0x1EBC},
    {DKID_TILDE   , 'i', 0x0129, 0x0128},
    {DKID_TILDE   , 'n', 0x00F1, 0x00D1},
    {DKID_TILDE   , 'o', 0x00F5, 0x00D5},
    {DKID_TILDE   , 'u', 0x0169, 0x0168},
    {DKID_TILDE   , 'v', 0x1E7D, 0x1E7C},
    {DKID_TILDE   , 'y', 0x1EF9, 0x1EF8},
    {DKID_DIAE    , 'a', 0x00E4, 0x00C4},
    {DKID_DIAE    , 'e', 0x00EB, 0x00CB},
    {DKID_DIAE    , 'h', 0x1E27, 0x1E26},
    {DKID_DIAE    , 'i', 0x00EF, 0x00CF},
    {DKID_DIAE    , 'o', 0x00F6, 0x00D6},
    {DKID_DIAE    , 't', 0x1E97, 0x1E97},
    {DKID_DIAE    , 'u', 0x00FC, 0x00DC},
    {DKID_DIAE    , 'w', 0x1E85, 0x1E84},
    {DKID_DIAE    , 'x', 0x1E8D, 0x1E8C},
    {DKID_DIAE    , 'y', 0x00FF, 0x0178},
    {DKID_CEDIL   , 'c', 0x00E7, 0x00C7},
    {DKID_CEDIL   , 'd', 0x1E11, 0x1E10},
    {DKID_CEDIL   , 'e', 0x0229, 0x0228},
    {DKID_CEDIL   , 'g', 0x0123, 0x0122},
    {DKID_CEDIL   , 'h', 0x1E29, 0x1E28},
    {DKID_CEDIL   , 'k', 0x0137, 0x0136},
    {DKID_CEDIL   , 'l', 0x013C, 0x013B},
    {DKID_CEDIL   , 'n', 0x0146, 0x0145},
    {DKID_CEDIL   , 'r', 0x0157, 0x0156},
    {DKID_CEDIL   , 's', 0x015F, 0x015E},
    {DKID_CEDIL   , 't', 0x0163, 0x0162},
    {DKID_CARON   , 'a', 0x01CE, 0x01CD},
    {DKID_CARON   , 'c', 0x010D, 0x010C},
    {DKID_CARON   , 'd', 0x010F, 0x010E},
    {DKID_CARON   , 'e', 0x011B, 0x011A},
    {DKID_CARON   , 'g', 0x01E7, 0x01E6},
    {DKID_CARON   , 'h', 0x021F, 0x021E},
    {DKID_CARON   , 'i', 0x01D0, 0x01CF},
    {DKID_CARON   , 'j', 0x01F0, 0x01F0},
    {DKID_CARON   , 'k', 0x01E9, 0x01E8},
    {DKID_CARON   , 'l', 0x013E, 0x013D},
    {DKID_CARON   , 'n', 0x0148, 0x0147},
    {DKID_CARON   , 'o', 0x01D2, 0x01D1},
    {DKID_CARON   , 'r', 0x0159, 0x0158},
    {DKID_CARON   , 's', 0x0161, 0x0160},
    {DKID_CARON   , 't', 0x0165, 0x0164},
    {DKID_CARON   , 'u', 0x01D4, 0x01D3},
    {DKID_CARON   , 'z', 0x017E, 0x017D},
    {DKID_OGONEK  , 'a', 0x0105, 0x0104},
    {DKID_OGONEK  , 'e', 0x0119, 0x0118},
    {DKID_OGONEK  , 'i', 0x012F, 0x012E},
    {DKID_OGONEK  , 'o', 0x01EB, 0x01EA},
    {DKID_OGONEK  , 'u', 0x0173, 0x0172},
    {DKID_RING    , 'a', 0x00E5, 0x00C5},
    {DKID_RING    , 'u', 0x016F, 0x016E},
    {DKID_RING    , 'w', 0x1E98, 0x1E98},
    {DKID_RING    , 'y', 0x1E99, 0x1E99},
    {DKID_DOT     , 'a', 0x0227, 0x0226},
    {DKID_DOT     , 'b', 0x1E03, 0x1E02},
    {DKID_DOT     , 'c', 0x010B, 0x010A},
    {DKID_DOT     , 'd', 0x1E0B, 0x1E0A},
    {DKID_DOT     , 'e', 0x0117, 0x0116},
    {DKID_DOT     , 'f', 0x1E1F, 0x1E1E},
    {DKID_DOT     , 'g', 0x0121, 0x0120},
    {DKID_DOT     , 'h', 0x1E23, 0x1E22},
    {DKID_DOT     , 'm', 0x1E41, 0x1E40},
    {DKID_DOT     , 'n', 0x1E45, 0x1E44},
    {DKID_DOT     , 'o', 0x022F, 0x022E},
    {DKID_DOT     , 'p', 0x1E57, 0x1E56},
    {DKID_DOT     , 'r', 0x1E59, 0x1E58},
    {DKID_DOT     , 's', 0x1E61, 0x1E60},
    {DKID_DOT     , 't', 0x1E6B, 0x1E6A},
    {DKID_DOT     , 'w', 0x1E87, 0x1E86},
    {DKID_DOT     , 'x', 0x1E8B, 0x1E8A},
    {DKID_DOT     , 'y', 0x1E8F, 0x1E8E},
    {DKID_DOT     , 'z', 0x017C, 0x017B},
    {DKID_MACRON  , 'a', 0x0101, 0x0100},
    {DKID_MACRON  , 'e', 0x0113, 0x0112},
    {DKID_MACRON  , 'g', 0x1E21, 0x1E20},
    {DKID_MACRON  , 'i', 0x012B, 0x012A},
    {DKID_MACRON  , 'o', 0x014D, 0x014C},
    {DKID_MACRON  , 'u', 0x016B, 0x016A},
    {DKID_MACRON  , 'y', 0x0233, 0x0232},
    {DKID_BREVE   , 'a', 0x0103, 0x0102},
    {DKID_BREVE   , 'e', 0x0115, 0x0114},
    {DKID_BREVE   , 'g', 0x011F, 0x011E},
    {DKID_BREVE   , 'i', 0x012D, 0x012C},
    {DKID_BREVE   , 'o', 0x014F, 0x014E},
    {DKID_BREVE   , 'u', 0x016D, 0x016C},
    {DKID_DBLACUTE, 'o', 0x0151, 0x0150},
    {DKID_DBLACUTE, 'u', 0x0171, 0x0170},
    {DKID_BELOWCOMMA, 's', 0x0219, 0x0218},
    {DKID_BELOWCOMMA, 't', 0x021B, 0x021A},
    {DKID_STROKE  , 'o', 0x00F8, 0x00D8},
    {DKID_STROKE  , 'l', 0x0142, 0x0141},
    {DKID_STROKE  , 'd', 0x0111, 0x0110},
    {DKID_STROKE  , 'h', 0x0127, 0x0126},
    {DKID_STROKE  , 't', 0x0167, 0x0166},
    {DKID_STROKE  , 'b', 0x0180, 0x0243},
    {DKID_STROKE  , 'z', 0x01B6, 0x01B5},
    {DKID_STROKE  , 'i', 0x0268, 0x0197},
    {DKID_CURR    , 'e', 0x20AC, 0x20AC},
    {DKID_CURR    , 'l', 0x00A3, 0x00A3},
    {DKID_CURR    , 'y', 0x00A5, 0x00A5},
    {DKID_CURR    , 'c', 0x00A2, 0x00A2},
    {DKID_CURR    , 'd', 0x0024, 0x0024},
    {DKID_CURR    , 'w', 0x20A9, 0x20A9},
    {DKID_CURR    , 'f', 0x20A3, 0x20A3},
    {DKID_CURR    , 'n', 0x20A6, 0x20A6},
    {DKID_CURR    , 'p', 0x20B1, 0x20B1},
    {DKID_CURR    , 't', 0x20AE, 0x20AE},
    {DKID_CURR    , 'r', 0x20B9, 0x20B9},
    {DKID_CURR    , 'u', 0x20A4, 0x20A4},
    {DKID_CURR    , 's', 0x20A7, 0x20A7},
    {DKID_CURR    , 'k', 0x20AD, 0x20AD},
};

// Spacing (stand-alone) form of each dead key, used when followed by space.
static const uint16_t dead_spacing[DKID_COUNT] = {
    0x005E, // ^
    0x00B4, // ´
    0x0060, // `
    0x007E, // ~
    0x00A8, // ¨
    0x00B8, // ¸
    0x02C7, // ˇ
    0x02DB, // ˛
    0x02DA, // ˚
    0x02D9, // ˙
    0x00AF, // ¯
    0x02D8, // ˘
    0x02DD, // ˝
    0x002C, // , (comma below)
    0x002F, // /
    0x00A4, // ¤
};

static inline bool dead_compose_lookup(uint8_t dead, char base, bool upper, uint16_t *out) {
    for (uint16_t i = 0; i < sizeof(dead_compose_table) / sizeof(dead_compose_table[0]); i++) {
        if (dead_compose_table[i].dead == dead && dead_compose_table[i].base == base) {
            *out = upper ? dead_compose_table[i].upper : dead_compose_table[i].lower;
            return true;
        }
    }
    return false;
}
