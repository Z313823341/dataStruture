/**
   栈的应用，匹配括号 
**/ 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MaxSize 50
typedef int ElemType;
//栈的链式存储与单链表类似 结点数据结构 
typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}StackNode, * LinkStackPoi;
// 链栈数据结构
typedef struct LinkStack{
	LinkStackPoi top;//栈底指针
	int count;//栈中元素的个数 
}LinkStack; 
//初始化栈
void initStack(LinkStack &S){
	S.top = NULL;
	S.count = 0; 
} 
//判断栈是否为空
bool isEmpty(LinkStack S) {
	if(S.top == NULL){
		return true;//1代表空栈 
	}
	return false;//0代表非空 
}
//入栈
void pushStack(LinkStack &S,ElemType x ){
	StackNode *node = (StackNode *)malloc(sizeof(StackNode));
	node->data = x;
	node->next = S.top;
	S.top = node;
	S.count++;
} 
//出栈
bool popStack(LinkStack &S,ElemType &x){
	if(S.top == NULL) return false;
	StackNode *node = S.top;
	x = node->data;
	S.top = node->next;
	free(node);
	S.count--;
	return true;
}
//打印栈中元素
void printfStack(LinkStack S){
	while(S.top!=NULL){
		StackNode *node = S.top;
		printf("%d ",node->data);
		S.top = node->next;
	}
	printf("\n");
}
//利用栈匹配括号
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
//		printf("出栈的元素为：%d",m);
//	}
	char str = '([])';
	ret = check(str,S);
	if(ret){
		printf("匹配成功！");	
	}
	
}
