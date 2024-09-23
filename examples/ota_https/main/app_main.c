/* OTA HTTPS Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <nvs_flash.h>
#include <app_network.h>
#include <esp_log.h>
#include <esp_rmaker_factory.h>
#include <esp_rmaker_ota_https.h>

static const char *TAG = "app_mmain";

void app_main()
{
    esp_err_t err = esp_event_loop_create_default();
    ESP_ERROR_CHECK(err);

    err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK( err );

    /* esp_rmaker_init() does the initialization of factory partition .
     * However, since we're not calling esp_rmaker_init(), we need to explicitly initialize factory partition.
     */
    err = esp_rmaker_factory_init();
    if (err != ESP_OK){
        ESP_LOGE(TAG, "Failed to initialize rmaker factory partition.");
    }
    ESP_ERROR_CHECK(err);
    

    app_network_init();
    app_network_start(POP_TYPE_RANDOM);

    // This should be called after internet connection is established
    esp_rmaker_ota_https_enable(NULL);
    // Checking OTA on boot
    esp_rmaker_ota_https_fetch();
}