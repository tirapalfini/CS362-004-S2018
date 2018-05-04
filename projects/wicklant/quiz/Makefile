CFLAGS = -Wall -fpic -coverage -lm

testme: testme.c
	gcc -o testme -g testme.c $(CFLAGS)

default: testme

all: testme

clean:
	rm -f *.o testme.exe testme *.gcov *.gcda *.gcno