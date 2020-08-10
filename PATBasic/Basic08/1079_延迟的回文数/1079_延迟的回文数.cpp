// 1079_延迟的回文数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool check(string A, int len) 
{
	int m = len / 2;
	for (int i = 0; i <= m; i++)
	{
		if (A[i] != A[len - i - 1]) return false;
	}
	return true;
}

int main()
{
	string A, C;
	int sig = 0, len;
	cin >> A;
	len = A.length();
	if (check(A, len))
	{
		cout << A << " is a palindromic number." << endl;
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		C.clear();
		int j = 0, res = 0;
		while (j < len)
		{
			res = res + A[j] + A[len - j - 1] - '0' - '0';
			C += char(res % 10 + '0');
			res /= 10;
			j++;
		}
		if (res) C += char(res + '0');
		cout << A << " + ";
		reverse(A.begin(), A.end());
		reverse(C.begin(), C.end());
		cout << A << " = " << C << endl;
		A = C;
		len = C.length();
		if (check(C, len))
		{
			sig = 1;
			break;
		}

	}
	if (sig) cout << C << " is a palindromic number." << endl;
	else cout << "Not found in 10 iterations." << endl;
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
