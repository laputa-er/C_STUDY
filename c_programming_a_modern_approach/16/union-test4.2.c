#include <stdio.h>

/**
 * 混合数据类型，包含整型和浮点型
 * 
 * @typedef {union} Number
 */
typedef union {
	int i;
	float f;
} Number;

int main () {
	// 声明混合型数组
	Number number_array[1000];

	// 赋值
	number_array[0].i = 5; // 第一个值为整型
	number_array[1].f = 3.14; // 第二个值为浮点型

	// 访问
	printf("%d\n", number_array[0].i); // 5
	
	return 0;
}