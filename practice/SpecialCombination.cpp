#include <iostream>

using namespace std;

int main()
{
	for (int i = 2; i < 1000; i++)
	{
		int tmp = i;
		int g, s, b;
		g = i % 10;
		tmp = tmp / 10;
		s = tmp % 10;
		b = tmp / 10;

		if (b == 0 && (s == 0 || s == 2 || s == 4 || s == 6 || s == 8) && (g == 2 || g == 4 || g == 6 || g == 8))
			cout << i << endl;
		else if ((b == 2 || b == 4 || b == 6 || b == 8) &&
			( s == 2 || s == 4 || s == 6 || s == 8) && (g == 2 || g == 4 || g == 6 || g == 8))
			cout << i << endl;
	}
	return 0;

}
