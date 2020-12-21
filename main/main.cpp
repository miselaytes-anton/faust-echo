#include "AC101.h"
#include "FaustEcho.h"
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

  AC101 ac101;
  ac101.begin();
  ac101.SetVolumeSpeaker(45);

  int SR = 48000;
  int BS = 8;

  FaustEcho faustEcho(SR, BS);
  faustEcho.start();

  while (1) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}