// LinkQueue.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "LinkQueue.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	ElemType d;
	LinkQueue *q = new LinkQueue();
	i=InitQueue(q);
	if(i)
		printf("�ɹ��ع�����һ���ն���!\n");

	printf("�Ƿ�ն��У�%d(1:�� 0:��)  ",QueueEmpty(q));
	printf("���еĳ���Ϊ%d\n",QueueLength(q));
	EnQueue(q,-5);
	EnQueue(q,5);
	EnQueue(q,10);
	printf("����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n",QueueLength(q));
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  ",QueueEmpty(q));
	printf("���е�Ԫ������Ϊ��");
	QueueTraverse(q);
	i=GetHead(q,&d);
	if(i==OK)
		printf("��ͷԪ���ǣ�%d\n",d);
	DeQueue(q,&d);
	printf("ɾ���˶�ͷԪ��%d\n",d);
	i=GetHead(q,&d);
	if(i==OK)
		printf("�µĶ�ͷԪ���ǣ�%d\n",d);
	ClearQueue(q);
	printf("��ն��к�,q.front=%u q.rear=%u q.front->next=%u\n",q->front,q->rear,q->front->next);
	DestroyQueue(q);
	printf("���ٶ��к�,q.front=%u q.rear=%u\n",q->front, q->rear);

	return 0;}
