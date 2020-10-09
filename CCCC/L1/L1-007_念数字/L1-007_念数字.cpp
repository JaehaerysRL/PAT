// L1-007_念数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n;
    cin >> n;
    int len = n.length();
    for (int i = 0; i < len; i++)
    {
        switch (n[i])
        {
        case '-':printf("fu"); break;
        case '1':printf(" yi" + !i); break;
        case '2':printf(" er" + !i); break;
        case '3':printf(" san" + !i); break;
        case '4':printf(" si" + !i); break;
        case '5':printf(" wu" + !i); break;
        case '6':printf(" liu" + !i); break;
        case '7':printf(" qi" + !i); break;
        case '8':printf(" ba" + !i); break;
        case '9':printf(" jiu" + !i); break;
        case '0':printf(" ling" + !i); break;
        default:
            break;
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
