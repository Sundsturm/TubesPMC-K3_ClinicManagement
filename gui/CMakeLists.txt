# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Define project name
project(guigtk)

# Set C_STANDARD and CPP_STANDARD
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

# Find GTK's package
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

# Include all header files, library, and flags that are related to GTK
include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})
add_definitions(${GTK4_CFLAGS_OTHER})

# List all sources files
file(GLOB GUI_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

# Make source file as a shared library
add_library(guigtk SHARED ${GUI_SOURCES})

# Including all header files related to GUI that have been made
target_include_directories(guigtk PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_link_libraries(guigtk ${GTK4_LIBRARIES})