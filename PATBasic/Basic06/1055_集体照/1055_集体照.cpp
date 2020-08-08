// 1055_集体照.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct _que 
{
	string Name;
	int Height;
}que;

bool cmp(que a, que b) 
{
	if (a.Height == b.Height) return a.Name < b.Name;
	else return a.Height > b.Height;
}

int main()
{
	int N, K, r, c, m, p;
	cin >> N >> K;
	c = N / K;
	r = N - K * c;
	que* person = new que[N];

	for (int i = 0; i < N; i++)
		cin >> person[i].Name >> person[i].Height;
	sort(person, person + N, cmp);

	c += r;
	m = c / 2;
	p = 0;
	que* per0 = new que[c]{};
	per0[m] = person[p++];
	for (int i = 1; i <= m; i++)
	{
		if (m - i >= 0) per0[m - i] = person[p++];
		if (m + i < c) per0[m + i] = person[p++];
	}
	cout << per0[0].Name;
	for (int i = 1; i < c; i++)
		cout << " " << per0[i].Name;
	cout << endl;
	delete[] per0;

	c -= r;
	m = c / 2;
	que* per = new que[c]{};
	for (int j = 1; j < K; j++)
	{
		per[m] = person[p++];
		for (int i = 1; i <= m; i++)
		{
			if (m - i >= 0) per[m - i] = person[p++];
			if (m + i < c) per[m + i] = person[p++];			
		}
		cout << per[0].Name;
		for (int i = 1; i < c; i++)
			cout << " " << per[i].Name;
		cout << endl;
	}
	delete[] per;
	delete[] person;
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
