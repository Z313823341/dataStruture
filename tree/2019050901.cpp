/**
孩子表示法 
	树的链式结构 
	需要设计两个结点类型结构
	一个是孩子链表的结点
	另一个是每个孩子链表的表头结点 
**/
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
typedef char ElemType;
typedef struct CNode{
	int child;//该孩子在表头数组的下标 
	struct CNode *next; //指向该节点的 下一个孩子结点 
}CNode,*Child; //孩子结点数据类型

typedef struct{
	ElemType data;//结点数据域 
	Child firstChild;//指向该结点的第一个孩子结点 
}TNode; //孩子结点数据类型i 

typedef struct{
	TNode node[MaxSize];//结点数据域 
	int n;//树种结点个数 
}Tree; 
