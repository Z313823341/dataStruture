/**
孩子兄弟表示法 
	就是要存储孩子结点和兄弟结点，具体来说，就是设置两个指针，分别指向该结点的第一个孩子结点和该结点的兄弟结点 
**/
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
typedef char ElemType;
typedef struct CSNode{
	ElemType data;
	struct CSNode *firstchild,*rightsib;
}CSNode;
