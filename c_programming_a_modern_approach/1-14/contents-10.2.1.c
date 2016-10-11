#define STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef int Bool;

int contents[STACK_SIZE];
int top = 0;

/**
 * 清空栈
 * 将top指针指向数组的第一项
 */
void make_empty(void){
	top = 0;
}

/**
 * 检查栈是否为空
 * @return  true:空；false:非空
 */
Bool is_empty(void){
	return top == 0;
}

/**
 * 检查栈是否已满
 * @return  true:已满；false:未满
 */
Bool is_full(void){
	return top == STACK_SIZE;
}

/**
 * 向栈中压入数据
 * @param i 要压入的数据项
 */
void push(int i){
	if(is_full()){
		stace_overflow();
	}else{
		contents[top++] = i;
	}
}

/**
 * 从栈中弹出数据项
 * @return  数据项
 */
int pop(void){
	if(is_empty()){
		stack_underflow();
	}else{
		return contents[--top];
	}
}