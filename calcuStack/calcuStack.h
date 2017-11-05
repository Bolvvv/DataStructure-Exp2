#pragma once
#include "Opnd.h"
#include "Optr.h"

class calcuStack {
public:
	void Run();                               //执行表达式
private:
	Opnd opnd;     //操作数栈 
	Optr optr;         //操作符栈          
	int isp(char op);                        //栈内优先数
	int icp(char op);                        //栈外优先数
	double DoOperator(double x, char op, double y);
	//形成运算指令，进行运算
	void GetChar(char &ch);         //从输入流获取一字符ch,并跳过空格及回车
	bool IsOperator(char ch);         //判断ch是否为操作符 
	//若为 false 则表明不为操作符，若为true则表明为操作符
};
