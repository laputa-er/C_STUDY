/**
 * Tests setjmp/longjmp
 */

#include <setjmp.h>
#include <stdio.h>

/**
 * @type {jmp_buf} env 存储位置数据的全局变量
 */
static jmp_buf env;

void f1 (void);
void f2 (void);

int main () {
	int ret;
	// 获得存储位置
	ret = setjmp(env);
	printf("setjmp returned %d\n", ret);

	// 第二次执行到这里的时候值不为0
	if (ret != 0) {
		printf("Program terminates: longjmp called\n");
		return 0;
	}

	f1();

	// 下面这句不会执行
	printf("Program terminates normally\n");
	return 0;
}

void f1 (void) {
	printf("f1 begins\n");
	f2();
	printf("f1 returns\n");
}
void f2 (void) {
	printf("f2 begins\n");
	// 按照env的值跳转到指定的环境
	longjmp(env, 1);
	printf("f2 returns\n");
}