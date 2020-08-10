// 1090_危险品装箱.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int N, M, tg1, tg2, K, sig, len;
	cin >> N >> M;
	map<int, vector<int>> mp;

	for (int i = 0; i < N; i++)
	{
		cin >> tg1 >> tg2;
		mp[tg1].emplace_back(tg2);
		mp[tg2].emplace_back(tg1);
	}

	for (int k = 0; k < M; k++)
	{
		sig = 1;
		cin >> K;
		vector<int> g;
		for (int i = 0; i < K; i++)
		{
			cin >> tg1;
			g.emplace_back(tg1);
		}
		for (int i = 0; i < K - 1; i++)
		{
			len = mp[g[i]].size();
			for (int j = i + 1; j < K; j++)
			{
				for (int l = 0; l < len; l++)
				{
					if (mp[g[i]][l] == g[j]) 
					{
						sig = 0;
						goto END;
					}
				}
			}
		}
		END:
		if (sig) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
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
