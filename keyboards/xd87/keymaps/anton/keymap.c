/* Copyright 2018 Alexander Fougner <fougner89 at gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  DISCORD = SAFE_RANGE,
  COMPILE,
  TABLE,
  SHRUG,
  LENNY,
  SHRUG2,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_tkl_iso(\
      KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
      KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
      KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,            KC_DEL,  KC_END,  KC_PGDN, \
      KC_BSPC,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT, KC_NUHS, KC_ENT, \
      KC_LSFT,KC_NUBS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,            KC_UP, \
      KC_LCTL,KC_LGUI,KC_LALT,                KC_SPC,                                 KC_RALT,MO(1), KC_APP,  KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT  ),

  [1] = LAYOUT_tkl_iso(\
      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,             _______, _______, _______, \
      _______,TABLE  ,LENNY  ,SHRUG  ,SHRUG2 ,_______,_______,_______,_______,_______,_______,_______,_______, _______,    KC_VOLU, KC_MPLY, KC_MNXT, \
      _______,KC_BTN1,KC_MS_U,KC_BTN2,_______,_______,_______,_______,_______,_______,_______,_______,_______,             KC_VOLD, KC_MSTP, KC_MPRV, \
      KC_CAPS,KC_MS_L,KC_MS_D,KC_MS_R,_______,_______,_______,_______,_______,_______,_______,_______,_______, _______, \
      _______,_______,_______,_______,COMPILE,_______,KC_WHOM,_______,KC_MAIL,_______,_______,_______,         _______,             BL_TOGG, \
      _______,_______,_______,                _______,                                DISCORD,_______,_______, _______,    BL_DEC,  BL_STEP, BL_INC   )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DISCORD:
      if (record->event.pressed) {
        // when keycode DISCORD is pressed
        SEND_STRING(SS_ALGR(SS_TAP(X_KP_PLUS)));
      } else {
        // when keycode DISCORD is released
      }
      break;

    case COMPILE:
      if(record->event.pressed) {
        SEND_STRING("qmk flash" SS_TAP(X_ENTER));
        bootloader_jump();
      } else {

      }
      break;

    case TABLE:
      if(record->event.pressed) {
        send_unicode_hex_string("0028 FF89 0CA5 76CA 0CA5 FF09 FF89 5F61 253B 2501 253B");
      } else {

      }
      break;

    case LENNY:
      if(record->event.pressed) {
        send_unicode_hex_string("0028 0020 0361 00B0 0020 035C 0296 0020 0361 00B0 0029 000A");
      } else {

      }
      break;

    case SHRUG:
      if(record->event.pressed) {
        send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF 000A");
      } else {

      }
      break;

    case SHRUG2:
      if(record->event.pressed) {
        send_unicode_hex_string("00AF 005C 005C 005C 005F 0028 30C4 0029 005C 005F 002F 00AF 000A");
      } else {

      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
