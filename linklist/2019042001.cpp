/**

     ��д�㷨 ��β��ͷ�������ÿ������ֵ 

**/


#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//β�巨����������
void createListTail(LinkList &L){
	LNode *r ;
	LNode *s ;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	r = L;
	int x;
	scanf("%d",&x) ;  
	while(x!=9999){
		s = (LNode *)malloc(sizeof(LNode)) ;//5 9 6 7 8 9 9 4 9999
		s->data = x ;
		r->next = s;
		r = s;
		scanf("%d",&x);
	}
	r->next = NULL;
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
//�������ÿ���ڵ��ֵ
void printfListContrary(LinkList &L){
	
	 if(L->next!=NULL){
	 	printfListContrary(L->next);
	 } 
	 printf("%d ",L->data);
} 

main(){
	LinkList L;
	createListTail(L);
	prinList(L);
	printfListContrary(L);
}

