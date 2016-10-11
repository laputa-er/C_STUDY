/**
 * Maintains a parts database (linked list version)
 */
#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
 /**
  * 定义零件
  */
 struct part {
 	int number; // 编号
 	char name[NAME_LEN + 1]; // 名字长度
 	int on_hand; // 当前库存
 	struct part *next; // 指向下一个零件
 };

// 链表（头节点）
struct part *inventory = NULL;

struct part *find_part (int number);
void insert (void);
void search (void);
void update (void);
void print (void);
int compare_parts (const void *p, const void *q);
int main(){
 	char code;
 	for (;;) {
 		printf("Enter operation code:");
 		scanf(" %c", &code);
 		// 跳过换行符
 		while (getchar() != '\n')
 			;
 		switch (code) {
 			case 'i': insert();
 				break;
 			case 's': search();
 				break;
 			case 'u': update();
 				break;
 			case 'p': print();
 				break;
 			case 'q': return 0;
 			default: printf("Illegal code\n");
 		}
 		printf("\n");
 	}
}

/**
 * 比较函数（提供给qsort函数最为排序规则）
 * @param  p 第一个零件
 * @param  q 第二个零件
 * @return   正数（1）：*p > *q;负数（-1）：*p < *q;零（0）：*p = *q
 */
int compare_parts (const void *p, const void *q) {
	return ((struct part *) p)->number - ((struct part *) q)->number;
}

/**
 * 搜索零件
 * @param  number 零件包含的值
 * @return        对应零件节点的地址（没找到返回NULL）
 */
 struct part *find_part (int number) {
 	struct part *p;
 	for (p = inventory; p != NULL && number > p->number; p = p ->next)
 		;
 	if (p != NULL && number == p->number) {
 		return p;
 	}
 	return NULL;
 }

/**
 * 插入一种零件
 */
void insert (void) {
 	struct part *cur, *prev, *new_node;
 	// 为新节点分配空间
 	new_node = malloc(sizeof(struct part));
 	if (new_node == NULL) {
 		printf("Database is full; can't add more parts.\n");
 		return;
 	}
 	// 零件编号
 	printf("Enter part number:");
 	scanf("%d", &new_node->number);

 	// 根据编号寻找插入位置(按从小到大的顺序排列)
 	for (cur = inventory, prev = NULL; cur != NULL && new_node->number > cur->number; prev = cur, cur = cur->next)
 		;

 	// 发现编号相同的节点
 	if (cur != NULL && new_node->number == cur->number) {
 		printf("Part already exits.\n");
 		free(new_node);
 		return;
 	}

 	// 零件名
 	printf("Enter part name:");
 	read_line(new_node->name, NAME_LEN);

 	// 零件数量
 	printf("Enter quantity on hand:");
 	scanf("%d", &new_node->on_hand);

 	// 插入进去
 	new_node->next = cur;
 	if (prev == NULL) {
 		inventory = new_node;
 	}
 	else {
 		prev->next = new_node;
 	}
 }

/**
 * 以交互的方式根据编号搜索并显示目标零件
 */
void search (void) {
	int number;
	struct part *p;
	printf("Enter part number:");
	scanf("%d", &number);
	p = find_part(number);
	if (p != NULL) {
		printf("Part name: %s\n", p->name);
		printf("Quantity on hand: %d\n", p->on_hand);
	}
	else {
		printf("Part not found.\n");
	}
}

/**
 * 修改零件
 */
void update (void) {
 	int number, change;
 	struct part *p;

 	printf("Enter part number:");
 	scanf("%d", &number);
 	p = find_part(number);
 	if (p != NULL) {
 		printf("Enter change in quantity on hand:");
 		scanf("%d", &change);
 		p->on_hand += change;
 	}
 	else {
 		printf("Part not found.\n");
 	}
 }

/**
 * 打印所有零件
 */
void print (void) {
 	struct part *p;
 	printf("Part number    Part Name   Quantity on hand\n");
 	for (p = inventory; p != NULL; p = p->next) {
 		printf("%7d      %-25s%11d\n", p->number, p->name, p->on_hand);
 	}
 }