#include "io.h" 
#include "stdio.h"    
#include "stdlib.h" 

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef int Status;
typedef int ElemType;

typedef struct StackNode
{
	ElemType data;
	StackNode* next;
}StackNode,*LinkStackPtr;

typedef struct 
{
	LinkStackPtr top;
	int count;
}LinkStack;

Status InitStack(LinkStack *s)
{
	s->top = NULL;
	s->count = 0;
	return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(LinkStack *s)
{
	if (s->count == 0)
	{
		return TRUE;
	}
	return FALSE;
}

Status ClearStack(LinkStack *s)
{
	StackNode *node,*tmp;
	node = s->top;
	while(node)
	{
		tmp = node;
		s->top = s->top->next;
		delete tmp;
		node = s->top;
	}
	return OK;
}

Status Push(LinkStack *s, ElemType ele)
{
	StackNode *node = new StackNode();
	node->data = ele;
	node->next = s->top;
	s->top = node;
	s->count ++;
	return OK;
}

Status Pop(LinkStack *s,ElemType *e)
{
	if (StackEmpty(s))
	{
		return ERROR;
	}
	StackNode *node;
	*e = s->top->data;
	node = s->top;
	s->top = s->top->next;
	delete node;
	s->count --;
	return OK;
}

Status GetTop(LinkStack *s,ElemType *e)
{
	if (s->count == 0)
	{
		return ERROR;
	}
	*e = s->top->data;
	return OK;
}

int StackLength(LinkStack *s)
{
	return s->count;
}

Status visit(ElemType ele)
{
	printf("%d ",ele);
	return OK;
}

Status StackTraverse(LinkStack *S)
{
	LinkStackPtr p;
	p=S->top;
	while(p)
	{
		visit(p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}