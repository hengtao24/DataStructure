#include "stdio.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef int Status;
typedef int ElemType;

typedef struct 
{
	ElemType data[MAXSIZE];
	int length;
} SqList;


/* ��ʼ��˳�����Ա� */
Status InitList(SqList &L)
{
	L.length = 0;
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
Status ListClear(SqList &L)
{
	L.length = 0;
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(SqList L)
{
	return L.length;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
Status ListEmpty(SqList L)
{
	if (L.length == 0)
	{
		return TRUE;
	}
	return FALSE;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ,ע��i��ָλ�ã���1��λ�õ������Ǵ�0��ʼ */
Status GetElem(SqList L,int i, ElemType* e)
{
	if (L.length <=0 || i<1 || i>L.length)
		return ERROR;
	*e = L.data[i-1];
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
int LocateElem(SqList L, ElemType e)
{
	if (L.length == 0)
	{
		return 0;
	}
	for (int i=0; i<L.length; i++)
	{
		if (L.data[i] == e)
		{
			return i+1;
		}
	}
	return 0;
}

/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status InsertList(SqList &L, int i, ElemType e)
{
	if (L.length == MAXSIZE)
		return ERROR;
	if (i<1 || i>L.length+1)
		return ERROR;
	if (i<= L.length)
	{
		for (int k = L.length-1;k>=i-1;k--)
		{
			L.data[k+1] = L.data[k];
		}
	}
	L.data[i-1] = e;
	L.length ++;
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(SqList &L,int j,ElemType *e)
{
	if (L.length == 0)
	{
		return ERROR;
	}
	if (j<1 || j> L.length)
	{
		return ERROR;
	}
	*e = L.data[j-1];
	for(int i = j-1;i<L.length-1;i++)
	{
		L.data[i] = L.data[i+1];
	}
	L.length--;
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(SqList L)
{
	for(int i = 0;i<L.length; i++)
	{
		printf("%d ",L.data[i]);
	}
	printf("\n");
	return OK;
}

void UnionL(SqList &L, SqList &Lb)
{
	int La_len,Lb_len;
	ElemType e;
	La_len = ListLength(L);
	Lb_len = ListLength(Lb);

	for (int i = 0;i<Lb_len; i++)
	{
		GetElem(Lb,i+1,&e);
		if (!LocateElem(L,e))
		{
			InsertList(L,La_len++,e);
		}
	}
}