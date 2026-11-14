#pragma once
#include<iostream>
#include"clsDynamicArray.h"
using namespace std;

template <class T>
class clsMyQueueArr
{
protected:
	clsDynamicArray <T> _MyArr;
public:

	void push(T Val)
	{
		_MyArr.InsertAtEnd(Val);
	}

	void pop()
	{
		_MyArr.DeleteFirstItem();
	}

	void Print()
	{
		_MyArr.PrintList();
	}

	int Size()
	{
		return _MyArr.Size();
	}

	bool IsEmpty()
	{
		return _MyArr.IsEmpty();
	}

	T front()
	{
		return _MyArr.GetItem(0);
	}

	T back()
	{
		return _MyArr.GetItem(Size() - 1);
	}

	T GetItem(int Index)
	{
		return _MyArr.GetItem(Index);
	}

	void Reverse()
	{
		_MyArr.Reverse();
	}

	void UpdateItem(int Index, T Val)
	{
		_MyArr.SetItem(Index, Val);
	}

	void InsertAfter(int Index, T Val)
	{
		_MyArr.InsertAfter(Index, Val);
	}

	void InsertAtFront(T Val)
	{
		_MyArr.InsertAtBeginning(Val);
	}

	void InsertAtBack(T Val)
	{
		_MyArr.InsertAtEnd(Val);
	}

	void Clear()
	{
		_MyArr.Clear();
	}
};

