/**
  ���һ���㷨��ʹ��һ����ͷ�ڵ�ĵ������������ 
  
  ���Կ���ֱ�Ӳ��������㷨��˼�� 
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
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
} 
void sorlList(LinkList &L){
	LNode *p = L->next;
	LNode *r = p->next;//r��ʾp�ĺ�̽�㣬��ֹ����
	LNode *pre;//pre��p��ǰ�����
	p->next = NULL;
	p = r;
	while(p!=NULL){
		r = p->next;
		pre = L;
		while(pre->next!=NULL&& pre->next->data<p->data){
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r; 
	}
	
}
main(){
	LinkList L;
	createlinkListHead(L);
	prinList(L);
	sorlList(L);
	prinList(L);
}

