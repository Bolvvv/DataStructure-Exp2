#pragma once
#include "stdafx.h"
#include<iostream>
using namespace std;
class Optr {
protected:
	int maxsize; //ջ�������ֵ
	int count;  //ջĿǰ����ֵ
	char *elems;  //����ָ��
public:
	bool Full() const //����������򷵻�true
	{
		if (count == maxsize)
			return true;
		else
			return false;
	}
	bool Empty() const //���Ϊ�գ��򷵻�t
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
	void clearOpnd() //���ջ����count��0
	{
		count = 0;
	}
	~Optr() //������
	{
		delete[]elems;
	}
	int push(char e) //��ջ
						//���� 0 ��ʾջ���������� 1 ��ʾ��ջ�ɹ�
	{
		if (Full())
			return 0;
		else
		{
			elems[count++] = e;
			return 1;
		}
	}
	char pop() //��ջ
				  //���� 0 ��ʾջΪ�գ����򷵻�ջ��ֵ
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
	char top() //չʾջ����ֵ
				  //���� 0 ��ʾջΪ�գ����򷵻�ջ����ֵ
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
