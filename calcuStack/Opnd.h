#pragma once
#include "stdafx.h"
#include<iostream>
using namespace std;
class Opnd {
protected:
	int maxsize; //栈的最大数值
	int count;  //栈目前的数值
	double *elems;  //储存指针
	void init(int size) {
		maxsize = size;
		if (elems != NULL) delete[]elems;
		elems = new double[maxsize];
		count = 0;
	}
	bool Full() const //如果已满，则返回true
	{
		if (count == maxsize)
			return true;
		else
			return false;
	}
	bool Empty() const //如果为空，则返回true
	{
		if (count == 0)
			return true;
		else
			return false;
	}
public:
	Opnd(int size)
	{
		elems = NULL;
		init(size);
	}
	Opnd() 
	{
		maxsize = 0;
		count = 0;
		elems = NULL;
	}
	void clearOpnd() //清空栈，将count置0
	{
		count = 0;
	}
	~Opnd() //析构类
	{
		delete[]elems;
	}
	int push(double e) //入栈
	{
		if (Full())
			return 0;
		else
		{
			elems[count++] = e;
			return 1;
		}
	}
	//返回 0 表示栈已满，返回 1 表示入栈成功
	double pop() //出栈
	{
		if (Empty())
			return 0;
		else
		{
			double e;
			e = elems[count - 1];
			count--;
			return e;
		}
	}
	//返回 0 表示栈为空，否则返回栈顶值
	double top()//展示栈顶的值
	{
		if (Empty())
		{
			return 0;
		}
		else
		{
			double e;
			e = elems[count - 1];
			return e;
		}
	}
	//返回 0 表示栈为空，否则返回栈顶的值
};

