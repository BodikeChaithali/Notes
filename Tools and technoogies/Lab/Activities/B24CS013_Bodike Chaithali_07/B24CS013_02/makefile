CC = gcc
CFLAGS = -Wall -I.
OBJ = main.o pallindrome.o
TARGET = pallindrome_check

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c pallindrome.h
	$(CC) $(CFLAGS) -c main.c

pallindrome.o: pallindrome.c pallindrome.h
	$(CC) $(CFLAGS) -c pallindrome.c

clean:
	rm -f $(OBJ) $(TARGET)

