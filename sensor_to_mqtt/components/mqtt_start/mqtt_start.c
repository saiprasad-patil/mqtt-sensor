#include <stdio.h>
#include "mqtt_start.h"
#include "mqtt_client.h"
#include "freertos/FreeRTOS.h"
#include <inttypes.h>
#include "esp_log.h"
#include "esp_tls.h"
#include <freertos/task.h>
#include "driver/gpio.h"
#include "esp_timer.h"

#define MQTT_TOPIC // Add topic name Eg. /topic
#define MQTT_BROKER_URI // Add mqtt broker uri Eg. mqtt://test.mosquitto.org
#define MQTT_BROKER_PORT 8883   // 1883 for tcp
#define MQTT_BROKER_USERNAME // Add broker username
#define MQTT_BROKER_PASSWORD // Add broker password
#define ECHO_GPIO 19
#define TRIGGER_GPIO 18

static const char *TAG = "ESP_MQTT";

//Function declarations
static void mqtt_pub(esp_mqtt_client_handle_t event_handler);
static float get_distance_cm();

const char* CERTIFICATE; // Create and add a certificate here

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    esp_mqtt_event_handle_t event = event_data;
    esp_mqtt_client_handle_t client = event->client;
    switch ((esp_mqtt_event_id_t)event_id)
    {
    case MQTT_EVENT_CONNECTED:
        int msg_id;
        msg_id = esp_mqtt_client_subscribe(client, MQTT_TOPIC, 1);
        ESP_LOGI(TAG, "MQTT topic: %s subscribed, msg_id = %d", MQTT_TOPIC, msg_id);
        mqtt_pub(client);
        break;
    case MQTT_EVENT_DISCONNECTED:
        printf("MQTT Disconnected \n");
        break;
    case MQTT_EVENT_DATA:
        printf("TOPIC=%.*s\r\n", event->topic_len, event->topic);
        printf("DATA=%.*s\r\n", event->data_len, event->data);
        break;
    default:
        break;
    }
}

static void mqtt_pub(esp_mqtt_client_handle_t client)
{
    gpio_set_direction(ECHO_GPIO, GPIO_MODE_INPUT);
    gpio_set_direction(TRIGGER_GPIO, GPIO_MODE_OUTPUT);
    while (true)
    {
        char DATA[30];
        sprintf(DATA, "Distance is %0.2f cm", get_distance_cm());
        int msg_id;
        msg_id = esp_mqtt_client_publish(client, MQTT_TOPIC, DATA, strlen(DATA), 1, 0);
        ESP_LOGI(TAG, "MQTT published to %s, msg_id = %d", MQTT_TOPIC, msg_id);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

float get_distance_cm()
{
    // Send trigger pulse
    gpio_set_level(TRIGGER_GPIO, 1);
    esp_rom_delay_us(10);
    gpio_set_level(TRIGGER_GPIO, 0);

    // Wait for the echo pulse
    while (!gpio_get_level(ECHO_GPIO))
        ;

    int64_t start_time = esp_timer_get_time();
    while (gpio_get_level(ECHO_GPIO))
        ;

    int64_t end_time = esp_timer_get_time();
    int64_t pulse_duration = end_time - start_time;

    // Speed of sound at sea level is approximately 343 meters per second (34300 cm/s)
    // Distance = (Time in microseconds) * (Speed of sound in air) / (2 * 1000000) (Convert to centimeters)
    float distance = pulse_duration * 34300.0 / (2 * 1000000);
    return distance;
}

static void mqtt_app_start(void)
{
    esp_tls_init();
    const esp_mqtt_client_config_t mqtt_cfg = {
        .broker.address.uri = MQTT_BROKER_URI,
        .broker.address.port = MQTT_BROKER_PORT,
        .broker.verification.certificate = CERTIFICATE,
        .credentials.username = MQTT_BROKER_USERNAME,
        .credentials.authentication.password = MQTT_BROKER_PASSWORD};
    esp_mqtt_client_handle_t client = esp_mqtt_client_init(&mqtt_cfg);
    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);
    ESP_ERROR_CHECK(esp_mqtt_client_start(client));
}

void mqtt(void)
{
    mqtt_app_start();
}
