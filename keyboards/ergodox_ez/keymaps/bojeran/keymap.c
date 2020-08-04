#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  DE_LSPO,
  DE_RSPC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_NO,                                          KC_NO,          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           DE_Z,                                           DE_PLUS,        DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_UE,
    TG(1),          LT(11,KC_A),    LCTL_T(KC_S),   LALT_T(KC_D),   LGUI_T(KC_F),   KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           DE_OE,          DE_AE,
    KC_LSHIFT,      LCTL_T(DE_Y),   KC_X,           KC_C,           LGUI_T(KC_V),   KC_B,           DE_COLN,                                        DE_GRV,         KC_N,           RGUI_T(KC_M),   KC_COMMA,       KC_DOT,         DE_MINS,        RSFT_T(KC_ENTER),
    OSL(9),         DE_LESS,        KC_LCTRL,       KC_LALT,        OSL(11),                                                                                                        DE_HASH,        DE_PLUS,        KC_RALT,        KC_NO,          DE_SS,
                                                                                                    KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,
                                                                                                                    KC_AUDIO_MUTE,  KC_MEDIA_PLAY_PAUSE,
                                                                                    KC_SPACE,       KC_BSPACE,      KC_MEDIA_PLAY_PAUSE,KC_AUDIO_MUTE,  KC_DELETE,      KC_SPACE
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_NO,          ST_MACRO_0,     ST_MACRO_1,     KC_NO,          KC_NO,          KC_NO,          TG(2),                                          TG(7),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          RESET,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          TG(8),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_ASOFF,       KC_NO,                                                                          KC_NO,          KC_ASON,        KC_NO,          TOGGLE_LAYER_COLOR,KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          RGB_VAI,        RGB_VAD,        KC_NO,          KC_NO,          TG(5),
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 TG(3),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           DE_Z,                                           DE_PLUS,        DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_SS,
    DE_CIRC,        LT(11,KC_A),    LCTL_T(KC_S),   LALT_T(KC_D),   LGUI_T(KC_F),   KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           DE_HASH,        KC_ENTER,
    KC_LSHIFT,      LCTL_T(DE_Y),   KC_X,           KC_C,           KC_V,           KC_B,           LALT(LCTL(KC_TAB)),                                DE_GRV,         KC_N,           RGUI_T(KC_M),   KC_COMMA,       KC_DOT,         DE_MINS,        KC_RSHIFT,
    KC_NO,          DE_LESS,        KC_LCTRL,       KC_LALT,        OSL(11),                                                                                                        DE_UE,          DE_PLUS,        KC_RALT,        DE_OE,          DE_AE,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_SPACE,       LGUI(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE,      KC_SPACE
  ),
  [3] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_NO,                                          KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           DE_Z,                                           DE_PLUS,        DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_SS,
    DE_CIRC,        LT(12,KC_A),    LGUI_T(KC_S),   LALT_T(KC_D),   LGUI_T(KC_F),   KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           DE_HASH,        KC_ENTER,
    KC_LSHIFT,      LCTL_T(DE_Y),   KC_X,           KC_C,           KC_V,           KC_B,           LCTL(KC_UP),                                    DE_GRV,         KC_N,           RGUI_T(KC_M),   KC_COMMA,       KC_DOT,         DE_MINS,        KC_RSHIFT,
    KC_LALT,        DE_LESS,        KC_LCTRL,       KC_LGUI,        OSL(12),                                                                                                        DE_UE,          DE_PLUS,        KC_NO,          DE_OE,          DE_AE,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_SPACE,       LCTL(KC_DOWN),  KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE,      KC_SPACE
  ),
  [4] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T),     DE_Z,                                           KC_TRANSPARENT, RSFT(DE_Z),     RSFT(KC_U),     RSFT(KC_I),     RSFT(KC_O),     RSFT(KC_P),     RSFT(DE_UE),
    KC_TRANSPARENT, RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G),                                                                     RSFT(KC_H),     RSFT(KC_J),     RSFT(KC_K),     RSFT(KC_L),     RSFT(DE_OE),    RSFT(DE_AE),
    KC_TRANSPARENT, RSFT(DE_Y),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B),     KC_TRANSPARENT,                                 KC_TRANSPARENT, RSFT(KC_N),     RSFT(KC_M),     DE_SCLN,        DE_COLN,        DE_UNDS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_SLASH,                                       KC_EQUAL,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Z,                                           KC_PLUS,        KC_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_SS,
    KC_LCTRL,       LT(11,KC_A),    KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_HASH,        KC_ENTER,
    KC_LSHIFT,      LCTL_T(KC_Y),   KC_X,           KC_C,           KC_V,           KC_B,           KC_COLN,                                        KC_GRAVE,       KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_MINUS,       KC_RSHIFT,
    KC_TRANSPARENT, KC_LABK,        KC_RALT,        KC_LALT,        OSL(11),                                                                                                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,                                          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_MS_BTN5,     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_BTN4,     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_RIGHT, KC_LGUI,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_MS_ACCEL1,   KC_MS_ACCEL0,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           DE_Z,                                           DE_PLUS,        DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_SS,
    KC_NO,          KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           DE_OE,          KC_ENTER,
    KC_LSHIFT,      DE_Y,           KC_X,           KC_C,           KC_V,           KC_B,           OSL(11),                                        DE_GRV,         KC_N,           KC_M,           KC_UP,          KC_DOT,         DE_MINS,        RSFT_T(KC_ENTER),
    KC_NO,          KC_NO,          KC_NO,          KC_LALT,        KC_SPACE,                                                                                                       KC_LEFT,        KC_DOWN,        KC_RIGHT,       DE_AE,          DE_UE,
                                                                                                    KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,
                                                                                                                    KC_AUDIO_MUTE,  KC_MEDIA_PLAY_PAUSE,
                                                                                    KC_SPACE,       KC_BSPACE,      KC_MEDIA_PLAY_PAUSE,KC_AUDIO_MUTE,  KC_DELETE,      KC_SPACE
  ),
  [8] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_NO,          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           DE_Z,                                           KC_TRANSPARENT, DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_SS,
    KC_LCTRL,       KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           DE_HASH,        KC_ENTER,
    KC_LCTRL,       DE_Y,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,                                           KC_F10,         KC_N,           KC_M,           KC_COMMA,       KC_DOT,         DE_MINS,        KC_RSHIFT,
    KC_NO,          DE_LESS,        KC_NO,          KC_LALT,        KC_SPACE,                                                                                                       KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,
                                                                                                    KC_M,           KC_F2,          KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_F3,          KC_TRANSPARENT,
                                                                                    KC_SPACE,       KC_DELETE,      KC_F4,          KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE
  ),
  [9] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_NO,                                          KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_PSCREEN,     DE_EXLM,        DE_DQOT,        DE_LPRN,        DE_RPRN,        DE_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, DE_EQL,         DE_PARA,        KC_NO,          KC_NO,          KC_ASTR,        DE_UE,
    KC_TRANSPARENT, DE_SLSH,        DE_BSLS,        DE_LBRC,        DE_RBRC,        DE_DLR,                                                                         KC_NO,          KC_NO,          KC_NO,          KC_NO,          DE_OE,          DE_AE,
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        DE_LCBR,        DE_RCBR,        DE_EURO,        KC_TRANSPARENT,                                 KC_TRANSPARENT, DE_TILD,        DE_AT,          KC_NO,          KC_NO,          KC_BSLASH,      KC_F14,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_NO,          KC_DOT,         KC_EQUAL,       KC_TRANSPARENT, KC_NO,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [10] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,                                          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    ST_MACRO_2,     KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LSFT(KC_1),     LSFT(KC_2),     LSFT(KC_3),     LSFT(KC_4),     LSFT(KC_5),     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [11] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_END,         KC_F5,          KC_NO,                                          KC_NO,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_HOME,        KC_NO,
    LALT(KC_TAB),   LGUI(KC_L),     LCTL(KC_RIGHT), DE_LPRN,        DE_RPRN,        KC_NO,          KC_NO,                                          KC_TRANSPARENT, DE_EQL,         DE_LPRN,        DE_RPRN,        KC_DOWN,        LCTL(KC_V),     DE_UE,
    DE_CIRC,        KC_TRANSPARENT, DE_PIPE,        DE_LBRC,        DE_RBRC,        DE_BSLS,                                                                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       DE_OE,          DE_AE,
    KC_NO,          LCTL(KC_C),     KC_DELETE,      DE_LCBR,        DE_RCBR,        LCTL(KC_LEFT),  KC_NO,                                          KC_TRANSPARENT, DE_TILD,        DE_AT,          KC_UP,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_NO,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_SPACE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE
  ),
  [12] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          LGUI(KC_RIGHT), LALT(KC_5),     LALT(KC_6),                                     LALT(KC_5),     LALT(KC_6),     LALT(KC_7),     LALT(KC_8),     LALT(KC_9),     LGUI(KC_LEFT),  KC_NO,
    LGUI(KC_TAB),   LCTL(LGUI(KC_Q)),LALT(KC_RIGHT), RSFT(KC_8),     RSFT(KC_9),     KC_NO,          KC_NO,                                          KC_NO,          DE_EQL,         KC_NO,          KC_NO,          KC_DOWN,        LGUI(KC_V),     DE_UE,
    DE_CIRC,        KC_TRANSPARENT, LALT(KC_7),     LALT(KC_5),     LALT(KC_6),     LALT(LSFT(KC_7)),                                                                KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       DE_OE,          DE_AE,
    KC_NO,          LGUI(KC_C),     KC_DELETE,      LALT(KC_8),     LALT(KC_9),     LALT(KC_LEFT),  KC_NO,                                          KC_NO,          LALT(KC_N),     LALT(KC_L),     KC_UP,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_NO,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_SPACE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE
  ),
};


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {14,222,242}, {14,222,242}, {14,222,242}, {14,222,242}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {85,203,158}, {169,120,255}, {31,255,255}, {146,224,255} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {0,0,0}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {30,96,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {15,176,169}, {15,176,169}, {15,176,169}, {15,176,169}, {15,176,169}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {15,176,169}, {15,176,169}, {15,176,169}, {15,176,169}, {15,176,169}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255} },

    [3] = { {159,58,255}, {159,58,255}, {159,58,255}, {159,58,255}, {159,58,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {159,58,255}, {159,58,255}, {159,58,255}, {159,58,255}, {159,58,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255} },

    [5] = { {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {14,222,242}, {14,222,242}, {0,0,0}, {32,176,255}, {0,0,0}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {0,0,0}, {255,220,201}, {255,220,201}, {205,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {32,176,255}, {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [7] = { {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {0,183,238}, {255,255,115}, {255,255,115}, {0,183,238}, {0,183,238}, {0,183,238}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115}, {255,255,115} },

    [8] = { {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150}, {99,255,150} },

    [9] = { {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {141,255,233}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [11] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {105,255,255}, {105,255,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {0,0,0}, {154,255,255}, {154,255,255}, {249,228,255}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [12] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {15,166,195}, {154,255,255}, {154,255,255}, {249,228,255}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
    case 9:
      set_layer_color(9);
      break;
    case 11:
      set_layer_color(11);
      break;
    case 12:
      set_layer_color(12);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

// What happens when you press a Macro Key
// You can lower e.g. the Delay or trigger a custom method
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_C)));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_B) SS_DELAY(100) SS_TAP(X_2));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_1) SS_DELAY(100) SS_TAP(X_TAB) SS_DELAY(100) SS_TAP(X_X));

    }
    break;
    case DE_LSPO:
      perform_space_cadet(record, KC_LSFT, KC_LSFT, KC_8);
      return false;
    case DE_RSPC:
      perform_space_cadet(record, KC_LSFT, KC_LSFT, KC_9);
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

// The three LEDs on the top right
// Change: disable LEDS
uint32_t layer_state_set_user(uint32_t state) {
  return state;
};
