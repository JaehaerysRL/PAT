// 1088_三人行.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cmath>
using namespace std;

void judge(double j, int m) 
{
	if (j > m) cout << " Cong";
	else if(j < m) cout << " Gai";
	else cout << " Ping";
}

int main()
{
	int M, X, Y, A, B, a, b, sig = 0;
	double t1, t2, C;//丙有可能不是整数
	cin >> M >> X >> Y;
	for (a = 9; a > 0; a--)
	{
		for (b = 9; b >= 0; b--)
		{
			t1 = abs(9 * a - 9 * b);
			t2 = 10 * b + a;
			C = t1 / X;
			if (C > 0 && C == t2 / Y) 
			{
				A = 10 * a + b;
				B = 10 * b + a;
				sig = 1;
				goto END;
			}
		}
	}
	END:
	if (sig) 
	{
		cout << A;
		judge(A, M);
		judge(B, M);
		judge(C, M);
	}
	else cout << "No Solution";
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
