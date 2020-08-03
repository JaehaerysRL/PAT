// 1014_福尔摩斯的约会.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int len = s1.length() < s2.length() ? s1.length() : s2.length();
	int Day, H = 0, M = 0, i, sig = 1;
	for (i = 0; i < len; i++)
	{
		if (sig)
		{
			if (s1[i] >= 'A' && s1[i] <= 'G' && s1[i] == s2[i]) 
			{
				Day = s1[i] - 'A' + 1;
				sig = 0;
				continue;
			}
		}
		else
		{
			if (s1[i] >= 'A' && s1[i] <= 'N' && s1[i] == s2[i])
			{
				H = s1[i] - 'A' + 10;
				break;
			}
			else if(s1[i] >= '0' && s1[i] <= '9' && s1[i] == s2[i])
			{
				H = s1[i] - '0';
				break;
			}
		}
	}
	switch (Day)
	{
	case 1:cout << "MON "; break;
	case 2:cout << "TUE "; break;
	case 3:cout << "WED "; break;
	case 4:cout << "THU "; break;
	case 5:cout << "FRI "; break;
	case 6:cout << "SAT "; break;
	default:cout << "SUN "; break;
	}
	printf("%02d", H);
	for (M; M < s3.length(); M++)
	{
		if (s3[M] == s4[M] && (s3[M]>='a' && s3[M] <= 'z' || s3[M] >= 'A' && s3[M] <= 'Z'))
		{
			printf(":%02d", M);
			break;
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
