#include <stdio.h>
#include "word.h"

/**
 * 从输入读入一个字符，并且把遇到的换行符或制表符转换为空格。
 * @return  格式化后的字符
 */
int read_char(void){
	int ch = getchar();
	if(ch == '\n' || ch == '\t'){
		return ' ';
	}
	return ch;
}

/**
 * 读入一个单词
 * @param word 存储位置的指针
 * @param len  word的最大长度
 */
void read_word(char *word, int len){
	int ch, pos = 0;
	
	/*跳过空格，在遇到第一个非空字符时停止*/
	while((ch = read_char()) == ' ')
		;

	/*从一个单词的开头字符读到单词的结尾，这个结尾可能是遇到的一个空格或者文件末尾的结束符*/
	while((ch != ' ' && ch != EOF)){
		if(pos < len){
			word[pos++] = ch;
		}
		ch = read_char();
	}
	word[pos] = '\0';
}