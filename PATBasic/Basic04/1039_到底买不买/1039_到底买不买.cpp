// 1039_到底买不买.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int s[62]{}, h[62]{};
	string S, H;
	cin >> S >> H;
	int ns = S.length(), nh = H.length();
	for (int i = 0; i < ns; i++)
	{
		if (S[i] >= '0' && S[i] <= '9') s[S[i] - '0']++;
		else if (S[i] >= 'a' && S[i] <= 'z') s[S[i] - 'a' + 10]++;
		else  s[S[i] - 'A' + 36]++;
	}
	for (int i = 0; i < nh; i++)
	{
		if (H[i] >= '0' && H[i] <= '9') h[H[i] - '0']++;
		else if (H[i] >= 'a' && H[i] <= 'z') h[H[i] - 'a' + 10]++;
		else  h[H[i] - 'A' + 36]++;
	}

	int res = 0;
	for (int i = 0; i < 62; i++)
		if (s[i] < h[i]) res += h[i] - s[i];

	if (res) cout << "No " << res << endl;
	else cout << "Yes " << ns - nh << endl;
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
