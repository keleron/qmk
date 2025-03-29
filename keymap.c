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

#include QMK_KEYBOARD_H

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_4 LALT_T(KC_4)
#define HOME_5 LCTL_T(KC_5)
#define HOME_6 LSFT_T(KC_6)

enum layer_names { _BASE, _MOVE, _SYMBOLS, _NUMBERS, _FN };

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&delete_key_override,
	NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(

        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TAB, HOME_A, HOME_S, HOME_D, HOME_F, KC_G, KC_H, HOME_J, HOME_K, HOME_L, HOME_SCLN, KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, LSFT(KC_SCLN), LSFT(KC_QUOT),
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--l------+--------+--------+--------+--------|
        XXXXXXX, MO(_NUMBERS), KC_ENT, KC_SPC, OSL(_SYMBOLS), KC_DEL
        //`--------------------------'  `-----------------------
        ),

    [_NUMBERS] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC, XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX, KC_HOME, KC_PGUP, KC_UP, KC_PGDN, XXXXXXX, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TAB, KC_LGUI, HOME_4, HOME_5, HOME_6, XXXXXXX, KC_END, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, KC_1, KC_2, KC_3, KC_0, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, _______, KC_ENT, KC_SPC, MO(_FN), XXXXXXX
        //`--------------------------'  `--------------------------'
        ),
    [_SYMBOLS] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, LSFT(KC_SLSH), XXXXXXX, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TAB, LSFT(KC_COMM), KC_LCBR, KC_LBRC, KC_LPRN, KC_MINS, KC_PLUS, KC_RPRN, KC_RBRC, KC_RCBR, LSFT(KC_DOT), KC_GRV,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, KC_TILD, KC_BSLS, KC_UNDS, XXXXXXX, XXXXXXX, KC_EQL, KC_SLSH, KC_PIPE, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, MO(_FN), KC_ENT, KC_SPC, OSL(_SYMBOLS), XXXXXXX
        //`----------------_----------'  `-------------------
        ),
    [_FN] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, KC_F1, KC_F2, XXXXXXX, KC_F4, KC_F5, KC_WSCH, XXXXXXX, KC_WFWD, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CW_TOGG, XXXXXXX, XXXXXXX, LCTL(KC_PGUP), KC_WBAK, LCTL(KC_PGDN), XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, _______, KC_ENT, KC_SPC, _______, XXXXXXX
        //`--------------------------'  `--------------------------'
        )
};
