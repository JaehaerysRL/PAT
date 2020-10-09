// L1-009_N个数求和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long gcdCN(long a, long b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	int r = 0;
	while (!((a & 1) || (b & 1)))
	{
		a >>= 1; b >>= 1;
		r++;
	}
	while (1)
	{
		while (!(a & 1)) a >>= 1;
		while (!(b & 1)) b >>= 1;
		(a > b) ? a = a - b : b = b - a;
		if (a == 0) return b << r;
		if (b == 0) return a << r;
	}
}

int main()
{
	int N;
	long a, b, ta, tb, na, nb, g;
	cin >> N;
	scanf("%ld/%ld", &a, &b);
	for (int i = 1; i < N; i++)
	{
		scanf("%ld/%ld", &ta, &tb);
		g = gcdCN(b, tb);
		na = tb / g * a + b / g * ta;
		nb = b / g * tb;
		if (!na) {
			a = 0; b = 1;
		}
		else {
			g = gcdCN(na, nb);
			a = na / g;
			b = nb / g;
		}
	}
	if (a < 0) {
		cout << "-";
		a = -a;
	}
	int sig = 0;
	if (a / b > 0) {
		cout << a / b;
		a %= b;
		sig++;
	}
	if (a) {
		printf(" %ld/%ld" + !sig, a, b);
	}
	else if (!sig) cout << "0";
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
