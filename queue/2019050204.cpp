/**
  链表的链式存储 
**/
 #include<stdio.h>
 #include<stdlib.h>
 typedef int ElemType;
 typedef struct LinkNode{
 	ElemType data;
 	struct LinkNode *next;
 }LinkNode;
 typedef struct {
 	LinkNode *front,*rear;
 }LinkQueue;
 
 //链式队列初始化
 void InitQueue(LinkQueue &q){
 	//头和尾指向同一个结点 
 	q.front = q.rear = (LinkNode *)malloc(sizeof(LinkNode));
 	q.front->next = NULL;
 }
 //入队操作
 void enQueue(LinkQueue &q,ElemType x){
 	LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
	 s->data = x;
	 s->next = NULL;
	 q.rear->next = s;
	 q.rear = s; 
 } 
 //出队操作
  bool deQueue(LinkQueue &q,ElemType &x){
  	if(q.front == q.rear) return false;
  		LinkNode *p = q.front->next;
  		x = p->data;
  		q.front->next  = p->next;
  		if(q.rear = p){//删除额是最后一个元素 
  			q.rear = q.front;
  		}
  		free(p);
  		return true;	
  }
  main(){
  	LinkQueue q;
  	bool ret;
  	ElemType x;
  	InitQueue(q);
  	enQueue(q,2);
  	enQueue(q,3);
  	enQueue(q,4);
  	enQueue(q,5);
  	enQueue(q,6);
  	ret = deQueue(q,x);
  	if(ret){
  		printf("出队元素为:%d",x);
  	}
  }
