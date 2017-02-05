fmt:fmt.o word.o line.o
	gcc -o fmt fmt.o word.o line.o
testA: word.o line.o
	ar -rs myReadLine.a word.o line.o
fmt.o:fmt.c word.h line.h
	gcc -c fmt.c
build: myReadLine.a fmt.o
	gcc -o fmt myReadLine.a fmt.o
word.o:word.c word.h
	gcc -c word.c
line.o:line.c line.h
	gcc -c line.c
clean:
	rm fmt.o word.o line.o fmt
