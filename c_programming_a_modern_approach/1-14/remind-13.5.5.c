/**
 * Prints a one-month reminder list
 * 程序需要读入一系列天和提示的组合，并且按照顺训进行存储（按日期排序）
 * 额外需求：
 * 1. 天在两个字符的域中右对齐
 * 2. 确定用户没有输入两位以上的数字
 */
#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50//备忘录数量
#define MSG_LEN 60//每条备忘的最大长度

 int read_line(char str[], int n);

 int main(){
 	//备忘录列表
 	char reminders[MAX_REMIND][MSG_LEN + 3];

 	//日期字符串和信息字符串
 	char day_str[3], msg_str[MSG_LEN + 1];

 	int day, i, j, num_remind = 0;

 	for(;;){
 		//如果备忘录已满，就停止循环
 		if(num_remind == MAX_REMIND){
 			printf("-- No space left --\n");
 			break;
 		}
 		//输入日期和一条备忘清单
 		printf("Enter day and reminder:");

 		//把日期读入到整形变量day中，即使输入更多的数字，在%与d之间的数2也会通知scanf函数在读入两个数字后停止
 		scanf("%2d", &day);

 		//如果日期输入0，则停止循环，不在输入任何备忘
 		if(day == 0){
 			break;
 		}
 		
 		//把day的值转换为字符串并写到day_str中
 		sprintf(day_str, "%2d", day);//day_str会包含一个空字符结尾的合法字符串
 		read_line(msg_str, MSG_LEN);//读入备忘信息

 		//找到备忘录的位置（根据日期从小到大排序的位置）
 		for(i = 0; i < num_remind; i++){
 			//确定这一天的位置
 			if(strcmp(day_str, reminders[i]) < 0){
 				break;
 			}
 		}
		
		//将包括该位置之后的备忘信息向后移动
		for(j = num_remind; j > i; j--){
			strcpy(reminders[j], reminders[j-1]);
		} 	

 		//将备忘信息放在空出来的位置
 		strcpy(reminders[i], day_str);

 		//将备忘信息拼接过去
 		strcat(reminders[i], msg_str);
 		num_remind++;
 	}

 	//打印出当前所有备忘信息
 	printf("\nDay Reminder\n");
 	for(i = 0; i < num_remind; i++){
 		printf("%s\n", reminders[i]);
 	}
 	return 0;
 }

/**
 * 读入一行
 * @param  str 存储字符串的位置
 * @param  n   字符串长度上限
 * @return     该条字符串的长度
 */
 int read_line(char str[], int n){
 	char ch;
 	int i = 0;

 	while((ch = getchar()) != '\n'){
 		if(i < n){
 			str[i++] = ch;
 		}
 	}
 	str[i] = '\0';
 	return i;
 }