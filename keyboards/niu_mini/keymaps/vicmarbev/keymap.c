#include QMK_KEYBOARD_H

enum layers{
    _QWERTY,
    _LOWER,
    _RAISE,
    _MOV 
};

#define SPCMOV LT(_MOV, KC_SPC)
#define RAISE LT(_RAISE, KC_ENT)
#define LOWER LT(_LOWER, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |  Ctrl | LAlt |  GUI | Lower |    Space    | Raise|  AltGr  |  | Down |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_mit(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, LOWER,     SPCMOV,     RAISE, KC_ALGR, KC_RGUI, KC_RCTL, KC_MEH
    ),

    /* Layer 1
     * ,-----------------------------------------------------------------------------------.
     * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      | Vol- | Vol+ | Mute |      |      |      |  F11 |  F12 |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Reset|      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_mit(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, KC_F11,  KC_F12,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        RESET,   _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
    ),

    /* Layer 2 (r_ Indicates RGB Controls)
     * ,-----------------------------------------------------------------------------------.
     * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |r_TOG |r_Mode|r_Hue+|r_Hue-|      |      |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |BL_TOG|BL_STEP|     |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_mit(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, BL_TOGG, BL_STEP, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
    ),


    /* MOV
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      | PgUp | CIns |      |      |      | SIns |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Bksp | Home | End  | Shift| Ctrl |PgDown| Left | Down |  Up  | Right| Del  |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |   *******   | Enter|      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     *
     * - Y outputs Control + Insert
     * - P outputs Shift + Insert
     */
    [_MOV] = LAYOUT_planck_mit(
            XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PGUP , C(KC_INS) , XXXXXXX , XXXXXXX , XXXXXXX  , S(KC_INS) , XXXXXXX,
            KC_BSPC , KC_HOME , KC_END  , KC_LSFT , KC_LCTL , KC_PGDN , KC_LEFT   , KC_DOWN , KC_UP   , KC_RIGHT , KC_DEL    , XXXXXXX,
            _______ , XXXXXXX , XXXXXXX , KC_CAPS , XXXXXXX , XXXXXXX , XXXXXXX   , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX   , _______,
            _______ , _______ , _______ , _______ , XXXXXXX ,         _______     , KC_ENT  , _______ , _______  , _______   , _______
            ),
};
