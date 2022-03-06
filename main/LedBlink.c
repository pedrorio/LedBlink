/* LED Pattern Example
Makes the Onboard LED of ESP32-C3-DevKITM-1 glow in colour pattern from White -> Red -> Green -> Blue -> Yellow
*/
#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"
#include "esp_log.h"
#include "driver/ledc.h"
#include "led_strip.h"
#include "sdkconfig.h"

static const char *TAG = "Led Pattern";

static led_strip_t *pStrip_a;

static void pattern_led(void)
{
/* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
	pStrip_a->set_pixel(pStrip_a, 0, 16, 16, 16);
	vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
	pStrip_a->refresh(pStrip_a, 100);
	pStrip_a->set_pixel(pStrip_a, 0, 255, 0, 0);
	vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
	pStrip_a->refresh(pStrip_a, 100);
	pStrip_a->set_pixel(pStrip_a, 0, 0, 255, 0);
	vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
	pStrip_a->refresh(pStrip_a, 100);
	pStrip_a->set_pixel(pStrip_a, 0, 0, 0, 255);
	vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
	pStrip_a->refresh(pStrip_a, 100);
	pStrip_a->set_pixel(pStrip_a, 0, 255, 255, 0);
	vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
/* Refresh the strip to send data */
	pStrip_a->refresh(pStrip_a, 100);
}
static void configure_led(void)
{
/* LED strip initialization with the GPIO and pixels number*/
	pStrip_a = led_strip_init(CONFIG_BLINK_LED_RMT_CHANNEL, CONFIG_BLINK_GPIO, 1);
/* Set all LED off to clear all pixels */
	pStrip_a->clear(pStrip_a, 50);
}
void app_main(void)
{
/* Configure the peripheral according to the LED type */
	configure_led();

	while (1) {
		ESP_LOGI(TAG, "Example configured to blink GPIO LED!");
		pattern_led();
		vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
	}
}