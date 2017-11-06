#include "stdafx.h"
#include "calcuStack.h"
#include<string>
using namespace std;
int main()
{
	calcuStack cal;  //定义类
	cal.inputString(); //输入内容

	//下面几行都在纯化输入内容
	if (cal.isInputStringWrong()) {
		cout << "输入错误" << endl;
		return 0;
	}  //判断输入内容书否有误
	cal.wipeoffBlank();  //去除空白和换行
	if (cal.isCalcuNumberNull())
	{
		cout << "未输入内容" << endl;
		return 0;
	}  //判断是否输入



	return 0;
}