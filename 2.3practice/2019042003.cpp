/**
   ��һ��������͵����ã�Ҳ���ǿռ临�Ӷ�ΪO��1��
   ���Բο�ͷ�巨�����������˼�� 
 
**/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//ͷ�巨����������
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
 //��ӡList�Ľڵ�
void prinList(LinkList L){
	LNode *p = L->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
} 

//���õ�������ͷ�ڵ�ȡ�£� Ȼ��ͷ�巨һ�β嵽ͷ������ 
void contraryList(LinkList &L){
	LNode *p,*r;
	p = L->next;
	L->next = NULL;//��ͷ�ڵ�ժ�� 
	while(p!=NULL){
	  r = p->next;
	  p->next = L->next;
	  L->next = p;
	  p = r; 
	} 
	
} 
 main(){
	LinkList L;
	createlinkListHead(L);
	prinList(L);
	contraryList(L);
	prinList(L);
} 
