#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "example.dat"

int main () {
	FILE *fp;

	// 1.大开文件
	fp = fopen(FILE_NAME, "r");
	if (fp == NULL) {
		printf("Cant't open %s\n", FILE_NAME);
		exit(EXIT_FAILURE);
	}
	else {
		printf("Opened!\n");
	}

	// 2.操作文件
	// ...
	// 3.关闭文件
	fclose(fp);
	return 0;
}