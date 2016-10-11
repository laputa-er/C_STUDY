/**
 * Checks whether a file can be opened for reading
 */
#include <stdio.h>
int int main(int argc, char const *argv[])
{
	FILE *fp;
	// 如果没有正确调用，给出使用提示
	if (argc != 2) {
		printf("usage: canopen filanem\n");
	}

	// 如果不能以只读方式打开
	if ((fp = fopen(argv[1], "r")) == NULL) {
		printf("%s can't be opened\n", argv[1]);
		return 1;
	}

	// 如果能以只读的方式打开 
	printf("%s can be opened\n", argv[1]);
	fclose(fp);
	return 0;
}