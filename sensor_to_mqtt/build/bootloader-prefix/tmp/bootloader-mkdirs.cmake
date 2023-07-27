# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/saipr/esp/esp-idf/components/bootloader/subproject"
  "C:/Users/saipr/Documents/PSY/Portfolio/sensor_to_mqtt/sensor_to_mqtt/build/bootloader"
  "C:/Users/saipr/Documents/PSY/Portfolio/sensor_to_mqtt/sensor_to_mqtt/build/bootloader-prefix"
  "C:/Users/saipr/Documents/PSY/Portfolio/sensor_to_mqtt/sensor_to_mqtt/build/bootloader-prefix/tmp"
  "C:/Users/saipr/Documents/PSY/Portfolio/sensor_to_mqtt/sensor_to_mqtt/build/bootloader-prefix/src/bootloader-stamp"
  "C:/Users/saipr/Documents/PSY/Portfolio/sensor_to_mqtt/sensor_to_mqtt/build/bootloader-prefix/src"
  "C:/Users/saipr/Documents/PSY/Portfolio/sensor_to_mqtt/sensor_to_mqtt/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/saipr/Documents/PSY/Portfolio/sensor_to_mqtt/sensor_to_mqtt/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/saipr/Documents/PSY/Portfolio/sensor_to_mqtt/sensor_to_mqtt/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
