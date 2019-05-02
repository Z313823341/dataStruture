/**
  将一个带有头节点的单链表A分解为两个带头节点的单链表A和B，使得A表中含有原表中为奇书的元素，B表中含有原表中序号为偶数的元素
  且保持相对顺序不变 
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
//思想：遍历链表，P为工作指针，pre为P的前驱指针，如果P->data是奇数，p = P->next,
//如果是偶数，采用尾插法建立链表，并从A中释放。 
void depriveList(LinkList &L){
	LNode *p = L->next;
	LNode *pre =L;
	LinkList LB = (LinkList)malloc(sizeof(LNode));
	LB->next = NULL;
	LNode *r = LB;
	while(p->next!=NULL){
		ElemType elem = p->data ;
		if(elem%2!=0){
			pre = p;
			p = p->next;
		}else{
			LNode *s = (LNode *)malloc(sizeof(LNode));
			s->data = p->data;
			r->next = s;
			r = s;
			//释放
			pre->next = p->next;
			free(p); 
			p =pre->next;
		}
	}
	r->next = NULL; 
	prinList(LB);
}
main(){
	LinkList L;
	createlinkListHead(L);
	prinList(L);
	depriveList(L);
	prinList(L);
	
}
