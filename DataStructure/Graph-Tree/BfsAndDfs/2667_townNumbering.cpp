#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
vector<string> mp;
vector<vector<bool>> v;
vector<int> answer;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int dfs(int y, int x)
{
	if (y < 0 || x < 0 || x >= n || y >= n)
		return 0;
	if (mp[y][x] == '0' || v[y][x])
		return 0;
	v[y][x] = true;
	int ans = 1;

	for (int i = 0; i < 4; i++)
		ans += dfs(y + dy[i], x + dx[i]);

	return ans;
}
int main()
{
	cin >> n;
	mp.resize(n);
	v.resize(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
		cin >> mp[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int tmp = dfs(i, j);
			if (tmp != 0) answer.push_back(tmp);
		}

	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (int a : answer)
		cout << a << '\n';
	return 0;
}

// https://www.acmicpc.net/problem/2667

/*
dfs all possible tile
*/