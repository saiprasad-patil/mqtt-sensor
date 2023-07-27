<p align="center">
  <a href="https://mqtt.org/">
    <img src="https://mqtt.org/assets/img/mqtt-logo-transp.svg" alt="Logo" width=72 height=72>
  </a>

  <h3 align="center">MQTT Sensor</h3>


## Requirements

Hardware

- ESP32 development kit
- Micro USB cable
- HC-SR04 ultrasonic sensor

Software

- [ESP-IDF v5](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/)

## File Structure


```text
sensor_to_mqtt/
└── build/
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

## Thanks




