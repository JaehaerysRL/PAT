﻿// L1-019_谁先倒.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int a, b, h1, q1, h2, q2, N;
    scanf("%d %d", &a, &b);
    int isEnd = 0, i = 0, c1 = 0, c2 = 0;
    scanf("%d", &N);
    while (isEnd == 0 && i < N)
    {
        i++;
        scanf("%d %d %d %d", &h1, &q1, &h2, &q2);
        if (q1 == h1 + h2 && q2 != h1 + h2) c1++;
        if (q1 != h1 + h2 && q2 == h1 + h2) c2++;
        if (c1 > a) {
            printf("A\n%d", c2);
            return 0;
        }
        if (c2 > b) {
            printf("B\n%d", c1);
            return 0;
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
