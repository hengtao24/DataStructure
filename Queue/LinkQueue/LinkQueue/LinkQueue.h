#include "io.h" 
#include "stdio.h"    
#include "stdlib.h" 

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct QueueNode
{
	ElemType data;
	QueueNode *next;
}QueueNode, *LinkQueuePtr;

typedef struct 
{
	LinkQueuePtr front,rear;
}LinkQueue;

Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = new QueueNode();
	Q->front->next = nullptr;
	return OK;
}

/* 销毁队列Q */
Status DestroyQueue(LinkQueue *Q)
{
	while(Q->front)
	{
		Q->rear=Q->front->next;
		delete Q->front;
		Q->front=Q->rear;
	}
	return OK;
}

/* 将Q清为空队列 */
Status ClearQueue(LinkQueue *Q)
{
	QueueNode *p,*q;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next=NULL;
	while(p)
	{
		q=p;
		p=p->next;
		delete q;
	}
	return OK;
}

Status QueueEmpty(LinkQueue *Q)
{
	if (Q->front == Q->rear)
	{
		return TRUE;
	}
	return FALSE;
}

int QueueLength(LinkQueue *Q)
{
	int count = 0;
	QueueNode *node;
	node = Q->front->next;
	while (node)
	{
		count ++;
		node = node->next;
	}
	return count;
}

Status EnQueue(LinkQueue *Q, ElemType ele)
{
	QueueNode *node = new QueueNode();
	node->data = ele;
	node->next = nullptr;
	Q->rear->next = node;
	Q->rear = node;
	return OK;
}

Status DeQueue(LinkQueue *Q, ElemType *e)
{
	QueueNode *node;
	if (Q->front == Q->rear)
	{
		return ERROR;
	}
	node = Q->front->next;
	*e = node->data;
	Q->front->next = node->next;
	if (node == Q->rear)
	{
		Q->rear = Q->front;
	}
	delete node;
	return OK;
}

Status GetHead(LinkQueue *Q,ElemType *e)
{
	if (Q->front == Q->rear)
	{
		return ERROR;
	}
	*e = Q->front->next->data;
	return OK;
}

Status visit(ElemType e)
{
	printf("%d ",e);
	return OK;
}

Status QueueTraverse(LinkQueue *Q)
{
	QueueNode *node;
	node = Q->front->next;
	while (node)
	{
		visit(node->data);
		node = node->next;
	}
	printf("\n");
	return OK;
}