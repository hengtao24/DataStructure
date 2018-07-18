// MyList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "SeqLinearList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SqList L;
	SqList lb;

	int i,j,k;
	InitList(L);
	printf("��ʼ��L��L.length=%d\n",L.length);

	for(j=1;j<=5;j++)
		i=InsertList(L,1,j);
	printf("��L�ı�ͷ���β���1��5��L.data=");
	ListTraverse(L);

	printf("L.length=%d \n",L.length);
	i=ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);

	i=ListClear(L);
	printf("���L��L.length=%d\n",L.length);
	i=ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);

	for(j=1;j<=10;j++)
		InsertList(L,j,j);
	printf("��L�ı�β���β���1��10��L.data=");
	ListTraverse(L); 
	printf("L.length=%d \n",L.length);

	InsertList(L,1,0);
	printf("��L�ı�ͷ����0��L.data=");
	ListTraverse(L); 
	printf("L.length=%d \n",L.length);

	ElemType e;
	GetElem(L,5,&e);
	printf("��5��Ԫ�ص�ֵΪ��%d\n",e);

	for(j=3;j<=4;j++)
	{
		k=LocateElem(L,j);
		if(k)
			printf("��%d��Ԫ�ص�ֵΪ%d\n",k,j);
		else
			printf("û��ֵΪ%d��Ԫ��\n",j);
	}

	k=ListLength(L); /* kΪ�� */
	for(j=k+1;j>=k;j--)
	{
		i=ListDelete(L,j,&e); /* ɾ����j������ */
		if(i==ERROR)
			printf("ɾ����%d������ʧ��\n",j);
		else
			printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
	}
	printf("�������L��Ԫ�أ�");
	ListTraverse(L); 

	j=5;
	ListDelete(L,j,&e); /* ɾ����5������ */
	printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);

	printf("�������L��Ԫ�أ�");
	ListTraverse(L); 

	//����һ����10������Lb
	i=InitList(lb);
	for(j=6;j<=15;j++)
		i=InsertList(lb,1,j);

	UnionL(L,lb);

	printf("��������ϲ���Lb��L��Ԫ�أ�");
	ListTraverse(L); 

	return 0;
}

