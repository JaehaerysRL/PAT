// 1025_反转链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
	const int MAXN = 100000;
	int Data[MAXN];
	int Next[MAXN];
	int Node[MAXN];
	int startA, N, K;
	cin >> startA >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int tA;
		cin >> tA >> Data[tA] >> Next[tA];
	}
	int cnt = 0;
	//筛选节点
	while (startA != -1)
	{
		Node[cnt++] = startA;
		startA = Next[startA];
	}
	//逆转
	for (int i = 0; i < cnt - cnt % K; i += K) {  // 每 K 个结点一个区间 
		for (int j = 0; j < K / 2; j++) {  // 反转链表
			int t = Node[i + j];
			Node[i + j] = Node[i + K - j - 1];
			Node[i + K - j - 1] = t;
		}
	}
	for (int i = 0; i < cnt - 1; i++)
		printf("%05d %d %05d\n", Node[i], Data[Node[i]], Node[i + 1]);
	printf("%05d %d -1\n", Node[cnt - 1], Data[Node[cnt - 1]]);
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
