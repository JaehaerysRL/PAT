// 1074_宇宙无敌加法器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string patBase, pat1, pat2;
	stack<char> ans;
	int N, len1, len2;
	cin >> patBase >> pat1 >> pat2;
	N = patBase.length(); len1 = pat1.length(); len2 = pat2.length();
	int p = len1 - 1, q = len2 - 1, k = N - 1, res = 0, t, n;
	while (p >= 0 && q >= 0)
	{
		t = res + pat1[p--] + pat2[q--] - '0' - '0';
		n = patBase[k--] - '0';
		if (!n) n = 10;
		res = t / n;
		ans.push(char(t % n + '0'));
	}
	while (p >= 0)
	{
		t = res + pat1[p--] - '0';
		n = patBase[k--] - '0';
		if (!n) n = 10;
		res = t / n;
		ans.push(char(t % n + '0'));
	}
	while (q >= 0)
	{
		t = res + pat2[q--] - '0';
		n = patBase[k--] - '0';
		if (!n) n = 10;
		res = t / n;
		ans.push(char(t % n + '0'));
	}
	int flag = 1;
	if (res) 
	{
		cout << res;
		flag = 0;
	}
	while (!ans.empty() && flag && ans.top() == '0') ans.pop();
	while (!ans.empty())
	{
		cout << ans.top();
		flag = 0;
		ans.pop();
	}
	if (flag) cout << 0;
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
