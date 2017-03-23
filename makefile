all: checkdirbin checkdirbuild main deposit deposit-calc
BIN=bin
BUILD=build
checkdirbin:
	@if [ ! -d $(BIN) ] ; then echo "creating $(BIN)" ; mkdir bin; fi
	@if [ -d $(BIN) ] ; then echo "$(BIN) exists"; else echo "$(BIN) not exists, error!"; exit 1; fi
checkdirbuild:
	@if [ ! -d $(BUILD) ] ; then echo "creating $(BUILD)" ; mkdir build; fi
	@if [ -d $(BUILD) ] ; then echo "$(BUILD) exists"; else echo "$(BUILD) not exists, error!"; exit 1; fi
main:src/main.c
	gcc -o build/main.o -c -Wall -Werror src/main.c 

deposit:src/deposit.c
	gcc -o build/deposit.o -c -Wall -Werror src/deposit.c

deposit-calc: build/main.o build/deposit.o
	gcc build/main.o build/deposit.o -o bin/deposit-calc

clean:
	rm -rf build/*.* bin/* bin/*.*


