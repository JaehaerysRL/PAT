// 1068_万绿丛中一点红.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;

int num[1002][1002]{};
int nei[8][2]{ -1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1 };
int M, N, T;
map<int, int> m;

bool judge(int tx, int ty) 
{
	int x, y, value, vmin, vmax;
	vmin = num[ty][tx] - T;
	vmax = num[ty][tx] + T;
	for (int i = 0; i < 8; i++)
	{
		x = tx + nei[i][0];
		y = ty + nei[i][1];
		if (x > 0 && x <= M && y > 0 && y <= N) 
		{
			value = num[y][x];
			if (value >= vmin && value <= vmax) return false;
		}
	}
	return true;
}

int main()
{
	int k, c = 0, x = 0, y = 0, value = 0;
	cin >> M >> N >> T;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &k);
			num[i][j] = k;
			m[k]++;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (m[num[i][j]] == 1 && judge(j, i)) 
			{
				c++;
				x = j;
				y = i;
				value = num[i][j];
			}
		}
	}
	if (c == 0) cout << "Not Exist" << endl;
	else if (c == 1) cout << "(" << x << ", " << y << "): " << value << endl;
	else cout << "Not Unique" << endl;
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
