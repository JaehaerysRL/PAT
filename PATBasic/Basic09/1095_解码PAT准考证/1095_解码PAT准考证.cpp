// 1095_解码PAT准考证.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

typedef struct _pat
{
	string id;
	char grade;
	int room;
	int date;
	int num;
	int score;
}PAT;

bool cmp(PAT a, PAT b) 
{
	if (a.grade != b.grade) 
	{
		if (a.grade == 'T' || b.grade == 'B') return true;
		else return false;
	}
	else if (a.score != b.score) return a.score > b.score;
	else return a.id < b.id;
}

typedef struct _room
{
	int room;
	int num;
}Room;

bool cmpr(Room a, Room b)
{
	if (a.num != b.num) return a.num > b.num;
	else return a.room < b.room;
}

int main()
{
	int N, M, tr, td, len, opt;
	char tg;
	string tid;
	cin >> N >> M;
	getchar();
	PAT* P = new PAT[N];
	map<int, pair<int, int>> mr;//考场->考生人数，总分
	map<int, vector<Room>> md;//日期->考场

	for (int i = 0; i < N; i++)
	{
		cin >> tid >> P[i].score;
		getchar();
		P[i].id = tid;
		P[i].grade = tid[0];
		P[i].room = stoi(tid.substr(1, 3));
		P[i].date = stoi(tid.substr(4, 6));
		P[i].num = stoi(tid.substr(10, 3));
		mr[P[i].room].first++;
		mr[P[i].room].second += P[i].score;
		len = md[P[i].date].size();
		int j = 0;
		for (j; j < len; j++)
		{
			if (md[P[i].date][j].room == P[i].room) 
			{
				md[P[i].date][j].num++;
				goto Flag;
			}
		}
		Room r;
		r.room = P[i].room;
		r.num = 1;
		md[P[i].date].emplace_back(r);
		Flag:
		continue;
	}
	sort(P, P + N, cmp);

	for (int k = 1; k <= M; k++)
	{
		int i;
		cin >> opt;
		getchar();
		switch (opt)
		{
		case 1:
			cin >> tg;
			getchar();
			printf("Case %d: 1 %c\n", k, tg);
			i = 0;
			while (i < N && P[i].grade != tg) i++;
			if (i == N) 
			{
				cout << "NA" << endl;
				break;
			}
			while (i < N && P[i].grade == tg) 
			{
				cout << P[i].id << " " << P[i].score << endl;
				i++;
			}
			break;
		case 2:
			cin >> tr;
			getchar();
			printf("Case %d: 2 %03d\n", k, tr);
			if (mr.find(tr) != mr.end()) cout << mr[tr].first << " " << mr[tr].second << endl;
			else cout << "NA" << endl;
			break;
		case 3:
			cin >> td;
			getchar();
			printf("Case %d: 3 %06d\n", k, td);
			if (md.find(td) != md.end()) 
			{
				len = md[td].size();
				Room* R = new Room[len];
				for (int j = 0; j < len; j++)
					R[j] = md[td][j];
				sort(R, R + len, cmpr);
				for (int j = 0; j < len; j++)
					printf("%03d %d\n", R[j].room, R[j].num);
				delete[] R;
			}
			else cout << "NA" << endl;
			break;
		default:
			break;
		}
	}

	delete[] P;
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
