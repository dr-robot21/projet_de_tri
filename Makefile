# Compiler and flags
CC = gcc
CFLAGS = -Wall -O2 -Iinclude

# Source directory
SRC_DIR = src

# All .c files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Executable name
TARGET = app

# Default rule
all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Clean: only remove executable
clean:
	rm -f $(TARGET)

re: clean all

.PHONY: all clean re
