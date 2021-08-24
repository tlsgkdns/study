#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

int N, M, K;
char c;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	vector<vector<int>> maze(N, vector<int>(M));
	vector<vector<vector<int>>> v(N, vector<vector<int>>(M, vector<int>(K + 1, -1)));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> c;
			maze[i][j] = c - '0';
		}
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 0));
	v[0][0][0] = 1;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int br = q.front().second;
		q.pop();
		if (y == N - 1 && x == M - 1)
			break;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
			if (maze[ny][nx] == 1)
			{
				if (br >= K || v[ny][nx][br + 1] != -1) continue;
				v[ny][nx][br + 1] = v[y][x][br] + 1;
				q.push({ {ny, nx}, br + 1 });
			}
			else
			{
				if (v[ny][nx][br] != -1) continue;
				v[ny][nx][br] = v[y][x][br] + 1;
				q.push({ {ny, nx}, br });
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= K; i++)
		if (v[N - 1][M - 1][i] != -1)
		{
			ans = v[N - 1][M - 1][i];
			break;
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14442