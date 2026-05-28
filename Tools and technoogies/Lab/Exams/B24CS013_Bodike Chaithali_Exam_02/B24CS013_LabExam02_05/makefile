CFLAGS=-Wall -O2
TARGET=math_program
all: $(TARGET)

$(TARGET): main.o fact.o fib.o 
	cc $(CFLAGS) main.o fact.o fib.o -o $(TARGET)
main.o: main.c   math_utils.h
	cc $(CFLAGS) main.c -c  main.o
fact.o: fact.c math_utils.h
	cc $(CFLAGS) fact.c -c fact.o
fib.o: fib.c math_utils.h
	cc $(CFLAGS) fib.c -c fib.o
clean:
	rm -rf *.o $(TARGET)
