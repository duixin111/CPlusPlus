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
	// ȫȱʡ�Ĺ��캯��
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


	//�������캯��
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

	//��������
Date::~Date()
{ 

}

	//��ֵ���������
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
}



	// ����+=����
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

	// ����+����
Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;

	return tmp;
}

	// ����-����
Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;

	return tmp;
}

	// ����-=����
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

	// ǰ��++
Date& Date::operator++()
{


}

	// ����++
Date Date::operator++(int)
{

}

	// ǰ��--
Date& Date::operator--()
{

}

	// ����--
Date Date::operator--(int)
{

}

	// >���������
bool Date::operator>(const Date& d)
{

}
	// ==���������
bool Date::operator==(const Date& d)
{

}
	// >=���������
inline bool Date::operator >= (const Date& d)
{

}
	// <���������
bool Date::operator < (const Date& d)
{

}
	// <=���������
bool Date::operator <= (const Date& d)
{

}
	// !=���������
bool Date::operator != (const Date& d)
{

}
	// ����-���� ��������
int Date::operator-(const Date& d)
{

}
	//��ӡ
void Date::PrintDate()
{
	cout << _year << "." << _month << "." << _day << endl;
}

int Date::days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
