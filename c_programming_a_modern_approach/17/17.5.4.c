#include <stdio.h>
#include <stdlib.h>
#define EXIT_FALURE 0
/**
 * @brief 节点
 * @struct
 */
struct node {
	int value;
	struct node *next; // 指向下一个节点
};

/**
 * 添加节点到链表头部
 * 需要注意的是，该函数执行后还需要将头部指向该函数返回的新的节点才能完成插入到链表头部的工作
 * @param  list 要插入的链表（指向头部节点的指针）
 * @param  n    要插入的节点存储的值
 * @return      新的链表（指向新的头节点的指针）
 */
struct node *add_to_list (struct node *list, int n) {
	// 声明新节点
	struct node *new_node;

	// 为新节点分配内存
	new_node = malloc(sizeof(struct node));

	if (new_node == NULL) {
		printf("Error: malloc failed in add_ro list\n");
		exit(EXIT_FALURE);
	}

	new_node->value = n;
	new_node->next = list;
	return new_node;
}

/**
 * 通过命令行完成链表的创建
 * @return  链表的头部
 */
struct node *read_numbers(void) {
	struct node *first = NULL;
	int n;

	printf("Enter a series of intergers (0 to terminate):\n");

	for (;;) {
		scanf("%d", &n);
		if (n == 0) {
			return first;
		}
		first = add_to_list(first, n);
	}
}

int main () {
	// 创建一个含有用户录入的数字的链表
	struct node *num_list;
	num_list = read_numbers();
}