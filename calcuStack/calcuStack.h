#pragma once
#include "stdafx.h"
#include "Opnd.h"
#include "Optr.h"
using namespace std;


class calcuStack {
public:
	calcuStack();
	bool IsOperator(char ch);         //判断ch是否为操作符
	//若为 false 则表明不为操作符，若为true则表明为操作符
	void wipeoffBlank(); //去除空白和换行
	void inputString();  //输入字符串，以"#"结尾
	bool isInputStringWrong(); //判断输入是否正确
	bool isCalcuNumberNull();  //判断参与运算的字符是否为空
	int calcuNumberCount();
private:
	Opnd opnd;     //操作数栈 
	Optr optr;         //操作符栈
	string input;  //定义输入字符串（未经过字符识别判断）
	string calcuNumber; //定义可操作的字符串
	int count; //定义正确的操作数数目
};
