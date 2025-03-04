#Variables
CC = gcc
CFLAGS =  -g -DUNITY_INCLUDE_DOUBLE -Wall -Wextra -Wpedantic -Wconversion
INCLUDES = src/*.h

#Rules
all: bin/test_ex2 bin/main_ex2

build/%.o: src/%.c $(COMMON_DEPS) build bin
	$(CC) $(CFLAGS) -c $< -o $@

bin/main_ex2: build/edit_distance.o build/main.o $(COMMON_DEPS) build bin
	$(CC) -o bin/main_ex2 build/edit_distance.o build/main.o

bin/test_ex2: build/edit_distance_test.o build/edit_distance.o build/unity.o $(COMMON_DEPS) build bin
	$(CC) -o bin/test_ex2  build/edit_distance_test.o build/edit_distance.o build/unity.o 

bin:
	mkdir -p bin

build:
	mkdir -p build

test:
	./bin/test_ex2

clean:
	rm -f build/* bin/*