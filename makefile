CC = gcc -Wall
OBJ = blackjack.o	fonctions.o

prog :	$(OBJ)
	$(CC) $(OBJ) -o	prog

fonctions.o : fonctions.c fonctions.h
	$(CC) -c fonctions.c

blackjack.o : blackjack.c
	$(CC) -c blackjack.c
