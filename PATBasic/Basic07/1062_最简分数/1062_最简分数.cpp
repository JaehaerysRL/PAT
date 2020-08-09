// 1062_最简分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

bool isSimp(int n, int m) 
{
	if (n % 2 == 0 && m % 2 == 0) return false;
	for (int i = 3; i <= n; i += 2)
		if (n % i == 0 && m % i == 0) return false;
	return true;
}

int main()
{
	int n1, m1, n2, m2, k, t;
	cin >> n1; cin.get(); cin >> m1;
	cin >> n2; cin.get(); cin >> m2;
	cin >> k;
	if ((n1 * m2 - n2 * m1) > 0) 
	{
		int t;
		t = n1;	n1 = n2; n2 = t;
		t = m1;	m1 = m2; m2 = t;
	}

	int left = k * n1 / m1 + 1, right = k * n2 / m2;
	if ((k * n2) % m2 == 0) right--;
	for (t = left; t <= right; t++)
		if (isSimp(t, k)) 
		{
			cout << t << "/" << k;
			t++;
			break;
		}
	for (t; t <= right; t++)
		if (isSimp(t, k))
			cout << " " << t << "/" << k;
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
