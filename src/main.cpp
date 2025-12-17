#include <stdio.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "led.h"
void vTaskCode(void *pv) {
    while(1) {
		led_sw();
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

int main() {
	stdio_init_all();
	sleep_ms(3000);
	led_init();
	xTaskCreate(
        vTaskCode,
        "blink",
        2048,
        NULL,
        1,
        NULL
    );
    vTaskStartScheduler();
    while(1){
		tight_loop_contents();
	}
}