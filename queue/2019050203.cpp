/**
  循环队列 
**/ 
#include<stdio.h> 
#include<stdlib.h>
#define MaxSize 5
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int front,rear;//队列头和队列尾 
}SqQueue; 

//循环队列初始化
bool initQueue(SqQueue &sq){
	sq.rear = sq.front = 0;
} 
//判空
bool isEmpty(SqQueue sq){
	if(sq.rear == sq.front) return true;
	else return false;
} 
//入队操作
bool enQueue(SqQueue &sq,ElemType x){
	//判断队列是否满
	if((sq.rear+1)%MaxSize==sq.front) return false; 
	sq.data[sq.rear] = x;
	sq.rear = (sq.rear + 1)%MaxSize;
} 
//出队操作
bool deQueue(SqQueue &sq,ElemType &x){
	if(sq.rear == sq.front) return false;
	x = sq.data[sq.front];
	sq.front = (sq.front+1)%MaxSize;
	return true;
} 
//获取队头元素
bool getFirst(SqQueue sq,ElemType &x){
	if(sq.rear==sq.front) return false;
	x = sq.data[sq.front];
	return true;
} 

main(){
	SqQueue sq;
	bool ret;
	ElemType element;
	initQueue(sq);
	ret = isEmpty(sq);
	if(ret){
		printf("queue is empty!\n");
	}
	enQueue(sq,2);
	enQueue(sq,3);
	enQueue(sq,4);
	ret = enQueue(sq,5);
	if(ret){
		printf("enqueue successfully!\n");
	}
	ret = getFirst(sq,element);
	if(ret){
		printf("队首元素为%d\n",element);
	}
	ret = deQueue(sq,element);
	if(ret){
		printf("出队成功！出队元素为%d\n",element);
	}
	ret = deQueue(sq,element);
	if(ret){
		printf("出队成功！出队元素为%d\n",element);
	}
	ret = getFirst(sq,element);
	if(ret){
		printf("队首元素为%d\n",element);
	}
	enQueue(sq,8);
	ret = getFirst(sq,element);
	if(ret){
		printf("队首元素为%d\n",element);
	}
}
