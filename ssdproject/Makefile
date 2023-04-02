all: ssd test

ssd: ssd.c
	gcc -c ssd.c
	gcc -o ssd ssd.o
test: test.c
	gcc -c test.c
	gcc -o test test.o

clean:
	rm test.o ssd.o
