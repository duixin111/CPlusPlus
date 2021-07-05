#include <iostream>
#include <string>

using namespace std;
void delete_str1(string& s1, const string& s2)
{
	int count[256] = { 0 };
	int i = 0;
	while (s2[i]!='\0')
	{
		count[s2[i]]++;//用s2中的字符作为下标的count数组对应元素加1
		i++;
	}
	i = 0;
	while (s1[i] != '\0')
	{
		if (count[s1[i]] != 0)//s1中字符在s2存在，则需要删除
		{
			s1.erase(i,1);//当然这里也可以用一个新的字符串接收要留下来的字符ret+=s1[i];(count[s1[i]] 0= 0)
		}
		else
		{
			i++;
		}
	}
}
int main()
{
	string s1;
	string s2;
	while (getline(cin, s1), getline(cin, s2))
	{
		delete_str1(s1, s2);
		cout << s1 << endl;
	}

	return 0;
}
