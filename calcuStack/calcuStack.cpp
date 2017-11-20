// calcuStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "calcuStack.h"
#include<string>
#include<math.h>
using namespace std;

bool calcuStack::IsOperator(char ch)
{
	if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '=' && ch != '(' && ch != ')')
	{
		return false;
	}
	else
	{
		return true;
	}
}

char calcuStack::Precede(char theta1, char theta2)
{
	if (theta1 == '+'&& theta2 == '+')
		return '>';
	else if (theta1 == '-'&& theta2 == '+')
		return '>';
	else if (theta1 == '*'&& theta2 == '+')
		return '>';
	else if (theta1 == '/'&& theta2 == '+')
		return '>';
	else if (theta1 == '('&& theta2 == '+')
		return '<';
	else if (theta1 == ')'&& theta2 == '+')
		return '>';
	else if (theta1 == '='&& theta2 == '+')
		return '<';
	else if (theta1 == '+'&& theta2 == '-')
		return '>';
	else if (theta1 == '-'&& theta2 == '-')
		return '>';
	else if (theta1 == '*'&& theta2 == '-')
		return '>';
	else if (theta1 == '/'&& theta2 == '-')
		return '>';
	else if (theta1 == '('&& theta2 == '-')
		return '<';
	else if (theta1 == ')'&& theta2 == '-')
		return '>';
	else if (theta1 == '='&& theta2 == '-')
		return '<';
	else if (theta1 == '+'&& theta2 == '*')
		return '<';
	else if (theta1 == '-'&& theta2 == '*')
		return '<';
	else if (theta1 == '*'&& theta2 == '*')
		return '>';
	else if (theta1 == '/'&& theta2 == '*')
		return '>';
	else if (theta1 == '('&& theta2 == '*')
		return '<';
	else if (theta1 == ')'&& theta2 == '*')
		return '>';
	else if (theta1 == '='&& theta2 == '*')
		return '<';
	else if (theta1 == '+'&& theta2 == '/')
		return '<';
	else if (theta1 == '-'&& theta2 == '/')
		return '<';
	else if (theta1 == '*'&& theta2 == '/')
		return '>';
	else if (theta1 == '/'&& theta2 == '/')
		return '>';
	else if (theta1 == '('&& theta2 == '/')
		return '<';
	else if (theta1 == ')'&& theta2 == '/')
		return '>';
	else if (theta1 == '='&& theta2 == '/')
		return '<';
	else if (theta1 == '+'&& theta2 == '(')
		return '<';
	else if (theta1 == '-'&& theta2 == '(')
		return '<';
	else if (theta1 == '*'&& theta2 == '(')
		return '<';
	else if (theta1 == '/'&& theta2 == '(')
		return '<';
	else if (theta1 == '('&& theta2 == '(')
		return '<';
	else if (theta1 == ')'&& theta2 == '(')
		return 'e';
	else if (theta1 == '='&& theta2 == '(')
		return '<';
	else if (theta1 == '+'&& theta2 == ')')
		return '>';
	else if (theta1 == '-'&& theta2 == ')')
		return '>';
	else if (theta1 == '*'&& theta2 == ')')
		return '>';
	else if (theta1 == '/'&& theta2 == ')')
		return '>';
	else if (theta1 == '('&& theta2 == ')')
		return '=';
	else if (theta1 == ')'&& theta2 == ')')
		return '>';
	else if (theta1 == '='&& theta2 == ')')
		return 'e';
	else if (theta1 == '+'&& theta2 == '=')
		return '>';
	else if (theta1 == '-'&& theta2 == '=')
		return '>';
	else if (theta1 == '*'&& theta2 == '=')
		return '>';
	else if (theta1 == '/'&& theta2 == '=')
		return '>';
	else if (theta1 == '('&& theta2 == '=')
		return 'e';
	else if (theta1 == ')'&& theta2 == '=')
		return '>';
	else if (theta1 == '='&& theta2 == '=')
		return '=';
}

double calcuStack::Operate(double left, char theta, double right)
{
	double sub;
	if (theta == '+')
	{
		sub = left + right;
	}
	else if (theta == '-')
	{
		sub = left - right;
	}
	else if (theta == '*')
	{
		sub = left * right;
	}
	else if (theta == '/')
	{
		sub = left / right;
	}
	return sub;
}

void calcuStack::Get20perands(Opnd & opnd, double &left, double & right)
{
	right = opnd.pop();
	left = opnd.pop();
}

void calcuStack::Run()
{
	Opnd opnd;
	Optr optr;
	optr.push('=');
	opnd.push(0);
	char ch;
	char optrTop;
	double operand;
	char theta;
	cout << "请输入表达式" << endl;
	cin >> ch;
	while ((optr.top(optrTop), optrTop != '=') || ch != '=')
	{
		if(!IsOperator(ch))
		{
			cin.putback(ch);
			cin >> operand;
			opnd.push(operand);
			cin >> ch;
		}
		else
		{
			switch(Precede(optrTop,ch))
			{
			case'<':
				optr.push(ch);
				cin >> ch;
				break;
			case'=':
				optr.pop(optrTop); //有问题
				cin >> ch;
				break;
			case'>':
				double left, right;
				Get20perands(opnd, left, right);
				optr.pop(theta);
				opnd.push(Operate(left, theta, right));
				break;
			case'e':
				cout << "操作符匹配错误" << endl;
				exit(2);
			}
		}
	}

	opnd.top(operand);
	cout << "表达式值为：" << operand << endl;
}
