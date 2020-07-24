#include QMK_KEYBOARD_H

#define _NP 0
#define _BL 1

enum custom_keycodes {
  NP = SAFE_RANGE,
  BL,
  PW,
  USER,
  USER_THEN_TABCODE,
  COMBO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty */

  [_NP] = LAYOUT_ortho_6x4(
    KC_ESC,              KC_TAB,  KC_BSPC, MO(_BL),
    KC_NLCK,             KC_PSLS, KC_PAST, KC_PMNS,
    KC_P7,               KC_P8,   KC_P9,   COMBO,
    KC_P4,               KC_P5,   KC_P6,   COMBO,
    USER_THEN_TABCODE,   KC_P2,   KC_P3,   KC_PENT,
    PW,                  PW ,     USER,    KC_PENT
  ),

  [_BL] = LAYOUT_ortho_6x4(
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, BL_ON,   _______, BL_INC,
    _______, BL_TOGG, _______, BL_INC,
    _______, BL_OFF,  _______, BL_DEC,
    BL_BRTG, _______, _______, BL_DEC
  )

};


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case PW:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING("Gil1Gamesh5");
        } else {
            // when keycode PW is released
        }
        break;
    case USER:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING("magermana");
        } else {
            // when keycode PW is released
        }
        break;
    case USER_THEN_TABCODE:
    if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING("magermana\t66886688");
        } else {
            // when keycode PW is released
        }
        break;
    case COMBO:
    if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING("magermana\tGil1Gamesh5\n");
        } else {
            // when keycode PW is released
        }
        break;
    }
    return true;
};

