CC = gcc -Wall
OBJ = Battle_arena.o	Elliot.o	Fabien.o

prog :	$(OBJ)
	$(CC) $(OBJ) -o	prog

Battle_arena.o : Battle_arena.c
	$(CC) -c Battle_arena.c

Elliot.o : Elliot.c Elliot.h
	$(CC) -c Elliot.c

Fabien.o : Fabien.c Fabien.h
	$(CC) -c Fabien.c
