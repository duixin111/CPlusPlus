#include <iostream>
#include "realizeString.h"

using namespace std;


int main()
{
	String s1("hello");
	String s2(s1);
	String s3(10, '$');

	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	s1[0] = 'H';
	cout << s1[0] << endl;

	s1 += ' ';
	s1 += "world";

	size_t pos = s1.find(' ');
	if (pos != String::npos)
	{
		cout << s1[pos] << endl;
	}
	else
	{
		cout << "不存在" << endl;
	}

	pos = s1.find('h');
	if (pos != String::npos)
	{
		cout << s1[pos] << endl;
	}
	else
	{
		cout << "不存在" << endl;
	}

	String s4 = s1.substr(0, 5);
	cout << s4 << endl;

	return 0;
}
