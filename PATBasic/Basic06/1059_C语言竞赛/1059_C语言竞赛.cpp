// 1059_C语言竞赛.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

bool isPrime(int p)
{
	if (p == 2) return true;
	else if (p % 2 == 0) return false;
	else 
		for (int i = 3; i <= sqrt(p); i+=2)
			if (p % i == 0) return false;
	return true;
}

int main()
{
	int N, K, id;
	map<int, int> m;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> id;
		m[id] = i;
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> id;
		if (m.find(id) == m.end()) printf("%04d: Are you kidding?\n", id);
		else if (m[id] == -1) printf("%04d: Checked\n", id);
		else 
		{
			if (m[id] == 1) printf("%04d: Mystery Award\n", id);		
			else if(isPrime(m[id])) printf("%04d: Minion\n", id);
			else printf("%04d: Chocolate\n", id);
			m[id] = -1;
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
