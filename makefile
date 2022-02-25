PROJECT_NAME = adts

CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -O3 
OBJECTS = Tester.o List.o

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(PROJECT_NAME)
	rm -f *.o

Tester.o: Tester.c