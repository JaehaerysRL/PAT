// L1-048_矩阵A乘以B.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
const int maxn = 100;

int main()
{
    int Ca, Cb, Ra, Rb;
    int A[maxn][maxn], B[maxn][maxn];
    cin >> Ra >> Ca;
    for (int i = 0; i < Ra; i++)
    {
        for (int j = 0; j < Ca; j++)
        {
            cin >> A[i][j];
        }
    }
    cin >> Rb >> Cb;
    for (int i = 0; i < Rb; i++)
    {
        for (int j = 0; j < Cb; j++)
        {
            cin >> B[i][j];
        }
    }
    if (Ca != Rb) cout << "Error: " << Ca << " != " << Rb << endl;
    else {
        cout << Ra << " " << Cb << endl;
        for (int i = 0; i < Ra; i++) {
            for (int j = 0; j < Cb; j++) {
                int s = 0;
                for (int k = 0; k < Ca; k++)
                    s += A[i][k] * B[k][j];
                printf(" %d" + !j, s);
            }
            cout << endl;
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
