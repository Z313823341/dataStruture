/**
	判断一个带头节点的循环双链表是否对称 
**/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode ,*DLinkList; 
//头插法建立双链表
DLinkList createDlinkList(DLinkList &DL) {
    DNode *s;
	int x;
	DL = (DLinkList)malloc(sizeof(DNode));
	DL->next = NULL;
	DL->prior = NULL;
	scanf("%d",&x);
	while(x!=9999){
		s = (DNode *)malloc(sizeof(DNode));
		s->data = x;
		s->next = DL->next;
		if(DL->next != NULL){ //第一次插入时，不需要设置新插入节点的后续节点的前驱 
			DL->next->prior = s;
		}
		s->prior = DL;
		DL->next = s;
		scanf("%d",&x); 
	}
	return DL;
} 
//打印list
void printfDLinkList(DLinkList DL){
	DNode *p = DL;
	while(p->next!=NULL){
		p = p->next;
		printf("%d ",p->data);
	}
	printf("\n");
}
//思想：两个工作指针，一个从表头开始，一个从表尾开始 
int isExcahnge(DLinkList dl){
	DNode *p = dl->next;
	DNode *q = dl->prior;
	while(p!=q && q->next!=p){
		if(p->data ==q->data){
			p = p->next;
			q = q->next;
		}
		else{
			return 0;
		}
	} 
	return 1;
} 
main(){
	DLinkList dl;
	createDlinkList(dl);
	printfDLinkList(dl);//1 3 6 8 6 3 1 9999
	printf("%d ",isExcahnge(dl));
}
