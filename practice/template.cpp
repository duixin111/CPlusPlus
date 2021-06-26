#include <assert.h>
#include <iostream>

using namespace std;

//template<typename S,typename T>
//
//S add(S left, T right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int m = add(1, 2);
//
//	return 0;
//}
//template<class T>
//int Find(T array[], size_t size, const T& data)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		if (array[i] == data)
//			return i;
//	}
//
//	return -1;
//}
//
//int main()
//{
//	//int array[] = { 1,3,2,5,4,6,9,8 };
//	char array[] = "mjihbsf";
//	int size = sizeof(array) / sizeof(array[0]);
//	int index = Find(array, size, 'l');
//
//	return index;
//}


template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)
		: _array(new T[capacity + 3])
		, _capacity(capacity + 3)
		, _size(0)
	{}

	// [fist, last)区间中包含的元素要放置到顺序表中
	SeqList(T* first, T* last)
	{
		T* it = first;
		size_t count = 0;
		while (it != last)
		{
			++it;
			++count;
		}

		_size = count;
		_capacity = count;
		_array = new T[_capacity];
		for (size_t i = 0; i < _size; ++i)
		{
			_array[i] = *first;
			++first;
		}
	}

	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	void PushBack(const T& data)
	{
		_CheckCapacity();
		_array[_size++] = data;
	}

	void PopBack()
	{
		if (Empty())
			return;

		_size--;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	size_t Size()const
	{
		return _size;
	}

	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	const T& operator[](size_t index)const
	{
		assert(index < _size);
		return _array[index];
	}


private:
	void _CheckCapacity();

private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

template<class T>
void SeqList<T>::_CheckCapacity()
{}


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	SeqList<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	cout << s1[0] << endl;
	cout << typeid(s1).name() << endl;

	int array[] = { 1, 2, 3, 4, 5 };
	const SeqList<int> s3(array, array+sizeof(array)/sizeof(array[0]));
	cout << s3.Size() << endl;
	cout << s3[0] << endl;
	
	SeqList<double> s2;
	s2.PushBack(1.0);
	s2.PushBack(2.0);
	s2.PushBack(3.0);
	s2.PushBack(4.0);
	cout << s2.Size() << endl;
	cout << s2.Capacity() << endl;
	s2.PopBack();
	cout << s2.Size() << endl;
	cout << typeid(s2).name() << endl;


	SeqList<Date> s4;

	Date d1(2021, 6, 16);
	Date d2(2021, 6, 17);
	Date d3(2021, 6, 18);
	s4.PushBack(d1);
	s4.PushBack(d2);
	s4.PushBack(d3);
	return 0;
}
