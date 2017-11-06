#pragma once
#include "stdafx.h"
#include<iostream>
using namespace std;
class Opnd {
protected:
	int maxsize; //ջ�������ֵ
	int count;  //ջĿǰ����ֵ
	double *elems;  //����ָ��
	void init(int size) {
		maxsize = size;
		if (elems != NULL) delete[]elems;
		elems = new double[maxsize];
		count = 0;
	}
	bool Full() const //����������򷵻�true
	{
		if (count == maxsize)
			return true;
		else
			return false;
	}
	bool Empty() const //���Ϊ�գ��򷵻�true
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
	void clearOpnd() //���ջ����count��0
	{
		count = 0;
	}
	~Opnd() //������
	{
		delete[]elems;
	}
	int push(double e) //��ջ
	{
		if (Full())
			return 0;
		else
		{
			elems[count++] = e;
			return 1;
		}
	}
	//���� 0 ��ʾջ���������� 1 ��ʾ��ջ�ɹ�
	double pop() //��ջ
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
	//���� 0 ��ʾջΪ�գ����򷵻�ջ��ֵ
	double top()//չʾջ����ֵ
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
	//���� 0 ��ʾջΪ�գ����򷵻�ջ����ֵ
};

