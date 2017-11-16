#pragma once
#include "stdafx.h"
#include "Opnd.h"
#include "Optr.h"
using namespace std;


class calcuStack {
private:
	static bool IsOperator(char ch);//判断是否是操作符
	static char Precede(char theta1, char theta2);//判断输入字符的优先级，以及括号的判断
	static double Operate(double left, char theta, double right);//进行运算
	static void Get20perands(Opnd &opnd, double &left, double &right);//获取操作符以及左右位操作数
public:
	calcuStack() {};
	virtual ~calcuStack() {};
	static void Run();
};
