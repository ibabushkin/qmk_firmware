#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

// TODO: compose layer for cyrillic
// TODO: revamp symbol layer to be useful: see comments
// TODO: default layer: place alt and ralt where meh and hyper reside rn

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.    ,--------------------------------------------------.
 * |      ` |   1  |   2  |   3  |   4  |   5  |      |    |      |   7  |   8  |   9  |   0  |   -  |   =    |
 * |--------+------+------+------+------+-------------|    |------+------+------+------+------+------+--------|
 * | tab    |   Q  |   W  |   E  |   R  |   T  |      |    |    6 |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
 * | esc    |   A  |   S  |   D  |   F  |   G  |------|    |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|   alt|    |ralt  |------+------+------+------+------+--------|
 * | shift  |   Z  |   X  |   C  |   V  |   B  |      |    |      |   N  |   M  |   ,  |   .  |   /  | rshift |
 * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
 *   | comp |      |      | TT(2)| TT(1)|                                | left | down |  up  | right|      |
 *   `----------------------------------'                                `----------------------------------'
 *                                        ,-------------.,------------.
 *                                        |  home|   end||pgd   |pgu   |
 *                                 ,------|------|------||------+------+------.
 *                                 |      | space|   meh||hyper |enter |      |
 *                                 |      |      |------||------|      |      |
 *                                 | super|      |   del||bs    |      | ctrl |
 *                                 `--------------------'`--------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_GRV,  KC_1,  KC_2,  KC_3,     KC_4,     KC_5,    KC_NO,
  KC_TAB,  KC_Q,  KC_W,  KC_E,     KC_R,     KC_T,    KC_NO,
  KC_ESC,  KC_A,  KC_S,  KC_D,     KC_F,     KC_G,
  KC_LSFT, KC_Z,  KC_X,  KC_C,     KC_V,     KC_B,    KC_LALT,
  KC_APP,  KC_NO, KC_NO, TT(MDIA), TT(SYMB),
                                             KC_HOME, KC_END,
                                                      KC_MEH,
                                   KC_LGUI,  KC_SPC,  KC_DEL,
  // right hand
  KC_NO,     KC_7,    KC_8,  KC_9,     KC_0,    KC_MINUS, KC_EQUAL,
  KC_6,      KC_Y,    KC_U,  KC_I,     KC_O,    KC_P,     KC_BSLS,
  KC_H,      KC_J,    KC_K,  KC_L,     KC_SCLN, KC_QUOT,
  KC_RALT,   KC_N,    KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
  KC_LEFT,   KC_DOWN, KC_UP, KC_RIGHT, KC_NO,
  KC_PGDN,   KC_PGUP,
  KC_HYPR,
  KC_BSPACE, KC_ENT,  KC_RCTRL
),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.    ,---------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |    |      |  F7  |  F8  |  F9  |  F10 |  F11 |   F12   |
 * |--------+------+------+------+------+------+------|    |------+------+------+------+------+------+---------|
 * |        |   !  |   @  |   #  |   $  |   %  |      |    |  F6  |   ^  |   &  |   *  |   (  |   )  |         |
 * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+---------|
 * |        |      |      |      |      |      |------|    |------|   [  |   ]  |   '  |   \  |   =  |         |
 * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+---------|
 * |        |      |      |      |      |      |      |    |      |   {  |   }  |   <  |   >  |      |         |
 * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+---------'
 *   |      |      |      |      |      |                                |      |    . |      |      |      |
 *   `----------------------------------'                                `----------------------------------'
 *                                        ,-------------.,------------.
 *                                        |      |      ||      |      |
 *                                 ,------|------|------||------+------+------.
 *                                 |      |      |      ||      |      |      |
 *                                 |      |      |------||------|      |      |
 *                                 |      |      |      ||      |      |      |
 *                                 `--------------------'`--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_TRNS,
  KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                KC_TRNS, KC_TRNS,
                                                         KC_TRNS,
                                      KC_TRNS,  KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
  KC_F6,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, KC_TRNS,
  KC_LBRC, KC_RBRC, KC_QUOT, KC_BSLS, KC_EQUAL, KC_TRNS,
  KC_LCBR, KC_RCBR, KC_LT,   KC_GT,   KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.    ,---------------------------------------------------.
 * |        |      |      |      |      |      |      |    |      |      |      |      |      |      |         |
 * |--------+------+------+------+------+-------------|    |------+------+------+------+------+------+---------|
 * |        |      |      |      |      |      |      |    |      |      |  ma0 |  ma1 |  ma2 |      |         |
 * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+---------|
 * |        |      |      |      |      |      |------|    |------|  ml  |  md  |  mu  |  mr  |      |         |
 * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+---------|
 * |        |      |      |      |      |      |      |    |      |  sl  |  sd  |  su  |  sr  |      |         |
 * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+---------'
 *   |      |      |      |      |      |                                | volup| voldo|  mute|  brup|  brdo|
 *   `----------------------------------'                                `----------------------------------'
 *                                        ,-------------.,-------------.
 *                                        | lock |      ||      |      |
 *                                 ,------|------|------||------+------+------.
 *                                 |      |      |      ||      |      |      |
 *                                 |  off |sleep |------||------|  mlc |  mrc |
 *                                 |      |      |      ||  mmc |      |      |
 *                                 `--------------------'`--------------------'
 */
[MDIA] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                            LGUI(KC_S), KC_TRNS,
                                                        KC_TRNS,
                                     KC_PWR,   KC_SLEP, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS,
           KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS,
                    KC_VOLU, KC_VOLD, KC_MUTE, KC_BRIU, KC_BRID,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_BTN2, KC_BTN1, KC_BTN3
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
