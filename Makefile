make: main.c functions.c conjunto.h
	gcc -o main main.c functions.c

run: main.exe
	./main