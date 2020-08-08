// 1057_数零壹.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
	char t;
	int letter[27]{};
	int num, z, o;
	while (cin.get(t),t!='\n')
	{
		if (t >= 'a' && t <= 'z') letter[t - 'a' + 1]++;
		else if (t >= 'A' && t <= 'Z') letter[t - 'A' + 1]++;
	}

	num = z = o = 0;
	for (int i = 1; i < 27; i++)
		num += i * letter[i];
	while (num)
	{
		if (num % 2) o++;
		else z++;
		num /= 2;
	}

	cout << z << " " << o << endl;
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
