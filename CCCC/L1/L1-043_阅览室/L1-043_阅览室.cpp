// L1-043_阅览室.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cmath>
#include <map>
using namespace std;

typedef struct book
{
    int sh;
    int sm;
    bool sig = true;//可借出
}Book;

int main()
{
    int N, num, m, h;
    char opt;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int f = 0;
        double t = 0;
        map<int, book> ntob;
        while (cin>>num,num)
        {
            cin >> opt >> h;
            cin.get(); 
            cin >> m;
            if (opt == 'S') {
                    ntob[num].sh = h;
                    ntob[num].sm = m;
                    ntob[num].sig = false;
            }
            else {
                if (!ntob[num].sig) {
                    f++;
                    t += m - ntob[num].sm + (h - ntob[num].sh) * 60;
                    ntob[num].sig = true;
                }
            }
        }
        cin >> opt >> h;
        cin.get();
        cin >> m;
        if (f) t = t / f;
        cout << f << " " << (int)(t + 0.5) << endl;
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
