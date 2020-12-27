# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LINK_TIME_OPTIMIZATION_ENABLE = yes
AUTO_SHIFT_ENABLE = no  # <- do everything via tap dance to be more flexible
SRC = matrix.c
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes


# My Stuff
MOUSEKEY_ENABLE = no
NKRO_ENABLE = yes
TAP_DANCE_ENABLE = yes  # depending how often you tap a key you get another key

# Debug
CONSOLE_ENABLE = yes  # to enable debugging

# Special Stuff
#BOOTMAGIC_ENABLE = full  # "Holding Space + KEY" does reconfigure the keyboard
COMMAND_ENABLE = no # "Left Shift + Right Shift + Key" does reconfigure the keyboard

