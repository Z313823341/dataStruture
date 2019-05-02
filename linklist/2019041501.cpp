/**
   在带头节点的单链表 L中 ，删除所有值为X的节点，并释放其空间
   
   用P从头至尾扫描单链表，pre指向*p节点的前驱。若P所指结点值为x，
   则删除，并让P指向下一个结点
   否则，pre和p指针同步后移一个结点 
    
**/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode , *LinkList;
//头插法建立链表
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
//打印List的节点
void prinList(LinkList L){
	LNode *p = L->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
} 
//删除所有值为X的节点，并释放空间 
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

