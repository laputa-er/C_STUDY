#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60//每一行的字符数

char line[MAX_LINE_LEN+1];
int line_len = 0;//当前行字符数
int num_words = 0;//当前行的单词数

void clear_line(void){
	line[0] = '\0';
	line_len = 0;
	num_words = 0;
}

void add_word(const char *word){
	//非第一个单词
	if(num_words > 0){
		line[line_len] = ' ';
		line[line_len + 1] = '\0';
		line_len++;
	}
	strcat(line, word);//将单词拼接上去
	line_len += strlen(word);
	num_words++;
}

int space_remaining(void){
	return MAX_LINE_LEN - line_len;
}

/**
 * 在line中一个一个写字符，如果需要添加额外的空格那么久在每对单词之间停顿。
 */
void write_line(void){
	int extra_spaces, spaces_to_insert, i ,j;
	extra_spaces = MAX_LINE_LEN - line_len;
	for(i = 0; i < line_len; i++){
		if(line[i] != ' '){
			putchar(line[i]);
		}else{
			spaces_to_insert = extra_spaces / (num_words - 1);
			for(j = 1; j <= spaces_to_insert + 1; j ++){
				putchar(' ');
			}
			extra_spaces -= spaces_to_insert;
			num_words--;
		}
	}
	putchar('\n');
}
void flush_line(void){
	if(line_len > 0){
		puts(line);
	}
}