// 1043_输出PATest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
	int num[6]{};
	int cnt = 0;
	char t;
	while ((t=cin.get())!='\n')
	{
		switch (t)
		{
		case 'P':
			num[0]++; break;
		case 'A':
			num[1]++; break;
		case 'T':
			num[2]++; break;
		case 'e':
			num[3]++; break;
		case 's':
			num[4]++; break;
		case 't':
			num[5]++; break;
		default:
			break;
		}
	}
	for (int i = 0; i < 6; i++)
		cnt += num[i];

	while (cnt)
	{
		if (num[0]) 
		{
			num[0]--;
			cnt--;
			cout << 'P';
		}
		if (num[1])
		{
			num[1]--;
			cnt--;
			cout << 'A';
		}
		if (num[2])
		{
			num[2]--;
			cnt--;
			cout << 'T';
		}
		if (num[3])
		{
			num[3]--;
			cnt--;
			cout << 'e';
		}
		if (num[4])
		{
			num[4]--;
			cnt--;
			cout << 's';
		}
		if (num[5])
		{
			num[5]--;
			cnt--;
			cout << 't';
		}
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
