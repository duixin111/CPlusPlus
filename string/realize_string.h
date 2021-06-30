#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <iostream>
#include <algorithm>
using namespace std;

class String
{
public:
	typedef char* iterator;
public:
	String(const char* str = "")
	{
		if (str == nullptr)
			str = "";
		_capacity = strlen(str);
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		_size = _capacity;
	}
	String(size_t n, char ch)
		:_str(new char[n+1])
		,_capacity(n)
		,_size(n)
	{
		memset(_str, ch, n);
		_str[_size] = '\0';
	}

	~String()
	{
		if (_str)
			delete[]_str;
	}
	// 深拷贝
	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		_size = strlen(s._str);
		_capacity = s._capacity;
		strcpy(_str, s._str);
	}

#if 0
	// 一种拷贝构造
	string& operator=(const string& s)
	{
		if (this != &s)
		{
			char* tmp = new char[strlen(s._str) + 1];
			strcpy(tmp, s._str);
			delete[]_str;
			_str = tmp;
		}
		return *this;
	}
#endif
#if 1
	String& operator=(String s)
	{
		std::swap(_str, s._str);
		return *this;
	}
#endif
	// 迭代器
public:
	iterator begin()
	{
		return _str;
	}
	iterator end()
	{
		return _str + _size;
	}
	size_t size()const
	{
		return _size;
	}
	size_t capacity()const
	{
		return _capacity;
	}
	bool empty()const
	{
		return 0 == _size;
	}
	void reserve(size_t newcapacity)
	{
		size_t oldcap = capacity();
		if (newcapacity > oldcap)
		{
			char* str = new char[newcapacity + 1];
			strcpy(str, _str);
			delete(_str);
			_str = str;
			_capacity = newcapacity;
		}
	}
	void resize(size_t newsize, char ch)
	{
		size_t oldsize = size();
		if (newsize <= oldsize)
			_size = newsize;
		else
		{
			size_t cap = capacity();
			if (newsize > cap)
				reserve(newsize * 2);
			memset(_str + _size, ch, newsize - oldsize);
		}
		_str[_size] = '\0';
		_size = newsize;
	}

	char& operator[](size_t index)
	{
		assert(index >= 0 && index < _size);
		return _str[index];
	}
	String& operator+=(char ch)
	{
		if (_size == _capacity)
			reserve(2 * _capacity);
		_str[_size++] = ch;
		_str[_size] = '\0';
		return *this;
	}
	String& operator+=(const String& s)
	{
		size_t newsize = _size + s.size();
		if (_size + s.size() > _capacity)
			reserve(newsize * 2);
		strcat(_str + _size, s._str);
		_size = newsize;
		_str[_size] = '\0';
		return *this;
	}
	void swap(String& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}
	void push_back(char ch)
	{
		*this += ch;
	}
	void clear()
	{
		_size = 0;
		_str[_size] = '\0';
	}
	void append(char ch)
	{
		push_back(ch);
	}
	void append(String s)
	{
		*this += s;
	}
	const char* c_str()const
	{
		return _str;
	}
	size_t find(char ch, size_t pos = 0)
	{
		if (pos >= _size)
			return npos;
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
				return i;
		}
		return npos;
	}
	size_t rfind(char ch, size_t pos = npos)
	{
		if (pos >= _size)
			return npos;
		for (size_t i = pos; i >= 0; i--)
		{
			if (_str[i] == ch)
				return i;
		}
		return npos;
	}
	String substr(size_t pos, size_t n = npos)
	{
		assert(pos < _size);
		size_t len = strlen(_str + pos);
		n = min(len, n);

		String tmp;
		tmp.resize(n + 1, 0);
		strncpy(tmp._str, _str + pos, n);
		return tmp;
	}
	friend ostream& operator<<(ostream& _cout, const String& s)
	{
		_cout << s._str;
		return _cout;
	}
private:
	char* _str;
	size_t _capacity;
	size_t _size;
public:
	static size_t npos;
};

size_t String::npos = -1;
