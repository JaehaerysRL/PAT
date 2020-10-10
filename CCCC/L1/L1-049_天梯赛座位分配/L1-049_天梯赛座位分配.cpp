// L1-049_天梯赛座位分配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
const int maxn = 101;

int main() {
	int n, m, max = 0, map[maxn][maxn] = { 0 }, s[maxn][maxn] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		if (m > max) max = m;
		for (int j = 0; j < m * 10; j++) {
			map[i][j] = 1;
		}
	}
	int flag = -1;
	int sum = 1; 
	for (int i = 0; i < max * 10; i++) {
		for (int j = 0; j < n; j++) {
			if (map[j][i]) {
				if (flag != j) {
					s[j][i] = sum++;
					flag = j;
				}
				else {
					sum += 1;
					s[j][i] = sum++;
					flag = j;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("#%d\n", i + 1);
		for (int j = 0; j < max * 10; j++)
			if (s[i][j]) {
				printf("%d%c", s[i][j], (j + 1) % 10 ? ' ' : '\n');
			}
	}
	return 0;
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
