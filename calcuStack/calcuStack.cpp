// calcuStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "calcuStack.h"
#include<string>
using namespace std;


calcuStack::calcuStack()
{
	count = 0;
}

bool calcuStack::IsOperator(char ch)
{
	if (ch != '(' || ch != ')' || ch != '+' || ch != '-' || ch != '*' || ch != '/'|| ch!='1'||ch!='2'||ch!='3' || ch != '4' || ch != '5' || ch != '6' || ch != '7' || ch != '8' || ch != '9' || ch != '0')
	{
		return false;
	}
	else
		return true;
}

void calcuStack::wipeoffBlank()
{
	int inputLength;
	char c;//用于输入字符串和操作字符串的中间转换
	inputLength = input.length();
	for (int i = 0; i < inputLength; i++)
	{
		c = input[i];
		if (c != ' '&&c != '\n')
		{
			count++;
			calcuNumber += c;
		}
	}
}

void calcuStack::inputString()
{
	getline(cin, input, '#');
}

bool calcuStack::isInputStringWrong()
{
	int inputLength;
	char c;//用于输入字符串和操作字符串的中间转换
	inputLength = input.length();
	for (int i = 0; i < inputLength; i++)
	{
		c = input[i];
		if (c != ' '&&c != '\n'&&c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9' && c != '(' && c != ')' && c != '+' && c != '-' && c != '*' && c != '/')
		{
			return true;
		}
	}
	return false;
}

bool calcuStack::isCalcuNumberNull()
{
	if (calcuNumber.length() != 0)
		return false;
	else
		return true;
}

int calcuStack::calcuNumberCount()
{
	count = calcuNumber.length();
	return count;
}
