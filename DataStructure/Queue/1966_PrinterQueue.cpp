#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int c, n, tmp;
	cin >> c;
	vector<vector<pair<int, int>>> docu(c);
	vector<int> fd(c), ans(c);
	queue<pair<int, int>> q;
	for (int i = 0; i < c; i++)
	{
		cin >> n >> fd[i];
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			docu[i].push_back(make_pair(tmp, j));
		}
	}
	for (int i = 0; i < c; i++)
	{
		for (pair<int, int> p : docu[i]) q.push(p);
		sort(docu[i].begin(), docu[i].end(), greater<pair<int, int>>());
		int ord = 1;
		while (!q.empty())
		{
			if (docu[i][ord - 1].first == q.front().first)
			{
				if (q.front().second == fd[i])
					ans[i] = ord;
				ord++;
			}
			else
				q.push(q.front());
			q.pop();
		}
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/1966