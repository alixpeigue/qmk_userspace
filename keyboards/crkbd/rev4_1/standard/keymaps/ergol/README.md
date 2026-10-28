# Ergo-L on a 46-key Corne v4.1

This keymap types **Ergo-L** (letters, symbols, accents) with the
**Qwerty-Lafayette implementation**: the host runs the French AZERTY
layout and the firmware sends AZERTY keycodes, so every key produces the
Ergo-L character for its position.  The navigation, window-manager and
management layers, the thumb keys, the four extra keys and the
Shift/Meta swap are taken from the `lafayette` keymap.

## Host requirement: `fr(oss)`

The keymap needs the **French (alt.)** variant, `fr(oss)`, which provides
native keys for É, È, œ, ≤, ≥, —, … and many more.  In Hyprland:

```lua
hl.config({ input = { kb_layout = "fr", kb_variant = "oss" } })
```

Then `hyprctl reload`.  Without the variant, several keys (e.g. `Ê` =
AltGr+Shift+r) produce nothing.

Build with:

```sh
qmk compile -kb crkbd/rev4_1/standard -km ergol
```

## Layers

| layer | access | content |
|-------|--------|---------|
| `DEF` | — | Ergo-L letters and punctuation |
| `SYM` | hold left inner thumb | Ergo-L symbols (AltGr) |
| `SYM4` | hold `Sym` + `Shift` | dead keys and extra symbols |
| `DK` | tap `★` (top row, `D`/`Y` side) | typography: accented letters, œ æ ç ß, host dead keys |
| `NUM` | hold right middle thumb | digits, F-keys, navigation, media |
| `WM` | hold `Enter` | Hyprland window manager bindings |
| `MGT` | hold an inner-lower extra key | bootloader, reboot, EEPROM, RGB |

### `DEF` — Ergo-L base layer

```
Tab    Q    C    O    P    W   Alt | Bspc   J    M    D    ★    Y   Bspc
Esc    A    S    E    N    F   MGT | MGT    L    R    T    I    U    '
Meta   Z    X    -    V    B         |        .    H    G    ,    K  RShift
              Ctrl  Sym  Space     Enter/WM  Num  Shift
```

`Shift` keeps the host's own shifted forms.  Three punctuation keys are
handled explicitly because AZERTY does not put the same character on the
shifted level:

| key | level 1 | level 2 |
|-----|---------|---------|
| `;` position | `.` | `:` |
| `,` position | `,` | `;` |
| `?` position | `-` | `?` |
| `'` position | `'` | `"` |

Modifiers:

| key | function |
|-----|----------|
| left outer thumb | `Ctrl` |
| right outer thumb | `Shift` |
| right inner thumb | `Enter`, and **`WM` layer** when held |
| left pinky | `Meta` — almost never needed, the `WM` layer sends `Super` itself |
| right pinky | `Shift` (spare) |

The four extra keys: `[0,6]` = `Alt`, `[4,6]` = `Backspace`, `[1,6]` and
`[5,6]` = hold for the `MGT` layer.

### `SYM` — Ergo-L symbols (AltGr)

```
       ^    <    >    $    %           @    &    *    '    `    ·
       {    (    )    }    =           \    +    -    /    "    ·
       ~    [    ]    _    #           |    !    ;    :    ?    ·
```

Same positions as the Ergo-L AltGr layer.  All of these exist natively in
`fr(oss)` — the backtick is `AltGr+7` (`grave`, U+0060).

### `SYM4` — `Shift` + `Sym`: dead keys and extra symbols

Identical to the `lafayette` keymap: the dead keys `^ ´ ` ~ ¨ ¸ ˇ ˛ ˘ ¯
˚ ˙`, the symbols `≤ ≥ ≠ ± × ÷ ‰ ⁽ ⁾ ¦ ¬ … ’ – —`, and a key that always
types `:` even with `Shift` held.  This mirrors Ergo-L's convention that
`Shift+AltGr` gives dead keys.

### `DK` — typography (`★`)

Ergo-L's accent layer, held as a one-shot (`OSL`): tap `★`, then the
accented letter.  `Shift` gives the capital (é/É, à/À, ç/Ç…).  The
layer also carries the host dead keys, so `¨` then `e` gives `ë`, etc.

```
       â    ç    œ    ô    ^           ŷ    µ    ´    ¨    û    `
       à    é    è    ê    ñ           (    )    î    ï    ù    ¸
       æ    ß    ×    _    -           –    —    …    ¿    ’    ·
```

`^ ` ´ ¨ ` ¸` are dead keys: they compose with the next letter (`^`+`a` =
`â`), or give the spacing accent when followed by `Space`.

### `NUM`, `WM`, `MGT`

Unchanged from the `lafayette` keymap:

* `NUM` — digits under the letter columns (`= 1…5` / `6…0 -`), F-keys,
  arrows, Home/End/PgUp/PgDn, Ins/Del, volume.
* `WM` — Hyprland bindings with `Super`: workspaces on `Q…P`
  (`Shift` = move window, `Ctrl` = resize with `HJKL`), focus, floating,
  close, clipboard, launchers, screenshot, power.
* `MGT` — `QK_BOOT`, `QK_RBT`, `EE_CLR` and the full RGB matrix control.

## Notes

* The uppercase accented letters and the special symbols are produced with
  `fr(oss)` AltGr combinations; only a few code points (`‰ ⁽ ⁾ ¦ · ª º ẞ
  •`) fall back to Unicode input, which needs an input method on the host
  (`Ctrl+Shift+U`, GTK/IBus).
* The dead-key table lives in `dead_keys.h`; the character tables and
  helpers live in `keymap.c`, shared with the `lafayette` keymap design.
