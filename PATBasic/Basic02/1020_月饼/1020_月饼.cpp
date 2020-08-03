// 1020_月饼.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct _moon {
	double price;
	double weight;
	double single;
}moon;

bool cmp(moon a, moon b) 
{
	return a.single > b.single;
}
 
int main()
{
	int N, i;
	double D, final = 0;
	cin >> N >> D;
	moon* M = (moon*)malloc(N * sizeof(moon));
	for (i = 0; i < N; i++)
		cin >> M[i].weight;
	for (i = 0; i < N; i++)
	{
		cin >> M[i].price;
		M[i].single = M[i].price / M[i].weight;
	}
	sort(M, M + N, cmp);
	i = 0;
	while (D > 0)
	{
		if (D >= M[i].weight) 
		{
			D -= M[i].weight;
			final += M[i].price;
		}
		else
		{
			final += D * M[i].single;
			break;
		}
		i++;
		if (i >= N) break;
	}
	printf("%.2lf\n", final);
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
