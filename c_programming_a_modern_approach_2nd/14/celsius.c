//
// Created by TonyEarth on 2016/12/29.
//

/************************************************
 * Converts a Fahrenheit temperature to Celsius *
 * **********************************************/

#include <stdio.h>

#define FREEZING_PT  32.0f
#define SCALE_FACTOR (5.0f / 9.0f)/*如果是(5/9)结果为0*/
int main(){
    float fahrenheit, celsius;

    printf("Enter Fahrenheit temperature:");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;/*温度转换*/

    printf("Celsius equivalent:%.1f\n", celsius);/*保留小数点后一位*/
    return 0;
}