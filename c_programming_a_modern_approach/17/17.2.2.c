#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 拼接两个字符串并返回一个“新字符串”（不改变原有的两个字符串）
 * @param  s1 要拼接的字符串的第一部分
 * @param  s2 要拼接的字符串的第二部分
 * @return    新字符串地址
 */
char *concat(const char *s1, const char *s2);

int main(int argc, char const *argv[]) {

	printf("%s\n", concat("abc", "def")); // abcdef

	return 0;
}

char *concat(const char *s1, const char *s2) {
	// 定义指向新字符串的临时指针变量
	char *result;

	// 为新字符串分配空间
	result = malloc(strlen(s1) + strlen(s2) + 1);

	// 分配内存失败
	if (result == NULL) {
		printf("Error: malloc failed in concat \n");
		exit (EXIT_FAILURE);
	}

	// 第一部分复制到新字符串的空间中（会有剩余）
	strcpy(result, s1);

	// 第二部分拼接到后面
	strcat(result, s2);

	return result;
}