/**
	�ж�һ����ͷ�ڵ��ѭ��˫�����Ƿ�Գ� 
**/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode ,*DLinkList; 
//ͷ�巨����˫����
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
		if(DL->next != NULL){ //��һ�β���ʱ������Ҫ�����²���ڵ�ĺ����ڵ��ǰ�� 
			DL->next->prior = s;
		}
		s->prior = DL;
		DL->next = s;
		scanf("%d",&x); 
	}
	return DL;
} 
//��ӡlist
void printfDLinkList(DLinkList DL){
	DNode *p = DL;
	while(p->next!=NULL){
		p = p->next;
		printf("%d ",p->data);
	}
	printf("\n");
}
//˼�룺��������ָ�룬һ���ӱ�ͷ��ʼ��һ���ӱ�β��ʼ 
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
