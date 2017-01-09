//
// Created by TonyEarth on 2017/1/3.
//
#ifndef LIST_H
#include <stdio.h>

#define LIST_H
#define BOOL int
#define TRUE 1
#define FALSE 0

struct Node;
/* 定义 PtrToNode 为指向  Node 的指针 */
typedef struct Node *PtrToNode;

/* PtrToNode 的别名 List */
typedef PtrToNode List;

/* PtrToNode 的别名 Position */
typedef PtrToNode Position;

/* ElementType 假定为字符串 */
typedef char *ElementType;

List MakeEmpty(List L);

int IsEmpty(List L);

int IsLast(Position P, List L);

Position Find(ElementType X, List L);

Position FindPrevious(ElementType X, List L);

void Insert(ElementType X, List l, Position p);

void DeleteNode(ElementType x, List l);

// 找到头节点
Position Header(List l);

// 获取第一个数据
Position First(List l);


Position Advanve(Position p);

#endif
