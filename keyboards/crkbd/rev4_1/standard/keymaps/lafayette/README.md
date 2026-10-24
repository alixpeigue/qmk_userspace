# Qwerty-Lafayette for the Corne v4.1 (AZERTY host)

This keymap implements [Qwerty-Lafayette](https://qwerty-lafayette.org) on a
42-key Corne (`crkbd/rev4_1/standard`), based on the
`lafayette_linux_v0.9.xkb_custom` XKB layout at the root of this repository.

**The host must be configured with the French AZERTY layout, `oss`
variant** (`fr(oss)`, "French (alt.)" in the layout list).  It is a normal
AZERTY layout with the same letters and the same basic AltGr symbols, but it
also has native keys for all the Lafayette characters, so no Unicode input
(and no input method) is required.

In Hyprland / `hyprland.lua`:

```lua
input = {
    kb_layout  = "fr",
    kb_variant = "oss",
},
```

The firmware sends the AZERTY keycodes that produce the Lafayette
characters, so the character positions follow Lafayette while the operating
system keeps its usual French layout.  Do not enable the Lafayette XKB
layout on the host at the same time.

Build it with:

```bash
qmk compile -kb crkbd/rev4_1/standard -km lafayette
```

## Layers

### `DEF` — base layer (levels 1 and 2)

```
Tab    Q    W    E    R    T   Alt | Bspc   Y    U    I    O    P   Bspc
Esc    A    S    D    F    G   MGT | MGT    H    J    K    L   ODK    '
Meta   Z    X    C    V    B         |        N    M    ,    .    /   RShift
              Ctrl  Sym  Space     Enter/WM  Num  Shift
```

The four keys around the `|` are the board's extra keys (see below).

`Shift` gives the uppercase letters and the Lafayette punctuation:

| key | level 1 | level 2 |
|-----|---------|---------|
| `'` | `'`     | `"`     |
| `,` | `,`     | `;`     |
| `.` | `.`     | `:`     |
| `/` | `/`     | `?`     |

Modifiers:

| key | function |
|-----|----------|
| left outer thumb | `Ctrl` |
| right outer thumb | `Shift` |
| right inner thumb | `Enter`, and **`WM` layer** when held |
| left pinky (`Meta`) | `Meta` (Super / Windows / Command) — almost never needed |
| right pinky | `Shift` (spare) |

There is no dedicated host AltGr key: the `SYM` layer sends the AltGr
combinations itself.

### `SYM` — AltGr layer (level 3)

Hold the left middle thumb key (`Sym`).  All of these are native AZERTY
keystrokes, so no Unicode is involved:

```
       ^    <    >    $    %          @    &    *    '    `
       {    (    )    }    =          \    +    -    /    "
       ~    [    ]    _    #          |    !    ;    :    ?
```

### `SYM4` — Shift+Sym layer (level 4)

Hold `Shift` while `Sym` is held:

| key | level 4          | key | level 4             |
|-----|------------------|-----|---------------------|
| `Q` | dead circumflex  | `W` | `≤`                 |
| `E` | `≥`              | `R` | dead currency       |
| `T` | `‰`              | `Y` | dead ring above     |
| `U` | (nothing)        | `I` | `×`                 |
| `O` | dead acute       | `P` | dead grave          |
| `A` | dead caron       | `S` | `⁽`                 |
| `D` | `⁾`              | `F` | dead dot above      |
| `G` | `≠`              | `H` | dead stroke         |
| `J` | `±`              | `K` | dead macron         |
| `L` | `÷`              | `ODK` | dead double acute |
| `Z` | dead tilde       | `X` | dead comma below    |
| `C` | dead ogonek      | `V` | `–`                 |
| `B` | (nothing)        | `N` | `¦`                 |
| `M` | `¬`              | `,` | dead cedilla        |
| `.` | `:`              | `/` | dead breve          |

Keys in the letter block without a level-4 character produce nothing, as in
the XKB layout.

### `ODK` — OneDeadKey latch (level 5)

Tap the `ODK` key (right of `L`), then the key holding the accented
character.  This is level 5 of the XKB layout:

```
  ___    æ    é    è   ___  ___        ___    ù    ï    œ   ___  ___
  ___    à    ß    ê    -    –          ŷ    û    î    ô    ¨   ___
  ___    â    ×    ç    _    —          ñ    µ    ·    …    ¿   ___
                    ___  ___   ’        ___  ___  ___
```

`Shift` selects the uppercase form.  Nearly all of these are native keys of
the `fr(oss)` layout (`É È À Ù Ç œ Œ ß ï ê î ô â û … ’ — –`) or dead-key
compositions on the host (`ŷ`, `ñ`, …).  Only `·`, `ª`, `º`, `ẞ` and `•`
fall back to Unicode input.  A key without a level-5 character simply types
its base character.

### `NUM` — numbers and navigation

Hold the right middle thumb key (`Num`).

```
  1    2    3    4    5    6          7    8    9    0    -    =
 F1   F2   F3   F4   F5   F6         ←    ↓    ↑    →   Home  End
 F7   F8   F9  F10  F11  F12        PgUp PgDn  Ins  Del  Vol- Vol+
                                             Play/Pause
```

The digits stay digits even when `Shift` is held.  The bootloader and RGB
controls live in the `MGT` layer.

## Dead keys

The dead keys on `Shift+Sym` follow level 4 of the XKB layout.  Press the
dead key, then the base letter; `Shift` selects the uppercase accented
letter.  Pressing `Space` after a dead key outputs the stand-alone accent
(`^`, `´`, `` ` ``, `~`, `¨`, `¸`, `ˇ`, `˛`, `˚`, `˙`, `¯`, `˘`, `˝`, `,`,
`/`, `¤`).  Any other key first outputs the stand-alone accent and is then
typed normally.

