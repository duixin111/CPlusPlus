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

	// ȫȱʡ�Ĺ��캯��
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
	return *this;
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

	// ����-����
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

	// ����-=����
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

	// ǰ��++
Date& Date::operator++()
{
	*this = *this + 1;
	return *this;
}

	// ����++
Date Date::operator++(int)
{
	Date tmp(*this);
	*this - *this + 1;
	return tmp;
}

	// ǰ��--
Date& Date::operator--()
{
	*this = *this - 1;
	return *this;
}

	// ����--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this = *this - 1;
	return tmp;
}

	// >���������
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

	// ==���������
bool Date::operator==(const Date& d)
{
	return (_year == d._year) && (_month == d._month) && (_day == d._day);
}

	// >=���������
inline bool Date::operator >= (const Date& d)
{
	return *this > d || *this == d;
}

	// <���������
bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}

	// <=���������
bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}

	// !=���������
bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

	// ����-���� ��������
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

	//��ӡ
void Date::PrintDate()
{
	cout << _year << "." << _month << "." << _day << endl;
}