// 1089_狼人杀简单版.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int N, tw;
	cin >> N;
	vector<int> v(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			vector<int> lie;
			vector<int> good(N + 1, 1);
			good[i] = good[j] = -1;
			for (int k = 1; k <= N; k++)
				if (v[k] * good[abs(v[k])] < 0) //说谎
					lie.emplace_back(k);
			if (lie.size() == 2 && good[lie[0]] + good[lie[1]] == 0)//正好一个狼人说谎 
			{
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
	cout << "No Solution" << endl;
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
