#### Konfigurasi Sistem ####
# Directories
INCLUDEDIR = /lib/include
LIBSRCDIR = /lib/src
BUILDDIR = /build
MAINDIR = /main

# Compiler dan flags yang digunakan
CC = gcc
CFLAGS = -Wall -g -I$(INCLUDEDIR) -fPIC
LDFLAGS = -shared
LIBS = -L$(BUILDDIR) -lmainlib
#### Selesai ####

# Library source files (.c)
LIB_SOURCES = $(wildcard $(LIBSRCDIR)/*.c)
MAIN_SOURCES = $(wildcard $(MAINDIR)/*.c)

# Generate object files (.o) dari library source files
LIB_OBJECTS = $(LIB_SOURCES:.c=.o)
MAIN_OBJECTS = $(MAIN_SOURCES:.c=.o)

# Target executable
LIB_TARGET = $(BUILDDIR)/libmainlib.so
MAIN_TARGET = $(BUILDDIR)/output

# Rules on default target
all: $(MAIN_TARGET)

# Memastikan path build ada
$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

# Membuat shared library dengan memastikan path build ada terlebih dahulu
$(LIB_TARGET): $(LIB_OBJECTS) | $(BUILDDIR)
	$(CC) $(LDFLAGS) -o $@ $^

# Build program utama dengan memastikan path build ada terlebih dahulu
$(MAIN_TARGET): $(MAIN_OBJECTS) $(LIB_TARGET) | $(BUILDDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean
clean: 
	rm -f $(BUILDDIR)/*.o $(LIB_TARGET) $(MAIN_TARGET)

.PHONY: all clean