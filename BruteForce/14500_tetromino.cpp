#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int paper[500][500];

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int N, M, ans = -1;

void solve(vector<vector<bool>>& v, int y, int x, int py, int px, int sum, int depth)
{
	if (depth == 4)
	{
		ans = max(ans, sum);
		return;
	}
	if (depth == 3)
		for (int i = 0; i < 4; i++)
		{
			int ny = py + dy[i];
			int nx = px + dx[i];
			if (ny < 0 || nx < 0 || ny == N || nx == M || v[ny][nx]) continue;
			ans = max(ans, sum + paper[ny][nx]);
		}

	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny == N || nx == M || v[ny][nx]) continue;
		v[ny][nx] = true;
		solve(v, ny, nx, y, x, sum + paper[ny][nx], depth + 1);
		v[ny][nx] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> paper[i][j];
	vector<vector<bool>> v(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			v[i][j] = true;
			solve(v, i, j, -1, -1, paper[i][j], 1);
			v[i][j] = false;
		}

	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14500