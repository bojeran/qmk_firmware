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
  ST_MACRO_3,
  DE_LSPO,
  DE_RSPC,
};

// Tap Dance declaration
enum {
    TD_ESC_CAPS,
    TD_NO_TG,
    TD_END_F4,
    TD_WIN_ARROW,
    TD_WIN_WASD,
    TD_MAC_ARROW,
    TD_MAC_WASD,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),

    // Comma once for Comma, twice for toggle layer to gaming, tripple for toggle layer to gaming 2
    // That doesn't work out, because you can't get back except you make the key transparent in the
    // gaming layer, which doesn't make sense. You could change to a layer which still have the comma
    // at the same position.
    //[TD_COMMA_TG] = ACTION_TAP_DANCE_LAYER_MOVE(KC_COMMA, 7),

    // The Layer you switch to must have a transparent key at that location!
    // Create it for activating arrow keys. TG(13) is used instead.
    //[TD_NO_TG] = ACTION_TAP_DANCE_LAYER_MOVE(KC_NO, 13),

    //KC_COMMA
    // MEDIA_PLAY_PAUSE once for MEDIA_PLAY_PAUSE, twice for MEDIA_NEXT_TRACK, tripple for MEDIA_PREV_TRACK

    // in vim layer: the key 4 (DOLLAR) once for END and two times for f4
    [TD_END_F4] = ACTION_TAP_DANCE_DOUBLE(KC_END, KC_F4),

    // in win and mac layer: the toggle for WASD and ARROW keys must be pressed twice
    //                       to prevent accidental Layout Switching
    [TD_WIN_ARROW] = ACTION_TAP_DANCE_TOGGLE_LAYER(KC_NO, 7),
    [TD_WIN_WASD] = ACTION_TAP_DANCE_TOGGLE_LAYER(KC_NO, 9),
    [TD_MAC_ARROW] = ACTION_TAP_DANCE_TOGGLE_LAYER(KC_NO, 8),
    [TD_MAC_WASD] = ACTION_TAP_DANCE_TOGGLE_LAYER(KC_NO, 10),

    // in mac layer: Overview and OSL to RtoL Layer on the same key
    //[TD_MAC_OVERMIRROR] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_UP), OSL(10)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // - Fallback: In Case KZ_TRANSPARENT is used, it will Fallback to a key in this Layer
  // - Testing: Quickly test new key combinations.
  [0] = LAYOUT_ergodox_pretty(
    TD(TD_ESC_CAPS),KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_NO,                                          KC_NO,          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           DE_Z,                                           DE_PLUS,        DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_UE,
    TG(1),          LT(5,KC_A),     LCTL_T(KC_S),   LALT_T(KC_D),   LGUI_T(KC_F),   KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           DE_OE,          DE_AE,
    KC_LSHIFT,      LCTL_T(DE_Y),   KC_X,           KC_C,           LGUI_T(KC_V),   KC_B,           DE_COLN,                                        DE_GRV,         KC_N,           RGUI_T(KC_M),   KC_COMMA,       KC_DOT,         DE_MINS,        RSFT_T(KC_ENTER),
    KC_NO,          DE_LESS,        KC_LCTRL,       KC_LALT,        OSL(6),                                                                                                         DE_HASH,        DE_PLUS,        KC_RALT,        KC_NO,          DE_SS,
                                                                                                    KC_PGUP,        KC_PGDOWN,      KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,
                                                                                                                    KC_MEDIA_NEXT_TRACK,KC_MEDIA_PLAY_PAUSE,
                                                                                    KC_SPACE,       KC_BSPACE,      KC_MEDIA_PLAY_PAUSE,KC_AUDIO_MUTE,  KC_DELETE,      KC_SPACE
  ),
  // - Control: Turn on or off Features, Switch to the Layer you like.
  // - Testing: Test Features, Macros, Special Settings
  [1] = LAYOUT_ergodox_pretty(
    KC_NO,          ST_MACRO_0,     ST_MACRO_1,     KC_NO,          KC_NO,          KC_NO,          TG(2),                                          TG(7),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          RESET,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          TG(8),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_ASOFF,       KC_NO,                                                                          KC_NO,          KC_ASON,        KC_NO,          TOGGLE_LAYER_COLOR,KC_NO,       KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          RGB_VAI,        RGB_VAD,        KC_NO,          KC_NO,          TG(4),
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // Windows (OS) Layout with special Vim Layer (5)
  [2] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 TG(3),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           DE_Z,                                           DE_PLUS,        DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_SS,
    DE_CIRC,        LT(5,KC_A),     LCTL_T(KC_S),   LALT_T(KC_D),   LCTL_T(KC_F),   KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           DE_HASH,        KC_ENTER,
    KC_LSHIFT,      LCTL_T(DE_Y),   KC_X,           KC_C,           LGUI_T(KC_V),   KC_B,           LALT(LCTL(KC_TAB)),                             DE_GRV,         KC_N,           RGUI_T(KC_M),   KC_COMMA,       KC_DOT,         DE_MINS,        KC_RSHIFT,
    TD(TD_WIN_WASD),DE_LESS,        KC_LCTRL,       KC_LALT,        OSL(5),                                                                                                         DE_UE,          DE_PLUS,        KC_RALT,        TD(TD_WIN_ARROW),KC_NO,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_SPACE,       LGUI(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE,      KC_SPACE
  ),
  // Mac OS Layout with special Mac OS Vim Layer (6)
  [3] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_NO,                                          KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           DE_Z,                                           DE_PLUS,        DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_SS,
    DE_CIRC,        LT(6,KC_A),     LGUI_T(KC_S),   LALT_T(KC_D),   LGUI_T(KC_F),   KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           DE_HASH,        KC_ENTER,
    KC_LSHIFT,      LCTL_T(DE_Y),   KC_X,           KC_C,           LGUI_T(KC_V),   KC_B,           LCTL(KC_UP),                                    DE_GRV,         KC_N,           RGUI_T(KC_M),   KC_COMMA,       KC_DOT,         DE_MINS,        KC_RSHIFT,
    TD(TD_MAC_WASD),DE_LESS,        KC_LCTRL,       KC_LGUI,        OSL(6),                                                                                                         KC_NO,          DE_PLUS,        KC_RALT,        TD(TD_MAC_ARROW),KC_NO,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_SPACE,       LCTL(KC_DOWN),  KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE,      KC_SPACE
  ),
  // The English Keyboard Layout for Linux
  // -> In Case you have a Linux with an English Keyboard Layout active
  //    and you can't easily change it.
  [4] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_SLASH,                                       KC_EQUAL,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Z,                                           KC_PLUS,        KC_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_SS,
    KC_LCTRL,       LT(6,KC_A),     KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_HASH,        KC_ENTER,
    KC_LSHIFT,      LCTL_T(KC_Y),   KC_X,           KC_C,           KC_V,           KC_B,           KC_COLN,                                        KC_GRAVE,       KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_MINUS,       KC_RSHIFT,
    KC_TRANSPARENT, KC_LABK,        KC_RALT,        KC_LALT,        OSL(5),                                                                                                         KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // Vim Layout for Windows
  [5] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          TD(TD_END_F4),  KC_F5,          KC_NO,                                          KC_NO,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_HOME,        KC_NO,
    LALT(KC_TAB),   LGUI(KC_L),     LCTL(KC_RIGHT), DE_LPRN,        DE_RPRN,        ST_MACRO_3,     KC_NO,                                          KC_TRANSPARENT, DE_EQL,         DE_LPRN,        DE_RPRN,        KC_DOWN,        LCTL(KC_V),     DE_UE,
    DE_CIRC,        KC_TRANSPARENT, DE_PIPE,        DE_LBRC,        DE_RBRC,        DE_BSLS,                                                                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       DE_OE,          DE_AE,
    OSL(11),        LCTL(KC_C),     KC_DELETE,      DE_LCBR,        DE_RCBR,        LCTL(KC_LEFT),  KC_NO,                                          KC_TRANSPARENT, DE_TILD,        DE_AT,          KC_UP,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_LALT,                                                                                                        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_NO,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_SPACE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE
  ),
  // Vim Layout for Mac OS
  [6] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          LGUI(KC_RIGHT), LALT(KC_5),     LALT(KC_6),                                     LALT(KC_5),     LALT(KC_6),     LALT(KC_7),     LALT(KC_8),     LALT(KC_9),     LGUI(KC_LEFT),  KC_NO,
    LGUI(KC_TAB),   LCTL(LGUI(KC_Q)),LALT(KC_RIGHT),RSFT(KC_8),     RSFT(KC_9),     ST_MACRO_3,     KC_NO,                                          KC_NO,          DE_EQL,         KC_NO,          KC_NO,          KC_DOWN,        LGUI(KC_V),     DE_UE,
    DE_CIRC,        KC_TRANSPARENT, LALT(KC_7),     LALT(KC_5),     LALT(KC_6),     LALT(LSFT(KC_7)),                                                               KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       DE_OE,          DE_AE,
    OSL(11),        LGUI(KC_C),     KC_DELETE,      LALT(KC_8),     LALT(KC_9),     LALT(KC_LEFT),  KC_NO,                                          KC_NO,          LALT(KC_N),     LALT(KC_L),     KC_UP,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_NO,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_SPACE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE
  ),
  // Arrow Key Layout Windows
  [7] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // Arrow Key Layout MacOS
  [8] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // Wasd Key Layout Windows
  [9] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_W,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // Wasd Key Layout MacOS
  [10] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_W,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // Right To Left Layout Win+MacOS
  [11] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPACE,                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           DE_HASH,                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_N,           RGUI_T(KC_M),   KC_COMMA,       KC_DOT,         DE_MINS,        KC_ENTER,                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
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

    [2] = { {15,176,169}, {15,176,169}, {15,176,169}, {15,176,169}, {15,176,169}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {169,120,255}, {15,176,169}, {15,176,169}, {15,176,169}, {15,176,169}, {15,176,169}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255} },

    [3] = { {159,58,255}, {159,58,255}, {159,58,255}, {159,58,255}, {159,58,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {169,120,255}, {159,58,255}, {159,58,255}, {159,58,255}, {159,58,255}, {159,58,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255} },

    [4] = { {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {105,255,255}, {105,255,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {0,0,0}, {154,255,255}, {154,255,255}, {249,228,255}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {15,166,195}, {154,255,255}, {154,255,255}, {249,228,255}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [7] = { {15,176,169}, {15,176,169}, {15,176,169}, {15,176,169}, {15,176,169}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {0,183,238}, {35,255,255}, {35,255,255}, {0,183,238}, {0,183,238}, {0,183,238}, {169,120,255}, {15,176,169}, {15,176,169}, {15,176,169}, {15,176,169}, {15,176,169}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255} },

    [8] = { {159,58,255}, {159,58,255}, {159,58,255}, {159,58,255}, {159,58,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {250,159,255}, {27,126,255}, {27,126,255}, {250,159,255}, {250,159,255}, {250,159,255}, {169,120,255}, {159,58,255}, {159,58,255}, {159,58,255}, {159,58,255}, {159,58,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255} },

    [9] = { {15,176,169}, {15,176,169}, {15,176,169}, {15,176,169}, {15,176,169}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {249,228,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {0,0,0}, {15,176,169}, {15,176,169}, {15,176,169}, {15,176,169}, {15,176,169}, {249,228,255}, {249,228,255}, {249,228,255}, {15,176,169}, {249,228,255}, {249,228,255}, {249,228,255}, {15,176,169}, {15,176,169}, {15,176,169}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255} },

    [10] = { {159,58,255}, {159,58,255}, {159,58,255}, {159,58,255}, {159,58,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {0,0,0}, {159,58,255}, {159,58,255}, {159,58,255}, {159,58,255}, {159,58,255}, {250,159,255}, {250,159,255}, {250,159,255}, {159,58,255}, {250,159,255}, {250,159,255}, {250,159,255}, {159,58,255}, {159,58,255}, {159,58,255}, {27,126,255}, {27,126,255}, {0,0,0}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255}, {27,126,255} },

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
    case 4:
      set_layer_color(4);
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
    case 10:
      set_layer_color(10);
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
      // This is the Stanard Control Sequence for tmux.
      SEND_STRING(SS_LCTL(SS_TAP(X_B)));

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
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_Z) SS_DELAY(100) SS_TAP(X_T));

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
