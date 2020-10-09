// L1-031_到底是不是太胖了.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int h, w;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &h, &w);
        double bw = (double)(h - 100) * 1.8;
        if (w - bw < 0.1 * bw && bw - w < 0.1 * bw) printf("You are wan mei!\n");
        else if (bw - w >= 0.1 * bw) printf("You are tai shou le!\n");
        else printf("You are tai pang le!\n");
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
