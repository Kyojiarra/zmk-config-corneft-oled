# Custom status screen with FalbaTech logo on peripheral
# Aktywny gdy CONFIG_ZMK_DISPLAY_STATUS_SCREEN_CUSTOM=y

if(CONFIG_ZMK_DISPLAY_STATUS_SCREEN_CUSTOM)
  zephyr_library()
  zephyr_library_sources(src/falbatech_logo.c)
  zephyr_library_sources(src/status_screen.c)
  zephyr_library_include_directories(${ZEPHYR_LVGL_MODULE_DIR})
  zephyr_library_include_directories(${ZEPHYR_BASE}/lib/gui/lvgl/)
  zephyr_library_include_directories(${CMAKE_SOURCE_DIR}/include)
  zephyr_library_include_directories(src)
endif()
