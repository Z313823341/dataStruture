/**
  ��������������������и��ڵ������Ԫ�� 
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
		printf("%d ",p->data);//1 2 3 4 5 6 7 8 9999 1 3 9 10 12 7 8 9999
		p = p->next;
	}
	printf("\n");
} 
//ÿ�α����ҳ�һ����Сֵ 
void printfListIncrease(LinkList &L){
	LNode *p = L->next;
	LNode *pre = L;
	while(L->next!=NULL){
		pre = L;
		p = pre->next;
		while(p->next!=NULL){
			if(p->next->data<pre->next->data){
				pre = p;
			}
			p = p->next;
		
		}
		LNode *u = pre->next;
		printf("%d ",u->data);
		pre->next = u->next;
		free(u);
	} 
	free(L);
}
main(){
	LinkList L;
	createlinkListHead(L);
	prinList(L);
	printfListIncrease(L);
}