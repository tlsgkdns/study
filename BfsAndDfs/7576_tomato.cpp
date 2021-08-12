#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, ans = 0, unripe = 0, riped = 0;
vector<vector<int>> tomato, v;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
	tomato.resize(N, vector<int>(M));
	v.resize(N, vector<int>(M, -1));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> tomato[i][j];
			if (tomato[i][j] == 1)
			{
				v[i][j] = 0;
				q.push(make_pair(i, j));
			}
			else if (tomato[i][j] == 0)
				unripe++;
		}
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M
				|| v[ny][nx] != -1 || tomato[ny][nx] == -1) continue;
			v[ny][nx] = v[y][x] + 1;
			riped++;
			ans = max(v[ny][nx], ans);
			q.push(make_pair(ny, nx));
		}
	}
	ans = (riped == unripe) ? ans : -1;
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/7576