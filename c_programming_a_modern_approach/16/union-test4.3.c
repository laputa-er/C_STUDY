#include <stdio.h>

#define INT_KIND 0
#define FLOAT_KIND 1

/**
 * 
 * @typedef {struct} 
 */
typedef struct {
	int kind; // 标记字段
	union {
		int i;
		float f;
	} u;
} Number;

/**
 * 根据数据结构的类型以不同的方式打印值
 * 
 * @param {struct} n 要打印的数据结构
 */
void print_number(Number n);

int main() {
	// 声明结构实例
	Number n;

	// 标记字段
	n.kind = INT_KIND;

	// 赋值
	n.u.i = 82;

	// 打印出来
	print_number(n); // 82
}

void print_number(Number n) {
	if (n.kind == INT_KIND) {
		if (n.kind == INT_KIND) {
			printf("%d\n", n.u.i);
		}
		else {
			printf("%g\n", n.u.f);
		}
	}
}
