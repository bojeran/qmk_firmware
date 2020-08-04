/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 20

#undef TAPPING_TERM
#define TAPPING_TERM 201

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 15

#define AUTO_SHIFT_TIMEOUT 150
#define NO_AUTO_SHIFT_ALPHA
#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define DISABLE_RGB_MATRIX_RAINDROPS


// My stuff
// Free up space
#undef NO_DEBUG
#define NO_DEBUG

#undef NO_PRINT
#define NO_PRINT

// Press more then 6 keys
#define FORCE_NKRO