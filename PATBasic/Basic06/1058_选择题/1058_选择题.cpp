// 1058_选择题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, M, L;
	int ans[101][9]{};
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

	for (int i = 0; i < N; i++)
	{
		int cnt = 1, score = 0, sig;
		while (cnt <= M)
		{
			cin.get();
			cin.get();
			cin >> L;
			sig = 1;
			if (L != ans[cnt][2]) sig = 0;
			for (int j = 0; j < L; j++)
			{
				cin >> c;
				if (sig && !ans[cnt][c - 'a' + 3]) sig = 0;
			}
			cin.get();
			if (sig) score += ans[cnt][0];
			else ans[cnt][8]++;
			cnt++;
		}
		cout << score << endl;
	}

	queue<int> ind;
	int max = 0;
	for (int i = 1; i <= M; i++)
	{
		if (ans[i][8] > max) 
		{
			max = ans[i][8];
			while (!ind.empty())
				ind.pop();
			ind.push(i);
		}
		else if(ans[i][8] == max) ind.push(i);
	}

	if (max) 
	{
		cout << ans[ind.front()][8];
		while (!ind.empty())
		{
			cout << " " << ind.front();
			ind.pop();
		}
	}
	else cout << "Too simple";
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