Example: `Shift+Sym`, `O` (acute), `E` → `é`; with `Shift` → `É`.

| key | dead key          |
|-----|-------------------|
| `Q` | circumflex        |
| `R` | currency          |
| `Y` | ring above        |
| `O` | acute             |
| `P` | grave             |
| `A` | caron             |
| `F` | dot above         |
| `H` | stroke            |
| `K` | macron            |
| `ODK` | double acute    |
| `Z` | tilde             |
| `X` | comma below       |
| `C` | ogonek            |
| `,` | cedilla           |
| `/` | breve             |

A diaeresis dead key is also available on the `ODK` layer, at the `ODK` key
position (level 5).

Precomposed characters are used whenever Unicode defines one; otherwise the
letter is typed on its own after the accent.

## Unicode input

With the `fr(oss)` host layout, only a handful of characters still use
Unicode input: `‰`, `⁽`, `⁾`, `¦`, `·`, `ª`, `º`, `ẞ` and `•`
(`Ctrl+Shift+U`, then the hexadecimal code point, then `Space`).  QMK's own
Unicode support assumes a US host layout, so the sequence is generated by
the keymap itself, using the AZERTY keycodes for the hexadecimal digits.

`Ctrl+Shift+U` is handled by the application or input method, not by the
kernel.  It needs an input method such as IBus (or a GTK app whose simple IM
handles it), and it does not work in every terminal emulator.  Without one,
everything except those few symbols still works.

### `WM` — window manager (Hyprland)

Hold **`Enter`** (right inner thumb) to enter this layer; a quick tap is a
normal `Enter`.  Every key sends the `SUPER + …` combination bound in
`~/.config/hypr/hyprland.lua`, so the Meta key is never needed.

```
              Q    W    E    R    T          Y    U    I    O    P
workspaces:   1    2    3    4    5          6    7    8    9    10

home row:     A = next monitor  S = terminal   |  H J K L = focus left/down/up/right
              D = files         F = floating   |  ODK = launcher   ' = display menu
              G = browser                      |
bottom row:   C = close        V = clipboard  |  N = screenshot   M = power menu
```

Modifiers used inside the layer:

* **`Shift` (left thumb, i.e. the `Space` key of this layer)** + `H/J/K/L`
  moves the window; + a workspace key moves the window to that workspace;
  + `F` toggles fullscreen; + `S` opens a terminal in the current directory.
* **`Ctrl` (left outer thumb)** + `H/J/K/L` resizes the window.

Shift is on the left thumb *inside this layer* on purpose: the physical
Shift now sits on the right thumb, which is the same hand that holds
`Enter`, so it could not be combined with the layer.

The workspace keys use the *unshifted* AZERTY digit keysyms (`&`, `é`, `"`,
`'`, `(`, `-`, `è`, `_`, `ç`, `à`), which is what the Hyprland config binds.

