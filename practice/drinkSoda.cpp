#include <iostream>

using namespace std;

int drinkSoda(int n)
{
	int Soda = 0;
	int bottle = n;

	Soda = bottle / 3;
	bottle = n % 3 + Soda;

	while (bottle >= 3)
	{
		Soda += bottle / 3;
		bottle = (bottle / 3) + (bottle % 3);
	}
	if (bottle == 2)
		Soda += 1;
	return Soda;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int Soda = drinkSoda(n);
		cout << Soda << endl;
	}

	return 0;
}
