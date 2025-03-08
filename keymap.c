/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include "keycodes.h"
#include QMK_KEYBOARD_H
#include <stdbool.h>

int WINDOWS = 1;

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom(); // enables Rgb, without saving settings
    rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
}

enum custom_keycodes { KC_OS = SAFE_RANGE, KEL_BACK, KEL_FORTH, KEL_GUI, KEL_CTRL };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_OS:
            if (record->event.pressed) {
                WINDOWS = !WINDOWS;
                if (WINDOWS) {
                    rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
                } else {
                    rgb_matrix_sethsv_noeeprom(HSV_WHITE);
                }
            } else {
                // Do something else when release
            }
            return false; // Skip all further processing of this
        case KEL_GUI:
            if (record->event.pressed) {
                if (WINDOWS) {
                    register_code(KC_LGUI);
                } else { // Make it work in mac
                    register_code(KC_LCTL);
                }
            } else {
                if (WINDOWS) {
                    unregister_code(KC_LGUI);
                } else { // Make it work in mac
                    unregister_code(KC_LCTL);
                }
            }
            return false;
        case KEL_CTRL:
            if (record->event.pressed) {
                if (WINDOWS) {
                    register_code(KC_LCTL);
                } else { // Make it work in mac
                    register_code(KC_LGUI);
                }
            } else {
                if (WINDOWS) {
                    unregister_code(KC_LCTL);
                } else { // Make it work in mac
                    unregister_code(KC_LGUI);
                }
            }
        default:
            return true; // Process all other keycodes normally
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_split_3x6_3(

                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  OSM(MOD_LSFT), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  KEL_CTRL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, LSFT(KC_SCLN), LSFT(KC_QUOT),
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KEL_GUI, MO(1), KC_ENT, KC_SPC, MO(2), KC_RALT
                                                                  //`--------------------------'  `------------------

                                                                  ),

                                                              [1] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  OSM(MOD_LSFT), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, KC_DEL,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  KEL_CTRL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KEL_GUI, _______, KC_ENT, KC_SPC, MO(3), KC_RALT
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),

                                                              [2] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, LSFT(KC_SLSH), XXXXXXX, KC_BSPC,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  OSM(MOD_LSFT), LSFT(KC_COMM), KC_LCBR, KC_LBRC, KC_LPRN, KC_MINS, KC_PLUS, KC_RPRN, KC_RBRC, KC_RCBR, LSFT(KC_DOT), KC_GRV,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  KEL_CTRL, XXXXXXX, KC_PIPE, KC_BSLS, KC_QUOT, KC_UNDS, KC_EQL, LSFT(KC_QUOT), KC_SLSH, KC_TILD, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KEL_GUI, MO(3), KC_ENT, KC_SPC, _______, KC_RALT
                                                                  //`----------------_----------'  `-------------------
                                                                  ),

                                                              [3] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  QK_BOOT, KC_F1, KC_F2, XXXXXXX, KC_F4, KC_F5, KC_WSCH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_OS,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, KC_CAPS, CW_TOGG, XXXXXXX, XXXXXXX, LCTL(KC_PGUP), KC_WBAK, KC_WFWD, LCTL(KC_PGDN), XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KEL_GUI, _______, KC_ENT, KC_SPC, _______, KC_RALT
                                                                  //`--------------------------'  `--------------------------'
                                                                  )};
