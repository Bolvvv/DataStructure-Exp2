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
	void judgeAndCalcu();  //进行运算优先级以及数字的相应运算
	bool isInputStringWrong(); //判断输入是否正确
	bool isCalcuNumberNull();  //判断参与运算的字符是否为空
	bool isFigure(char &e);  //判断输入是否为数字
	int calcuNumberCount();  //返回正确的输入字符个数
	int transCharToInt(char e);  //字符转换为数字
	int transArrayToNumber();  //将字符里面的单一数字转化为10进制数字
	
private:
	Opnd opnd;     //操作数栈 
	Optr optr;         //操作符栈
	string input;  //定义输入字符串（未经过字符识别判断）
	string calcuNumber; //定义可操作的字符串
	int figureArray[100]; //定义用来储存数字的数组，最多有100个数字
	int figureCount;  //用来记录数字个数，便于将字符转化为10进制数.该figureCount的起始值为0
	int count; //定义正确的操作数数目
};
