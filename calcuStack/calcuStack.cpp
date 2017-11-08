// calcuStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "calcuStack.h"
#include<string>
#include<math.h>
using namespace std;


calcuStack::calcuStack()
{
	figureCount = 0;
	count = 0;
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

void calcuStack::judgeAndCalcu()
{
	char c;
	char a;
	for (int i = 0; i < count; i++)
	{
		c = calcuNumber[i];
		a = optr.top();
		if (isFigure(c))
		{
			figureArray[figureCount] = transCharToInt(c);
			figureCount++;
			if (i == count-1) {
				int sub = transArrayToNumber();
				opnd.push(sub);
				figureCount = 0;
				continue;
			}
		}
		else
		{
			if (figureCount != 0) 
			{
				int sub = transArrayToNumber();
				opnd.push(sub);
				figureCount = 0;
			}
			if (optr.Empty())
			{
				optr.push(c);
			}
			else
			{
				if (judgePriority(c, a) == 1 || judgePriority(c, a) == 2)
				{
					optr.push(c);
				}
				else if (judgePriority(c, a) == 3)
				{
					while (judgePriority(c, a) != 1||a != NULL) 
					{
						double pop1, pop2, sub;
						char option = optr.pop();
						pop1 = opnd.pop();
						pop2 = opnd.pop();
						if (option == '+')
						{
							sub = pop2 + pop1;
							opnd.push(sub);
							a = optr.top();
						}
						else if (option == '-')
						{
							sub = pop2 - pop1;
							opnd.push(sub);
							a = optr.top();
						}
						else if (option == '*')
						{
							sub = pop2 * pop1;
							opnd.push(sub);
							a = optr.top();
						}
						else if (option == '/')
						{
							sub = pop2 / pop1;
							opnd.push(sub);
							a = optr.top();
						}
					}
					optr.push(c);
				}
				char mm = optr.top();
				if (judgePriority(c, mm) == 4)
				{
					optr.pop();
					optr.pop();
				}
			}
		}
	}
}

int calcuStack::transCharToInt(char e)
{
	int trans;
	trans = e - 48;
	return trans;
}

int calcuStack::transArrayToNumber()
{
	int sub = 0;
	for (int i = 0; i < figureCount; i++)
	{
		int number;
		int n;
		n = figureCount - i-1;
		number = figureArray[i];
		number = number*pow(10, n);
		sub += number;
	}
	return sub;
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

bool calcuStack::isFigure(char &e)
{
	if (e == '+' || e == '-' || e == '*' || e == '/' || e == '(' || e == ')')
		return false;
	else
		return true;
}

int calcuStack::judgePriority(char stackout, char stackin)
{
	int a, b;
	if (stackout == '+')
	{
		a = 1;
	}
	else if (stackout == '-')
	{
		a = 1;
	}
	else if (stackout == '*')
	{
		a = 2;
	}
	else if (stackout == '/')
	{
		a = 2;
	}
	else if (stackout == '(')
	{
		a = -1;
	}
	else if (stackout == ')')
	{
		a = 0;
	}
	if (stackin == '+')
	{
		b = 1;
	}
	else if (stackin == '-')
	{
		b = 1;
	}
	else if (stackin == '*')
	{
		b = 2;
	}
	else if (stackin == '/')
	{
		b = 2;
	}
	else if (stackin == '(')
	{
		b = -1;
	}
	else if (stackin == ')')
	{
		b = 0;
	}
	if (a > b)
		return 1;
	else if (a == b)
		return 2;
	else if (a < b)
		return 3;
	else if (a == 0 && b == -1)
		return 4;
}

void calcuStack::finishNumberStack()
{
	while (opnd.returnCount() != 1)
	{
		double pop1, pop2, sub;
		char option = optr.pop();
		pop1 = opnd.pop();
		pop2 = opnd.pop();
		if (option == '+')
		{
			sub = pop2 + pop1;
			opnd.push(sub);
		}
		else if (option == '-')
		{
			sub = pop2 - pop1;
			opnd.push(sub);
		}
		else if (option == '*')
		{
			sub = pop2 * pop1;
			opnd.push(sub);
		}
		else if (option == '/')
		{
			sub = pop2 / pop1;
			opnd.push(sub);
		}
	}
}

double calcuStack::popResult()
{
	return opnd.pop();
}

int calcuStack::calcuNumberCount()
{
	count = calcuNumber.length();
	return count;
}
