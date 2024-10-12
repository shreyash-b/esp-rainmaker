#pragma once

#include <esp_rmaker_ota.h>
#include <esp_timer.h>

typedef struct {
    esp_rmaker_ota_cb_t ota_cb;
    esp_rmaker_post_ota_diag_t ota_diag;
    void *priv;
    bool ota_in_progress;
    bool ota_valid;
    char *ota_url;
    char *fw_version;
    char *ota_job_id;
    char *metadata;
    int filesize;
    esp_timer_handle_t autofetch_timer;
    esp_timer_handle_t rollback_timer;
} esp_rmaker_ota_https_t;

#define OTA_HTTPS_NVS_PART_NAME     "nvs"
#define OTA_HTTPS_NVS_NAMESPACE    "rmaker_ota"
#define OTA_HTTPS_JOB_ID_NVS_NAME  "rmaker_ota_id"