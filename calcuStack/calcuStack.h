#pragma once
#include "stdafx.h"
#include "Opnd.h"
#include "Optr.h"
using namespace std;


class calcuStack {
public:
	calcuStack();


	void inputString();  //�����ַ�������"#"��β
	bool isInputStringWrong(); //�ж������Ƿ���ȷ
	void wipeoffBlank(); //ȥ���հ׺ͻ���
	bool isCalcuNumberNull();  //�жϲ���������ַ��Ƿ�Ϊ��
	//��Ϊ false �������Ϊ����������Ϊtrue�����Ϊ������
	int calcuNumberCount();  //������ȷ�������ַ�����


	int transCharToInt(char e);  //�ַ�ת��Ϊ����
	int transArrayToNumber();  //���ַ�����ĵ�һ����ת��Ϊ10��������
	void judgeAndCalcu();  //�����������ȼ��Լ����ֵ���Ӧ����
	bool isFigure(char &e);  //�ж������Ƿ�Ϊ����
	int judgePriority(char stackout, char stackin);  //�ж���������������ȼ�
	//��a>b�򷵻�1
	//��a==b�򷵻�2
	//��a<b�򷵻�3
	//��aΪ')'��bΪ'('�򷵻�4

	void finishNumberStack();  //��ɶ�ջ������ȼ���������;
	double popResult(); //���ؽ��
	
private:
	Opnd opnd;     //������ջ 
	Optr optr;         //������ջ
	string input;  //���������ַ�����δ�����ַ�ʶ���жϣ�
	string calcuNumber; //����ɲ������ַ���
	int figureArray[100]; //���������������ֵ����飬�����100������
	int figureCount;  //������¼���ָ��������ڽ��ַ�ת��Ϊ10������.��figureCount����ʼֵΪ0
	int count; //������ȷ�Ĳ�������Ŀ
};
