main.exe: obj/main.o obj/exception.o obj/hash_functions.o obj/starter_functions.o
	gcc -o main.exe obj/main.o obj/exception.o obj/hash_functions.o obj/starter_functions.o -Wall

obj/main.o: main.c source/header/header.h
	gcc -c main.c -o obj/main.o -Wall

obj/exception.o: source/exception.c source/header/header.h
	gcc -c source/exception.c -o obj/exception.o -Wall

obj/hash_functions.o: source/hash_functions.c source/header/header.h
	gcc -c source/hash_functions.c -o obj/hash_functions.o -Wall

obj/starter_functions.o: source/starter_functions.c source/header/header.h
	gcc -c source/starter_functions.c -o obj/starter_functions.o -Wall

