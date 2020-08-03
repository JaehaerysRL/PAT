// 1003_我要通过.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int k = 0; k < n; k++)
	{
		string s;
		cin >> s;
		int m = s.length();
		int cl = 0, cm = 0, cr = 0;
		int sig = 1;
		for (int i = 0; i < m; i++)
		{
			switch (sig)
			{
			case 1:
				if (s[i] == 'P') sig = 2;
				else if (s[i] != 'A') goto END;
				else cl++;
				break;
			case 2:
				if (s[i] == 'T') sig = 3;
				else if (s[i] != 'A') goto END;
				else cm++;
				break;
			case 3:
				if (s[i] != 'A') goto END;
				else cr++;
				break;
			}
		}
		if(sig != 3 || cm == 0) goto END;
		if (cl == 0)
			if (cr == 0) sig = 0;
			else goto END;
		else
			if (cr / cl == cm) sig = 0;
			else goto END;
	END:
		if (!sig) cout << "YES" << endl;
		else cout << "NO" << endl;
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
