/***************************************************
*
*	Description:This is a learning of C++ template programming ( 一个学习C++模板编程的练习)
*	Platform: win8.1_x64 + vs2013
*	Author: Bluer
*	Date: 2015-07-06
*
***************************************************/



#include <iostream>
#include <tchar.h>
#include <windows.h>
#include <Stack>

#include "Stack.h"
using namespace std;


void TestCStack();		//用于测试栈模板类的函数


INT main( int _Argc,  char ** _Argv,  char ** _Env)
{
	TestCStack();
	system("pause");
	return 0;
}



//用于测试栈模板类的函数
void TestCStack()
{
	CStack<int, 2> stack(2);
	cout << "stack.IsEmpty() " << stack.IsEmpty() << endl;
	cout << "stack.IsFull() " << stack.IsFull() << endl;
	stack.Push(10);
	cout << "stack.Push(10) " << endl;
	int tmp = 20;
	stack.Push(tmp);
	cout << "stack.Push(20) " << endl;
	cout << "stack.GetMaxSize() " << stack.GetMaxSize() << endl;
	cout << "stack.GetCurSize() " << stack.GetCurSize() << endl;
	stack.Push(30);
	cout << "stack.Push(30) " << endl;
	cout << "stack.GetCurSize() " << stack.GetCurSize() << endl;
	cout << "stack.IsFull() " << stack.IsFull() << endl;
	cout << "stack.Pop() " << stack.Pop(nullptr) << endl;
	int res;
	cout << "stack.Pop() " << stack.Pop(&res) << endl;
	cout << "stack.Pop() " << stack.Pop(nullptr) << endl;
	cout << "stack.GetCurSize() " << stack.GetCurSize() << endl;
	stack.Push(40);
	cout << "stack.Push(40) " << endl;
	cout << "stack.GetCurSize() " << stack.GetCurSize() << endl;
	cout << "stack.IsEmpty() " << stack.IsEmpty() << endl;
	cout << "stack.IsFull() " << stack.IsFull() << endl;
	stack.Clear();
	cout << "stack.Clear() " << endl;
	cout << "stack.GetCurSize() " << stack.GetCurSize() << endl;
	cout << "stack.IsEmpty() " << stack.IsEmpty() << endl;
	cout << "stack.IsFull() " << stack.IsFull() << endl;

	CStack<string, 1>::value_type a;
	a = "hello";
	cout << "CStack<string, 1>::value_type a = hello;  " << a.c_str() << endl;
	CStack<int, 2>::value_type b = 12;
	cout << "CStack<int, 2>::value_type b = 12;  " << b << endl;
}