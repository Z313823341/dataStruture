/**
    �ҳ���������Ĺ������   
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
//��ͳ˼�� "�� "���������������� ʱ�临�Ӷ�ΪL1.length*L2.length 
//X ���ַ����ҵ��ǹ���Ԫ�� �����ǹ������  �����Ǵ����
 
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
//��������ĳ���
int getLength(LinkList L){
	LNode *p = L->next;
	int i = 0;
	while(p!=NULL){
		i++;
		p = p->next;
	}
} 
/**
  ������㣺Ҳ���������ĳһ��㿪ʼ�����ǵ�next��ָ��ͬһ��㣬��ˣ��ӵ�һ��������㿪ʼ��֮�����ǵĽ�㶼���غϵ�
  Ҳ���������������Y�ͣ���������X�� 
**/ 
//��һ��˼ά ����ʱ�临�Ӷȵ��㷨 ֻ�������������β�ڵ㣬�������β�ڵ�һ����˵�������й�����㣬������������û�й������
//Ȼ������������ĳ��ȿ��ܲ���ͬ����������������֮��ΪK���������ڳ������ϱ���K����㣬��ʱͬ���������Ǿ��ܱ�֤�ܹ�����ͬһ�������
//�ڱ����У���һ����ͬ�Ľ����ǵ�һ��������� 

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
    	printf("û�й�����㣡");
	}else{
		printf("%d",s->data);
	}
    
    }
    

