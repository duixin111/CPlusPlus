#include <iostream>
#include <vector>

using namespace std;


// 初始化
void TestVector1()
{
	vector<int> v1;
	vector<int> v2(10, 5);
	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
	vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));

	vector<int> v4(v3);

	// c++11
	vector<int> v5{ 1,2,3,4,5,6,7,8,9,0 };

	cout << v2.capacity() << endl;
	cout << v2.size() << endl;

	for (size_t i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;
	auto it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	auto rit = v3.rbegin();
	while (rit != v3.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
	for (auto e : v4)
		cout << e << " ";
	cout << endl;
}

// 测试扩容机制
void TestVector2()
{
	vector<int> v;
	size_t oldcapacity = v.capacity();
	for (size_t i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (oldcapacity != v.capacity())
		{
			oldcapacity = v.capacity();
			cout << oldcapacity << endl;
		}
	}
}


// 插入删除    左闭右开   迭代器失效
void TestVector3()
{
	vector<int> v{ 1,2,3,4,5 };
	v.insert(v.begin() + 2, 6);
	v.insert(v.begin(), 3, 0);

	vector<int> v1{ 7,8,9 };
	v.insert(v.end(), v1.begin(), v1.end());
	v.erase(v.begin());
	v.erase(v.begin(), v.begin() + 2);

	// 错误示范
	//auto it = v.begin();
	//while (it != v.end())
	//{
	//	v.erase(it);
	//	it++;
	//}
	v.clear();
}
int main()
{
	// TestVector1();
	// TestVector2();
	// TestVector3();
	TestVector4();
	return 0;
}
