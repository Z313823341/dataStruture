/**
   C= {a1,b1,a2,b2,a3,b3...an,bn}存放与带头结点的单链表C中。 
   设计一个原地算法 使得 拆分C为A和B，使得
    A ={a1,a2,a3...an}
    B = {bn,bn-1...b1}
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
		printf("%d ",p->data);//1 2 3 4 5 6 7 8 9999 1 3 9 10 12 7 8 9999
		p = p->next;
	}
	printf("\n");
} 
//思想：奇数为尾插法 插入到A中，偶数为头插法插入到B中 
void diviceList(LinkList LC){
	LNode *p = LC->next;
	LNode *pre = LC;
	LinkList LA = (LinkList)malloc(sizeof(LNode));
	LinkList LB = (LinkList)malloc(sizeof(LNode));
	LA->next = NULL;
	LNode *r = LA;
	LB->next = NULL;
	int i = 0;
	while(p!=NULL){
	    	LNode *s = (LNode *)malloc(sizeof(LNode));
			s->data  = p->data;
		if (i%2!=0){
			r->next = s;
			r = s;
		}else{
			s->next = LB->next;
			LB->next = s; 
			
		}
		p = p->next;
		i++;
	}
	r->next = NULL;
	prinList(LA);
	prinList(LB);
}
main(){
	LinkList LC;
	createlinkListHead(LC);
	prinList(LC);
	diviceList(LC);
}
