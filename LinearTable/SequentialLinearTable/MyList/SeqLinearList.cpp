// MyList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SeqLinearList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SqList L;
	SqList lb;

	int i,j,k;
	InitList(L);
	printf("初始化L后：L.length=%d\n",L.length);

	for(j=1;j<=5;j++)
		i=InsertList(L,1,j);
	printf("在L的表头依次插入1～5后：L.data=");
	ListTraverse(L);

	printf("L.length=%d \n",L.length);
	i=ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n",i);

	i=ListClear(L);
	printf("清空L后：L.length=%d\n",L.length);
	i=ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n",i);

	for(j=1;j<=10;j++)
		InsertList(L,j,j);
	printf("在L的表尾依次插入1～10后：L.data=");
	ListTraverse(L); 
	printf("L.length=%d \n",L.length);

	InsertList(L,1,0);
	printf("在L的表头插入0后：L.data=");
	ListTraverse(L); 
	printf("L.length=%d \n",L.length);

	ElemType e;
	GetElem(L,5,&e);
	printf("第5个元素的值为：%d\n",e);

	for(j=3;j<=4;j++)
	{
		k=LocateElem(L,j);
		if(k)
			printf("第%d个元素的值为%d\n",k,j);
		else
			printf("没有值为%d的元素\n",j);
	}

	k=ListLength(L); /* k为表长 */
	for(j=k+1;j>=k;j--)
	{
		i=ListDelete(L,j,&e); /* 删除第j个数据 */
		if(i==ERROR)
			printf("删除第%d个数据失败\n",j);
		else
			printf("删除第%d个的元素值为：%d\n",j,e);
	}
	printf("依次输出L的元素：");
	ListTraverse(L); 

	j=5;
	ListDelete(L,j,&e); /* 删除第5个数据 */
	printf("删除第%d个的元素值为：%d\n",j,e);

	printf("依次输出L的元素：");
	ListTraverse(L); 

	//构造一个有10个数的Lb
	i=InitList(lb);
	for(j=6;j<=15;j++)
		i=InsertList(lb,1,j);

	UnionL(L,lb);

	printf("依次输出合并了Lb的L的元素：");
	ListTraverse(L); 

	return 0;
}

