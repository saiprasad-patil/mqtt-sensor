idf_component_register(SRCS "wifi_start.c"
                    INCLUDE_DIRS "include"
                    REQUIRES esp_netif nvs_flash esp_wifi)
