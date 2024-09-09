# the compiler: gcc for C program, define as g++ for C++
  CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET = fracturing

default: all

all: build test execute clean

build: $(TARGET).c
	$(CC) $(CFLAGS) $(TARGET).c -o $(TARGET) -lm

test: build
	bash check_build.sh

execute: $(TARGET)
	./$(TARGET) < test_inputs.txt > out.txt

clean: 
	$(RM) $(TARGET)