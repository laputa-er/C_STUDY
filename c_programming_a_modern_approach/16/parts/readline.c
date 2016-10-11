#include <ctype.h>
#include <stdio.h>
#include "readline.h"

/**
 * 读入一行
 * 会跳过开头的空白符
 *
 * @param  str 读入的内容
 * @param  n   字符串的内容
 * @return     读入字符的个数
 */
int read_line(char str[], int n) {
	// ch的类型为int而不是char，便于判定EOF
	int ch, i =0;
	// 跳过所有空白符
	while (isspace(ch = getchar()))
		;
	while (ch != '\n' && ch != EOF) {
		if (i < n) {
			str[i++] = ch;
		}
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}