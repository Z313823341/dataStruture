/**
	树的顺序存储结构 
**/
#include<stdio.h>
#include<stdlib.h>
#definde MaxSize 50
typedef char ElemType;
typedef struct TNode{
	ElemType data;//结点数据 
	int parent;//该结点双亲在数组中的下标 
}TNode;//结点数据类型

typedef struct {
	TNode nodes[MaxSize];//结点数组 
	int n;//结点数量 
}Tree; //树的双亲表示结构 

 
