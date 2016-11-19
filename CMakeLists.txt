
cmake_minimum_required(VERSION 2.8)
project(Spi_driver)

set(MCU atmega8)
set(FCPU 8000000UL)

find_program(AVR_AR avr-ar)
find_program(AVR_RANLIB avr-ranlib)
find_program(AVR_CXX avr-g++)

set(SOURCES
    SpiAvrDriver.cpp
    )

include_directories(
    ../External/include/
    )

set(CMAKE_CXX_COMPILER ${AVR_CXX})
set(CMAKE_AR ${AVR_AR})
set(CMAKE_RANLIB ${AVR_RANLIB})
set(CMAKE_CXX_FLAGS "-Wall -Werror -Os -lto -mmcu=${MCU} -DF_CPU=${FCPU}")
set(FLASH_FLAGS "-R .eeprom -R .fuse -R .lock -R .signature")

add_library(${PROJECT_NAME} STATIC ${SOURCES})
