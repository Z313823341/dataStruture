/**
 	ABԪ�ص������е�����
	 ��AB�Ľ���
	 �����A�� 
**/

#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//ͷ�巨����������
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
 //��ӡList�Ľڵ�
void prinList(LinkList L){
	LNode *p = L->next;
	while(p!=NULL){
		printf("%d ",p->data);//1 2 3 4 5 6 7 8 9 6 3 5 7 9999 1 3 9 10 12 7 8 9999
		p = p->next;
	}
	printf("\n");
} 
//˼�룺�ӵ�һ��Ԫ�ؿ�ʼɨ�裬����������Ԫ����ȣ����������pa<pb,��pa����һ��ָ�룬���pa>pb,��pb����һ��ָ�� 
void getEqual(LinkList &la,LinkList &lb){
	LNode *pa = la->next;
	LNode *pre = la;
	LNode *pb = lb->next;
	LNode *pc = la;
	la->next = NULL;
	while(pa&&pb){
		if(pa->data<pb->data){
			LNode *u = pa;
			pa = pa->next;
			free(u);
		}else if(pa->data>pb->data){
			LNode *u = pb;
			pb = pb->next;
			free(u); 
		}else{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			LNode *u = pb;
			pb = pb->next;
			free(u); 
		}
	}
	while(pa){
		LNode *u = pa;
		pa = pa->next;
		free(u);
	}
	while(pb){
		LNode *u = pb;
		pb = pb->next;
		free(u);
	}
	pc->next = NULL;
	free(lb);
}  
main(){
	LinkList la;
	LinkList lb;
	createlinkListHead(la);
	createlinkListHead(lb);
	prinList(la);//9 7 5 3 1 9999 10 9 8 5 4 2 9999
	prinList(lb);
	getEqual(la,lb); 
	prinList(la);
}
