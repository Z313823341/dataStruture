/**
 	������������Ԫ��ֵ�����������е����Ա���д�㷨 ����������鲢��һ����Ԫ�ش���ݼ��ĵ�����
	 Ҫ������ԭ������������Ľ���Ź鲢��ĵ����� 
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
//˼�룺ͷ�巨���ӵ�һ����㿪ʼ��������� pa<pb,��pa���ƣ�pa���뵽la����pa=pb����pa pbͬʱ���ƣ���pa>pb,��pb���뵽la�У�pb����
//��pa��ѭ�����ף���paָ��pb����pb��ѭ�����ף���pa���β��뵽 la�� 
void mergeAB(LinkList &la,LinkList &lb){
	LNode *pa = la->next;
	LNode *pb = lb->next;
	LNode *r;//r������Ź���ָ��ĺ�̽�� 
	la->next = NULL;
	while(pa&&pb){
		if(pa->data<=pb->data){
			r = pa->next;
			pa->next = la->next;
			la->next = pa;
			pa = r;
		}
		else{
			r = pb->next;
			pb->next = la->next;
			la->next = pb;
			pb = r;
		} 
	}
	if(pa){
		pb = pa;
	}
	while(pb){
		r = pb->next;
		pb->next = la->next;
		la->next = pb;
		pb = r;
	}
	free(lb);
} 
main(){
	LinkList la;
	LinkList lb;
	createlinkListHead(la);
	createlinkListHead(lb);
	prinList(la);
	prinList(lb);
	mergeAB(la,lb);//1 3 5 7 9 9999 2 4 6 8 9 10 11 9999
	prinList(la);
	//prinList(lb);
	

}
