/**
   AB����������Ԫ�ص����������һ���㷨��A��B�Ĺ���Ԫ�ز���������C��Ҫ���ƻ�A��B�Ľ�� 
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
		printf("%d ",p->data);//1 2 3 4 5 6 7 8 9 6 3 5 7 9999 1 3 9 10 12 7 8 9999
		p = p->next;
	}
	printf("\n");
} 
//˼�룺����������ӵ�һ����㿪ʼ��������Ԫ����ͬ����ȡ��β�巨���뵽������C�У�������ȣ���С���Ǹ�ָ����� 
LinkList getCommon(LinkList la,LinkList lb){
	LNode *pa = la->next;
	LNode *pb = lb->next;
	LinkList lc = (LinkList)malloc(sizeof(LNode));
	
	LNode *r = lc; 
	while((pa!=NULL)&&(pb!=NULL)){
		
			printf("%d\n",pb->data);
		 if(pa->data<pb->data)
		 
		 	pa = pa->next;
		 
		 else if(pa->data>pb->data)
		 	pb = pb->next;
		 
		 else{
		 	LNode *s = (LNode *)malloc(sizeof(LNode));
		 	printf("%d\n",pa->data);
		 	s->data = pa->data;
		 	r->next = s;
		 	r = s;
		 	pa = pa->next;
		 	pb = pb->next;
		 }
	} 
	r->next = NULL;
	return lc; 
} 

main(){
	LinkList la;
	LinkList lb;
	createlinkListHead(la);
	createlinkListHead(lb);
	prinList(la);//9 7 5 3 1 9999 10 9 8 5 4 2 9999
	prinList(lb);
	LinkList lc = getCommon(la,lb); 
	
//	LNode *w = (LNode *)malloc(sizeof(LNode));
//	w->data = 2;
//	lc->next = w;
//	w->next = NULL;
	prinList(lc);
}
