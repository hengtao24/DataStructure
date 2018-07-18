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


/* 初始化顺序线性表 */
Status InitList(SqList &L)
{
	L.length = 0;
	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ListClear(SqList &L)
{
	L.length = 0;
	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(SqList L)
{
	return L.length;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(SqList L)
{
	if (L.length == 0)
	{
		return TRUE;
	}
	return FALSE;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
Status GetElem(SqList L,int i, ElemType* e)
{
	if (L.length <=0 || i<1 || i>L.length)
		return ERROR;
	*e = L.data[i-1];
	return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
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

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
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

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
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

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
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