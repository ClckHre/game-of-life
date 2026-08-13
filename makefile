CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -lncurses

life: main.o life.o
	$(CC) $(CFLAGS) main.o life.o -o life
main.o: src/main.c src/life.h
	$(CC) $(CFLAGS) -c src/main.c
life.o: src/life.c src/life.h
	$(CC) $(CFLAGS) -c src/life.c
clean:
	rm -f life main.o life.o

.PHONY: clean
