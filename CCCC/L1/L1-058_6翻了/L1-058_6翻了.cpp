// L1-058_6翻了.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int len = s.length(), c = 0;
    for (int i = 0; i <= len; i++)
    {
        if (i == len || s[i] != '6') {
            if (c > 9) cout << 27, c = 0;
            else if (c > 3) cout << 9, c = 0;
            else if (c)
                while (c)
                    cout << 6, c--;
            if (i != len) cout << s[i];
        }
        else c++;
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
