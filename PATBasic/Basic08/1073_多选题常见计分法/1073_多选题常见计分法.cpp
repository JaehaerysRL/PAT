// 1073_多选题常见计分法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int N, M, L;
	int ans[101][14]{};
	char c;
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> ans[i][0] >> ans[i][1] >> ans[i][2];
		L = ans[i][2];
		for (int j = 0; j < L; j++)
		{
			cin >> c;
			ans[i][c - 'a' + 3] = 1;
		}
	}
	for (int k = 0; k < N; k++)
	{
		int cnt = 1, sig;
		double score = 0;
		while (cnt <= M)
		{
			cin.get();
			cin.get();
			cin >> L;
			sig = 1;//满分
			int tans[5]{};//记录选项
			for (int j = 0; j < L; j++)
			{
				cin >> c;
				tans[c - 'a']++;				
			}
			cin.get();
			for (int i = 0; i < 5; i++)
			{
				if (tans[i] > ans[cnt][3 + i])//错选 
				{
					ans[cnt][9 + i]++;
					sig = -1;					
				}
				else if(tans[i] < ans[cnt][3 + i])//漏选
				{
					ans[cnt][9 + i]++;
					if (sig != -1) sig = 0;
				}
			}
			if (sig == 1) score += ans[cnt][0];
			else if (sig == 0) score += (double)ans[cnt][0] / 2;
			cnt++;
		}
		printf("%0.1lf\n", score);
	}

	queue<int> ind;
	int tmax = 0;
	for (int i = 1; i <= M; i++)
	{
		ans[i][8] = max({ ans[i][9],ans[i][10],ans[i][11],ans[i][12],ans[i][13] });
		if (ans[i][8] > tmax)
		{
			tmax = ans[i][8];
			while (!ind.empty())
				ind.pop();
			ind.push(i);
		}
		else if (tmax && ans[i][8] == tmax) ind.push(i);
	}

	if (tmax)
	{
		while (!ind.empty())
		{
			for (int i = 0; i < 5; i++)
			{
				if (ans[ind.front()][9 + i] == tmax)
				{
					cout << tmax << " " << ind.front() << "-" << char(i + 'a') << endl;
				}
			}
			ind.pop();
		}
	}
	else cout << "Too simple" << endl;
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
