// 1044_火星数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	int N, num;
	string str;
	map<string, int> mtoe;
	mtoe["tret"] = 0;
	mtoe["jan"] = 1;
	mtoe["feb"] = 2;
	mtoe["mar"] = 3;
	mtoe["apr"] = 4;
	mtoe["may"] = 5;
	mtoe["jun"] = 6;
	mtoe["jly"] = 7;
	mtoe["aug"] = 8;
	mtoe["sep"] = 9;
	mtoe["oct"] = 10;
	mtoe["nov"] = 11;
	mtoe["dec"] = 12;
	mtoe["tam"] = 13;
	mtoe["hel"] = 26;
	mtoe["maa"] = 39;
	mtoe["huh"] = 52;
	mtoe["tou"] = 65;
	mtoe["kes"] = 78;
	mtoe["hei"] = 91;
	mtoe["elo"] = 104;
	mtoe["syy"] = 117;
	mtoe["lok"] = 130;
	mtoe["mer"] = 143;
	mtoe["jou"] = 156;
	map<int, string> etom;
	etom[0] = "tret";
	etom[1] = "jan";
	etom[2] = "feb";
	etom[3] = "mar";
	etom[4] = "apr";
	etom[5] = "may";
	etom[6] = "jun";
	etom[7] = "jly";
	etom[8] = "aug";
	etom[9] = "sep";
	etom[10] = "oct";
	etom[11] = "nov";
	etom[12] = "dec";
	etom[13] = "tam";
	etom[26] = "hel";
	etom[39] = "maa";
	etom[52] = "huh";
	etom[65] = "tou";
	etom[78] = "kes";
	etom[91] = "hei";
	etom[104] = "elo";
	etom[117] = "syy";
	etom[130] = "lok";
	etom[143] = "mer";
	etom[156] = "jou";

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str[0] >= '0' && str[0] <= '9') 
		{
			int len = str.length();
			num = 0;
			for (int j = len - 1; j >= 0; j--)
			{
				num *= 10;
				num += str[len - 1 - j] - '0';
			}
			if (num < 13) cout << etom[num] << endl;
			else 
			{
				if (num % 13) cout << etom[num - num % 13] << " " << etom[num % 13] << endl;
				else cout << etom[num] << endl;
			}
		}
		else 
		{
			num = mtoe[str];
			if (num < 13) cout << num << endl;
			else 
			{
				char t = cin.get();
				if (t == ' ') 
				{
					cin >> str;
					num += mtoe[str];
				}
				cout << num << endl;
			}
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
