#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
        int count = 0;
        bool flag = false;
        for(size_t i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                flag = true;
                break;
            }
            count++;
        }
        if(flag == false)
        {
            cout << count << endl;
            continue;
        }
        count = 0;
        for(size_t i = s.size() - 1 ; i >= 0; i--)
        {
            if(s[i] != ' ')
                count++;
            else
                break;
        }
        cout << count << endl;
    }
    
    return 0;
}
