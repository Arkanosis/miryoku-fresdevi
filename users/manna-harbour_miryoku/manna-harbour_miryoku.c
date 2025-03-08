// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define MIRYOKU_X(LAYER, STRING) [U_##LAYER] = U_MACRO_VA_ARGS(MIRYOKU_LAYERMAPPING_##LAYER, MIRYOKU_LAYER_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

#if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(U_SYM, KC_ENT), LT(U_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(U_NAV, KC_SPC), LT(U_MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
  #if defined (MIRYOKU_LAYERS_FLIP)
const uint16_t PROGMEM thumbcombos_sym[] = {KC_UNDS, KC_LPRN, COMBO_END};
  #else
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
  #endif
const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
  COMBO(thumbcombos_base_left, LT(U_MEDIA, KC_ESC)),
  COMBO(thumbcombos_nav, KC_DEL),
  COMBO(thumbcombos_mouse, KC_BTN3),
  COMBO(thumbcombos_media, KC_MUTE),
  COMBO(thumbcombos_num, KC_DOT),
  #if defined (MIRYOKU_LAYERS_FLIP)
  COMBO(thumbcombos_sym, KC_RPRN),
  #else
  COMBO(thumbcombos_sym, KC_LPRN),
  #endif
  COMBO(thumbcombos_fun, KC_APP)
};
#endif

const key_override_t kp_0_override = ko_make_with_layers_and_negmods(0, KC_KP_0, KC_0, ~0, MOD_MASK_SHIFT | MOD_BIT(KC_RALT));
const key_override_t kp_1_override = ko_make_with_layers_and_negmods(0, KC_KP_1, KC_1, ~0, MOD_MASK_SHIFT | MOD_BIT(KC_RALT));
const key_override_t kp_2_override = ko_make_with_layers_and_negmods(0, KC_KP_2, KC_2, ~0, MOD_MASK_SHIFT | MOD_BIT(KC_RALT));
const key_override_t kp_3_override = ko_make_with_layers_and_negmods(0, KC_KP_3, KC_3, ~0, MOD_MASK_SHIFT | MOD_BIT(KC_RALT));
const key_override_t kp_4_override = ko_make_with_layers_and_negmods(0, KC_KP_4, KC_4, ~0, MOD_MASK_SHIFT | MOD_BIT(KC_RALT));
const key_override_t kp_5_override = ko_make_with_layers_and_negmods(0, KC_KP_5, KC_5, ~0, MOD_MASK_SHIFT | MOD_BIT(KC_RALT));
const key_override_t kp_6_override = ko_make_with_layers_and_negmods(0, KC_KP_6, KC_6, ~0, MOD_MASK_SHIFT | MOD_BIT(KC_RALT));
const key_override_t kp_7_override = ko_make_with_layers_and_negmods(0, KC_KP_7, KC_7, ~0, MOD_MASK_SHIFT | MOD_BIT(KC_RALT));
const key_override_t kp_8_override = ko_make_with_layers_and_negmods(0, KC_KP_8, KC_8, ~0, MOD_MASK_SHIFT | MOD_BIT(KC_RALT));
const key_override_t kp_9_override = ko_make_with_layers_and_negmods(0, KC_KP_9, KC_9, ~0, MOD_MASK_SHIFT | MOD_BIT(KC_RALT));

const key_override_t **key_overrides = (const key_override_t *[]) {
	&kp_0_override,
	&kp_1_override,
	&kp_2_override,
	&kp_3_override,
	&kp_4_override,
	&kp_5_override,
	&kp_6_override,
	&kp_7_override,
	&kp_8_override,
	&kp_9_override,
	NULL
};
