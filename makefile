BIN=bin
BUILD=build
CHECK=checkdirbuild checkdirbin
OBJECTS=build/main.o build/deposit.o
CC=gcc
CFLAGS=-c -Wall
#//////////////////////////////////////////////////////
.PHONY: all clean

#//////////////////////////////////////////////////////
all: $(CHECK) main deposit deposit-calc

checkdirbin:
	@if [ ! -d $(BIN) ] ; then echo "creating $(BIN)" ; mkdir bin; fi
	@if [ -d $(BIN) ] ; then echo "$(BIN) exists"; else echo "$(BIN) not exists, error!"; exit 1; fi
checkdirbuild:
	@if [ ! -d $(BUILD) ] ; then echo "creating $(BUILD)" ; mkdir build; fi
	@if [ -d $(BUILD) ] ; then echo "$(BUILD) exists"; else echo "$(BUILD) not exists, error!"; exit 1; fi
main:src/main.c
	$(CC)  -o build/main.o $(CFLAGS) -Werror src/main.c 

deposit:src/deposit.c
	$(CC)  -o build/deposit.o $(CFLAGS)  -Werror src/deposit.c

deposit-calc: $(OBJECTS)
	$(CC) $(OBJECTS) -o bin/deposit-calc

clean:
	rm -rf build/*.* bin/* bin/*.*


