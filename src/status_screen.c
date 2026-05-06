/*
 * Custom status screen for Corne FT z OLED
 *
 * Peripheral (prawa połówka): wyświetla logo FalbaTech na pełnym ekranie 128x32
 * Central (lewa połówka): standardowe widgety ZMK (battery, output, layer)
 *
 * Override dla weak symbol zmk_display_status_screen() z core ZMK.
 */

#include <zephyr/kernel.h>
#include <lvgl.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include "falbatech_logo.h"

#if !IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)

/* Peripheral - tylko logo na pełnym ekranie */

lv_obj_t *zmk_display_status_screen(void) {
    lv_obj_t *screen = lv_obj_create(NULL);

    lv_obj_t *logo = lv_image_create(screen);
    lv_image_set_src(logo, &falbatech_logo);
    lv_obj_align(logo, LV_ALIGN_CENTER, 0, 0);

    return screen;
}

#else

/* Central - standardowe widgety ZMK */

#include <zmk/display/widgets/output_status.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/display/widgets/layer_status.h>

#if IS_ENABLED(CONFIG_ZMK_WIDGET_BATTERY_STATUS)
static struct zmk_widget_battery_status battery_status_widget;
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_OUTPUT_STATUS)
static struct zmk_widget_output_status output_status_widget;
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_LAYER_STATUS)
static struct zmk_widget_layer_status layer_status_widget;
#endif

lv_obj_t *zmk_display_status_screen(void) {
    lv_obj_t *screen = lv_obj_create(NULL);

#if IS_ENABLED(CONFIG_ZMK_WIDGET_BATTERY_STATUS)
    zmk_widget_battery_status_init(&battery_status_widget, screen);
    lv_obj_align(zmk_widget_battery_status_obj(&battery_status_widget),
                 LV_ALIGN_TOP_RIGHT, 0, 0);
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_OUTPUT_STATUS)
    zmk_widget_output_status_init(&output_status_widget, screen);
    lv_obj_align(zmk_widget_output_status_obj(&output_status_widget),
                 LV_ALIGN_TOP_LEFT, 0, 0);
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_LAYER_STATUS)
    zmk_widget_layer_status_init(&layer_status_widget, screen);
    lv_obj_align(zmk_widget_layer_status_obj(&layer_status_widget),
                 LV_ALIGN_BOTTOM_LEFT, 0, 0);
#endif

    return screen;
}

#endif
