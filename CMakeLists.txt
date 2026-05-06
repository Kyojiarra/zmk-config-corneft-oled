# Dodaje custom status screen z logo FalbaTech do builda firmware.
# Aktywne tylko gdy CONFIG_CUSTOM_STATUS_SCREEN=y i wyświetlacz jest włączony.

if(CONFIG_CUSTOM_STATUS_SCREEN)
    zephyr_include_directories(src)
    zephyr_library_sources(
        src/falbatech_logo.c
        src/status_screen.c
    )
endif()
