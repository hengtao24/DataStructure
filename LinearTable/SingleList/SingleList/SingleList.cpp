// SingleList.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include "singlelist.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int a[5] = {2,4,6,8,10};
	int b[6] = {1,2,5,7,10,12};

	int Min = 0;
	int Max = 0;

	List<int> *list1 = new List<int>();
	List<int> *list2 = new List<int>();
	Node<int> *node;

 	for (int k=0;k<5;k++){
		node = list1->CreateNode(a[k]);	//������������
		list1->InsertRear(node);
	}
	list1->PrintList();					//����ǰ��ӡ

	for (int k=0;k<6;k++){
		node = list2->CreateNode(b[k]);	//������������
		list2->InsertRear(node);
	}
	list2->PrintList();					//����ǰ��ӡ

	//��һ�� ��������
	list1->InverseList();				//����
	list1->PrintList();					//���ú��ӡ

	//�ڶ��� ɾ���ض��ڵ�
	cout<<"������Maxֵ��";
	cin>>Max;
	cout<<"������Minֵ��";
	cin>>Min;
	list1->DeleteNodeBetweenMinMax(Min,Max);
	list1->PrintList();

	//������ ����ĺϲ���������
	list1->InverseList();				//����
	list2->PrintList();
	list1->CombineListByOrder(list1,list2); //�ϲ���������
	list1->PrintList();					  //��ӡ
	return 0;
}

