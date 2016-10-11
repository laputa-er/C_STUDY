#ifndef LINE_H
#define LINE_H
/**
 * 清空当前行
 */
void clear_line(void);

/**
 * 为当前行追加单词。除了当前行的第一个单词，每个单词前添加一个空格。
 * @param word 追加的单词
 */
void add_word(const char *word);

/**
 * 获得当前行剩余空间大小（字符数）
 * @return  剩余位置的字符数
 */
int space_remaining(void);

/**
 * 写入一行（对其进行调整）
 */
void write_line(void);

/**
 * 写入一行（不进行调整），如果这一行为空则什么也不做
 */
void flush_line(void);
#endif