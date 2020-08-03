// 1016_部分A+B.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string A, DA, B, DB;
	cin >> A >> DA >> B >> DB;
	int pa, pb;
	pa = pb = 0;
	for (int i = 0; i < A.length(); i++)
		if(A[i] == DA[0])
			pa = 10 * pa + DA[0] - '0';
	for (int i = 0; i < B.length(); i++)
		if (B[i] == DB[0])
			pb = 10 * pb + DB[0] - '0';
	cout << pa + pb;
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
