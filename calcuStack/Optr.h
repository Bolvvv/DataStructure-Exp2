#pragma once
#include "stdafx.h"
#include<iostream>
using namespace std;
class Optr {
protected:
	int maxsize; //栈的最大数值
	int count;  //栈目前的数值
	char *elems;  //储存指针
public:
	bool Full() const //如果已满，则返回true
	{
		if (count == maxsize)
			return true;
		else
			return false;
	}
	bool Empty() const //如果为空，则返回t
	{
		if (count == 0)
			return true;
		else
			return false;
	}
	Optr()
	{
		elems = NULL;
		maxsize = 100;
		if (elems != NULL) delete[]elems;
		elems = new char[maxsize];
		count = 0;
	}
	void clearOpnd() //清空栈，将count置0
	{
		count = 0;
	}
	~Optr() //析构类
	{
		delete[]elems;
	}
	int push(char e) //入栈
						//返回 0 表示栈已满，返回 1 表示入栈成功
	{
		if (Full())
			return 0;
		else
		{
			elems[count++] = e;
			return 1;
		}
	}
	char pop() //出栈
				  //返回 0 表示栈为空，否则返回栈顶值
	{
		if (Empty())
			return 0;
		else
		{
			char e;
			e = elems[count - 1];
			count--;
			return e;
		}
	}
	char top() //展示栈顶的值
				  //返回 0 表示栈为空，否则返回栈顶的值
	{
		if (Empty())
		{
			return 0;
		}
		else
		{
			char e;
			e = elems[count - 1];
			return e;
		}
	}
};
