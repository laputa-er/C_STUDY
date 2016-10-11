#include <stdio.h>
#include <string.h>

#define TITLE_LEN 20
#define AUTHOR_LEN 10
#define DESIGN_LEN 10

/**
 * 礼品册上的商品
 * 可以存储3种类型的商品：书籍、杯子、衬衫
 *
 * @type {struct}
 */
struct catalog_item {
	int stock_number; // 编号
	float price; // 价格
	int item_type; // 分类
	union {
		// 可能是书
		struct {
			char title[TITLE_LEN + 1];
			char author[AUTHOR_LEN + 1];
			int num_pages;
		} book;

		// 可能是杯子
		struct {
			char design[DESIGN_LEN + 1];
		} mug;

		// 可能是衬衫
		struct {
			char design[DESIGN_LEN + 1];
			int colors;
			int sizes;
	 	} shirt;
	} item;
};

int main () {
	// 声明结构体实例
	struct catalog_item bookItem;

	// 为结构体中的联合的成员赋值
	strcpy(bookItem.item.book.title, "three body");

	// 访问结构题中的联合的成员
	printf("%s\n", bookItem.item.book.title);
}