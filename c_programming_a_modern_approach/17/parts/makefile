invent2:invent2.o readline.o
	gcc invent2.o readline.o -o invent2 -lm -v
invent2.o:invent2.c readline.h
	gcc -Wall -c invent2.c
readline.o:readline.c readline.h
	gcc -c readline.c