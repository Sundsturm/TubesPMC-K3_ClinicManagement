# Minimum CMake version required
cmake_minimum_required(VERSION 3.0)

# Project name
project(tugas_besar_pmc)

# Set the output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

# Set CMake Standard
set(CMAKE_C_STANDARD 17)

# Include subdirectories
add_subdirectory("lib/")
add_subdirectory("gui/")

# Add executable from the main code
add_executable(out "${CMAKE_SOURCE_DIR}/main/main.c")

# Include all header files in the project
target_include_directories(out
    PUBLIC "${CMAKE_SOURCE_DIR}/lib/include"
    PUBLIC "${CMAKE_SOURCE_DIR}/gui/include")

# Link the executable file 
target_link_libraries(out
    PRIVATE mainlib
    PRIVATE guigtk
)