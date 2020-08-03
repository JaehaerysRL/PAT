// 1012_数字分类.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int c1, c2, c3, c4, c5, s1, s2, s4, s5, t, sig;
	c1 = c2 = c3 = c4 = c5 = s1 = s2 = s4 = s5 = 0;
	sig = 1;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		switch (t%5)
		{
		case 0:
			if (t % 2 == 0) 
			{
				c1++;
				s1 += t;
			}
			break;
		case 1:
			c2++;
			s2 += sig * t;
			sig *= -1;
			break;
		case 2:
			c3++;
			break;
		case 3:
			c4++;
			s4 += t;
			break;
		case 4:
			c5++;
			if (t > s5) s5 = t;
		default:
			break;
		}
	}
	if (c1) cout << s1;
	else cout << "N";
	if (c2) cout << " " << s2;
	else cout << " N";
	if (c3) cout << " " << c3;
	else cout << " N";
	if (c4) printf(" %.1lf", (double)s4 / (double)c4);
	else cout << " N";
	if (c5) cout << " " << s5;
	else cout << " N";
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
