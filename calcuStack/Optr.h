#pragma once
#pragma once
#include<iostream>
using namespace std;
class Optr {
protected:
	int maxsize; //ջ�������ֵ
	int count;  //ջĿǰ����ֵ
	char *elems;  //����ָ��
	void init(int size);
	bool Full() const; //����������򷵻�true
	bool Empty() const; //���Ϊ�գ��򷵻�t
public:
	Optr(int size);
	Optr();
	void clearOpnd(); //���ջ����count��0
	~Optr();  //������
	int push(char e); //��ջ
						//���� 0 ��ʾջ���������� 1 ��ʾ��ջ�ɹ�
	char pop(); //��ջ
				  //���� 0 ��ʾջΪ�գ����򷵻�ջ��ֵ
	char top(); //չʾջ����ֵ
				  //���� 0 ��ʾջΪ�գ����򷵻�ջ����ֵ
};