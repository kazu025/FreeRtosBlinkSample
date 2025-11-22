#include <stdio.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"

void vTaskCode(void *pv) {
    const uint LED = 25;
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
    while(1) {
        gpio_put(LED, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_put(LED, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

int main() {
	stdio_init_all();
	sleep_ms(3000);
    xTaskCreate(
        vTaskCode,
        "blink",
        2048,
        NULL,
        1,
        NULL
    );
    vTaskStartScheduler();
    while(1){}
}