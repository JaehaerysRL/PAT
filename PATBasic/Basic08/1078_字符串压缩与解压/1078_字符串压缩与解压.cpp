// 1078_字符串压缩与解压.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

void cps() 
{
	string str;
	getline(cin, str);
	int len = str.length(), i = 0, cnt = 0;
	while (i < len)
	{
		if (i != len - 1 && str[i] == str[i + 1]) 
		{
			cnt = 1;
			while (str[i] == str[i + 1])
			{
				cnt++;
				i++;
			}
			cout << cnt;
		}
		cout << str[i++];
	}
	cout << endl;
}
void dcps() 
{
	string str;
	getline(cin, str);
	int len = str.length(), i = 0, cnt = 0;
	while (i < len)
	{
		if (str[i] >= '0' && str[i] <= '9') 
		{
			cnt *= 10;
			cnt += str[i] - '0';
		}
		else 
		{
			if (cnt) 
			{
				for (int j = 0; j < cnt; j++)
					cout << str[i];
				cnt = 0;
			}
			else cout << str[i];
		}
		i++;
	}
	cout << endl;
}

int main()
{
	char opt;
	cin >> opt; cin.get();
	if (opt == 'C') cps();
	else if (opt == 'D') dcps();
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
