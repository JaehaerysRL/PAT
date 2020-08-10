// 1081_检查密码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, sig1, sig2, sig3, len;
	string tpw;
	cin >> N;
	cin.get();
	for (int k = 0; k < N; k++)
	{
		getline(cin, tpw);
		len = tpw.length();
		sig1 = sig2 = sig3 = 0;
		if (len < 6) 
		{
			cout << "Your password is tai duan le." << endl;
			continue;
		}
		else 
		{
			for (int i = 0; i < len; i++)
			{
				if (tpw[i] >= '0' && tpw[i] <= '9') sig1 = 1;
				else if (tpw[i] >= 'a' && tpw[i] <= 'z') sig2 = 1;
				else if (tpw[i] >= 'A' && tpw[i] <= 'Z') sig2 = 1;
				else if (tpw[i] != '.') 
				{
					sig3 = 0;
					break;
				}
				sig3 = 1;
			}
		}
		if (!sig3) cout << "Your password is tai luan le." << endl;
		else if (!sig1) cout << "Your password needs shu zi." << endl;
		else if (!sig2) cout << "Your password needs zi mu." << endl;
		else cout << "Your password is wan mei." << endl;
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
