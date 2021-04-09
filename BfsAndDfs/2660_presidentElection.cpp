#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> connect;


int f(int start, int n)
{
	queue<pair<int, int>> q;
	vector<bool> know(n + 1, false);
	know[start] = true;
	q.push(make_pair(start, 0));
	int m = -1;
	while (!q.empty())
	{
		int f = q.front().first;
		int s = q.front().second;
		q.pop();
		if (m < s) m = s;
		for (int i = 1; i <= n; i++)
			if (connect[f][i] && !know[i])
			{
				know[i] = true;
				q.push(make_pair(i, s + 1));
			}
	}
	return m;
}
int main(void)
{
	int n, x, y;
	cin >> n;

	connect.resize(n + 1, vector<bool>(n + 1, false));

	while (true)
	{
		cin >> x >> y;
		if (x == -1 && y == -1) break;
		connect[x][y] = true;
		connect[y][x] = true;
	}
	vector<int> candidate(n + 1);
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		int c = f(i, n);
		candidate[i] = c;
	}
	int m = *min_element(candidate.begin() + 1, candidate.end());
	for (int j = 1; j <= n; j++)
		if (candidate[j] == m)
			ans.push_back(j);

	cout << m << " " << ans.size() << '\n';
	for (int a : ans) cout << a << " ";
	cout << '\n';

}

// https://www.acmicpc.net/problem/2660

/*
error: I don't know myself
bfs problem. maybe Floyd-Warshall ?
*/