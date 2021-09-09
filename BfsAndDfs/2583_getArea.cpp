#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int M, N, K, c1, r1, c2, r2;
vector<vector<bool>> area, v;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1,1 };
bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < M && x < N);
}
int bfs(int a, int b)
{
	queue<pair<int, int>> q;
	int ret = 1;
	q.push({ a, b });
	v[a][b] = true;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!inRange(ny, nx) || v[ny][nx] || area[ny][nx]) continue;
			v[ny][nx] = true;
			ret++;
			q.push({ ny, nx });
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N >> K;
	area.resize(M, vector<bool>(N, false)); v.resize(M, vector<bool>(N, false));
	for (int i = 0; i < K; i++)
	{
		cin >> c1 >> r1 >> c2 >> r2;
		for (int r = r1; r < r2; r++)
			for (int c = c1; c < c2; c++)
				area[r][c] = true;
	}
	vector<int> ans;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			if (area[i][j] || v[i][j]) continue;
			ans.push_back(bfs(i, j));
		}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int a : ans) cout << a << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/2583