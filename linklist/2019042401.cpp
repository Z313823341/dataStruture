/**
    找出两个链表的公共结点   
**/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//头插法建立单链表
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
 //打印List的节点
void prinList(LinkList L){
	LNode *p = L->next;
	while(p!=NULL){
		printf("%d ",p->data);//1 2 3 4 5 6 7 8 9999 1 3 9 10 12 7 8 9999
		p = p->next;
	}
	printf("\n");
} 
//传统思想 "蛮 "方法遍历两个链表 时间复杂度为L1.length*L2.length 
//X 这种方法找的是公共元素 而并非公共结点  所以是错误的
 
void findSmaeLNode(LinkList L1,LinkList L2){
	LNode *p1 = L1->next;	
	while(p1!=NULL){
		LNode *p2 = L2->next;
		while(p2!=NULL){
			if(p1->data==p2->data){
				printf("%d ",p1->data);
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
} 
//计算链表的长度
int getLength(LinkList L){
	LNode *p = L->next;
	int i = 0;
	while(p!=NULL){
		i++;
		p = p->next;
	}
} 
/**
  公共结点：也就是链表从某一结点开始，它们的next都指向同一结点，因此，从第一个公共结点开始，之后他们的结点都是重合的
  也就是两条链表呈现Y型，而不会是X型 
**/ 
//另一种思维 线性时间复杂度的算法 只需遍历两个链表到尾节点，如果两个尾节点一样，说明他们有公共结点，否则两个链表没有公共结点
//然而，两个链表的长度可能不相同，假设两个链表长度之差为K，我们现在长链表上遍历K个结点，此时同步遍历我们就能保证能够到达同一个结点了
//在遍历中，第一个相同的结点就是第一个公共结点 

 LNode* faindUnionNode(LinkList L1,LinkList L2){
 	 int len1 = getLength(L1);
 	 int len2 = getLength(L2);
 	 LinkList longList,shortList;
 	 int k = 0;
 	 if(len1<len2){
 	 	k = len2-len1;
 	 	longList = L2;
 	 	shortList = L1;
 	 }
 	 else{
 	 	k = len1 -len2;
 	 	longList = L1;
 	 	shortList = L2;
 	 }
 	 while(k--){
 	 	longList = longList->next;
 	 }
 	 while(longList!=NULL){
 	 	if(longList = shortList){
 	 		return longList;
 	 	}
 	 	else{
 	 		longList =longList->next;
 	 		shortList = shortList->next;
 	 	}
 	 }
 	 return NULL;
 	 
 } 
main(){
	LinkList L1;
	LinkList L2;
	createlinkListHead(L1);
	createlinkListHead(L2);
	prinList(L1);
	prinList(L2);
    LNode *s = faindUnionNode(L1,L2);
    if(s==NULL){
    	printf("没有公共结点！");
	}else{
		printf("%d",s->data);
	}
    
    }
    

