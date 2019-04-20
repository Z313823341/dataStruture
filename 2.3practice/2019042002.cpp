/**
  带头节点的单链表L中，删除最小节点的高效算法 （假设最小值节点唯一） 

**/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
 typedef struct LNode{
 	ElemType data;
 	struct LNode *next;
 }LNode,*LinkList;
 
 //头插法建立单链表
 void createlinkListHead(LinkList &L){
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
//删除最下的结点
void deleteMin(LinkList &L){
	LNode *p = L->next;
	int min = p->data;
	while(p->next!=NULL){
		if(min<p->data){
			
		}
	}
} 
main(){
	LinkList L;
	createlinkListHead(L);
	prinList(L);
}
