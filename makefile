DIR=build/src build/test bin
OBJECTS=build/src/main.o build/src/deposit.o
CC=gcc
CFLAGS=-c -Wall
#//////////////////////////////////////////////////////
.PHONY: all clean makedir

#//////////////////////////////////////////////////////
all:makedir main deposit deposit-calc

makedir:
	mkdir -p $(DIR)

main:src/main.c
	$(CC)  -o build/src/main.o $(CFLAGS) -Werror src/main.c 

deposit:src/deposit.c
	$(CC)  -o build/src/deposit.o $(CFLAGS)  -Werror src/deposit.c

deposit-calc: $(OBJECTS)
	$(CC) $(OBJECTS) -o bin/deposit-calc

clean:
	rm -rf build/*.* bin/* bin/*.* build/src/*.* build/test/*.*
