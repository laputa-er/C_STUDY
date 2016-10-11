/**
 * Reverses a series of numbers (pointer version)
 */
#include <stdio.h>
 #define N 10
 int main(){
 	int a[N], *p;

 	//输入N个数组存储到数组中
 	printf("Enter %d numbers\n", N);
 	for(p = a; p < a + N; p++){
 		scanf("%d", p);
 	}

 	//逆向打印所有数组元素
 	printf("In reverse order:");
 	for(p = a + N -1; p >= a; p--){
 		printf(" %d", *p);
 	}
 	printf("\n");

 	return 0;
 }