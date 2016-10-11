/**
 * Maintains a parts database (array version)
 */
#include <stdio.h>
 #include "readline.h"

 #define NAME_LEN 25
 #define MAX_PARTS 100

/**
 * 零件
 */
 struct part {
 	int number;
 	char name[NAME_LEN + 1];
 	int on_hand;
 } inventory[MAX_PARTS];

 int num_parts = 0; // 当前零件的数量

 int find_part (int number);

 void insert(void);
 void search(void);
 void update(void);
 void print(void);

// 循环等待用户操作
 int main () {
 	char code;
 	for (;;) {
 		printf("Enter operation code:");
 		scanf(" %c", &code);

 		// 跳过所有的换行符
 		while (getchar() != '\n')
 			;
 		switch (code) {
 			case 'i':
 				insert();
 				break;
 			case 's':
 				search();
 				break;
 			case 'u':
 				update();
 				break;
 			case 'p':
 				print();
 				break;
 			case 'q':
 				return 0;
 			default:
 				printf("Illegal code\n");
 		}
 		printf("\n");
 	}
 }

/**
 * 按照零件的编号查找零件在清单数组中的下标
 * @param  number 零件的编号
 * @return        零件在清单中的下标
 */
 int find_part (int number) {
 	int i;
 	for (i = 0; i < num_parts; i++) {
 		if (inventory[i].number == number) {
 			return i;
 		}
 	}
 	return -1;
 }

/**
 * 通过命令行插入零件
 */
 void insert (void) {
 	// 输入零件号
 	int part_number;
 	if (num_parts == MAX_PARTS) {
 		printf("Datebase is full, can't add more parts .\n");
 		return;
 	}
 	printf("Enter partnumber: ");
 	scanf("%d", &part_number);
 	if (find_part(part_number) >= 0) {
 		printf("Part already exists.\n");
 		return;
 	}
 	inventory[num_parts].number = part_number;

 	// 输入零件名
 	printf("Enter part name: ");
 	read_line(inventory[num_parts].name, NAME_LEN);
 	printf("Enter quantity on hand: ");
 	scanf("%d", &inventory[num_parts].on_hand);
 	num_parts++;
 }

/**
 * 在命令行根据零件编号搜索零件
 */
 void search (void) {
 	int i, number;
 	printf("Enter part number: ");
 	scanf("%d", &number);
 	i = find_part(number);
 	if (i >= 0) {
 		printf("Part name: %s\n", inventory[i].name);
 		printf("Quantity on hand: %d\n", inventory[i].on_hand);
 	}
 	else {
 		printf("Part not found.\n");
 	}
 }

/**
 * 更新清单中某种零件的数量
 */
 void update(void) {
 	int i, number, change;
 	printf("Enter part number : ");
 	scanf("%d", &number);
 	i = find_part(number);
 	if (i >= 0) {
 		printf("Enter change in quantity on hand: ");
 		scanf("%d", &change);
 		inventory[i].on_hand += change;
 	}
 	else {
 		printf("Part not found.\n");
 	}
 }

/**
 * 打印当前零件清单中所有种类零件的信息
 */
 void print (void) {
 	int i;
 	printf("Part Number   Part Name             "
 		   "Quantity on hand\n");
 	for (i = 0; i < num_parts; i++) {
 		printf("%7d     %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
 	}
 }