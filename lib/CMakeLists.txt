# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Define project name
project(mainlib)

# All library source files (.c)
file (GLOB LIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

# Make a shared library
add_library(mainlib SHARED ${LIB_SOURCES})

# Include the header files
target_include_directories(mainlib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")