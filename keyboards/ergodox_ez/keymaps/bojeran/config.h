/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
// The delay when reading the value of the pin. It actually
// defines how many matrix scans are done before the value
// is considered stable. Therefore this directly affects
// the latency drastically.
// If this is too low you might see a key pressed twice.
// This almost just depends on
// - The actual keyboard electronics and switches. There is
//   usually a short period where the electronic signal is
//   unreliable and can cause the keyboard to detect multiple
//   key presses in succession.
// Caution: When there is solar storm or a strong electro magnetic
//          field nearby you might see more issues with a lower value.
// To determine this value begin with the lowest number 1 and
// increase it by one each time you have issues. Everything
// else would just introduce additional latency.
// When following the complex discussion about the optimal value
// for this it's almost always either 1, 2 or 3. But some
// Ergodox Users use DEBOUNCE 1.
#undef DEBOUNCE
#define DEBOUNCE 1

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


// Either Disable all DEBUGGING or leave it
// enabled.
//#undef NO_DEBUG
//#define NO_DEBUG
// This option allows you to see the Scan Rate
// inside of QMK Toolbox when connected to
// the keyboard.
#define DEBUG_MATRIX_SCAN_RATE

#undef NO_PRINT
#define NO_PRINT

// Press more then 6 keys
#define FORCE_NKRO

// Sets the USB polling rate in milliseconds for the keyboard
// This value is usually rounded down (floor) to a power of 2
// 10ms is rounded to 8ms (125 hz). Gaming Keyboards usually
// have the ability to go to 4ms (250 hz), 2ms (500 hz) and 1ms
// (1000 hz). This will increase the CPU usage on the computer.
#undef USB_POLLING_INTERVAL_MS
#define USB_POLLING_INTERVAL_MS 10

// I don't need all 31 levels of backlight brightness.
// 3 Levels are more then enough. (4 with off)
#undef BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 3

// Ergodox EZ has a relatively slow scan rate therefore it might be
// a good idea to enable QMK_KEYS_PER_SCAN. This might good when
// you press multiple keys at the same time?
//#undef QMK_KEYS_PER_SCAN
//#define QMK_KEYS_PER_SCAN 4