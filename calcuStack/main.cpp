#include "stdafx.h"
#include "calcuStack.h"
#include<string>
using namespace std;
int main()
{
	double outSub; 
	calcuStack cal;  //������
	cal.inputString(); //��������

	//���漸�ж��ڴ�����������
	if (cal.isInputStringWrong()) {
		cout << "�������" << endl;
		return 0;
	}  //�ж����������������
	cal.wipeoffBlank();  //ȥ���հ׺ͻ���
	if (cal.isCalcuNumberNull())
	{
		cout << "δ��������" << endl;
		return 0;
	}  //�ж��Ƿ�����
	cal.judgeAndCalcu();
	cal.finishNumberStack();
	outSub = cal.popResult();
	cout << outSub << endl;
	system("PAUSE");
	return 0;
}