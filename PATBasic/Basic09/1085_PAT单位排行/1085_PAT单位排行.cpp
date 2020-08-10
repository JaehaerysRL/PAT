// 1085_PAT单位排行.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

typedef struct _pat
{
	string school;
	int score;
	int num;
}PAT;

bool cmp(PAT a, PAT b) 
{
	if (a.score != b.score) return a.score > b.score;
	else if (a.num != b.num) return a.num < b.num;
	else return a.school < b.school;
}

int main()
{
	int N, score;
	string id, school;
	map<string, pair<double,int>> mp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> id >> score >> school;
		transform(school.begin(), school.end(), school.begin(), static_cast<int(*)(int)>(tolower));
		mp[school].second++;
		if (id[0] == 'A') mp[school].first += score;
		else if (id[0] == 'T') mp[school].first += 1.5 * score;
		else mp[school].first += score / 1.5;
	}

	int K = mp.size(), i = 0;
	PAT* p = new PAT[K];
	for (auto x: mp)
	{
		p[i].school = x.first;
		p[i].score = (int)x.second.first;
		p[i].num = x.second.second;
		i++;
	}
	sort(p, p + K, cmp);

	cout << K << endl;
	int res = 0;
	for (i = 0; i < K - 1; i++)
	{
		if (p[i].score == p[i + 1].score) 
		{
			if (!res) res = i + 1;
			cout << res << " " << p[i].school << " " << p[i].score << " " << p[i].num << endl;
		}
		else 
		{
			if (res) cout << res << " " << p[i].school << " " << p[i].score << " " << p[i].num << endl;
			else cout << i + 1 << " " << p[i].school << " " << p[i].score << " " << p[i].num << endl;
			res = 0;
		} 
	}
	if (res) cout << res << " " << p[i].school << " " << p[i].score << " " << p[i].num << endl;
	else cout << i + 1 << " " << p[i].school << " " << p[i].score << " " << p[i].num << endl;

	delete[] p;
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
