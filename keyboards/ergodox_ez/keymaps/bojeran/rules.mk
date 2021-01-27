# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LTO_ENABLE = yes  # <- Link time optimization
AUTO_SHIFT_ENABLE = no  # <- do everything via tap dance to be more flexible
SRC = matrix.c
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes


# My Stuff
MOUSEKEY_ENABLE = no
# Press down multiple keys at the same time and media keys??
# Not sure what happens with no but diabling this might make the
# the dedicated keyboard port on my KVM switch work.
NKRO_ENABLE = no
TAP_DANCE_ENABLE = yes  # depending how often you tap a key you get another key

# Debug
#CONSOLE_ENABLE = yes  # to enable debugging

# Special Stuff
#BOOTMAGIC_ENABLE = full  # "Holding Space + KEY" does reconfigure the keyboard
COMMAND_ENABLE = no # "Left Shift + Right Shift + Key" does reconfigure the keyboard

# Disables usb suspend check after keyboard startup.
# Usually the keyboard waits for the host to wake it up before any tasks are performed.
# This is useful for split keyboards as one half will not get a wakeup call but must
# send commands to the master.
# This was recommended to me through the QMK support to get it running on a KVM switch.
# But it does not seem to do anything.
NO_USB_STARTUP_CHECK = yes
