/**
  ջ�Ļ������� 
**/
#include<stdio.h> 
#include<stdlib.h>
#define MaxSize 50
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;

//��ʼ��ջ
void initStack(SqStack &s){
	s.top = -1;
} 

//�ж�ջ��
bool stackEmpty(SqStack &s){
	if(s.top = -1) return true;
	else return false;
}

//��ջ push
bool push (SqStack &s,ElemType x){
	if(s.top == MaxSize-1){
		return false;
	}
	s.data[++s.top] = x;
	return true;
} 

//��ջ pop
bool pop(SqStack &s,ElemType &x){
	if(s.top == -1){
		return false;
	}
	x = s.data[s.top--];
	return true;
} 

//��ȡջ��Ԫ��
bool getTop(SqStack s,ElemType &x){
	if(s.top==-1) return false;
	x = s.data[s.top];
	return true;
} 
int main(){
	SqStack s;
	bool flag;
	ElemType m;
	initStack(s);
	flag = stackEmpty(s);
	if(flag){
		printf("stack is empty!\n");
	}
	flag = push(s,2);
	if(flag){
		printf("stack is empty!\n");
	}else{
		printf("stack is not empty!\n");
	}
	flag = push(s,3);
	flag = push(s,4);
	if(flag){
		printf("stack is empty!\n");
	}else{
		printf("stack is not empty!\n");
	}
	flag = getTop(s,m);
	if(flag){
		printf("%d\n",m);
	}
	flag = pop(s,m);
	if(flag){
		printf("%d\n",m);
	}
	flag = pop(s,m);
	if(flag){
		printf("%d\n",m);
	}
} 
