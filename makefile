DIR=build/src build/test bin
OBJECTS=build/src/main.o build/src/deposit.o
CC=gcc
CFLAGS=-c -Wall -Werror
HEADSFILE=src/deposit.h thirdparty/ctest.h
OBJECTS2=build/src/deposit.o build/test/deposit_test.o build/test/main.o build/test/validation_test.o
OPTIONI=-I thirdparty -I src
#//////////////////////////////////////////////////////
.PHONY: all clean makedir mainprog test

#//////////////////////////////////////////////////////
all:makedir mainprog test

makedir:
	mkdir -p $(DIR)


clean:
	rm -rf build/*.* bin/* bin/*.* build/src/*.* build/test/*.*

#//////////////////////////////////////////////////////
#Main programm
mainprog: makedir main deposit deposit-calc

main:src/main.c
	$(CC)  -o build/src/main.o $(CFLAGS) src/main.c 

deposit:src/deposit.c
	$(CC)  -o build/src/deposit.o $(CFLAGS) src/deposit.c

deposit-calc: $(OBJECTS)
	$(CC) $(OBJECTS) -o bin/deposit-calc

#/////////////////////////////////////////////////////
#Test programm
test: makedir  deposit_test test_main validation_test deposit-calc-test

deposit-calc-test: $(OBJECTS2) $(HEADSFILE)
	$(CC) -Wall -Werror $(OBJECTS2) -o bin/deposit-calc-test

deposit_test: test/deposit_test.c $(HEADSFILE)
	$(CC) $(CFLAGS) $(OPTIONI)  test/deposit_test.c -o build/test/deposit_test.o

test_main: test/main.c thirdparty/ctest.h
	$(CC) $(CFLAGS) $(OPTIONI)  test/main.c -o build/test/main.o

validation_test: test/validation_test.c $(HEADSFILE)
	$(CC) $(CFLAGS) $(OPTIONI)  test/validation_test.c -o build/test/validation_test.o