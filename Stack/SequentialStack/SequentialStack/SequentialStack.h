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

typedef struct 
{
	ElemType data[MAXSIZE] ;
	int top;
}SqStack;

Status InitStack(SqStack *s)
{
	s-> top = -1;
	return OK;
}

Status ClearStack(SqStack *s)
{
	s->top = -1;
	return OK;
}

/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
Status StackEmpty(SqStack *S)
{ 
	if (S->top==-1)
		return TRUE;
	else
		return FALSE;
}


int StackLength(SqStack *S)
{ 
	return S->top+1;
}

Status Push(SqStack *s, ElemType ele)
{
	if (s->top == MAXSIZE - 1)
	{
		return ERROR;
	}
	s->top ++;
	s->data[s->top] = ele;
	return OK;
}

Status Pop(SqStack *s, ElemType *e)
{
	if (s->top == -1)
	{
		return ERROR;
	}
	*e = s->data[s->top];
	s->top --;
	return OK;
}

/*��ӡ���Ԫ��*/
Status visit(ElemType ele)
{
	printf("%d ",ele);
	return OK;
}

/*��ӡջ��Ԫ��*/
Status StackTraverse(SqStack *S)
{
	int i;
	i=0;
	while(i<=S->top)
	{
		visit(S->data[i++]);
	}
	printf("\n");
	return OK;
}

/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
Status GetTop(SqStack *S,ElemType *e)
{
	if (S->top==-1)
		return ERROR;
	else
		*e=S->data[S->top];
	return OK;
}