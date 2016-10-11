/**
 * Tests signals
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void handler(int sig);
void raise_sig(void);

int main () {
	// 声明函数指针
	void (*orig_handler)(int);

	/*1. 第一次实验*/
	// 注册处理函数
	printf("---first--- %d\n", SIGILL);
	signal(SIGILL, handler);
	// 触发信号
	raise_sig();

	/*2. 第二次实验*/
	// 再次注册,忽略相应信号
	printf("---second---\n");
	orig_handler = signal(SIGILL, SIG_IGN);
	raise_sig();

	/*3. 第三次实验*/
	printf("---third---\n");
	// 更改为第一次实验使用的处理函数
	signal(SIGILL, orig_handler);
	raise_sig();
	return 0;
}

void handler (int sig) {
	printf("Handler called for signal %d\n", sig);
}

void raise_sig (void) {
	raise(SIGILL);
}