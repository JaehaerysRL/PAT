// 1045_快速排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int N, c = 0, max = 0, t;
	cin >> N;
	int* num = new int[N] {};
	int* snum = new int[N] {};
	int* mnum = new int[N] {};
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &t);
		snum[i] = num[i] = t;
		if (num[i] > max) 
			max = t;
		mnum[i] = max;
	}

	sort(snum, snum + N);

	for (int i = 0; i < N; i++)
	{
		t = num[i];
		if (t == snum[i] && mnum[i] <= t) 
		{
			q.push(t);
			c++;
		}
	}
	cout << c << endl;
	int sig = 0;
	while (!q.empty())
	{
		if (sig) cout << " ";
		else sig = 1;
		cout << q.top();
		q.pop();
	}
	cout << endl;

	delete[] num;
	delete[] snum;
	delete[] mnum;
	return 0;
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
