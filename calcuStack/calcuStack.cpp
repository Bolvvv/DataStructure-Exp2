// calcuStack.cpp : 定义控制台应用程序的入口点。
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
