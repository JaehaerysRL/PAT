// 1080_MOOC期终成绩.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef struct _pat
{
	string name;
	int p;
	int m;
	int n;
	int G;
	bool pass = false;
}PAT;

bool cmp(PAT a, PAT b) 
{
	if (a.pass > b.pass) return true;
	else if (a.pass < b.pass) return false;
	else if (a.G > b.G) return true;
	else if (a.G < b.G) return false;
	else if (a.name < b.name) return true;
	else return false;
}

int main()
{
	int P, M, N, K;
	cin >> P >> M >> N;
	map<string, int[3]> gt;
	string ts;
	int tg;

	for (int i = 0; i < P; i++)
	{
		cin >> ts >> tg;
		gt[ts][0] = tg + 1;//多加1区分没做和0分
	}
	for (int i = 0; i < M; i++)
	{
		cin >> ts >> tg;
		gt[ts][1] = tg + 1;//多加1区分没做和0分
	}
	for (int i = 0; i < N; i++)
	{
		cin >> ts >> tg;
		gt[ts][2] = tg + 1;//多加1区分没做和0分
	}

	K = gt.size();
	int i = 0, ct = 0;
	PAT* Score = new PAT[K];
	for (auto x:gt)
	{
		Score[i].name = x.first;
		Score[i].p = x.second[0];
		Score[i].m = x.second[1];
		Score[i].n = x.second[2];
		if (Score[i].m > Score[i].n)
		{
			tg = ((Score[i].m - 1) * 4 + (Score[i].n - 1) * 6) / 10;
			if ((Score[i].m - 1) * 4 + (Score[i].n - 1) * 6 - 10 * tg >= 5) tg++;
			Score[i].G = tg + 1;
		}
		else Score[i].G = Score[i].n;
		if (Score[i].G >= 61 && Score[i].p >= 201) 
		{
			Score[i].pass = true;
			ct++;
		}
		i++;
	}

	sort(Score, Score + K, cmp);
	for (int i = 0; i < ct; i++)
	{
		cout << Score[i].name << " " << Score[i].p - 1 << " " << Score[i].m - 1 << " " << Score[i].n - 1 << " " << Score[i].G - 1 << endl;
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
