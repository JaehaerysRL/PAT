// L1-025_正整数A+B.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

int judge(string s) {
    int len = s.length();
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9') sum = sum * 10 + (s[i] - '0');
        else return -1;
    }
    return sum;
}

int main()
{
    string A, B, H;
    getline(cin, H);
    int len = H.length();
    for (int i = 0; i < len; i++)
    {
        if (H[i] == ' ') {
            A = H.substr(0, i);
            while (H[++i] == ' ');
            B = H.substr(i, len - i); 
            break;
        }
    }
    int a = judge(A), b = judge(B);
    if (a > 0 && b > 0 && a <= 1000 && b <= 1000) printf("%d + %d = %d", a, b, a + b);
    else if (a > 0 && a <= 1000) printf("%d + ? = ?", a);
    else if (b > 0 && b <= 1000) printf("? + %d = ?", b);
    else printf("? + ? = ?");
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
