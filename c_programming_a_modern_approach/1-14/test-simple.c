#include <stdio.h>
#define SIZE  3
void testStringArr();
int main(){
	testStringArr();
}
void testStringArr(){
	
	//字符数组形式声明的字符串
	char strArr[] = {'a', 'b', 'c', '\0'};


	//指针方式声明的字符串
	char *strPointer = "def";

	// strArr = "aaa";
	strPointer = "bbb";
	printf("%s\n", strPointer);
}