// 1075_链表元素分类.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

typedef struct node
{
	int Address;
	int Data;
	int Next;
	int Sig = 4;
	int Index = 0;
}Node;

bool cmp(Node a, Node b)
{
	if (a.Sig < b.Sig) return true;
	else if (a.Sig > b.Sig) return false;
	else {
		return a.Index < b.Index;
	}
}

bool cmpIndex(Node a, Node b)
{
	return a.Index < b.Index;
}

int main()
{
	int fst, N, K, a, d, n;
	map<int, int> m;
	cin >> fst >> N >> K;
	Node* L = new Node[N];

	for (int i = 0; i < N; i++)
	{
		cin >> a >> d >> n;
		L[i].Address = a; L[i].Data = d; L[i].Next = n;
		if (d < 0) L[i].Sig = 0;
		else if (d <= K) L[i].Sig = 1;
		else L[i].Sig = 2;
		m[a] = i;
	}

	int i = fst, c = 1, res = 0;
	while (i != -1)
	{
		L[m[i]].Index = c++;
		i = L[m[i]].Next;
	}
	res = N - c + 1;
	sort(L, L + N, cmpIndex);
	sort(L + res, L + N, cmp);

	i = 0;
	for (i; i < c - 2; i++)
	{
		printf("%05d %d %05d\n", L[i + res].Address, L[i + res].Data, L[i + res + 1].Address);
	}
	printf("%05d %d -1\n", L[i + res].Address, L[i + res].Data);
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
