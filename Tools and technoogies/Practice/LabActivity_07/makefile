CC=gcc
CFLAGS=-Wall -I.
TARGET=pallindrome_check
all: $(TARGET)

$(TARGET): main.o pallindrome.o
	$(CC) $(CFLAGS) main.o pallindrome.o -o $(TARGET)

main.o: main.c pallindrome.h
	$(CC) $(CFLAGS) -c main.c

pallindrome.o: pallindrome.c pallindrome.h
	$(CC) $(CFLAGS) -c pallindrome.c

clean:
	rm -f *.o $(TARGET)
