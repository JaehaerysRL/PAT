// 1064_朋友数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct _fri 
{
	int Num;
	int Card;
}fri;

bool cmp(fri a, fri b) 
{
	return a.Card < b.Card;
}

int main()
{
	int N, t, s;
	cin >> N;
	fri* num = new fri[N];
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &t);
		num[i].Num = t;
		s = 0;
		while (t)
		{
			s += t % 10;
			t /= 10;
		}
		num[i].Card = s;
	}
	sort(num, num + N, cmp);

	int i = 0, sig = 1;
	queue<int> q;
	for (i; i < N; i++)
	{
		if (sig) 
		{
			q.push(num[i].Card);
			sig = 0;
		} 
		if (num[i].Card != num[i + 1].Card) sig = 1;
	}

	cout << q.size() << endl;
	cout << q.front();
	q.pop();
	while (!q.empty())
	{
		cout << " " << q.front();
		q.pop();
	}

	delete[] num;
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
