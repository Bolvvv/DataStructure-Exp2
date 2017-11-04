#pragma once
#include<iostream>
using namespace std;
class Opnd {
protected:
	int maxsize; //栈的最大数值
	int count;  //栈目前的数值
	double *elems;  //储存指针
	void init(int size);
	bool Full() const; //如果已满，则返回true
	bool Empty() const; //如果为空，则返回t
public:
	Opnd(int size);
	Opnd();
	void clearOpnd(); //清空栈，将count置0
	~Opnd();  //析构类
	int push(double e); //入栈
	//返回 0 表示栈已满，返回 1 表示入栈成功
	double pop(); //出栈
	//返回 0 表示栈为空，否则返回栈顶值
	double top(); //展示栈顶的值
	//返回 0 表示栈为空，否则返回栈顶的值
};