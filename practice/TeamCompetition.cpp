#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int max(int a, int b, int c)
{
    int sun = a+b+c;
    int maxvalue = a>b?a:b;
    maxvalue = maxvalue>c?maxvalue:c;
    int minvalue = a< b?a:b;
    minvalue = minvalue<c?minvalue:c;
    
    return sun - maxvalue - minvalue;
}

int main()
{
	int team;
	while (scanf("%d", &team) != EOF)
	{
		int player = team * 3;
		int level = 0;
		int* arr1 = new int[player];
		for (int i = 0; i < player; i++)
			scanf("%d", &arr1[i]);
		for (int i = 0; i < player; i+=3)
		{
			int tmp1 = arr1[i];
			int tmp2 = arr1[i + 1];
			int tmp3 = arr1[i + 2];
			int maxLevel = max(tmp1, tmp2, tmp3);
			level += maxLevel;
		}
		cout << level << endl;
	}
    
    return 0;
}
