#pragma once
#include<iostream>
using namespace std;
class Opnd {
protected:
	int maxsize; //ջ�������ֵ
	int count;  //ջĿǰ����ֵ
	double *elems;  //����ָ��
	void init(int size);
	bool Full() const; //����������򷵻�true
	bool Empty() const; //���Ϊ�գ��򷵻�t
public:
	Opnd(int size);
	Opnd();
	void clearOpnd(); //���ջ����count��0
	~Opnd();  //������
	int push(double e); //��ջ
	//���� 0 ��ʾջ���������� 1 ��ʾ��ջ�ɹ�
	double pop(); //��ջ
	//���� 0 ��ʾջΪ�գ����򷵻�ջ��ֵ
	double top(); //չʾջ����ֵ
	//���� 0 ��ʾջΪ�գ����򷵻�ջ����ֵ
};