/**
 * Copy a file(既可以是文本文件，也可以是二进制文件)
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *source_fp, *dest_fp;
	int ch;

	// 如果没有给出正确的参数
	if (argc != 3) {
		fprintf(stderr, "usage: fcopy source dest\n");
		exit(EXIT_FAILURE);
	}

	// 打开原始文件
	if ((source_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "can't open %s\n", argv[1]);
		fclose(source_fp);
		exit(EXIT_FAILURE);
	}

	// 打开目标文件
	if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "can't open %s\n", argv[2]);
		fclose(source_fp);
		exit(EXIT_FAILURE);
	}

	// 复制内容(一个字符一个字符地)
	while ((ch = getc(source_fp)) != EOF) {
		putc(ch, dest_fp);
	}

	fclose(source_fp);
	fclose(dest_fp);
	return 0;
}