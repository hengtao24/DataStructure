// SingleList.cpp : 定义控制台应用程序的入口点。
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
		node = list1->CreateNode(a[k]);	//创建已有链表
		list1->InsertRear(node);
	}
	list1->PrintList();					//倒置前打印

	for (int k=0;k<6;k++){
		node = list2->CreateNode(b[k]);	//创建已有链表
		list2->InsertRear(node);
	}
	list2->PrintList();					//倒置前打印

	//第一题 倒置链表
	list1->InverseList();				//倒置
	list1->PrintList();					//倒置后打印

	//第二题 删除特定节点
	cout<<"请输入Max值：";
	cin>>Max;
	cout<<"请输入Min值：";
	cin>>Min;
	list1->DeleteNodeBetweenMinMax(Min,Max);
	list1->PrintList();

	//第三题 有序的合并两个链表
	list1->InverseList();				//倒置
	list2->PrintList();
	list1->CombineListByOrder(list1,list2); //合并两个链表
	list1->PrintList();					  //打印
	return 0;
}

