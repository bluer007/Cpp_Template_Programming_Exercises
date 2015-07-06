/***************************************************
*
*	CStack栈类模板的定义文件
*
***************************************************/


#ifndef _STACK_H_
#define _STACK_H_

#include <assert.h>

template <typename T, int MaxSize>
class CStack
{
public:
	explicit CStack(int maxSize);
	explicit CStack();
	~CStack();

	const T& Pop(int* result);		//出栈
	int Push(const T& elem);		//入栈
	int IsEmpty();					//是否为空
	int IsFull();					//是否为满
	int GetMaxSize();				//返回栈总大小
	int GetCurSize();				//返回栈当前元素数量
	int Clear();					//清空整个栈

	typedef T value_type;			//以元素类型来定义类型

protected:
	const int MAX_SIZE;				//记录栈总大小
	T* m_top;						//记录栈顶的指针
	T* m_stack;						//存储整个栈
};


template <typename T, int MaxSize>
CStack<T, MaxSize>::CStack(int maxSize)
	: MAX_SIZE(maxSize)
{
	assert(maxSize == MaxSize && MaxSize > 0);
	
	//第一个栈元素m_stack[0]做不存储元素的栈底
	this->m_stack = new T[MAX_SIZE + 1]();
	this->m_top = this->m_stack;
}

template <typename T, int MaxSize>
CStack<T, MaxSize>::CStack()
	: MAX_SIZE(MaxSize)
{
	assert(MaxSize > 0);

	//第一个栈元素m_stack[0]做不存储元素的栈底
	this->m_stack = new T[MAX_SIZE + 1]();
	this->m_top = this->m_stack;

}

template <typename T, int MaxSize>
CStack<T, MaxSize>::~CStack()
{
	if (this->m_stack)
	{
		delete this->m_stack;
		this->m_stack = nullptr;
	}
}


/*
* 功能: 出栈
* 参数: elem用于接收出栈的元素
* 返回值: 成功为true, 失败为false
*/
template <typename T, int MaxSize>
const T& CStack<T, MaxSize>::Pop(int* result)
{
	static T elem;
	int res = true;
	do 
	{
		if (this->IsEmpty())
		{	
			//如果栈空
			res = false;
			break;
		}
		else
		{
			//栈不空
			elem = *this->m_top;
			this->m_top--;
		}
	} while (0);

	if (result) *result = res;
	return elem;
}


/*
* 功能: 入栈
* 参数: elem用于接收入栈的元素
* 返回值: 成功为true, 失败为false
*/
template <typename T, int MaxSize>
int CStack<T, MaxSize>::Push(const T& elem)
{
	if (this->IsFull())
		return false;	//如果栈满
	else
	{
		//栈不满
		this->m_top++;
		*this->m_top = elem;
	}
	return true;
}


/*
* 功能: 检查是否栈为空
* 参数: 无
* 返回值: 栈为空返回true, 栈不空为false
*/
template <typename T, int MaxSize>
int CStack<T, MaxSize>::IsEmpty()
{
	return (m_top == m_stack);
}


/*
* 功能: 检查是否栈为满
* 参数: 无
* 返回值: 栈为满返回true, 栈不满为false
*/
template <typename T, int MaxSize>
int CStack<T, MaxSize>::IsFull()
{
	return (this->GetCurSize() == this->MAX_SIZE);
}


/*
* 功能: 返回栈当前元素数量
* 参数: 无
* 返回值: 返回栈当前元素数量
*/
template <typename T, int MaxSize>
int CStack<T, MaxSize>::GetCurSize()
{
	int a = (this->m_top - this->m_stack);
	return (this->m_top - this->m_stack);
}


/*
* 功能: 返回栈总大小
* 参数: 无
* 返回值: 返回栈总大小
*/
template <typename T, int MaxSize>
int CStack<T, MaxSize>::GetMaxSize()
{
	return this->MAX_SIZE;
}


/*
* 功能: 清除栈中所有元素
* 参数: 无
* 返回值: 成功返回true, 否则false
*/
template <typename T, int MaxSize>
int CStack<T, MaxSize>::Clear()
{
	this->m_top = this->m_stack;
	
	return true;
}










#endif /*_STACK_H_*/