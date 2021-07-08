#include<iostream>
#include<string>
using namespace std;
int main ()
{
    string s;
    cin>>s;
    string::iterator it=s.begin();
    string ret;
    while (it != s.end())
    {
        while(it!=s.end()&&!(*it-'0'>=0&&*it-'0'<=9))
        {
            ++it;
        }
        string tmp;
        while(it!=s.end()&&*it-'0'>=0&&*it-'0'<=9)
        {
            tmp+=*it;
            ++it;
        }
        if (tmp.size()>ret.size())
        {
            ret=tmp;
        }
    }
    cout<<ret<<endl;
    return 0;
}
