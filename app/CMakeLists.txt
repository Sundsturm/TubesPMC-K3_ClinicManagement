# Minimum version
cmake_minimum_required(VERSION 3.6)

# Project name
project(tugas_besar_pmc)

# Set the output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

# Set C type compiler
set(CMAKE_C_STANDARD 17)

# Find GTK's package
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)

# Add subdirectory related to the main library
add_subdirectory("../lib" "../build/mainlibbuild")

# List all sources files
file(GLOB GUI_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

# Make source file as a shared library
add_executable(app ${GUI_SOURCES})

# Including all header files
target_include_directories(app
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE "${CMAKE_SOURCE_DIR}/lib/include")

# Including all GTK's header files
target_include_directories(app PRIVATE
    "D:/msysnew/mingw64/bin/../include/gtk-3.0"
    "D:/msysnew/mingw64/bin/../include/pango-1.0"
    "D:/msysnew/mingw64/bin/../include"
    "D:/msysnew/mingw64/bin/../include/harfbuzz"
    "D:/msysnew/mingw64/bin/../include/cairo"
    "D:/msysnew/mingw64/bin/../include/freetype2"
    "D:/msysnew/mingw64/bin/../include/pixman-1"
    "D:/msysnew/mingw64/bin/../include/gdk-pixbuf-2.0"
    "D:/msysnew/mingw64/bin/../include/libpng16"
    "D:/msysnew/mingw64/bin/../include/webp"
    "D:/msysnew/mingw64/bin/../include/atk-1.0"
    "D:/msysnew/mingw64/bin/../include/fribidi"
    "D:/msysnew/mingw64/bin/../include/glib-2.0"
    "D:/msysnew/mingw64/bin/../lib/glib-2.0/include")

# Linking main library related to the program and all GTK's libraries
target_link_libraries(app PRIVATE mainlib)
target_link_libraries(app PRIVATE
    gtk-3
    gdk-3
    z
    gdi32
    imm32
    shell32
    ole32
    uuid
    winmm
    dwmapi
    setupapi
    cfgmgr32
    hid
    winspool
    comctl32
    comdlg32
    pangowin32-1.0
    pangocairo-1.0
    pango-1.0
    harfbuzz
    atk-1.0
    cairo-gobject
    cairo
    gdk_pixbuf-2.0
    gio-2.0
    gobject-2.0
    glib-2.0
    intl)
target_link_directories(app PRIVATE "../lib")
target_link_directories(app PRIVATE ${GTK_LIBRARY_DIRS})

# Add compiler flags to the shared library
target_compile_options(app PRIVATE
    "-ID:/msysnew/mingw64/bin/../include/gtk-3.0"
    "-ID:/msysnew/mingw64/bin/../include/pango-1.0"
    "-ID:/msysnew/mingw64/bin/../include"
    "-ID:/msysnew/mingw64/bin/../include/harfbuzz"
    "-ID:/msysnew/mingw64/bin/../include/cairo"
    "-ID:/msysnew/mingw64/bin/../include/freetype2"
    "-ID:/msysnew/mingw64/bin/../include/pixman-1"
    "-ID:/msysnew/mingw64/bin/../include/gdk-pixbuf-2.0"
    "-ID:/msysnew/mingw64/bin/../include/libpng16"
    "-ID:/msysnew/mingw64/bin/../include/webp"
    "-ID:/msysnew/mingw64/bin/../include/atk-1.0"
    "-ID:/msysnew/mingw64/bin/../include/fribidi"
    "-ID:/msysnew/mingw64/bin/../include/glib-2.0"
    "-ID:/msysnew/mingw64/bin/../lib/glib-2.0/include")
target_compile_options(app PRIVATE ${GTK_CFLAGS_OTHER})
target_compile_options(app PRIVATE "-export-dynamic")
