#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

//˫����ڵ㶨�� 
typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode,*DLinkList;

//˫������ͷ�巨
DLinkList Dlist_head_insert(DLinkList &DL){
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
//˫������β�巨
DLinkList Dlist_tail_insert(DLinkList &DL){
	DNode *s,*r;
	int x;
	DL = (DLinkList)malloc(sizeof(DNode));
	DL->prior = NULL;
	r = DL;
	scanf("%d",&x);
	while(x!=9999){
		s = (DNode *)malloc(sizeof(DNode));
		s->data = x;
		s->prior = r;
		r->next = s;
		r = s;
		scanf("%d",&x);
	}
	r->next = NULL;
	return DL;
} 
//��ӡ˫��������
void printfDLinkList(DLinkList DL){
	DNode *p = DL;
	while(p->next!=NULL){
		p = p->next;
		printf("%d ",p->data);
	}
	printf("\n");
} 
//˫������Ų��ң����ؽڵ�
DNode *getElemByIndex(DLinkList DL,int i){
	int j = 1;
	DNode *p = DL->next;
	if(i==0) return DL;
	if(i<1) return NULL;
	while(p&&j<i){
		p = p->next;
		j++;
	}
	return p;
} 
 //˫����ֵ����
 DNode *getNodeByElem(DLinkList DL,ElemType e){
 	int j = 1;
 	DNode *p = DL->next;
 	while(p!=NULL && p->data!=e){
 		p = p->next;
 		j++;
 	}
 	return p;
 } 

//˫����Ĳ������
void insertElem(DLinkList &DL,int i , ElemType e){
	//�ҳ�Ҫ����λ�õ�ǰ���ڵ�
	DNode *p =  getElemByIndex(DL,i-1);
	DNode *s = (DNode *)malloc(sizeof(DNode));
	s->data = e;
	s->prior = p;
	s->next = p->next;
	p->next->prior = s;
	p->next = s;
} 

//˫�����ɾ������
void deleteElem(DLinkList &DL,int i){
	//�ҳ�Ҫɾ��λ�õ�ǰ���ڵ�
	 DNode *p =  getElemByIndex(DL,i);
	 p->prior->next = p->next;
	 p->next->prior = p->prior;
	 free(p);
	 
	 
} 
int main(){
	DLinkList DL;
	DNode *search;
	//Dlist_head_insert(DL);//3 4 5 6 7 9999
	Dlist_tail_insert(DL);
//	search = getElemByIndex(DL,1);
//	if(search!=NULL){
//		printf("%d",search->data);
//		printf("\n");
//	}
	search = getNodeByElem(DL,4);
	if(search!=NULL){
		printf("%d",search->data);
		printf("\n");
	}
	printfDLinkList(DL);
	insertElem(DL,2,88);
	printfDLinkList(DL);
	deleteElem(DL,4);
	printfDLinkList(DL);
}
