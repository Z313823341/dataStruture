/**
  ��һ������ͷ�ڵ�ĵ�����A�ֽ�Ϊ������ͷ�ڵ�ĵ�����A��B��ʹ��A���к���ԭ����Ϊ�����Ԫ�أ�B���к���ԭ�������Ϊż����Ԫ��
  �ұ������˳�򲻱� 
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
		printf("%d ",p->data);//1 2 3 4 5 6 7 8 9999 1 3 9 10 12 7 8 9999
		p = p->next;
	}
	printf("\n");
} 
//˼�룺��������PΪ����ָ�룬preΪP��ǰ��ָ�룬���P->data��������p = P->next,
//�����ż��������β�巨������������A���ͷš� 
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
			//�ͷ�
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
