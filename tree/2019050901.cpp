/**
���ӱ�ʾ�� 
	������ʽ�ṹ 
	��Ҫ�������������ͽṹ
	һ���Ǻ�������Ľ��
	��һ����ÿ����������ı�ͷ��� 
**/
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
typedef char ElemType;
typedef struct CNode{
	int child;//�ú����ڱ�ͷ������±� 
	struct CNode *next; //ָ��ýڵ�� ��һ�����ӽ�� 
}CNode,*Child; //���ӽ����������

typedef struct{
	ElemType data;//��������� 
	Child firstChild;//ָ��ý��ĵ�һ�����ӽ�� 
}TNode; //���ӽ����������i 

typedef struct{
	TNode node[MaxSize];//��������� 
	int n;//���ֽ����� 
}Tree; 
