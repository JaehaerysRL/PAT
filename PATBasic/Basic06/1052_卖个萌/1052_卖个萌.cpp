// 1052_卖个萌.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ch[3][10];
	int K, p, sig;
	p = sig = 0;
	int cs[5];
	char t;

	for (int i = 0; i < 3; i++)
	{
		while ((t=cin.get())!='\n')
		{
			if (!sig && t == '[')
				sig = 1;
			else if (sig) 
			{
				if (t != ']')
					ch[i][p] += t;
				else 
				{
					p++;
					sig = 0;
				}
			}
		}
		p = 0;
	}

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < 5; j++)
			cin >> cs[j];
		if (ch[0][cs[0]-1] != "" && ch[0][cs[4]-1] != "" && ch[1][cs[1]-1] != "" && ch[1][cs[3]-1] != "" && ch[2][cs[2]-1] != "")
			cout << ch[0][cs[0]-1] << "(" << ch[1][cs[1]-1] << ch[2][cs[2]-1] << ch[1][cs[3]-1] << ")" << ch[0][cs[4]-1] << endl;
		else cout << "Are you kidding me? @\\/@" << endl;
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
