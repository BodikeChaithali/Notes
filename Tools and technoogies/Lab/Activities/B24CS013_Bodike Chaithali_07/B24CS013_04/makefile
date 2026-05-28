CC = gcc
CFLAGS = -Wall -std=c11
OBJ = main.o functions.o
TARGET = program

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c
functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c
clean:
	rm -f $(OBJ) $(TARGET)
