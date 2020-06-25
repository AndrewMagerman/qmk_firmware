#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define DSK_LFT LGUI(LCTL(KC_LEFT))
#define DSK_RT  LGUI(LCTL(KC_RIGHT))
#define SHFINS  SFT_T(KC_INS)
#define RUN  LCTL(SFT_T(KC_F10))
#define DEBUG  LCTL(SFT_T(KC_F9))
#define CALTTAB LCTL(LALT(KC_TAB))



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
          ALT_T(KC_ENT), LT(_LOWER, KC_TAB), CTL_T(KC_BSPC),    SFT_T(KC_SPC), LT(_RAISE, KC_DEL), KC_LGUI     \
),

[_RAISE] = LAYOUT( \
  KC_EXLM,    KC_AT,    KC_HASH, KC_DLR,  KC_PERC,      KC_PLUS,   KC_7,     KC_8,   KC_9, KC_0,    \
  KC_CIRC,    KC_AMPR,  KC_TILD, KC_PIPE, KC_BSLS,      KC_MINUS,  KC_4,     KC_5,   KC_6, KC_EQL,  \
  KC_DQT,     KC_QUOT,  KC_UNDS, KC_GRV,  _______,      KC_ASTR,   KC_1,     KC_2,   KC_3, _______, \
                     _______, MO(_ADJUST), _______,     _______,   _______,  _______                \
),


[_LOWER] = LAYOUT( \
  KC_ESC,   KC_HOME, KC_UP,   KC_END,   _______,     KC_LPRN, KC_RPRN, CALTTAB, SHFINS , _______,
  KC_VOLU,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGUP,     KC_LBRC, KC_RBRC, _______, _______, _______, \
  KC_VOLD,  KC_MPRV, KC_MPLY, KC_MNXT,  KC_PGDN,     KC_LCBR, KC_RCBR, _______, _______, _______, \
                    _______, _______, _______,      _______,  MO(_ADJUST), _______                \
),


[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10, \
  _______, DSK_LFT, _______, DSK_RT,  _______,      TSKMGR,  CALTDEL,  _______, KC_F11,   KC_F12, \
  RESET,   _______, _______, _______, _______,      RUN    , DEBUG  ,  _______, _______,  _______,\
                    _______, _______, _______,      _______, _______,  _______                    \
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
  return true;
}
