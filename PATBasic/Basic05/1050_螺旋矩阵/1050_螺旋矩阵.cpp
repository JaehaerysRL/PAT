// 1050_螺旋矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(int a, int b) 
{
	return a > b;
}

int main()
{
	int N;
	cin >> N;
	int* num = new int[N];
	for (int i = 0; i < N; i++)
		scanf_s("%d", &num[i]);
	sort(num, num + N, cmp);

	int m, n;
	m = sqrt(N);
	while (N % m != 0) 
		m++;
	n = N / m;
	if (n > m) 
	{
		m = n;
		n = N / m;
	}

	int** rec = new int* [m];
	for (int i = 0; i < m; i++)
		rec[i] = new int[n] {};
	int sig = 1, i = 0, j = 0, t = 0;
	while (t < N)
	{
		rec[i][j] = num[t++];
		if (sig == 1)
		{
			if (j + 1 < n && !rec[i][j + 1])
				j++;
			else
			{
				sig = 2;
				i++;
			}
		}
		else if (sig == 2)
		{
			if (i + 1 < m && !rec[i + 1][j])
				i++;
			else
			{
				sig = 3;
				j--;
			}
		}
		else if (sig == 3)
		{
			if (j - 1 >= 0 && !rec[i][j - 1])
				j--;
			else
			{
				sig = 4;
				i--;
			}
		}
		else
		{
			if (i - 1 >= 0 && !rec[i - 1][j])
				i--;
			else
			{
				sig = 1;
				j++;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		printf("%d", rec[i][0]);
		for (int j = 1; j < n; j++)
			printf(" %d", rec[i][j]);
		printf("\n");
	}

	delete[] num;
	for (int i = 0; i < m; i++)
		delete[] rec[i];
	delete[] rec;
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
