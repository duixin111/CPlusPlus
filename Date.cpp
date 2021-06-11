#include <iostream>
#include "Date.h"
using namespace std;


int Date::GetMonthDay(int year, int month)
{
	if (month == 1 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		return 29;
	else if (month == 1)
		return 28;
	else
		return days[month - 1];
}
	// 全缺省的构造函数
Date::Date(int year, int month, int day)
	: _year(year)
	, _month(month)
	, _day(day)
{
	if (month > 12 || month < 1 || day<1 || day>GetMonthDay(year, month))
		cout << "error!" << endl;

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
	Date tmp(*this);
	tmp += day;

	return tmp;
}

	// 日期-天数
Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;

	return tmp;
}

	// 日期-=天数
Date& Date::operator-=(int day)
{
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


}

	// 后置++
Date Date::operator++(int)
{

}

	// 前置--
Date& Date::operator--()
{

}

	// 后置--
Date Date::operator--(int)
{

}

	// >运算符重载
bool Date::operator>(const Date& d)
{

}
	// ==运算符重载
bool Date::operator==(const Date& d)
{

}
	// >=运算符重载
inline bool Date::operator >= (const Date& d)
{

}
	// <运算符重载
bool Date::operator < (const Date& d)
{

}
	// <=运算符重载
bool Date::operator <= (const Date& d)
{

}
	// !=运算符重载
bool Date::operator != (const Date& d)
{

}
	// 日期-日期 返回天数
int Date::operator-(const Date& d)
{

}
	//打印
void Date::PrintDate()
{
	cout << _year << "." << _month << "." << _day << endl;
}

int Date::days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
