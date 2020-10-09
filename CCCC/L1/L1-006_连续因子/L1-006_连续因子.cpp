// L1-006_连续因子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long n) {
    if (2 == n) return true;
    if (!(n & 1)) return false;
    long k = sqrt(n);
    for (int i = 3; i <= k; i += 2)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    long N;
    cin >> N;
    if (isPrime(N)) {
        cout << "1\n" << N << endl;
    }
    else
    {
        long l, t, c;
        for (c = 12; c >= 1; c--)
        {
            long k = long(pow(N, (double)1 / c));
            for (l = 2; l <= k; l++)
            {
                t = 1;
                for (int i = 0; i < c; i++)
                    t *= (l + i);
                if (t > N) break;
                else if (N % t == 0) goto END;
            }
        }
    END:
        cout << c << endl;
        for (int i = 0; i < c; i++)
            printf("*%ld" + !i, l + i);
        cout << endl;
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
