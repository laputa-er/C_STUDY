/**
 * Sorts an array of integers using Quicksort algorthm
 */
#include <stdio.h>

 #define N 12

 void quicksort(int a[], int low, int high);
 void printArr(int a[], int flag);

 int main(){
 	int a[N] = {5,4,7,8,3,0,7,1,9,2,0,6};
 			  
 	quicksort(a, 0, N-1);
 	printArr(a, 3);
 }

/**
 * 打印数组
 * @param {int} a 需要打印的数组
 * @param {int} flag 表示打印时排序处在的状态
 */
void printArr(int a[], int flag){
	printf("%d\n", flag);
	for(int i = 0; i < N; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
/**
 * 自己实现的快排程序：快速排序
 * @param {int} a[] 被排序的数组
 * @param {int} low 起点
 * @param {int} high 终点
 */
 void myquicksort(int a[], int low, int high){
 	printf("%d****%d\n", low, high);
 	if(low >= high){
 		return ;
 	}else{
 		int middleValue = a[low];
 		int emptyPoint = low;
 		int newLow = low, 
 			newHigh = high;
 		
 		/**
 		 * 只要low指针和high指针没有最后相遇，就交替往中间靠拢。并在在这个过程中完成位置的交换。
 		 * 原理是：有点像拆东墙补西墙，把中间数字两边的数字看作东墙和西墙的话，
 		 * 其实就是在东墙上找西墙上的砖补到西墙上，东墙被拿走砖的位置且只能是这个位置需要西墙去补。一来二去就完成了砖的交换过程。
 		 */
 		while(newLow < newHigh){
 			if(newLow == emptyPoint){
 				//待定的位置为低位：高位指针向左移动寻找比中间值小的数
 				while(a[newHigh] >= middleValue){
 					if(newHigh > newLow){
 						newHigh--;	
 					}else{
 						goto done;
 					}
 				}
 				a[emptyPoint] = a[newHigh];
 				emptyPoint = newHigh;
 			}else{
 				//待定的位置为高位：低位指针向右移动寻找比中间值大的数
 				while(a[newLow] <= middleValue){
 					if(newHigh > newLow){
 						newLow++;
 					}else{
 						goto done;
 					}
 				}
 				a[emptyPoint] = a[newLow];
 				emptyPoint = newLow;
 			}
 			printArr(a, 1);
 		}
 		//标记
 		done:
 		a[emptyPoint] = middleValue;
 		printArr(a, 0);
 		if(newLow > low){
 			quicksort(a, low, newLow - 1);	
 		}
 		if(newHigh < high){
 			quicksort(a, newHigh + 1, high);	
 		}
 	}	
 }