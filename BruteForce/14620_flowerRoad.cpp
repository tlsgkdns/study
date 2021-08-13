#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans = 1000000000;
int dy[5] = { 1, -1, 0, 0, 0 };
int dx[5] = { 0, 0, 1, -1, 0 };
vector<vector<int>> f;

void solve(vector<vector<bool>>& v, int d, int c, int pos)
{
	if (d == 3)
	{
		ans = min(ans, c);
		return;
	}
	int y = pos / N;
	int x = pos % N;
	for (int i = y; i < N; i++)
		for (int j = x; j < N; j++)
		{
			if (i - 1 < 0 || j - 1 < 0 || i + 1 >= N || j + 1 >= N) continue;
			if (v[i][j] || v[i - 1][j] || v[i][j - 1] || v[i + 1][j] || v[i][j + 1]) continue;
			int cost = c;
			for (int k = 0; k < 5; k++)
			{
				v[i + dy[k]][j + dx[k]] = true;
				cost += f[i + dy[k]][j + dx[k]];
			}
			solve(v, d + 1, cost, pos);
			for (int k = 0; k < 5; k++)	v[i + dy[k]][j + dx[k]] = false;
		}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<vector<bool>> v(N, vector<bool>(N, false));
	f.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> f[i][j];
	solve(v, 0, 0, 0);
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/14620