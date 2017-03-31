DIR=build bin
OBJECTS=build/main.o build/deposit.o
CC=gcc
CFLAGS=-c -Wall
#//////////////////////////////////////////////////////
.PHONY: all clean makedir

#//////////////////////////////////////////////////////
all:  main deposit deposit-calc

makedir:
	mkdir -p $(DIR) 
main:src/main.c
	$(CC)  -o build/main.o $(CFLAGS) -Werror src/main.c 

deposit:src/deposit.c
	$(CC)  -o build/deposit.o $(CFLAGS)  -Werror src/deposit.c

deposit-calc: $(OBJECTS)
	$(CC) $(OBJECTS) -o bin/deposit-calc

clean:
	rm -rf build/*.* bin/* bin/*.*
