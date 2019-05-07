/**
   ջ��Ӧ�ã�ƥ������ 
**/ 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MaxSize 50
typedef int ElemType;
//ջ����ʽ�洢�뵥�������� ������ݽṹ 
typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}StackNode, * LinkStackPoi;
// ��ջ���ݽṹ
typedef struct LinkStack{
	LinkStackPoi top;//ջ��ָ��
	int count;//ջ��Ԫ�صĸ��� 
}LinkStack; 
//��ʼ��ջ
void initStack(LinkStack &S){
	S.top = NULL;
	S.count = 0; 
} 
//�ж�ջ�Ƿ�Ϊ��
bool isEmpty(LinkStack S) {
	if(S.top == NULL){
		return true;//1�����ջ 
	}
	return false;//0����ǿ� 
}
//��ջ
void pushStack(LinkStack &S,ElemType x ){
	StackNode *node = (StackNode *)malloc(sizeof(StackNode));
	node->data = x;
	node->next = S.top;
	S.top = node;
	S.count++;
} 
//��ջ
bool popStack(LinkStack &S,ElemType &x){
	if(S.top == NULL) return false;
	StackNode *node = S.top;
	x = node->data;
	S.top = node->next;
	free(node);
	S.count--;
	return true;
}
//��ӡջ��Ԫ��
void printfStack(LinkStack S){
	while(S.top!=NULL){
		StackNode *node = S.top;
		printf("%d ",node->data);
		S.top = node->next;
	}
	printf("\n");
}
//����ջƥ������
bool check(char *str,LinkStack &S){
	int leng = strlen(str);
	ElemType m;
	bool ret;
	for(int i = 0 ; i < leng ; i ++){
		char a = str[i];
		switch (a){
			case '(':
			case'[':
			pushStack(S,a);
			break;
			case')':
			popStack(S,m);
			if(m!='(') return false;
			break;
			case']':
			popStack(S,m);
			if(m!='[') return false;
			break;
		}
	}
	ret = isEmpty(S);
	if(ret) return true;
	else return false;
} 
int main(){
	LinkStack S;
	bool ret;
	ElemType m;
	initStack(S);
	ret = isEmpty(S);
//	if(ret){
//		printf("stack is empty!\n");
//	}
//	pushStack(S,2);
//	pushStack(S,3);
//	pushStack(S,4);
//	pushStack(S,5);
//	pushStack(S,6);
//	ret = isEmpty(S);
//	if(ret){
//		printf("stack is empty!\n");
//	}else{
//		printf("stack is not empty!\n");
//	}
//	printfStack(S);
//	ret = popStack(S,m);
//	if(ret){
//		printf("��ջ��Ԫ��Ϊ��%d",m);
//	}
	char str = '([])';
	ret = check(str,S);
	if(ret){
		printf("ƥ��ɹ���");	
	}
	
}
