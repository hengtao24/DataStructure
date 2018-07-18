#include<iostream>

template<typename T>class List;

template<typename T> class Node
{
public:
	T data;				// ������
	Node<T> *next;	    // ָ����
public:
	Node();
	Node(const T & data);
	Node<T>* RemoveAfter();
	friend class List<T>;    // ��ListΪ��Ԫ�࣬List��ֱ�ӷ���Node��˽�г�Ա����ṹ��һ�����㣬������ȫ
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

//�������
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

// ��������
template<typename T> void List<T>::InverseList()
{
	if (head == tail)
		return;

	Node<T>* tmp1 = NULL;
	Node<T>* tmp2 = NULL;

	for (int i=0; i<Count; i++)
	{
		tmp1 = head->RemoveAfter(); // ȡ����ǰ�ڵ��ĵ�һ����Ч�ڵ�
		tmp1-> next = tmp2;         // ��ȡ���Ľڵ�ָ��tmp2
		tmp2 = tmp1;				// �ٽ�tmp2ָ��tmp1
		if (i == 0)
		{
			tail = tmp1;
		}
	}
	head->next = tmp2;
}

// ɾ�������нڵ�ֵλ��min��max֮��Ľڵ�
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
			DeleteNode(tmp2);	   //����Ļ�ɾ��tmp2	
		}
		else
		{
			tmp1 = tmp1->next;     //�����������������
		}
	}
}

// ɾ���ڵ�
template<typename T> Node<T>* List<T>::DeleteNode(Node<T>* node)
{
	Node<T> * tmp = head;
	while (tmp->next != NULL && tmp->next != node) // �ҵ�p��λ��
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

// �ϲ�����
template<typename T> List<T>* List<T>::CombineListByOrder(List<T>* l1,List<T>* l2)
{
	Node<T>* tmp1 = NULL;
	Node<T>* tmp2 = NULL;
	Node<T>* nodeNow = NULL;  // �ýڵ���Զָ��ϲ�����ĵ�ǰ�ڵ�

	if (l1->Count == 0)
		return l2;
	if (l2->Count == 0)
		return l1;

	tmp1 = l1->head->next;
	tmp2 = l2->head->next;
	nodeNow = l1->head;

	while (tmp1 != nullptr && tmp2 != nullptr)
	{
		if (tmp1->data <= tmp2->data) //L1��С��nodeNowָ��L1
		{
			nodeNow ->next = tmp1;
			nodeNow = tmp1;
			tmp1 = tmp1->next;
		}
		else
		{
			nodeNow ->next = tmp2;   //����nodeNowָ��L2
			nodeNow = tmp2;
			tmp2 = tmp2->next;
		}
	}
	if (tmp1 == nullptr)
	{
		nodeNow->next = tmp2;	// L1Ϊ�ս�L1���ڵ�ָ��tmp2
		l1->tail = l2->tail;    // �ϲ�β�ڵ�
	}
	if (tmp2 == nullptr)
	{
		nodeNow->next = tmp1;		// L2Ϊ����L2���ڵ�ָ��tmp1
	}
	delete DeleteNode(l2->head);
	return l1;
}