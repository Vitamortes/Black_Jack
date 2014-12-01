CC = gcc -Wall
OBJ = blackjack.o	Elliot.o	Linus.o	Fabien.o

prog :	$(OBJ)
	$(CC) $(OBJ) -o	prog

Fabien.o : Fabien.c Fabien.h
	$(CC) -c Fabien.c

blackjack.o : blackjack.c
	$(CC) -c blackjack.c

Elliot.o : Elliot.c Elliot.h
	$(CC) -c Elliot.c

Linus.o : Linus.c Linus.h
	$(CC) -c Linus.c

