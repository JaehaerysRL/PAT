// L1-023_输出GPLT.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int len = str.length(), c = 0;
    int num[4]{};
    for (int i = 0; i < len; i++)
    {
        switch (str[i]) {
        case 'g':
        case 'G':
            num[0]++; c++; break;
        case 'p':
        case 'P':
            num[1]++; c++; break;
        case 'l':
        case 'L':
            num[2]++; c++; break;
        case 't':
        case 'T':
            num[3]++; c++; break;
        default:
            break;
        }
    }
    while (c)
    {
        if (num[0]-->0) c--, cout << 'G';
        if (num[1]-->0) c--, cout << 'P';
        if (num[2]-->0) c--, cout << 'L';
        if (num[3]-->0) c--, cout << 'T';
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
