/**
   将一个单链表就地逆置，也就是空间复杂度为O（1）
   可以参考头插法建立单链表的思想 
 
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
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
} 

//逆置单链表、把头节点取下， 然后头插法一次插到头结点后面 
void contraryList(LinkList &L){
	LNode *p,*r;
	p = L->next;
	L->next = NULL;//把头节点摘下 
	while(p!=NULL){
	  r = p->next;
	  p->next = L->next;
	  L->next = p;
	  p = r; 
	} 	
} 
//逆置单链表 也可以考虑遍历线性表，并将结点指针反转
void reverseList(LinkList &L) {
	LNode *pre;
	LNode *p = L->next;
	LNode *r = p->next;
	p->next = NULL;
	while(r!=NULL){
		pre = p;
		p = r;
		r = r->next;
		p->next = pre;
	}
	L->next = p;
}
 main(){
	LinkList L;
	createlinkListHead(L);
	prinList(L);
	//contraryList(L);
	reverseList(L);
	prinList(L);
} 
