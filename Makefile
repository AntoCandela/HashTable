CC=gcc
CFLAGS=-Wall -g
MAIN=main.exe

$(MAIN): obj/main.o obj/exception.o obj/functions.o
	$(CC) $(CFLAGS) -o $(MAIN) obj/main.o obj/exception.o obj/functions.o

obj/main.o: main.c source/header.h
	$(CC) $(CFLAGS) -c main.c -o obj/main.o

obj/exception.o: source/exception.c source/header.h
	$(CC) $(CFLAGS) -c source/exception.c -o obj/exception.o

obj/functions.o: source/functions.c source/header.h
	$(CC) $(CFLAGS) -c source/functions.c -o obj/functions.o
