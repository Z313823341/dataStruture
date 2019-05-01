/**
 	假设有两个按元素值递增次序排列的线性表，编写算法 将这两个表归并成一个按元素次序递减的单链表
	 要求利用原来两个单链表的结点存放归并后的单链表 
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
//思想：头插法，从第一个结点开始遍历，如果 pa<pb,则pa后移，pa插入到la，若pa=pb，则将pa pb同时后移，若pa>pb,把pb插入到la中，pb后移
//若pa先循环到底，把pa指向pb，若pb先循环到底，把pa依次插入到 la。 
void mergeAB(LinkList &la,LinkList &lb){
	LNode *pa = la->next;
	LNode *pb = lb->next;
	LNode *r;//r用来存放工作指针的后继结点 
	la->next = NULL;
	while(pa&&pb){
		if(pa->data<=pb->data){
			r = pa->next;
			pa->next = la->next;
			la->next = pa;
			pa = r;
		}
		else{
			r = pb->next;
			pb->next = la->next;
			la->next = pb;
			pb = r;
		} 
	}
	if(pa){
		pb = pa;
	}
	while(pb){
		r = pb->next;
		pb->next = la->next;
		la->next = pb;
		pb = r;
	}
	free(lb);
} 
main(){
	LinkList la;
	LinkList lb;
	createlinkListHead(la);
	createlinkListHead(lb);
	prinList(la);
	prinList(lb);
	mergeAB(la,lb);//1 3 5 7 9 9999 2 4 6 8 9 10 11 9999
	prinList(la);
	//prinList(lb);
	

}
