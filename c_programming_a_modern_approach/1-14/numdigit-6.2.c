/**
 * Calculates the number od digits in an interger
 */
#include <stdio.h>
 int main(){
 	int digits = 0, n;
 	printf("Enter a nonnegative interger:");
 	scanf("%d",&n);
 	//如果使用while循环，输入0将导致判断错误（认为0为0位数字）
 	do{
 		n /= 10;
 		digits++;
 	}while(n > 0);
 	printf("The number has %d digit(s).\n", digits);
 	return 0;
 }