The launcher positions (`S`, `D`, `G`, `ODK`, `'`, `N`) are arbitrary — tell
me your preferred order if you want them shuffled.

## Extra keys (`_ex2`)

The Corne v4.1 PCB has four extra switch positions between the halves —
two above the left thumb cluster and two above the right one (matrix
`[0,6]`, `[1,6]` on the left and `[4,6]`, `[5,6]` on the right).  They are
not part of `LAYOUT_split_3x6_3`, so this keymap uses
`LAYOUT_split_3x6_3_ex2` instead.

Current assignment (base layer):

| physical key | matrix | keycode |
|---|---|---|
| left inner, upper | `[0,6]` | `Alt` |
| left inner, lower | `[1,6]` | **`MGT` layer** when held |
| right inner, upper | `[4,6]` | `Bksp` |
| right inner, lower | `[5,6]` | **`MGT` layer** when held |

They are `_______` on all other layers, so they keep that behaviour
everywhere.  To customise them, edit the `[DEF]` layer in `keymap.c`: the
four entries sit between the two halves of the source, in the order

```
row 0:  ... FR_T,   <[0,6]>, <[4,6]>,   FR_Y ...
row 1:  ... FR_G,   <[1,6]>, <[5,6]>,   FR_H ...
```

Replace `KC_LALT`, `KC_BSPC` (row 0) and `MO(MGT)`, `MO(MGT)` (row 1) with
whatever you want — any QMK keycode works, including layer keys
(`MO(...)`, `OSL(...)`, `LT(...)`) or macros you add in
`process_record_user()`.

You can check the order with:

```bash
qmk info -kb crkbd/rev4_1/standard -l
```

## `MGT` — management layer

Hold one of the two inner-lower extra keys (or both, they are the same) to
reach it:

```
top row:   QK_BOOT  QK_RBT   EE_CLR   ·   ·   ·    |  ·   ·   ·   ·   ·   ·
home row:  RM_TOGG  RM_NEXT  RM_PREV  RM_HUEU  RM_HUED  RM_SATU  |  RM_SATD  RM_VALU  RM_VALD  RM_SPDU  RM_SPDD  ·
```

* `QK_BOOT` — jump to the RP2040 UF2 bootloader
* `QK_RBT` — reboot the controller
* `EE_CLR` — wipe the EEPROM (RGB state, settings)
* `RM_TOGG` / `RM_NEXT` / `RM_PREV` — RGB matrix on-off and effect cycling
* `RM_HUEU` / `RM_HUED`, `RM_SATU` / `RM_SATD`, `RM_VALU` / `RM_VALD`,
  `RM_SPDU` / `RM_SPDD` — hue, saturation, brightness and speed

The destructive keys are on the top row so they need a deliberate reach.
The encoder's rotation changes RGB brightness while the layer is held.

## Flashing the firmware

Both halves run the same `crkbd_rev4_1_standard_lafayette.uf2`; flash each
half separately by plugging the USB cable into the half you want to flash.

To put a half into the RP2040 bootloader (it then appears as a `RPI-RP2`
USB drive), use any of these:

* **`QK_BOOT` key:** hold `Num` (right middle thumb) and press the leftmost
  thumb key of the left half (the `Ctrl` key in the base layer).
* **Bootmagic (works after a power-up, even with a broken keymap):** hold the
  bootmagic key while plugging in the USB cable:
  * left half: the second key of the top row (the `q` key);
  * right half: the second key from the right of the top row (the `p` key,
    left of `Bksp`).

  Bootmagic also clears the stored EEPROM settings.
* **Hardware reset:** double-tap the controller's `RESET` button within
  500 ms, or hold `BOOTSEL` while plugging the cable in.

Then run:

```bash
qmk flash -kb crkbd/rev4_1/standard -km lafayette
```

or drop the `.uf2` file onto the `RPI-RP2` drive.

## Limitations

* The digit-row levels of Lafayette (subscripts and superscripts such as `₁`
  and `¹`) have no dedicated keys on a 3x6 Corne; the `NUM` layer provides the
  ordinary digits instead.
* Unicode input assumes the Linux `Ctrl+Shift+U` sequence; there is no
  Windows/macOS mode switch.
