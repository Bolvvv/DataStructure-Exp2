// calcuStack.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "calcuStack.h"


int main()
{
	int a = 0;
    return 0;
}

bool calcuStack::IsOperator(char ch)
{
	if (ch != '(' || ch != ')' || ch != '+' || ch != '-' || ch != '*' || ch != '/')
	{
		return false;
	}
	else
		return true;
}
