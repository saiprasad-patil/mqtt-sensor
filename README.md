<p align="center">
  <a href="https://mqtt.org/">
    <img src="https://hornerautomation.eu/wp-content/uploads/2021/11/mqtt-ver.png" alt="Logo" width=72 height=72>
  </a>

<h3 align="center">MQTT Sensor</h3>

In this project, I utilized ESP32 and the HC-SR04 sensor to develop a streamlined system for remote data monitoring. By employing ESP-IDF over MQTT, the sensor readings are efficiently sent to a HiveMQ broker. This seamless integration allows for easy access and analysis of real-time data from remote locations, making it ideal for applications like environmental monitoring, industrial automation, and smart agriculture. 

## Requirements

**Hardware**

- ESP32 development kit
- Micro USB cable
- HC-SR04 ultrasonic sensor module
- Connecting wires

**Software**

- [ESP-IDF v5](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/)

## File Structure


```text
sensor_to_mqtt/
└── components/
    └── mqtt_start/
    └── wifi_start/
└── main/
    ├── CMakeLists.txt
    ├── sensor_to_mqtt.c
└── CMakeLists.txt
└── sdkconfig
    
```

## Building

- Open sensor_to_mqtt in cmd
- Run export.bat to set up ESP-IDF environment
- Add details to files such as Wi-Fi SSID, password, mqtt broker username, password, uri etc.
- Make sure to connect esp32 to your PC and sensor to pins as provided in code.
- Run   
  ```idf.py build flash monitor```


## Documentation
- [esp-wifi](https://docs.espressif.com/projects/esp-idf/en/v5.1/esp32/api-reference/network/esp_wifi.html)
- [esp-mqtt](https://docs.espressif.com/projects/esp-idf/en/v5.1/esp32/api-reference/protocols/mqtt.html)
- [esp-tls](https://docs.espressif.com/projects/esp-idf/en/v5.1/esp32/api-reference/protocols/esp_tls.html)
- [esp-gpio](https://docs.espressif.com/projects/esp-idf/en/v5.1/esp32/api-reference/peripherals/gpio.html)
- [FreeRTOS](https://docs.espressif.com/projects/esp-idf/en/v5.1/esp32/api-reference/system/freertos_idf.html)
- [HiveMQ](https://docs.hivemq.com/hivemq/4.17/user-guide/getting-started.html#get-started)
  
## Thank You!




