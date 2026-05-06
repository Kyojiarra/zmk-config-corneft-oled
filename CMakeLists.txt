# Custom status screen for Corne FT z OLED
# Wzór z corneish_zen w upstream ZMK

if(CONFIG_CUSTOM_STATUS_SCREEN)
  zephyr_library()
  zephyr_library_sources(src/falbatech_logo.c)
  zephyr_library_sources(src/status_screen.c)
  zephyr_library_include_directories(${ZEPHYR_LVGL_MODULE_DIR})
  zephyr_library_include_directories(${ZEPHYR_BASE}/lib/gui/lvgl/)
  zephyr_library_include_directories(${CMAKE_SOURCE_DIR}/include)
  zephyr_library_include_directories(src)
endif()
