
set (CMAKE_SYSTEM_NAME Generic)
cmake_minimum_required(VERSION 2.8)

project(Spi_driver)

include (../External/PlatformDependency.cmake)

set(SOURCES
    SpiDriver.cpp
    )

if (${_TARGET_PLATFORM} STREQUAL "AVR")

    set (SOURCES
        ${SOURCES}
        SpiAvr.cpp
        )

elseif (${_TARGET_PLATFORM} STREQUAL "RASPBERRYPI")

endif()

include_directories(
    ../External/include/
    )

add_library(${PROJECT_NAME} STATIC ${SOURCES})
