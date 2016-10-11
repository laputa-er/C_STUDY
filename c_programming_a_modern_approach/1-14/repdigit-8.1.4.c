/**
 * Checks numbers for repeated digits
 */
#include <stdio.h>
 #define TRUE 1
 #define FALSE 0

 typedef int Bool;

 int main(){
 	Bool digit_seen[10] = {0};
 	int digit;
 	long int n;

 	printf("Enter a number:");
 	scanf("%ld", &n);

 	while(n > 0){
 		//取个位数
 		digit  = n % 10;
 		//检查个位数是不是已经有过一个了，是的话终止循环
 		if(digit_seen[digit]){
 			break;
 		}
 		//以当前个位数作为索引将对应数字元素的值改为TRUE
 		digit_seen[digit] = TRUE;
 		n /= 10;
 	}
 	if(n>0){
 		//n>0说明至少有一个数字发生了重复
 		printf("Repeated digit\n\n");
 	}else{
 		printf("No repeated digit\n\n");
 	}
 	return 0;
 }