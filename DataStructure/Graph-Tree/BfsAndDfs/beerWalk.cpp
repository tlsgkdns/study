#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

vector<int> dp;

int dist(pair<int, int> p1, pair<int, int> p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	const int limit = 1000;
	vector<string> ans;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		queue<pair<int, int>> q;
		int n;
		cin >> n;
		vector<pair<int, int>> pos(n + 2);
		vector<bool> v(n + 2, false);
		for (int j = 0; j < n + 2; j++)
			cin >> pos[j].first >> pos[j].second;
		q.push(pos[0]);
		v[0] = true;
		while (!q.empty())
		{
			auto p = q.front();
			if (p.first == pos[n + 1].first && p.second == pos[n + 1].second)
				break;
			for (int k = 1; k < n + 2; k++)
				if (dist(p, pos[k]) <= 1000 && !v[k])
				{
					v[k] = true;
					q.push(pos[k]);
				}
			q.pop();
		}
		if (q.empty()) ans.push_back("sad");
		else ans.push_back("happy");
	}
	for (string a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/9020

/*
Maybe I have read question more carefully.
typical bfs problem
*/