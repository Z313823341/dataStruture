/**
  ��һ������� ��ͷ���ĵ�����L�У�ɾ������ĳ����ֵ֮���Ԫ��
   
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
		printf("%d ",p->data);//3 2 8 5 9 7 4 1 9999
		p = p->next;
	}
	printf("\n");
} 
void deteltX_Y(LinkList &L,int x, int y){
	//pre��p��ǰ����� 
	LNode *p = L->next;
    LNode *pre = L;
	while(p!=NULL){
	if(p->data>x && p->data<y){
		pre->next = p->next; 
		free(p);
		p = pre->next;
	} else{
		pre = p;
		p = p->next;
	}
} 
}
main(){
	LinkList L;
	createlinkListHead(L);
	prinList(L);
	deteltX_Y(L,3,7);
	prinList(L);
} 
