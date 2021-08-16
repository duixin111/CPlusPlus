#include <stdio.h> 
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string num;
	int init = 0;
	int MAX = 0;
	string arr;
	while (getline(cin, num))
	{
		int n = atoi(num.c_str());

		for (int i = 0; i < n; i++)
		{
			getline(cin, arr);
			if (arr[2] == 'c')
			{
				++init;
				if (init > MAX)
					MAX = init;
			}
			if (arr[2] == 'd')
				--init;
		}
		cout << MAX << endl;
		init = 0;
		MAX = 0;
		arr.clear();

	}

	return 0;
}
