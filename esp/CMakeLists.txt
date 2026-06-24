# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

# Board selection: -DBOARD=<name> via cmake/idf.py, or BOARD env var, or default jc3248w535.
# This must be set BEFORE include(project.cmake) so ESP-IDF reads the right sdkconfig.
if(NOT DEFINED BOARD)
    if(DEFINED ENV{BOARD})
        set(BOARD $ENV{BOARD})
    else()
        set(BOARD "wt99p4c5_s1")
    endif()
endif()
# Use sdkconfig.defaults for Kconfig overrides
set(SDKCONFIG_DEFAULTS "${CMAKE_CURRENT_SOURCE_DIR}/sdkconfig.defaults")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(tiny386)
