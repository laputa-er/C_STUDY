/**
 * Compaer a Universal Prouct Code check digit
 */
#include <stdio.h>
 int main(){
 	int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total;
 	/*输入左边第一位数字*/
 	printf("Enter the first (single) digit:");
 	scanf("%d", &d);
 	/*输入2-6位数字*/
 	printf("Enter first groun of value digits:");
 	scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
 	/*输入7-11位数字*/
 	printf("Enter second group of five digits:");
 	scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
 	first_sum = d + i2 + i4 + j1 + j3 + j5;
 	second_sum = i1 + i3 + i5 + j2 + j4;
 	total = 3 * first_sum + second_sum;

 	printf("Check digit:%d\n", 9 - ((total - 1) % 10));

 	return 0;

 }