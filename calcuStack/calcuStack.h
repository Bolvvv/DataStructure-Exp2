#pragma once
#include "stdafx.h"
#include "Opnd.h"
#include "Optr.h"
using namespace std;


class calcuStack {
public:
	calcuStack();
	bool IsOperator(char ch);         //�ж�ch�Ƿ�Ϊ������
	//��Ϊ false �������Ϊ����������Ϊtrue�����Ϊ������
	void wipeoffBlank(); //ȥ���հ׺ͻ���
	void inputString();  //�����ַ�������"#"��β
	bool isInputStringWrong(); //�ж������Ƿ���ȷ
	bool isCalcuNumberNull();  //�жϲ���������ַ��Ƿ�Ϊ��
	int calcuNumberCount();
private:
	Opnd opnd;     //������ջ 
	Optr optr;         //������ջ
	string input;  //���������ַ�����δ�����ַ�ʶ���жϣ�
	string calcuNumber; //����ɲ������ַ���
	int count; //������ȷ�Ĳ�������Ŀ
};
