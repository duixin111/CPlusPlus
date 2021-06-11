#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	Date a(1999, 2, 11);
	a.PrintDate();
	Date b(a);
	b.PrintDate();

	return 0;
}