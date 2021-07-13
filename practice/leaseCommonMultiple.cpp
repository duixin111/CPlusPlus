#include <iostream>

using namespace std;

int main()
{
    int m,n;
    while(cin >> m >> n)
    {
        if(m < n)
        {
            int tmp = m;
            m = n;
            n = tmp;
        }
        int num = m;
        while(1)
        {
            if(num % m == 0 && num % n == 0)
            {
                cout << num << endl;
                break;
            }
            num++;
            
        }
    }
    return 0;
}
