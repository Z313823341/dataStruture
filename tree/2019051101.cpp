/**
�����ֵܱ�ʾ�� 
	����Ҫ�洢���ӽ����ֵܽ�㣬������˵��������������ָ�룬�ֱ�ָ��ý��ĵ�һ�����ӽ��͸ý����ֵܽ�� 
**/
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
typedef char ElemType;
typedef struct CSNode{
	ElemType data;
	struct CSNode *firstchild,*rightsib;
}CSNode;
