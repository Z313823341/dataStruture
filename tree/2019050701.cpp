/**
	����˳��洢�ṹ 
**/
#include<stdio.h>
#include<stdlib.h>
#definde MaxSize 50
typedef char ElemType;
typedef struct TNode{
	ElemType data;//������� 
	int parent;//�ý��˫���������е��±� 
}TNode;//�����������

typedef struct {
	TNode nodes[MaxSize];//������� 
	int n;//������� 
}Tree; //����˫�ױ�ʾ�ṹ 

 
