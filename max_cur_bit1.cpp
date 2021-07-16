#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >> n)
    {
        int count = 0;
        int maxcount = 0;
        while(n)
        {
            if(n & 1)
            {
                count++;
                maxcount = max(count, maxcount);
            }
            else
                count = 0;
            n >>= 1;
        }
        cout << maxcount << endl;
    }
    return 0;
}
