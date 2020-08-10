// 1091_N-自守数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int M, N, K, T, L, sig;
	cin >> M;
	for (int k = 0; k < M; k++)
	{
		cin >> K;
		string str = to_string(K);
		L = str.length();
		L = pow(10, L);
		sig = 1;
		for (N = 1; N < 10; N++)
		{
			T = N * K * K;
			if ((T - K) % L == 0) 
			{
				sig = 0;
				cout << N << " " << T << endl;
				break;
			}
		}
		if (sig) cout << "No" << endl;
	}
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
