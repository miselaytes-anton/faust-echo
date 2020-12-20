#include "AC101.h"
#include "FaustSawtooth.h"
#include "esp_log.h"
#include "esp_spi_flash.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"
#include "soc/timer_group_reg.h"
#include "soc/timer_group_struct.h"
#include <stdio.h>

extern "C" {
void app_main(void);
}

void app_main(void) {
  // https://github.com/espressif/arduino-esp32/issues/595#issuecomment-423796631

  AC101 ac101;
  ac101.begin();
  ac101.SetVolumeSpeaker(45);
  printf("volume speaker=%d\n", ac101.GetVolumeSpeaker());

  int SR = 48000;
  int BS = 8;

  FaustSawtooth faustSawtooth(SR, BS);
  faustSawtooth.start();

  while (1) {
    TIMERG0.wdt_wprotect = TIMG_WDT_WKEY_VALUE;
    TIMERG0.wdt_feed = 1;
    TIMERG0.wdt_wprotect = 0;
    faustSawtooth.setParamValue("freq", rand() % (2000 - 50 + 1) + 50);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}