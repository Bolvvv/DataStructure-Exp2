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
	void judgeAndCalcu();  //�����������ȼ��Լ����ֵ���Ӧ����
	bool isInputStringWrong(); //�ж������Ƿ���ȷ
	bool isCalcuNumberNull();  //�жϲ���������ַ��Ƿ�Ϊ��
	bool isFigure(char &e);  //�ж������Ƿ�Ϊ����
	int calcuNumberCount();  //������ȷ�������ַ�����
	int transCharToInt(char e);  //�ַ�ת��Ϊ����
	int transArrayToNumber();  //���ַ�����ĵ�һ����ת��Ϊ10��������
	
private:
	Opnd opnd;     //������ջ 
	Optr optr;         //������ջ
	string input;  //���������ַ�����δ�����ַ�ʶ���жϣ�
	string calcuNumber; //����ɲ������ַ���
	int figureArray[100]; //���������������ֵ����飬�����100������
	int figureCount;  //������¼���ָ��������ڽ��ַ�ת��Ϊ10������.��figureCount����ʼֵΪ0
	int count; //������ȷ�Ĳ�������Ŀ
};
