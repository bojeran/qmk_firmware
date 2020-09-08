# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LINK_TIME_OPTIMIZATION_ENABLE = yes
COMMAND_ENABLE = no
AUTO_SHIFT_ENABLE = no  # <- do everything via tap dance to be more flexible
SRC = matrix.c
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes


# My Stuff
MOUSEKEY_ENABLE = no
NKRO_ENABLE = yes
TAP_DANCE_ENABLE = yes  # depending how often you tap a key you get another key

