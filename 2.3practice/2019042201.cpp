/**
  设计一个算法，使得一个带头节点的单链表递增有序 
  
  可以考虑直接插入排序算法的思想 
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
void sorlList(LinkList &L){
	LNode *p = L->next;
	LNode *r = p->next;//r表示p的后继结点，防止断链
	LNode *pre;//pre是p的前驱结点
	p->next = NULL;
	p = r;
	while(p!=NULL){
		r = p->next;
		pre = L;
		while(pre->next!=NULL&& pre->next->data<p->data){
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r; 
	}
	
}
main(){
	LinkList L;
	createlinkListHead(L);
	prinList(L);
	sorlList(L);
	prinList(L);
}

