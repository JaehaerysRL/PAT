// 1019_数字黑洞.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num[4];
	int N, L, R;
	cin >> N;
	while (true)
	{
		for (int i = 0; i < 4; i++)
		{
			num[i] = N % 10;
			N /= 10;
		}
		sort(num, num + 4);
		if (num[0] == num[3]) 
		{
			for (int j = 0; j < 4; j++)
				cout << num[0];
			cout << " - ";
			for (int j = 0; j < 4; j++)
				cout << num[0];
			cout << " = 0000" << endl;
			break;
		}
		else
		{
			L = 1000 * num[3] + 100 * num[2] + 10 * num[1] + num[0];
			R = 1000 * num[0] + 100 * num[1] + 10 * num[2] + num[3];
			N = L - R;
			printf("%04d - %04d = %04d\n", L, R, N);
		}
		if (N == 6174) break;
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
