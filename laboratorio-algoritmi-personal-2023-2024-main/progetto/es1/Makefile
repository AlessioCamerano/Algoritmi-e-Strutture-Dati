#Variables
CC = gcc
CFLAGS =  -g -DUNITY_INCLUDE_DOUBLE -Wall -Wextra -Wpedantic -Wconversion
INCLUDES = src/*.h
COMMON_DEPS = $(INCLUDES) Makefile

#Rules
all: bin/main_ex1 bin/test_ex1

build/%.o: src/%.c $(COMMON_DEPS) build bin
	$(CC) $(CFLAGS) -c $< -o $@

bin/main_ex1: build/Sort.o build/main.o build/Record.o $(COMMON_DEPS) build bin
	$(CC) -o bin/main_ex1 build/Sort.o build/main.o build/Record.o

bin/test_ex1: build/SortTest.o build/Sort.o build/unity.o $(COMMON_DEPS) build bin
	$(CC) -o bin/test_ex1  build/SortTest.o build/Sort.o build/unity.o 

bin:
	mkdir bin

build:
	mkdir build

test:
	./bin/test_ex1

clean:
	rm -f build/* bin/*
