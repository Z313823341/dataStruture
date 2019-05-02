/**
   在一个线性链表中，有数值相同的元素存在，存储的方式为单链表
   设计一个算法，删除相同的元素，使表中不再有重复的元素 
**/

#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//头插法建立单链表
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
 //打印List的节点
void prinList(LinkList L){
	LNode *p = L->next;
	while(p!=NULL){
		printf("%d ",p->data);//1 2 3 4 5 6 7 8 9 6 3 5 7 9999 1 3 9 10 12 7 8 9999
		p = p->next;
	}
	printf("\n");
} 
void deleteSame(LinkList &L){
	LNode *p = L->next;
	LNode *q ;//q是p的后继结点 
	while(p->next!=NULL){
		q = p->next; 
		if(p->data == q->data){
			p->next = q->next;
			free(q);
			
			
		}else{
			
			p = p->next;
		} 
		
	}
}
main(){
	LinkList L;
	createlinkListHead(L);
	prinList(L);
	deleteSame(L);
	prinList(L);
}
