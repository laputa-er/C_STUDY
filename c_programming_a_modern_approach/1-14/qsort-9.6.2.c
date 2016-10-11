/**
 * Sorts an array of intergers using Quicksort algorithm
 */
#include <stdio.h>
 #define N 10
 /*声明函数*/

 void quicksort(int a[], int low, int high);
 int split(int a[], int low, int high);

 int main(){
 	int a[N], i;

 	/*输入需要排队的数组*/
 	printf("Enter %d numbers to be sorted :", N);
 	for(i = 0; i < N; i++){
 		scanf("%d", &a[i]);
 	}

 	/*调用排序函数进行排序*/
 	quicksort(a, 0, N - 1);

 	/*打印排序好的数组*/
 	printf("In sorted order:");
 	for(i = 0; i < N; i++){
 		printf("%d ", a[i]);
 	}
 }

/**
 * 快排程序
 * @param {Array} a 数组
 * @param {int} low 开始下标 
 * @param {int} high 结束下标
 */
 void quicksort(int a[], int low, high){
 	int middle;
 	if(low >= high){
 		return;
 	}
 	//获得分段的中间位置
 	middle = split(a, low, high);
 	quicksort(a, low, middle -1);
 	quicksort(a, middle + 1, high);
 }

 int split(int a[], int low, int high){
 	int part_element = a[low];
 	for(;;){
 		/*high指针向左移动寻找比part_element小的数，直到找到或low和high指针重合*/
 		while(low < high && part_element <= a[high]){
 			high--;
 		}
 		//如果重合了，说明没有找到
 		if(low >= high){
 			break;
 		}
 		//如果找到了，将找到的比中间值小的数放到当前low指针指向的位置，并将指针向右移动
 		a[low++] = a[high];

 		/*low指针向右移动，寻找比part_element大的数，直到找到一个或low和high重合*/
 		while(low < high && a[low] <= part_element){
 			low++;
 		}
 		//重合了就停止循环
 		if(low >= high){
 			break;
 		}
 		//如果没重合，就讲找到的数移动到high指针指向的位置，并将high的指针向左移动一下
 		a[high--] = a[low];
 		return high;
 	}
 }
