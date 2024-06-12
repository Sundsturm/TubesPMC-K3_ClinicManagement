# Add prefix to all the strings in a list
function (add_prefix result_list input_list prefix_var)
    set(out_list "")
    foreach(item ${${input_list}})
        list(APPEND out_list "${prefix_var}${item}")
    endforeach()
    set(${result_list} "${out_list}" PARENT_SCOPE)
endfunction()

# Find GTK's package
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk4)

# List all sources files
file(GLOB GUI_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

# Make source file as a shared library
add_library(guigtk SHARED ${GUI_SOURCES})

# Including all header files related to GUI that have been made
target_include_directories(guigtk PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Including all GTK's header files
target_include_directories(guigtk PRIVATE
    "D:/msysnew/mingw64/bin/../include/gtk-4.0"
    "D:/msysnew/mingw64/bin/../include/pango-1.0"
    "D:/msysnew/mingw64/bin/../include/fribidi"
    "D:/msysnew/mingw64/bin/../include"
    "D:/msysnew/mingw64/bin/../include/harfbuzz"
    "D:/msysnew/mingw64/bin/../include/gdk-pixbuf-2.0"
    "D:/msysnew/mingw64/bin/../include/webp"
    "D:/msysnew/mingw64/bin/../include/cairo"
    "D:/msysnew/mingw64/bin/../include/freetype2"
    "D:/msysnew/mingw64/bin/../include/libpng16"
    "D:/msysnew/mingw64/bin/../include/pixman-1"
    "D:/msysnew/mingw64/bin/../include/graphene-1.0"
    "D:/msysnew/mingw64/bin/../lib/graphene-1.0/include"
    "D:/msysnew/mingw64/bin/../include/glib-2.0"
    "D:/msysnew/mingw64/bin/../lib/glib-2.0/include")

# Linking all GTK's libraries
target_link_libraries(guigtk PRIVATE
    gtk-4
    pangowin32-1.0
    pangocairo-1.0
    pango-1.0
    harfbuzz
    gdk_pixbuf-2.0
    cairo-gobject
    cairo
    graphene-1.0
    gio-2.0
    gobject-2.0
    glib-2.0
    intl)
target_link_directories(guigtk PRIVATE ${GTK_LIBRARY_DIRS})

# Add compiler flags to the shared library
target_compile_options(guigtk PUBLIC
    "-ID:/msysnew/mingw64/bin/../include/gtk-4.0"
    "-ID:/msysnew/mingw64/bin/../include/pango-1.0"
    "-ID:/msysnew/mingw64/bin/../include/fribidi"
    "-ID:/msysnew/mingw64/bin/../include"
    "-ID:/msysnew/mingw64/bin/../include/harfbuzz"
    "-ID:/msysnew/mingw64/bin/../include/gdk-pixbuf-2.0"
    "-ID:/msysnew/mingw64/bin/../include/webp"
    "-ID:/msysnew/mingw64/bin/../include/cairo"
    "-ID:/msysnew/mingw64/bin/../include/freetype2"
    "-ID:/msysnew/mingw64/bin/../include/libpng16"
    "-ID:/msysnew/mingw64/bin/../include/pixman-1"
    "-ID:/msysnew/mingw64/bin/../include/graphene-1.0"
    "-ID:/msysnew/mingw64/bin/../lib/graphene-1.0/include"
    "-ID:/msysnew/mingw64/bin/../include/glib-2.0"
    "-ID:/msysnew/mingw64/bin/../lib/glib-2.0/include")
target_compile_options(guigtk PRIVATE ${GTK_CFLAGS_OTHER})