#pragma once
#include "Opnd.h"
#include "Optr.h"

class calcuStack {
public:
	void Run();                               //ִ�б��ʽ
private:
	Opnd opnd;     //������ջ 
	Optr optr;         //������ջ          
	int isp(char op);                        //ջ��������
	int icp(char op);                        //ջ��������
	double DoOperator(double x, char op, double y);
	//�γ�����ָ���������
	void GetChar(char &ch);         //����������ȡһ�ַ�ch,�������ո񼰻س�
	bool IsOperator(char ch);         //�ж�ch�Ƿ�Ϊ������ 
	//��Ϊ false �������Ϊ����������Ϊtrue�����Ϊ������
};
