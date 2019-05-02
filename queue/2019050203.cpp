/**
  ѭ������ 
**/ 
#include<stdio.h> 
#include<stdlib.h>
#define MaxSize 5
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int front,rear;//����ͷ�Ͷ���β 
}SqQueue; 

//ѭ�����г�ʼ��
bool initQueue(SqQueue &sq){
	sq.rear = sq.front = 0;
} 
//�п�
bool isEmpty(SqQueue sq){
	if(sq.rear == sq.front) return true;
	else return false;
} 
//��Ӳ���
bool enQueue(SqQueue &sq,ElemType x){
	//�ж϶����Ƿ���
	if((sq.rear+1)%MaxSize==sq.front) return false; 
	sq.data[sq.rear] = x;
	sq.rear = (sq.rear + 1)%MaxSize;
} 
//���Ӳ���
bool deQueue(SqQueue &sq,ElemType &x){
	if(sq.rear == sq.front) return false;
	x = sq.data[sq.front];
	sq.front = (sq.front+1)%MaxSize;
	return true;
} 
//��ȡ��ͷԪ��
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
		printf("����Ԫ��Ϊ%d\n",element);
	}
	ret = deQueue(sq,element);
	if(ret){
		printf("���ӳɹ�������Ԫ��Ϊ%d\n",element);
	}
	ret = deQueue(sq,element);
	if(ret){
		printf("���ӳɹ�������Ԫ��Ϊ%d\n",element);
	}
	ret = getFirst(sq,element);
	if(ret){
		printf("����Ԫ��Ϊ%d\n",element);
	}
	enQueue(sq,8);
	ret = getFirst(sq,element);
	if(ret){
		printf("����Ԫ��Ϊ%d\n",element);
	}
}
