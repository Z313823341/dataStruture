/**
	 判断B是否是A的连续子序列 
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
//思想：从第一个结点开始遍历，若pa= pb，则继续，若pa！=pb,则pa继续下一个，pb从第一个开始 
int isbelonging(LinkList la,LinkList lb){
	LNode *pa = la->next;
	LNode *pb = lb->next;
	while(pa&&pb){
		if(pa->data!=pb->data){
			pa = pa->next;
			pb = lb;
		}else{
			pa = pa->next;
			pb = pb->next;
		}
	}
	if(pb == NULL){
		return 1;
		}
		else{
			return 0;
		}
} 
main(){
	LinkList la;
	LinkList lb;
	createlinkListHead(la);
	createlinkListHead(lb);
	prinList(la);//9 7 5 3 1 9999 5 3 1 9999
	prinList(lb);
	bool isB = isbelonging(la,lb); 
	printf("%d",isB); 
	
}
