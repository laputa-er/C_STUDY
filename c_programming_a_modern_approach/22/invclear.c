/**
 * modify a file of part records by setting the quantity
 */
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25	
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
} inventory[MAX_PARTS];

int num_parts;
int main() {
	FILE *fp;
	int i;

	// 打开清单
	if ((fp = fopen("invent.dat", "rb+")) == NULL) {
		fprintf(stderr, "can't open inventory file\n");
		exit(EXIT_FAILURE);
	}

	// 读取零件(元素为结构体的数组)
	num_parts = fread(inventory, sizeof(struct part), MAX_PARTS, fp);
	for (i = 0; i < num_parts; i++) {
		inventory[i].on_hand = 0;
	}

	// 移动到文件开始处
	rewind(fp);

	// 将修改后的清单数据存储到文件中
	fwrite(inventory, sizeof(struct part), num_parts, fp);
	fclose(fp);
	return 0;
}