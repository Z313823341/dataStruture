/**
  栈的基本操作 
**/
#include<stdio.h> 
#include<stdlib.h>
#define MaxSize 50
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;

//初始化栈
void initStack(SqStack &s){
	s.top = -1;
} 

//判断栈空
bool stackEmpty(SqStack &s){
	if(s.top = -1) return true;
	else return false;
}

//入栈 push
bool push (SqStack &s,ElemType x){
	if(s.top == MaxSize-1){
		return false;
	}
	s.data[++s.top] = x;
	return true;
} 

//出栈 pop
bool pop(SqStack &s,ElemType &x){
	if(s.top == -1){
		return false;
	}
	x = s.data[s.top--];
	return true;
} 

//获取栈顶元素
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
