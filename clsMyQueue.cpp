#pragma once
#include<iostream>
#include"clsDblLinkedList.h"
using namespace std;

template <class T>
class clsMyQueue
{
protected:
	clsDblLinkedList <T> _MyList;
public:

	void push(T Val)
	{
		_MyList.InsertAtEnd(Val);
	}

	void pop()
	{
		_MyList.DeleteFirstNode();
	}

	void Print()
	{
		_MyList.PrintList();
	}

	int Size()
	{
		return _MyList.Size();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(int Index, T Val)
	{
		_MyList.UpdateItem(Index, Val);
	}

	void InsertAfter(int Index, T Val)
	{
		_MyList.InsertAfter(Index, Val);
	}

	void InsertAtFront(T Val)
	{
		_MyList.InsertAtBeginning(Val);
	}

	void InsertAtBack(T Val)
	{
		_MyList.InsertAtEnd(Val);
	}

	void Clear()
	{
		_MyList.Clear();
	}
};

