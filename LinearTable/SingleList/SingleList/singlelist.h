#include<iostream>

template<typename T>class List;

template<typename T> class Node
{
public:
	T data;				// 数据域
	Node<T> *next;	    // 指针域
public:
	Node();
	Node(const T & data);
	Node<T>* RemoveAfter();
	friend class List<T>;    // 以List为友元类，List可直接访问Node的私有成员，与结构体一样方便，但更安全
};

template<typename T> Node<T>::Node()
{
	next = NULL;
}

template<typename T> Node<T>::Node(const T & data)
{
	this->data = data;
	this->next = NULL;
}

template<typename T> Node<T>* Node<T>::RemoveAfter()
{
	Node<T> *node = next;
	if (next == NULL)
	{
		node = NULL;
	}
	else
	{
		next = node->next;
	}
	return node;
}

template<typename T> class List
{
	Node<T> *head,*tail;
	int Count;
public:
	List();
	~List();
	void MakeEmpty();
	void PrintList();
	Node<T>* CreateNode(T data);
	void InsertRear(Node<T>* node);
	void InsertFront(Node<T>* node);
	void InverseList();
	void DeleteNodeBetweenMinMax(int,int);
	Node<T>* DeleteNode(Node<T>*);
	List<T>* CombineListByOrder(List<T>*,List<T>*);
};

template<typename T> List<T>::List()
{
	head = tail = new Node<T>();
	Count = 0;
}

template<typename T> List<T>::~List()
{
	MakeEmpty();
	delete head;
	delete tail;
}

//清空链表
template<typename T> void List<T>::MakeEmpty()
{
	Node<T> *tmp;
	while (head->next != null)
	{
		tmp = head->next;
		head->next = tmp->next;
		delete tmp;
	}
	Count = 0;
	tail = head;
}

template<typename T> void List<T>::PrintList()
{
	Node<T>* tmp;
	tmp = head;
	while(tmp->next != NULL)
	{
		cout<<tmp->next->data<<'\t';
		tmp = tmp->next;
	}
	cout<<endl;
}

template<typename T> Node<T>* List<T>::CreateNode(T data)
{
	Node<T>* node = new Node<T>(data);
	return node;
}

template<typename T> void List<T>::InsertRear(Node<T>* node)
{
	node->next = tail->next;
	tail->next = node;
	tail = node;
	Count ++;
}

template<typename T> void List<T>::InsertFront(Node<T>* node)
{
	node->next = head->next;
	head->next = node;
	if (head = tail)
	{
		tail = node;
	}
	Count ++;
}

// 倒置链表
template<typename T> void List<T>::InverseList()
{
	if (head == tail)
		return;

	Node<T>* tmp1 = NULL;
	Node<T>* tmp2 = NULL;

	for (int i=0; i<Count; i++)
	{
		tmp1 = head->RemoveAfter(); // 取出当前节点后的第一个有效节点
		tmp1-> next = tmp2;         // 将取出的节点指向tmp2
		tmp2 = tmp1;				// 再将tmp2指向tmp1
		if (i == 0)
		{
			tail = tmp1;
		}
	}
	head->next = tmp2;
}

// 删除链表中节点值位于min和max之间的节点
template<typename T> void List<T>::DeleteNodeBetweenMinMax(int min,int max)
{
	if (head == tail)
		return;
	Node<T>* tmp1 = head;
	Node<T>* tmp2 = NULL;

	int len = Count;

	for (int i=0; i<len; i++)
	{
		tmp2 = tmp1->next;
		if (tmp2->data > min && tmp2->data < max)
		{
			DeleteNode(tmp2);	   //满足的话删除tmp2	
		}
		else
		{
			tmp1 = tmp1->next;     //不满足继续向下索引
		}
	}
}

// 删除节点
template<typename T> Node<T>* List<T>::DeleteNode(Node<T>* node)
{
	Node<T> * tmp = head;
	while (tmp->next != NULL && tmp->next != node) // 找到p的位置
	{
		tmp = tmp->next;
	}
	if (tmp->next == tail)
	{
		tail = tmp;
	}
	if (tmp->next != NULL)
	{
		Count --;
	}
	return tmp->RemoveAfter();
}

// 合并链表
template<typename T> List<T>* List<T>::CombineListByOrder(List<T>* l1,List<T>* l2)
{
	Node<T>* tmp1 = NULL;
	Node<T>* tmp2 = NULL;
	Node<T>* nodeNow = NULL;  // 该节点永远指向合并链表的当前节点

	if (l1->Count == 0)
		return l2;
	if (l2->Count == 0)
		return l1;

	tmp1 = l1->head->next;
	tmp2 = l2->head->next;
	nodeNow = l1->head;

	while (tmp1 != nullptr && tmp2 != nullptr)
	{
		if (tmp1->data <= tmp2->data) //L1较小则将nodeNow指向L1
		{
			nodeNow ->next = tmp1;
			nodeNow = tmp1;
			tmp1 = tmp1->next;
		}
		else
		{
			nodeNow ->next = tmp2;   //否则将nodeNow指向L2
			nodeNow = tmp2;
			tmp2 = tmp2->next;
		}
	}
	if (tmp1 == nullptr)
	{
		nodeNow->next = tmp2;	// L1为空将L1最后节点指向tmp2
		l1->tail = l2->tail;    // 合并尾节点
	}
	if (tmp2 == nullptr)
	{
		nodeNow->next = tmp1;		// L2为空则将L2最后节点指向tmp1
	}
	delete DeleteNode(l2->head);
	return l1;
}