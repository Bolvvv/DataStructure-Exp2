#pragma once
#include "stdafx.h"
#include "Opnd.h"
#include "Optr.h"
using namespace std;


class calcuStack {
private:
	static bool IsOperator(char ch);//�ж��Ƿ��ǲ�����
	static char Precede(char theta1, char theta2);//�ж������ַ������ȼ����Լ����ŵ��ж�
	static double Operate(double left, char theta, double right);//��������
	static void Get20perands(Opnd &opnd, double &left, double &right);//��ȡ�������Լ�����λ������
public:
	calcuStack() {};
	virtual ~calcuStack() {};
	static void Run();
};
