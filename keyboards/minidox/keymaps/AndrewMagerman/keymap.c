#include QMK_KEYBOARD_H
#include "keymap_german_ch.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTZ 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// macro keys
#define CALTDEL LCTL(LALT(KC_DEL)) // ctrl-alt-del
#define CALTESC LCTL(LSFT(KC_ESC)) // ctrl-alt-esc
#define CALT LCTL(KC_LALT) // ctrl-alt
#define MUTE KC_AUDIO_MUTE
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define VOL_UP KC_AUDIO_VOL_UP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTZ] = LAYOUT( \
  CH_Q,    CH_W,    CH_E,    CH_R,    CH_T,                       CH_Z,    CH_U,    CH_I,    CH_O,    CH_P, \
  CH_A,    CH_S,    CH_D,    CH_F,    CH_G,                       CH_H,    CH_J,    CH_K,    CH_L,    KC_SPC,  \
  CH_Y,    CH_X,    CH_C,    CH_V,    CH_B,                       CH_N,    CH_M,    CH_COMM, CH_DOT,  CH_MINS,  \
          KC_LCTRL, MO(_LOWER), MO(_RAISE),		                  KC_LGUI, KC_LSFT, KC_LALT \
),

[_RAISE] = LAYOUT( \
  CH_EXLM,  CH_QST,   CH_PARA, CH_DLR,  CH_HASH,                  CH_PLUS,  CH_7,    CH_8,   CH_9,    CH_0,  \
  CH_CIRC,  CH_QUOT,  CH_DQOT, CH_GRV,  CH_AMPR,              	  CH_ASTR,  CH_4,    CH_5,   CH_6,    CH_EQL, \
  CH_SLSH,  CH_PIPE,  CH_BSLS, CH_AT,   CH_EURO,                  CH_PERC,  CH_1,    CH_2,   CH_3,    KC_TAB,  \
                      _______, _______, _______,                  _______,  _______,  _______ \
),

[_LOWER] = LAYOUT( \
  _______,  CH_RCBR,  CH_RBRC,  CH_RPRN,  CH_LESS,                KC_HOME,      KC_PGDOWN,  KC_PGUP,  KC_END,   CH_TILD,  \
  KC_ESC,   CH_LCBR,  CH_LBRC,  CH_LPRN,  CH_MORE,                KC_LEFT,      KC_DOWN,    KC_UP,    KC_RIGHT, KC_ENT,  \
  KC_BSPC,  KC_DEL,   _______,  _______,  KC_PSCR,                _______,      CH_AE,      CH_OE,    CH_UE,    _______,  \
                        _______, _______, _______,                _______,      MO(_ADJUST),_______  \
),


[_ADJUST] = LAYOUT( \
  MUTE,    VOL_DOWN,  _______,  _______,  VOL_UP,                 _______,   KC_F7,    KC_F8,    KC_F9,   KC_F10,  \
  CALTESC,  CALTDEL,  _______,  CALT,     _______,                _______,   KC_F4,    KC_F5,    KC_F6,   KC_F11,  \
  RESET,    _______,  _______,  _______,  _______,                _______,   KC_F1,    KC_F2,    KC_F3,   KC_F12,  \
                      _______,  _______,  _______,                _______,  _______,  _______  \
)};

void matrix_init_user(void) {
  set_single_persistent_default_layer(_QWERTZ);
};
