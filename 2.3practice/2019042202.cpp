/**
  ��һ������� ��ͷ���ĵ�����L�У�ɾ������ĳ����ֵ֮���Ԫ��
   
**/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//ͷ�巨����������
 void createlinkListHead(LinkList &L){//3 5 9 9 6 8 7 9999 
 	LNode *s;
 	int x;
 	L = (LinkList)malloc(sizeof(LNode));
 	L->next = NULL;
 	scanf("%d",&x);
 	while(x!=9999){
 		s = (LNode *)malloc(sizeof(LNode));
 		s->data = x;
 		s->next = L->next;
 		L->next = s;
 		scanf("%d",&x);
 	}
 } 
 //��ӡList�Ľڵ�
void prinList(LinkList L){
	LNode *p = L->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
} 
void deteltX_Y(LinkList &L,int x, int y){
	LNode *p = L->next;
	LNode *r = p->next;
	while(p!=NULL){
	r = p->next;
	if(p->data>x && p->data<y){
		L->next = p->next;
		free(p);
	} 
	p = r;
	
} 
