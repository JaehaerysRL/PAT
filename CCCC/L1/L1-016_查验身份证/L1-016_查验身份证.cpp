// L1-016_查验身份证.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int N, Z, R = 0;
	char M;
	cin >> N;
	string id;
	int weight[17]{ 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	map<int, char> mp;
	for (int i = 0; i < 2; i++)
		mp.insert({ i,char(1 - i + '0') });
	mp.insert({ 2,'X' });
	for (int i = 3; i < 11; i++)
		mp.insert({ i,char(12 - i + '0') });

	for (int i = 0; i < N; i++)
	{
		cin >> id;
		Z = 0;
		for (int j = 0; j < 17; j++)
			Z += (id[j] - '0') * weight[j];
		Z %= 11;
		M = mp[Z];
		if (M != id[17])
		{
			cout << id << endl;
			R++;
		}
	}
	if (!R) cout << "All passed" << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
