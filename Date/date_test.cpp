#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	Date a(1999, 2, 11);
	a.PrintDate();
	Date b(a);
	b.PrintDate();

	a += 10;
	a.PrintDate();
	cout << a << endl;
	a -= 10;
	cout << a << endl;

	return 0;
}