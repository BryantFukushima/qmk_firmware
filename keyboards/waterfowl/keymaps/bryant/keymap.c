/* Copyright 2022  CyanDuck
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _COLEMAKDH,
    _NAV,
    _SYM,
    _NUM,
    _FUNC,
    _MOUSE,
    _GAMING
};

  

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak-DH
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |                      |   J  |   L  |   U  |   Y  |   '  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |                      |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |  |PLAY |    |CAPS |  |   K  |   H  |   ,  |   .  |   /  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |TO(6)|   | ESC | BSPC  | DEL  |            | ENTER | SPC | TAB  |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_COLEMAKDH] = LAYOUT(
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
  MT(MOD_LSFT, KC_A),    MT(MOD_LALT, KC_R),    MT(MOD_LCTL, KC_S),    MT(MOD_LGUI, KC_T),    KC_G,         KC_M,    MT(MOD_RGUI, KC_N),    MT(MOD_RCTL, KC_E),    MT(MOD_RALT, KC_I),    MT(MOD_RSFT, KC_O),
  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
  TO(6), LT(4,KC_ESC), LT(1,KC_BSPC), LT(3, KC_DEL), KC_MPLY,         KC_CAPS, KC_ENT, LT(2, KC_SPC), LT(5, KC_TAB), KC_4
),

/* NAVNUM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |  UP  | Copy |  Cut |                      | PGUP |  LUP |   Up |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |      | Left | Down | Right| Paste|                      | LLFT | Left | Down | Right| LRGT |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |  SFT |  CTL |  ALT |  GUI | Undo |  |  2  |    |  3  |  | PGDN |  LDN | Home |  End |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |  1  |   |     |       |      |            | ENTER | SPACE | TAB|   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_NAV] = LAYOUT(
  KC_NO,   KC_NO,    KC_UP,    LGUI(KC_C),  LGUI(KC_X),    KC_PGUP,    LALT(KC_UP),    KC_UP,    KC_NO,    KC_NO,
  KC_NO,   KC_LEFT,  KC_DOWN,  KC_RGHT,     LGUI(KC_V),    LGUI(KC_LBRC),     KC_LEFT,    KC_DOWN,    KC_RIGHT,    LGUI(KC_RBRC),
  KC_LSFT, KC_LALT,  KC_LCTL,  KC_LGUI,     LGUI(KC_Z),    KC_PGDN,       LALT(KC_DOWN),    KC_HOME,    KC_END,    KC_NO,
  KC_1, KC_NO, KC_NO, KC_NO, KC_2,         KC_3, KC_ENT, KC_SPC,  KC_TAB, KC_4
),

/* SYM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   {  |   &  |   *  |   |  |   }  |                      |      |      |      |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   (  |   $  |   %  |   ^  |   )  |                      |  \   |   :  |   ;  |   ~  |   `  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   [  |   !  |   @  |   #  |   ]  |  |  2  |    |  3  |  |      | GUI  |  CTL |  ALT |  SFT |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |  1  |   |  =  |   -   |   _  |            |       |    |       |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_SYM] = LAYOUT(
  KC_LCBR, KC_AMPR, KC_ASTR, KC_PIPE, KC_RCBR,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_LPRN, KC_DLR,  KC_PERC, KC_CIRC, KC_RPRN,        KC_BSLS,   KC_COLN, KC_SCLN, KC_TILD, KC_GRV,
  KC_LBRC, KC_EXLM, KC_AT,   KC_HASH, KC_RBRC,        KC_NO,   KC_RGUI, KC_RCTL,   KC_RALT,   KC_RSFT,
  KC_1, KC_EQL, KC_MINS, KC_UNDS, KC_2,         KC_3, KC_NO, KC_NO, KC_NO, KC_4
),

/* NUM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |      |      |      |                      |   +  |   7  |   8  |   9  |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |  SFT |  ALT | CTRL |  GUI |      |                      |   -  |   4  |   5  |   6  |   .  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |      |      |      |  |  2  |    |  3  |  |   =  |   1  |   2  |   3  |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |  1  |   |     |       |      |            | ENTER  | 0 | BSPC  |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_NUM] =  LAYOUT(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_PLUS, KC_7,    KC_8,    KC_9,    KC_NO,
  KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, KC_NO,         KC_MINS, KC_4,    KC_5,    KC_6,    KC_DOT,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_EQL,  KC_1,    KC_2,    KC_3,    KC_NO,
  KC_1, KC_NO, KC_NO, KC_NO, KC_2,         KC_3, KC_ENT, KC_0, KC_BSPC, KC_4
),

/* FUNC
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |      | VOLU |      |                      |      |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |      |      |      | VOLD |      |                      |      |  F4  |  F5  |  F6  |  F11 |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      | Prev | Play | Next |  |  2  |    |  3  |  |      |  F1  |  F2  |  F3  |  F12 |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |  1  |   |     |       |      |            | ENTER | SPC | BSP  |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_FUNC] = LAYOUT(
  KC_NO,  KC_NO,   KC_NO,   KC_VOLU, KC_NO,         KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  KC_NO,  KC_NO,   KC_NO,   KC_VOLD, KC_NO,         KC_NO,   KC_F4,   KC_F5,   KC_F6,   KC_F11,
  KC_NO,  KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT,       KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12,
  KC_1, KC_NO, KC_NO, KC_NO, KC_2,         KC_3, KC_ENT, KC_SPC, KC_BSPC, KC_4
),

/* MOUSE
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      | MUP  |      |      |                      |      |      |      |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |      | MLT  | MDN  | MRT  |      |                      |      | MLBT | MRBT |      |      |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |      |      |      |  |  2  |    |  3  |  |      |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |  1  |   |     |       |      |            | ENTER | SPC | BSP  |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_MOUSE] = LAYOUT(
  KC_NO,  KC_NO,   KC_MS_U,   KC_NO, KC_NO,         KC_NO,  KC_NO,   KC_NO,   KC_NO, KC_NO,
  KC_NO,  KC_MS_L,   KC_MS_D,   KC_MS_R, KC_NO,         KC_NO,  KC_BTN1,  KC_BTN2,   KC_NO, KC_NO,
  KC_NO,  KC_NO,   KC_NO,   KC_NO, KC_NO,         KC_NO,  KC_ACL0,   KC_ACL1,   KC_ACL2, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
),

/* GAMING
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |  TAB |   Q  |  W  |   E   |   R  |                      |   T  |   Y  |   U  |   I  |   O  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |  SFT |  A   |  S  |   D  |   F   |                      |   G  |   H  |   J  |   K  |   L  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |  ALT |  Z   |  X  |  C   |   V   |  |  1  |    |  2  |  |   B  |   N  |   M  |      |   P  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |TO(0)|   | ESC |  SPC  | CTL  |            | ENTER | SPC | BSP  |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_GAMING] = LAYOUT(
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,         KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,
  KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,         KC_G,    KC_H,    KC_J,    KC_K,    KC_L,
  KC_LALT,  KC_Z,    KC_X,    KC_C,    KC_V,         KC_B,    KC_N,    KC_M,    KC_NO,   KC_P,
  TO(0), KC_ESC, KC_SPC, KC_LCTL, KC_1,         KC_2, KC_ENT, KC_SPC, KC_BSPC, KC_3
),
};
