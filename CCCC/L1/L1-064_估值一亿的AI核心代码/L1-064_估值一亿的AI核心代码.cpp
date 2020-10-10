// L1-064_估值一亿的AI核心代码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
using namespace std;

int main()
{
    int n;
	string s;
	cin >> n; cin.get();
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		cout << s << endl;
		int len = s.length();
		s = regex_replace(s, regex("(\\s+)"), " ");//删除连续的多余空格
		if (s.front() == ' ')
			s.erase(s.begin());//删除字符串行首的空格
		if (s.back() == ' ')
			s.pop_back();//删除字符串行末的空格
		s = regex_replace(s, regex("( !)"), "!");//删除！前的空格	
		s = regex_replace(s, regex("( ,)"), ",");//删除,前的空格
		s = regex_replace(s, regex("( \\.)"), ".");	//删除.前的空格
		s = regex_replace(s, regex("( \\?)"), "?");	//删除?前的空格
		s = regex_replace(s, regex("( ')"), "'");//删除'前的空格
		for (auto& c : s)
			if (c != 'I') //除了I的字母
				c = tolower(c);//转化为小写字母
		s = regex_replace(s, regex("(\\bcan you\\b)"), "_I can");//将can you替换为I can
		s = regex_replace(s, regex("(\\bcould you\\b)"), "_I could");//将could you替换为I could	
		s = regex_replace(s, regex("(\\bI\\b)"), "you");//将I替换为you	
		s = regex_replace(s, regex("(\\bme\\b)"), "you");//将me替换为you
		s = regex_replace(s, regex("(\\?)"), "!");//将?替换为!
		s = regex_replace(s, regex("(\\b_I\\b)"), "I");//为了避免重复替换而设置的_I换回I
		cout << "AI: " << s << endl;
	}
}
//https://blog.csdn.net/Fiveneves/article/details/104751060

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
