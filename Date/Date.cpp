#include <iostream>
#include "Date.h"

using namespace std;

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

int Date::GetMonthDay(int year, int month)
{
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		return 29;
	else if (month == 1)
		return 28;
	else
		return days[month];
}

	// 全缺省的构造函数
Date::Date(int year, int month, int day)
	: _year(year)
	, _month(month)
	, _day(day)
{
	if (!((month <= 12 && month > 1) && day > 0 && day <= GetMonthDay(year, month)))
	{
		cout << "error!" << endl;
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	_year = year;
	_month = month;
	_day = day;
}

	//拷贝构造函数
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

	//析构函数
Date::~Date()
{ 

}

	//赋值运算符重载
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

	// 日期+=天数
Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > Date::GetMonthDay(_year, _month))
	{
		_day -= Date::GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

	// 日期+天数
Date Date::operator+(int day)
{
	if (day < 0)
		return *this - (0 - day);
	Date tmp(*this);
	tmp._day += day;

	int DayOfMonth = 0;
	while (tmp._day > (DayOfMonth = GetMonthDay(tmp._year, tmp._month)))
	{
		tmp._month++;
		tmp._day -= DayOfMonth;
		if(tmp._year > 12)
		{
			tmp._year++;
			tmp._month = 1;
		}
	}
	return tmp;
}

	// 日期-天数
Date Date::operator-(int day)
{
	if (day < 0)
		return *this + (0 - day);
	Date tmp(*this);
	tmp._day -= day;
	while (tmp._day <= 0)
	{
		tmp._month -= 1;
		if (tmp._month == 0)
		{
			tmp._month = 12;
			tmp._year -= 1;
		}
		tmp._day += tmp.GetMonthDay(tmp._year, tmp._month);
	}

	return tmp;
}

	// 日期-=天数
Date& Date::operator-=(int day)
{
	if (day < 0)
		return *this += -day;

	_day -= day;

	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

	// 前置++
Date& Date::operator++()
{
	*this = *this + 1;
	return *this;
}

	// 后置++
Date Date::operator++(int)
{
	Date tmp(*this);
	*this - *this + 1;
	return tmp;
}

	// 前置--
Date& Date::operator--()
{
	*this = *this - 1;
	return *this;
}

	// 后置--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this = *this - 1;
	return tmp;
}

	// >运算符重载
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	else if (_year == d._year)
	{
		if (_month > d._month)
			return true;
		else if (_month == d._month)
		{
			if (_day > d._day)
				return true;
		}
	}
	return false;
}

	// ==运算符重载
bool Date::operator==(const Date& d)
{
	return (_year == d._year) && (_month == d._month) && (_day == d._day);
}

	// >=运算符重载
inline bool Date::operator >= (const Date& d)
{
	return *this > d || *this == d;
}

	// <运算符重载
bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}

	// <=运算符重载
bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}

	// !=运算符重载
bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

	// 日期-日期 返回天数
int Date::operator-(const Date& d)
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int day = 0;
	while (min < max)
	{
		++min;
		++day;
	}
	return day * flag;
}

	//打印
void Date::PrintDate()
{
	cout << _year << "." << _month << "." << _day << endl;
}