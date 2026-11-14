
#pragma once
#include<iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
protected:
	int _Size = 0;
	T* _TempArray;

public:
	T* OriginalArray;

	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)Size = 0;
		_Size = Size;

		OriginalArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}

	bool SetItem(int index, T Val)
	{
		if (index >= _Size || index < 0)
		{
			return 0;
		}
		OriginalArray[index] = Val;
		return 1;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0 ? true : false);
	}

	void PrintList()
	{
		for (int i = 0; i <= _Size - 1; i++)
		{
			cout << OriginalArray[i] << " ";
		}
		cout << "\n";
	}

	void Resize(int NewSize)
	{
		if (NewSize < 0)
			NewSize = 0;

		_TempArray = new T[NewSize];

		if (NewSize < _Size)
			_Size = NewSize;

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		_Size = NewSize;

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	T GetItem(int Index)
	{
		return OriginalArray[Index];
	}

	void Reverse()
	{
		_TempArray = new T[_Size];
		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[_Size - 1 - i];
		}
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = new T[_Size];
	}

	bool DeleteItemAt(int Index)
	{
		if (Index >= _Size || Index < 0 || _Size == 0)
			return 0;
		_Size--;
		_TempArray = new T[_Size];

		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		for (int i = Index + 1; i < _Size + 1; i++)
		{
			_TempArray[i - 1] = OriginalArray[i];
		}
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	bool DeleteFirstItem()
	{
		if (DeleteItemAt(0))
			return 1;
		else
			return 0;
	}

	bool DeleteLastItem()
	{
		if (DeleteItemAt(_Size - 1))
			return 1;
		else
			return 0;
	}

	int Find(int Val)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == Val)
				return i;
		}
		return -1;
	}

	bool DeleteItem(int Val)
	{
		int Index = Find(Val);

		if (Index == -1)
			return 0;

		if (DeleteItemAt(Index))
			return 1;
		else
			return 0;
	}

	bool InsertAt(int Index, T Val)
	{
		if (Index > _Size || Index < 0)
		{
			return 0;
		}
		_Size++;
		_TempArray = new T[_Size];
		_TempArray[Index] = Val;
		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		for (int i = Index + 1; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i - 1];
		}
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return 1;
	}

	bool InsertAtBeginning(T Val)
	{
		return(InsertAt(0, Val) ? 1 : 0);
	}

	bool InsertBefore(int Index, T Val)
	{
		return(InsertAt(Index, Val) ? 1 : 0);
	}

	bool InsertAfter(int Index, T Val)
	{
		return(InsertAt(Index + 1, Val) ? 1 : 0);
	}

	bool InsertAtEnd(T Val)
	{
		return (InsertAt(_Size, Val) ? 1 : 0);
	}
};

