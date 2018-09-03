// SequentialStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SequentialStack.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int j;
	SqStack *s = new SqStack();
	int e;
	if(InitStack(s)==OK)
	{
		for(j=1;j<=10;j++)
			Push(s,j);
	}

	printf("栈中元素依次为：");
	StackTraverse(s);
	Pop(s,&e);
	printf("弹出的栈顶元素 e=%d\n",e);
	printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
	GetTop(s,&e);
	printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
	ClearStack(s);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
	return 0;
}

