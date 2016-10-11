#include <stdio.h>

#include "stack.h"
int main(){
	//编译器会通过stack.h中make_empty的原型找到对应的定义，从而正确调用
	make_empty();
}