fmt.exe:fmt.obj word.obj line.obj
	gcc -o fmt fmt.obj word.obj line.obj
fmt.obj:fmt.c word.h line.h
	gcc -c fmt.c
word.obj:word.c word.h
	gcc -c word.c
line.obj:line.c line.h
	gcc -c line.c
