#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> c
= { {5, 5}, {4, 6}, {2, 6} };

int main()
{
	vector<pair<int, int>> crs;
	for (vector<int> p : c)
		crs.push_back(make_pair(p[1], p[0]));
	sort(crs.begin(), crs.end());
	int time = 0, ans = 0;
	priority_queue<int> q;
	for (int i = 0; i < crs.size(); i++)
	{
		q.push(crs[i].second);
		time += crs[i].second;
		if (time > crs[i].first)
		{
			time -= q.top();
			q.pop();
		}
	}
	cout << q.size() << '\n';
}
// https://leetcode.com/problems/course-schedule-iii/