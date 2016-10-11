/**
 * Prints a table of compound interest
 */
#include <stdio.h>
 #define NUM_RATES (sizeof(value) / sizeof(value[0]))
 #define INITIAL_BALANCE 100.00

 int main(){
 	int i, low_rate, num_years, year;
 	float value[5];

 	printf("Enter interest rate:");
 	scanf("%d", &low_rate);
 	printf("Enter number of years:");
 	scanf("%d", &num_years);

 	//表格标题行
 	printf("\nYears");
 	for(i = 0; i < NUM_RATES; i++){
 		printf("%6d%%", low_rate + i);//两个%%代表要显示%字符串
 		value[i] = INITIAL_BALANCE;
 	}
 	printf("\n");
 	//各个利率下逐年100美金的价值
 	for(year = 1; year <= num_years; year++){
 		printf("%3d    ", year);
 		for(i = 0; i < NUM_RATES; i++){
 			value[i] += (low_rate+i) / 100.0 * value[i];
 			printf("%7.2f", value[i]);
 		}
 		printf("\n");	
 	}
 	return 0;
 }