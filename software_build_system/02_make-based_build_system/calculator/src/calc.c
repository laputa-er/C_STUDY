/**
 * 只能处理 + - * / 四则运算
 * 只能处理整数
 * "+ - * / ()" 之外的字符将被忽略
 * @author mengqingshen
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/* 栈深度 */
#define BOTTOM 0
#define BOOL int

#define TRUE 1
#define FALSE 0

#define NUMFLAG '@'

/* 提取的运算式的词元 */
typedef struct tokenNode {
    char opr;
    double data;
} tokenNode;

/* 词元栈（用动态分配的数组实现栈的功能） */
typedef tokenNode* Token;

/* 词元栈元素 */
typedef struct tokenStack {
    Token token;
    int size;
    int top;
} tokenStack;

/* 运算栈 */
typedef tokenStack* Stack;

/**
 * 创建运算栈结构体实例
 * @param size 栈的大小
 * @return 栈的头节点
 */
Stack newStack(int size) {
    /* 为词元栈结构体实例分配空间 */
    Stack L = (Stack)malloc(sizeof(tokenStack));

    /* 初始化栈 */
    // 指向动态分配的内存块的指针可以当作数组的名字使用
    L->token = (Token)malloc(size * sizeof(tokenNode));
    L->top = 0;
    L->size = size;
    return L;
}

/**
 * 判断栈空
 */
BOOL isEmpty(Stack L) {
    if (BOTTOM >= L->top) {
        return TRUE;
    }
    return FALSE;
}

/**
 * 判断栈满
 */
BOOL isFull(Stack L) {
    if (L->size <= L->top) {
        return true;
    }
    return false;
}

/**
 * 入栈
 */
BOOL push(Stack L, tokenNode node) {
    if (isFull(L)) {
        printf("The stack is full!!!\n");
        return FALSE;
    }

    ++L->top;
    L->token[L->top].opr = node.opr;
    L->token[L->top].data = node.data;
    return TRUE;
}

/**
 * 出栈
 */
BOOL pop(Stack L) {
    if (isEmpty(L)) {
        printf("The stack is empty!!!\n");
        return FALSE;
    }
    --L->top;
    return TRUE;
}

/**
 * 获取栈顶的运算的运算符
 */
char getTopOpr(Stack L) {
    return L->token[L->top].opr;
}

/**
 * 获取栈顶的运算的操作数
 */
char getTopData(Stack L) {
    return L->token[L->top].data;
}

/**
 * 删除指定的运算栈（要防止堆内存泄漏）
 */
void deleteStack(Stack L) {
    L->top = 0;
    L->size = 0;
    free(L->token);
    L->token = NULL;
    free(L);
    L = NULL;
}

/**
 * 创建一个指定大小的 Token （数组）
 * @return
 */
Token newToken(size) {
    if (0 == size) {
        return NULL;
    }
    Token L = (Token)malloc(sizeof(tokenNode));
    return L;
}

void deleteToken (Token L) {
    free(L);
    L = NULL;
}

/**
 * 将字符串转换为 Token
 * @param str 用户输入的字符串
 * @param str_length 字符串的长度
 * @param L 写入的目标空间
 */
void stringToToken(char str[], int str_length, Token L) {
    /* 这个标记是协助区分数字字符和非数字字符段的 */
    BOOL preint = FALSE;
    int i, j = 0, sum = 0;
    for (i = 0; i < str_length; i++) {
        // 当前字符为数字
        if (str[i] >= '0' && str[i] <= '9') {
            // 0 ~ 9 之间的字符假定为用户输入的运算式的操作数，将每一段数字区域转换为数字
            if (FALSE == preint) {
                sum = 0;
                preint = TRUE;
            }
            sum = sum * 10 + str[i] - '0';
        }
        // 当前字符为非数字(所以是运算符)
        else {
            // 上一个字符是数字（也就是说，前面的一个操作数转换完了）
            if (TRUE == preint) {
                L[j].opr = NUMFLAG;
                L[j].data = sum;
                preint = FALSE;
                ++j;
            }

            switch(str[i]) {
                case '+':
                case '-':
                case '*':
                case '/':
                case '(':
                case ')':
                    L[j].opr = str[i];
                    ++j;
                    break;
                default:// 非法字符直接过滤掉
                    continue;
            }
        }
    }

    // 如果是最后一个字符，且是一个数字(之所以要增加这个判断，是因为之前对数字的处理无法处理到最后一个数字)
    if(str[str_length - 1] >= '0' && str[str_length - 1] <= '9') {
        if(TRUE == preint) {
            L[j].opr = NUMFLAG;
            L[j].data = sum;
            preint = FALSE;
        }
    }
}

/**
 * 获取一个运算式中词元的总数
 * @param str 运算式
 * @return 词元的总是
 */
int sizeElementExpression(char str[]) {
    int sz_element = 0, i;
    int flag_preint = FALSE;
    for(i = 0; str[i] != '\0'; i++) {
        // 提取数字（最末尾的数字处理不到）
        if (str[i] >= '0' && str[i] <= '9') {
            if (FALSE == flag_preint) {
                flag_preint = TRUE;
                ++sz_element;
            }
            continue;
        }
        else {
            switch (str[i]) {
                case '+':
                case '-':
                case '*':
                case '/':
                case '(':
                case ')':
                    ++ sz_element,
                    flag_preint = FALSE;
                    break;
                default:
                    continue;
            }
        }
    }
    return sz_element;
}

/**
 * 打印 Token 中的词元
 * @param L
 * @param len
 */
void printToken(Token L, int len) {
    int i = 0;
    for(; i < len; i++) {
        // 运算符
        if (NUMFLAG != L[i].opr) {
            printf('%c', L[i].opr);
        }
        else {
            printf('%lf', L[i].data);
        }
    }
}

// 将后缀表达式打印出来
void printStack(Stack suffixstack) {
    int i = 1;
    for (; i <= suffixstack->top; i++) {
        // 运算符
        if(NUMFLAG != suffixstack->token[i].opr) {
            printf('%c', suffixstack->token[i].opr);
        }
        // 数字
        else {
            printf('%lf', suffixstack->token[i].data);
        }
    }
    printf('\n');
}

// 将中缀运算式转换为后缀运算式（逆波兰式）
Stack changeToSuffixStack(Token token, int len) {
    // 数字存放在后缀表达式数组中
    Stack sufstack = newStack(len);

    // 运算符需要进入符号栈进行栈运算
    Stack symbolstack = newStack(len);

    int i;
    for(i = 0; i < len; i++) {
        // 数字
        if (NUMFLAG == token[i].opr) {
            push(sufstack, token[i]);
        }
        // 运算符
        else {
            // 运算符栈为空: 直接 push 进去
            if (isEmpty(symbolstack)) {
                push(symbolstack, token[i]);
                continue;
            }

            // '(': 直接 push 进去
            if ('(' == token[i].opr) {
                push(sufstack, token[i]);
                continue;
            }

            // ')':
            if (')' == token[i].opr) {
                while ('(' != symbolstack->token[symbolstack->top].opr) {
                    tokenNode p;
                    p.opr = getTopOpr(symbolstack);
                    push(sufstack, p);
                    pop(symbolstack);
                }

            }
        }
    }
}