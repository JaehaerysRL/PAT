// 1034_有理数四则运算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

void simpOut(long a, long b) 
{
	long k, s = 1;
	if (a < 0) 
	{
		a *= -1;
		s *= -1;
	}
	if (b < 0)
	{
		b *= -1;
		s *= -1;
	}
	k = a / b;
	a -= b * k;

	if (s < 0) cout << "(-";
	if (k || (a == 0))
		cout << k;
	if (a) 
	{
		long ta = a, tb = b, t;
		while (tb)
		{
			t = ta;
			ta = tb;
			tb = t % tb;
		}
		a /= ta;
		b /= ta;
		if (k) cout << " ";
		cout << a << "/" << b;
	}
	if (s < 0) cout << ")";
}

int main()
{
	long a1, a2, b1, b2;
	cin >> a1; cin.get();
	cin >> b1; 
	cin >> a2; cin.get();
	cin >> b2; 

	simpOut(a1, b1);
	cout << " + ";
	simpOut(a2, b2);
	cout << " = ";
	simpOut(a1 * b2 + a2 * b1, b1 * b2);
	cout << endl;

	simpOut(a1, b1);
	cout << " - ";
	simpOut(a2, b2);
	cout << " = ";
	simpOut(a1 * b2 - a2 * b1, b1 * b2);
	cout << endl;

	simpOut(a1, b1);
	cout << " * ";
	simpOut(a2, b2);
	cout << " = ";
	simpOut(a1 * a2, b1 * b2);
	cout << endl;

	simpOut(a1, b1);
	cout << " / ";
	simpOut(a2, b2);
	cout << " = ";
	if (a2) simpOut(a1 * b2, a2 * b1);
	else cout << "Inf";
	cout << endl;
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
