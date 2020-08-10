// 1094_谷歌的招聘.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(long n) 
{
	if (n % 2 == 0) 
	{
		if (n == 2) return true;
		else return false;
	}
	else 
	{
		long s = sqrt(n);
		for (long i = 3;i <= s; i+=2)
		{
			if (n % i == 0) return false;
		}
		return true;
	}
}

int main()
{
	int L, K, sig = 1, i;
	long p;
	string str;
	cin >> L >> K >> str;
	for (i = 0; i <= L - K; i++)
	{
		p = stol(str.substr(i, K));
		if (isPrime(p)) 
		{
			sig = 0;
			break;
		}
	}

	if (sig) cout << 404 << endl;
	else cout << str.substr(i, K) << endl;
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
