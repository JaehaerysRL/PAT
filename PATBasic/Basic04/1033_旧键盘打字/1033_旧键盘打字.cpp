// 1033_旧键盘打字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string bk, str;
	getline(cin, bk); 
	getline(cin, str);
	int l1 = bk.length(), l2 = str.length();
	int key[42]{};

	for (int i = 0; i < l1; i++)
	{
		if (bk[i] >= 'a' && bk[i] <= 'z')
			key[bk[i] - 'a' + 10] = 1;
		else if (bk[i] >= 'A' && bk[i] <= 'Z')
			key[bk[i] - 'A' + 10] = 1;
		else if (bk[i] >= '0' && bk[i] <= '9')
			key[bk[i] - '0'] = 1;
		else if (bk[i] == '_')
			key[36] = 1;
		else if (bk[i] == ',')
			key[37] = 1;
		else if (bk[i] == '.')
			key[38] = 1;
		else if (bk[i] == '-')
			key[39] = 1;
		else if (bk[i] == '+')
			key[40] = 1;
	}
	for (int i = 0; i < l2; i++) 
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (!key[str[i] - 'a' + 10]) cout << str[i];
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (!key[str[i] - 'A' + 10] && !key[40]) cout << str[i];
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			if (!key[str[i] - '0']) cout << str[i];
		}
		else if (str[i] == '_' && !key[36]) cout << str[i];
		else if (str[i] == ',' && !key[37]) cout << str[i];
		else if (str[i] == '.' && !key[38]) cout << str[i];
		else if (str[i] == '-' && !key[39]) cout << str[i];
	}
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
