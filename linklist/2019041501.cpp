/**
   �ڴ�ͷ�ڵ�ĵ����� L�� ��ɾ������ֵΪX�Ľڵ㣬���ͷ���ռ�
   
   ��P��ͷ��βɨ�赥����preָ��*p�ڵ��ǰ������P��ָ���ֵΪx��
   ��ɾ��������Pָ����һ�����
   ����pre��pָ��ͬ������һ����� 
    
**/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode , *LinkList;
//ͷ�巨��������
LinkList create_link_head(LinkList &L){
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	int x;
	LNode *s;
	scanf("%d",&x);
	while(x!=9999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d",&x);
	}
	return L;//5 9 6 7 8 9 9 4 9999
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
//ɾ������ֵΪX�Ľڵ㣬���ͷſռ� 
void delete_X(LinkList &L,int x){
	LNode *p = L->next;
	LNode *pre = L;
	LNode *q;
	while(p!=NULL) {
		if(p->data==x){
			q = p;
			p = p->next;
			pre->next = p;
			free(q);
		}
		else{
			pre = p;
			p = p->next;
		}
	}
} 
int main(){
	LinkList L;
	create_link_head(L);
	prinList(L);
	delete_X(L,9);
	prinList(L);
}

