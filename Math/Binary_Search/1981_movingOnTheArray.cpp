#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int N;
vector<vector<int>> arr;

bool bfs(int baseMin, int baseMax)
{
	queue<pair<pair<int, int>, pair<int, int>>> q;
	vector<vector<bool>> v(N, vector<bool>(N, false));
	v[0][0] = true;
	q.push(make_pair(make_pair(arr[0][0], arr[0][0]), make_pair(0, 0)));
	while (!q.empty())
	{
		int mx = q.front().first.first;
		int mn = q.front().first.second;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		if (baseMin > mn || baseMax < mx) continue;
		if (y == N - 1 && x == N - 1) return true;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			int nMax = max(mx, arr[ny][nx]);
			int nMin = min(mn, arr[ny][nx]);
			int sub = nMax - nMin;
			if (v[ny][nx]) continue;
			v[ny][nx] = true;
			q.push(make_pair(make_pair(nMax, nMin), make_pair(ny, nx)));
		}
	}
	return false;
}
bool check(int m)
{
	for (int i = 0; i + m <= 200; i++)
		if (bfs(i, i + m)) return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	arr.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	int l = 0, r = 201;
	while (l < r)
	{
		int m = (l + r) / 2;
		if (check(m)) r = m;
		else l = m + 1;
	}
	cout << l << '\n';
}

// https://www.acmicpc.net/problem/1981