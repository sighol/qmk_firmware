/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

// LT(layer, kc): turn on layer when held, kc when tapped.
// MT(mod, kc): mod when held, kc when tapped
// MO(layer): Momentarily activates layer. As soon as you let go of the key, the layer is deactivated.
// LM(layer, mod: Momentarily activates layer with modifiers active). The modifiers this accepts are prefixed with MOD, not KC.
#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

// Blank template at the bottom

enum customKeycodes {
	URL  = 1
};

#define SH_LPAR S(KC_8)
#define SH_RPAR S(KC_9)
#define SH_LBRK ALGR(KC_8)
#define SH_RBRK ALGR(KC_9)
#define SH_LCBRK ALGR(KC_7)
#define SH_RCBRK ALGR(KC_0)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,---------------------------------------------.                         ,-------------------------------------------.
 * | TAB      |   Q  |   W  |   F  |   P  |   G  |                         |   J  |   L  |   U  |   Y  |   Ø  |  Å     |
 * |----------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * | BKSP     |   A  |   R  |   S  |   T  |   D  | ALTGR|           | PGUP |   H  |   N  |   E  |   I  |   O  |  Æ     |
 * |----------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | LShift   |   Z  |   X  |   C  |   V  |   B  | WIN  |-          | dead |   K  |   M  | ,  ; | . :  | +  ? |  - _   |
 * `----------+------+------+------+------+-------------' \         `-------------+------+------+------+------+--------'
 *                    .----------.   .--------.           |                     .--------.   .-----.
 *                    |  NUMB    |   | CTRL   |           |                     | Space  |   |NUMB |
 *                    '----------'   '--------'           |                     `--------.   '-----'
 *                                        ,-------.       |              ,-------.
 *                                        |       | <----/               | PGDN  |
 *                                 ,------|-------|                      |-------|------.
 *                                 | ALT  |Escape |                      | L2    | ENTER |
 *                                 |      |       |                      |       |       |
 *                                 |      |       |                      |       |       |
 *                                 `--------------'                      `--------------'
 */
[BASE] = LAYOUT(
    KC_TAB,  KC_Q,  KC_W,   KC_F,   KC_P, KC_G,                                          KC_J, KC_L,    KC_U,   KC_Y, KC_SCLN, KC_LBRC,
    KC_BSPC, KC_A,  KC_R,   KC_S,   KC_T, KC_D, KC_RALT,                       KC_PGUP,  KC_H, KC_N,    KC_E,   KC_I,    KC_O, KC_QUOT,
    KC_LSFT, KC_Z,  KC_X,   KC_C,   KC_V, KC_B, KC_LGUI, KC_NO,     KC_PGDN,    KC_H,  KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,

                 MO(SYMB), KC_LCTL, KC_LALT, KC_ESC,                                 MO(NUMB), KC_ENT, KC_SPC, MO(NUMB)
),
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                                ,-------------------------------------------.
 * |        |      |  7   |  8   |  9   |      |                                |      | WRDL |  UP  | WRDR |      |        |
 * |--------+------+------+------+------+------|------.                  ,------|------+------+------+------+------+--------|
 * |        |      |  4   |  5   |  6   |      |      |                  |      |      | LEFT | DOWN | RGHT |      |        |
 * |--------+------+------+------+------+------|------|-----.      ,-----|------|------+------+------+------+------+--------|
 * |        |      |  1   |  2   |  3   |  0   |      |     |      |     | HOME | END  |      |      |      |      |        |
 * `--------+------+------+------+------+------+------+-----´      `-----+------+------+------+------+------+------+--------'
 *                        .------.   .------.                                      .------.   .-----.
 *                        |      |   |      |                                      | BOOT |   |     |
 *                        '------'   '------'                                      `------´   `-----´
 *
 *                                           ,--------------.      ,--------------.
 *                                           |      |       |      |       |      |
 *                                           |      |       |      |       |      |
 *                                           |      |       |      |       |      |
 *                                           `--------------'      `--------------'
 */
[NUMB] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_7, KC_8, KC_9,    KC_0,                                              KC_TRNS, C(KC_LEFT),   KC_UP, C(KC_RGHT), KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS,                             KC_TRNS, KC_PLUS,   KC_LEFT, KC_DOWN,    KC_RGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_HOME,    KC_END, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,

                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,  KC_TRNS, QK_BOOT, KC_TRNS
),
/* Keymap 2: Pad/Function layer
 * ,-------------------------------------------.                                ,-------------------------------------------.
 * |        |      |  F7  |  F8  |  F9  | F10  |                                |   (  |  )   |      |      |      |        |
 * |--------+------+------+------+------+------|------.                  ,------|------+------+------+------+------+--------|
 * |        |      |  F4  |  F5  |  F6  | F11  |PRNTSC|                  | INS  |   [  |  ]   |      |      |      |        |
 * |--------+------+------+------+------+------|------|-----.      ,-----|------|------+------+------+------+------+--------|
 * |        |      |  F1  |  F2  |  F3  | F12  |      |     |      |     | dead |   {  |  }   |      |      |      |        |
 * `--------+------+------+------+------+------+------+-----´      `-----+------+------+------+------+------+------+--------'
 *                        .------.   .------.                                      .------.   .-----.
 *                        |      |   |      |                                      |      |   |     |
 *                        '------'   '------'                                      `------´   `-----´
 *
 *                                           ,--------------.      ,--------------.
 *                                           |      |       |      |       |      |
 *                                           |      |       |      |       |      |
 *                                           |      |       |      |       |      |
 *                                           `--------------'      `--------------'
 */
[SYMB] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10,                                             KC_TRNS, SH_LCBRK, SH_RCBRK, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11, KC_PSCR,                         KC_INSERT, KC_TRNS,  SH_LPAR,  SH_RPAR, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS,  SH_LBRK,  SH_RBRK, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
};

/* Keymap template
 *
 * ,-------------------------------------------.                                ,-------------------------------------------.
 * |        |      |      |      |      |      |                                |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.                  ,------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                  |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|-----.      ,-----|------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |     |      |     |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+------+------+-----´      `-----+------+------+------+------+------+------+--------'
 *                        .------.   .------.                                      .------.   .-----.
 *                        |      |   |      |                                      |      |   |     |
 *                        '------'   '------'                                      `------´   `-----´
 *
 *                                           ,--------------.      ,--------------.
 *                                           |      |       |      |       |      |
 *                                           |      |       |      |       |      |
 *                                           |      |       |      |       |      |
 *                                           `--------------'      `--------------'
[SYMB] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
 */
