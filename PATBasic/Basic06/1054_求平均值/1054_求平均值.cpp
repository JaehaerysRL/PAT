// 1054_求平均值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N, C, sig, len, flag, cn;
	string str;
	cin >> N;
	C = N; 
	double sum = 0, t;

	for (int k = 0; k < N; k++)
	{
		cin >> str;
		len = str.length();
		t = 0; cn = 0;
		flag = 1; sig = 1;
		if (str[0] == '-') sig = -1;
		else if (str[0] <= '9' && str[0] >= '0') t += str[0] - '0';
		else goto F;
		for (int i = 1; i < len; i++)
		{
			if (flag) //整数部分
			{
				if (str[i] <= '9' && str[i] >= '0') 
				{
					t *= 10; t += str[i] - '0';
				}
				else if (str[i] == '.') 
					flag = 0;
				else goto F;
			}
			else //小数部分 
			{
				if (str[i] <= '9' && str[i] >= '0' && cn < 2)
					t += (str[i] - '0') * pow(0.1, ++cn);
				else goto F;
			}
		}
		if(fabs(t)>1000) goto F;
		sum += t * sig;
		continue;
		F:
		C--;
		cout << "ERROR: " << str << " is not a legal number" << endl;
		continue;
	}

	if (C > 1) printf("The average of %d numbers is %.2lf\n", C, sum / C);
	else if(C) printf("The average of 1 number is %.2lf\n", sum);
	else printf("The average of 0 numbers is Undefined\n", sum);
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
