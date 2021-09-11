#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GreComDiv(int yi,int monster)
{
    int z = monster;
	while(yi % monster != 0)
	{
		z = yi % monster;
		yi = monster;
		monster = z;	
	}
	return z;
}

int up(int yi, int monster)
{
    if(monster <= yi)
        return monster;
    return GreComDiv(yi, monster);
}

int main()
{
    int number;
    int init;
    while(cin >> number >> init)
    {
        vector<int> Def(number);
        for(int i = 0; i < number; i++)
        {
            cin >> Def[i];
        }
        for(auto e : Def)
        {
            init += up(init, e);
        }
        cout << init << endl;
    }

    return 0;
}
