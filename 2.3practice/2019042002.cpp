/**
  ��ͷ�ڵ�ĵ�����L�У�ɾ����С�ڵ�ĸ�Ч�㷨 ��������Сֵ�ڵ�Ψһ�� 

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
//ɾ�����µĽ��
void deleteMin(LinkList &L){
	//����ָ�� pre��p��ǰ����� 
	LNode *pre = L;
	LNode *p = pre->next; 
	//��Сֵ��㼰��ָ��
	LNode *minpre = pre;
	LNode *minp = minpre->next;
	while(p!=NULL){
		if(p->data<minp->data){
			minp = p;
			minpre = pre;
		}
		//ɨ����һ����� 
		pre = p;
		p = p->next; 
	}
	minpre->next = minp->next;
	free(minp); 
} 
main(){
	LinkList L;
	createlinkListHead(L);
	prinList(L);
	deleteMin(L);
	prinList(L);
}
