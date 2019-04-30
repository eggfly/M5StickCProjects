#ifndef _APP_NVS_H
#define _APP_NVS_H

#include "nvs_flash.h"
#include "nvs.h"

void nvs_test() {
  // Initialize NVS
  esp_err_t err = nvs_flash_init();
  if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
    // NVS partition was truncated and needs to be erased
    // Retry nvs_flash_init
    ESP_ERROR_CHECK(nvs_flash_erase());
    err = nvs_flash_init();
  }
  ESP_ERROR_CHECK( err );

  // Open
  printf("\n");
  printf("Opening Non-Volatile Storage (NVS) handle... ");
  nvs_handle my_handle;
  err = nvs_open("device_data", NVS_READWRITE, &my_handle);
  if (err != ESP_OK) {
    printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
  } else {
    printf("Done\n");

    // Read
    printf("Reading restart counter from NVS ... ");
    uint32_t restart_counter = 0; // value will default to 0, if not set yet in NVS
    err = nvs_get_u32(my_handle, "restart_counter", &restart_counter);
    switch (err) {
      case ESP_OK:
        printf("Done\n");
        printf("Restart counter = %d\n", restart_counter);
        break;
      case ESP_ERR_NVS_NOT_FOUND:
        printf("The value is not initialized yet!\n");
        break;
      default :
        printf("Error (%s) reading!\n", esp_err_to_name(err));
    }

    // Close
    nvs_close(my_handle);
  }
}
#endif // _APP_NVS_H
