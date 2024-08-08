CC = gcc
CFLAGS = -Wall
TARGET = program

# 'make' will create the executable file
all: $(TARGET)

$(TARGET): main.o integration.o utils.o 
	$(CC) main.o integration.o utils.o -o $(TARGET)

main.o: main.c integration.h utils.h 
	$(CC) $(CFLAGS) -c main.c

integration.o: integration.c integration.h
	$(CC) $(CFLAGS) -c integration.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

# 'make clean' will remove the executable file and all .o files
clean:
	rm -f *.o $(TARGET)

.PHONY: all clean
